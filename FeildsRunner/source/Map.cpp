#include <random>
#include "../header/Map.h"

using namespace std;

Map::Map(const std::vector<Tower *> &_towers, const std::vector<Enemies *> &_enemies, Window *_map_window) {
    read_input_file();
    towers = _towers;
    enemies = _enemies;
    map_window = _map_window;
    gold = INITIAL_GOLD;
    health = INITIAL_HEALTH;
    wave_number = 0;
    wave_finished = false;
    passed_time = 0;
    map_squares_to_middle_points();
    find_enemies_for_each_round();
    shuffle_enemies_of_each_round();
}

Point Map::find_square_middle_point(Point location) {
    for (int i = 2; i <= 20; i++) {
        for (int j = 3; j <= 13; j++) {
            if (i * 60 < location.x && location.x < i * 60 + 60 && j * 60 < location.y && location.y < j * 60 + 60) {
                return {i * 60 + 30, j * 60 + 30};
            }
        }
    }
    return {0, 0};
}

bool Map::find_square_emptiness(Point location_middle_square) {
    for (auto tower : towers) {
        if (location_middle_square.x == tower->position.x && location_middle_square.y == tower->position.y)
            return false;
    }
    return true;
}

bool
Map::process_event(chrono::time_point<chrono::system_clock, chrono::duration<long, ratio<1, 1000000000>>> start_time) {
    auto now_time = std::chrono::system_clock::now();

    Event event = map_window->poll_for_event();
    process_wave();
    switch (event.get_type()) {
        case Event::QUIT:
            return false;
        case Event::LCLICK: {
            try {
                Point location = find_square_middle_point(event.get_mouse_position());
                process_left_click_event(location);
            }
            catch (MapExceptions &exception) {
                exception.handle_exception_sound(map_window);
            }
        }
        case Event::KEY_RELEASE:
            if (event.get_pressed_key() == 'q') {
                return false;
            }
        default:;
    }
    return true;
}

void Map::render() {
    map_window->clear();
    map_window->draw_img("./Assets/background.png");
    for (int i = 2; i <= 20; i++) {
        for (int j = 3; j <= 13; j++) {
            map_window->draw_rect(Rectangle(Point(i * 60, j * 60), Point(i * 60 + 60, j * 60 + 60)), WHITE);
        }
    }
    for (const auto &tower : towers) {
        map_window->draw_img(tower->tower_picture,
                             Rectangle(tower->position - tower->size / 2, tower->position + tower->size / 2));
    }
    for (const auto &enemie : enemies) {
        enemie->move(map_window, path, passed_time);
    }
    map_window->show_text("Gold: " + to_string(gold), Point(200, 220), RGB(20, 50, 100), FONT_TEXT_SANSSERIF, 50);
    map_window->show_text("HP: " + to_string(health), Point(1000, 220), RGB(20, 50, 100), FONT_TEXT_SANSSERIF, 50);
    map_window->draw_img("./RSDL/example/assets/cursor.png",
                         Rectangle(get_current_mouse_position() - Point(15, 15), 30, 30));
    map_window->update_screen();
    passed_time += 1;
    delay(RENDER_TIME);
}

Tower *Map::find_tower_from_location(Point location) {
    for (const auto &tower : towers) {
        if (tower->position.x == location.x && tower->position.y == location.y) {
            return tower;
        }
    }
    return nullptr;
}

void Map::process_left_click_event(Point mouse_position) {
    bool finish = false;
    auto start = std::chrono::system_clock::now();
    while (!finish) {
        auto end = std::chrono::system_clock::now();
        if ((end - start).count() >= 1000000000)
            throw MapExceptions(NO_KEY_PRESS_CODE);
        Event event1 = map_window->poll_for_event();
        if (event1.get_pressed_key() != -1)
            finish = process_pressed_key_command(event1.get_pressed_key(), mouse_position);
    }
}

bool Map::build_tower(char pressed_key, Point mouse_clicked_location) {
    if (find_square_emptiness(mouse_clicked_location)) {
        Tower *new_tower = nullptr;
        if (pressed_key == BUILD_GATTLING_KEY)
            new_tower = new Gattling(mouse_clicked_location);
        else if (pressed_key == BUILD_MISSILE_KEY)
            new_tower = new Missile(mouse_clicked_location);
        else if (pressed_key == BUILD_TESLA_KEY)
            new_tower = new Tesla(mouse_clicked_location);
        else if (pressed_key == BUILD_GLUE_KEY)
            new_tower = new Glue(mouse_clicked_location);
        else throw MapExceptions(BUILD_TOWER_ERROR_CODE);
        gold -= new_tower->cost;
        towers.push_back(new_tower);
        map_window->play_sound_effect(BUILD_NEW_TOWER_SOUND);
        return true;
    } else throw MapExceptions(LOCATION_FOR_TOWER_FULL_CODE);
}

