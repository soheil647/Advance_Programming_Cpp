#include "../header/Map.h"

using namespace std;

Map::Map(Window *_map_window) {
    read_input_file();
    towers = {};
    enemies = {};
    map_window = _map_window;
    gold = INITIAL_GOLD;
    health = INITIAL_HEALTH;
    wave_number = 0;
    wave_finished = false;
    passed_time = 0;
    respawned_enemie = 0;
    map_window->play_music(BACKGROUND_SONG);
    complete_path_sequence();
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
        if (location_middle_square.x == tower->get_position().x && location_middle_square.y == tower->get_position().y)
            return false;
    }
    return true;
}

bool
Map::process_event() {
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
            if (event.get_pressed_key() == EXIT) {
                return false;
            }
        default:;
    }
    return true;
}

void Map::render() {
    map_window->clear();
    if (health <= 0)
        render_lose();
    else if (health > 0 && wave_number >= enemies_each_round.size())
        render_win();
    else {
        map_window->draw_img(BACKGROUND_PICTURE);
        show_enemies_path();
        for (const auto &tower : towers) {
            tower->fire(enemies, map_window);
        }
        for (const auto &enemie : enemies) {
            health = enemie->move(map_window, path, passed_time, health, gold);
        }
        render_goods();
        passed_time += 1;
    }
    map_window->update_screen();
    delay(RENDER_TIME);
}

Tower *Map::find_tower_from_location(Point location) {
    for (const auto &tower : towers) {
        if (tower->get_position().x == location.x && tower->get_position().y == location.y) {
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
        if ((end - start).count() >= 1500000000)
            throw MapExceptions(NO_KEY_PRESS_CODE);
        Event event1 = map_window->poll_for_event();
        if (event1.get_pressed_key() != -1)
            finish = process_pressed_key_command(event1.get_pressed_key(), mouse_position);
    }
}

bool Map::build_tower(char pressed_key, Point mouse_clicked_location) {
    if (find_square_emptiness(mouse_clicked_location) && check_path_build(mouse_clicked_location)) {
        Tower *new_tower = Tower::build(gold, pressed_key, mouse_clicked_location);
        if (new_tower == nullptr) {
            throw MapExceptions(BUILD_TOWER_ERROR_CODE);
        }
        towers.push_back(new_tower);
        map_window->play_sound_effect(BUILD_NEW_TOWER_SOUND);
        return true;
    } else throw MapExceptions(LOCATION_FOR_TOWER_FULL_CODE);
}

bool Map::update_tower(Point mouse_location) {
    Tower *clicked_tower = find_tower_from_location(mouse_location);
    if (clicked_tower == nullptr)
        throw MapExceptions(UPDATE_TOWER_ERROR_CODE);
    gold = clicked_tower->update(gold);
    map_window->play_sound_effect(UPDATE_TOWER_SOUND);
    return true;
}

bool Map::check_path_build(Point mouse_clicked_location) {
    for (Point middle : path) {
        if (mouse_clicked_location.x == middle.x && mouse_clicked_location.y == middle.y)
            return false;
    }
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

void Map::process_wave() {
    auto now_time = std::chrono::system_clock::now();
    if (!wave_finished) {
        if (is_three_second_passed()) {
            if (is_time_in_second_passed(50)) {
                int number_of_enemies = 0;
                for (int enemie_number = 0; enemie_number < NUMBER_OF_ENEMIES_TYPE; enemie_number++)
                    number_of_enemies += enemies_count[wave_number][enemie_number];

                if (respawned_enemie != number_of_enemies) {
                    enemies.push_back(&enemies_each_round[wave_number][respawned_enemie]);
                    respawned_enemie++;
                }
                wave_finished = count_remaining_enemies();
            }
        }
    } else reset_wave();
}

void Map::reset_wave() {
    enemies.clear();
    wave_number++;
    passed_time = 0;
    respawned_enemie = 0;
    wave_finished = false;
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

void Map::complete_path_sequence() {
    vector<Point> new_path = path;
    for (int i = 0; i < new_path.size(); i++) {
        Point temp_diff = (new_path[i + 1] - new_path[i]);
        if (temp_diff.y == 0 && temp_diff.x > 1)
            new_path.insert(new_path.begin() + i + 1, new_path[i] + Point(1, 0));
        if (temp_diff.y > 1 && temp_diff.x == 0)
            new_path.insert(new_path.begin() + i + 1, new_path[i] + Point(0, 1));
        if (temp_diff.y < -1 && temp_diff.x == 0)
            new_path.insert(new_path.begin() + i + 1, new_path[i] + Point(0, -1));
    }
    path = new_path;
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
    for (auto &i : enemies_each_round)
        shuffle(i.begin(), i.end(), std::default_random_engine(seed));
}

bool Map::is_three_second_passed() {
    return passed_time >= 300;
}

bool Map::is_time_in_second_passed(int time) {
    return passed_time % time == 0;
}

bool Map::count_remaining_enemies() {
    int count = 0;
    for (const auto &enemie: enemies) {
        if ((enemie->get_location().x == 0 && enemie->get_location().y == 0) ||
            (enemie->get_location().x == 1 && enemie->get_location().y == 0))
            count++;
    }
    return count == respawned_enemie;
}

void Map::show_enemies_path() {
    for (int i = 0; i < path.size() - 1; i++) {
        Point temp_diff = (path[i] - path[i + 1]);
        if (temp_diff.x == 0) {
            if (temp_diff.y > 0)
                map_window->draw_img(UP_PATH,
                                     Rectangle(path[i] - Point(30, 30), path[i] + Point(30, 30)));
            if (temp_diff.y < 0)
                map_window->draw_img(DOWN_PATH,
                                     Rectangle(path[i] - Point(30, 30), path[i] + Point(30, 30)));
        }
        if (temp_diff.x != 0)
            map_window->draw_img(RIGHT_PATH,
                                 Rectangle(path[i] - Point(30, 30), path[i] + Point(30, 30)));
    }
    map_window->draw_img(END_PATH,
                         Rectangle(path[path.size() - 1] - Point(30, 30), path[path.size() - 1] + Point(30, 30)));
}

void Map::render_lose() {
    map_window->stop_music();
    map_window->play_sound_effect(LOSE_SOUND);
    map_window->draw_img(LOSE_PICTURE, Rectangle(Point(0, 0), Point(1365, 1024)));
}

void Map::render_win() {
    map_window->stop_music();
    map_window->play_sound_effect(WIN_SOUND);
    map_window->draw_img(WIN_PICTURE, Rectangle(Point(0, 0), Point(1365, 1024)));
}

void Map::render_goods() {
    map_window->show_text(": " + to_string(gold), Point(490, 220), RGB(20, 50, 100), FONT_TEXT_SANSSERIF, 50);
    map_window->draw_img(GOLD_PICTURE,
                         Rectangle(Point(400, 220), Point(400, 220) + Point(90, 90)));
    map_window->show_text(": " + to_string(health), Point(870, 220), RGB(20, 50, 100), FONT_TEXT_SANSSERIF, 50);
    map_window->draw_img(HEALTH_PICTURE,
                         Rectangle(Point(800, 200), Point(800, 200) + Point(90, 90)));
    map_window->draw_img(CURSOR_PICTURE,
                         Rectangle(get_current_mouse_position() - Point(15, 15), 30, 30));
}