bool Map::update_tower(Point mouse_location) {
    Tower *clicked_tower = find_tower_from_location(mouse_location);
    if (clicked_tower == nullptr)
        throw MapExceptions(UPDATE_TOWER_ERROR_CODE);
    clicked_tower->update();
    gold -= clicked_tower->cost;
    map_window->play_sound_effect(UPDATE_TOWER_SOUND);
    return true;
}

bool Map::process_pressed_key_command(char pressed_key, Point mouse_clicked_location) {
    KEY_BINDING key_binding{KEYS};
    if (find(key_binding.begin(), key_binding.end(), pressed_key) == key_binding.end())
        throw MapExceptions(WRONG_KEY_PRESS_CODE);
    if (pressed_key == UPDATE_TOWER_KEY) {
        return update_tower(mouse_clicked_location);
    } else return build_tower(pressed_key, mouse_clicked_location);
}

int i = 0;

void Map::process_wave() {
    auto now_time = std::chrono::system_clock::now();
    if (is_three_second_passed()) {
        if (is_time_in_second_passed(50)) {
            int number_of_enemies = 0;
            for (int enemie_number = 0; enemie_number < NUMBER_OF_ENEMIES_TYPE; enemie_number++)
                number_of_enemies += enemies_count[wave_number][enemie_number];

            if (i != number_of_enemies) {
                enemies.push_back(&enemies_each_round[wave_number][i]);
                i++;
            }
        }
    }
}

void Map::process_wave_time() {
    auto now_time = std::chrono::system_clock::now();
    if (!wave_finished) {

    }
}

void Map::read_input_file() {
    string path_str;
    stringstream waves_text;
    getline(cin, path_str);

    size_t pos = 0;
    std::string token;
    string delimiter = " ";
    vector<int> temp;
    while ((pos = path_str.find(' ')) != std::string::npos) {
        token = path_str.substr(0, pos);
        temp.push_back(stoi(token));
        path_str.erase(0, pos + delimiter.size());
    }
    temp.push_back(stoi(path_str));

    for (int n = 0; n < temp.size(); n += 2)
        path.emplace_back(Point(temp[n], temp[n + 1]));

    while (getline(cin, path_str)) {
        vector<int> enemies_counter;
        while ((pos = path_str.find(' ')) != std::string::npos) {
            token = path_str.substr(0, pos);
            enemies_counter.push_back(stoi(token));
            path_str.erase(0, pos + delimiter.size());
        }
        enemies_counter.push_back(stoi(path_str));
        enemies_count.push_back(enemies_counter);
    }
}

void Map::map_squares_to_middle_points() {
    for (auto &m : path)
        m = Point(m.x * SQUARE_LENGTH + FIRST_SQUARE_X + HALF_SQUARE_LENGTH,
                  m.y * SQUARE_LENGTH + FIRST_SQUARE_Y + HALF_SQUARE_LENGTH);
}


void Map::find_enemies_for_each_round() {
    for (const vector<int> &each_round: enemies_count) {
        vector<Enemies> temp_enemie;
        for (int enemie_number = 0; enemie_number < each_round.size(); enemie_number++) {
            for (int j = 0; j < each_round[enemie_number]; j++) {
                Enemies new_enemie;
                if (enemie_number == 0)
                    new_enemie = Enemies(path[0], RUNNER_PARAMETER);
                if (enemie_number == 1)
                    new_enemie = Enemies(path[0], STUBBORN_RUNNER_PARAMETER);
                if (enemie_number == 2)
                    new_enemie = Enemies(path[0], SUPPERTROOPER);
                if (enemie_number == 3)
                    new_enemie = Enemies(path[0], SCRAMBLER);
                temp_enemie.push_back(new_enemie);
            }
        }
        enemies_each_round.push_back(temp_enemie);
    }
}

void Map::shuffle_enemies_of_each_round() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(enemies_each_round[0].begin(), enemies_each_round[0].end(), std::default_random_engine(seed));
}

bool Map::is_three_second_passed() {
    return passed_time >= 300;
}
bool Map::is_time_in_second_passed(int time) {
    return passed_time % time == 0;
}
