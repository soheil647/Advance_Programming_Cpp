
#include "../RSDL/src/rsdl.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>

#include "Tower.cpp"
#include "Bullet.cpp"
#include "Gattling.cpp"

using namespace std;
#define FONT_SANSSERIF "./Assets/OpenSans.ttf"
#define BUILD_GATTLING_KEY 'g'
#define BUILD_MISSILE_KEY 'm'
#define BUILD_TESLA_KEY 't'
#define BUILD_GLUE_KEY 'l'



bool process_event(const Event &event, vector<Tower *> &towers, Window *win, int &gold, int &health_point) {
    switch (event.get_type()) {
        case Event::QUIT:
            return false;
        case Event::LCLICK: {
            auto start = std::chrono::system_clock::now();
            while (true) {
                auto end = std::chrono::system_clock::now();
                Event event1 = win->poll_for_event();
                if (event1.get_pressed_key() == BUILD_GATTLING_KEY) {
                    Tower *new_tower = new Gattling("gattling1", event.get_mouse_position(), Point(100, 100),
                                                    "./Assets/towers/gattling1.png",
                                                    20, 10, "./extra/biker.png", 100);
                    gold -= new_tower->cost;
                    towers.push_back(new_tower);
                    win->play_sound_effect("./RSDL/example/assets/sound.wav");
                    break;
                }
                if (event1.get_pressed_key() == BUILD_MISSILE_KEY) {
                    Tower *new_tower = new Gattling("gattling1", event.get_mouse_position(), Point(100, 100),
                                                    "./Assets/towers/gattling1.png",
                                                    20, 10, "./extra/biker.png", 100);
                    gold -= new_tower->cost;
                    towers.push_back(new_tower);
                    win->play_sound_effect("./RSDL/example/assets/sound.wav");
                    break;
                }
                if (event1.get_pressed_key() == BUILD_GLUE_KEY) {
                    Tower *new_tower = new Gattling("gattling1", event.get_mouse_position(), Point(100, 100),
                                                    "./Assets/towers/gattling1.png",
                                                    20, 10, "./extra/biker.png", 100);
                    gold -= new_tower->cost;
                    towers.push_back(new_tower);
                    win->play_sound_effect("./RSDL/example/assets/sound.wav");
                    break;
                }
                if (event1.get_pressed_key() == BUILD_TESLA_KEY) {
                    Tower *new_tower = new Gattling("gattling1", event.get_mouse_position(), Point(100, 100),
                                                    "./Assets/towers/gattling1.png",
                                                    20, 10, "./extra/biker.png", 100);
                    gold -= new_tower->cost;
                    towers.push_back(new_tower);
                    win->play_sound_effect("./RSDL/example/assets/sound.wav");
                    break;
                }
                else if ((end - start).count() >= 3000000000)
                    break;
            }
        }
        case Event::KEY_RELEASE:
            if (event.get_pressed_key() == 'q') {
                return false;
            }
        default:;
        case Event::NA:
            break;
        case Event::RCLICK:

            break;
        case Event::LRELEASE:
            break;
        case Event::RRELEASE:
            break;
        case Event::MMOTION:
            break;
        case Event::KEY_PRESS:
            break;
        case Event::NO_EVENT:
            break;
    }
    return true;
}

void render(Window &win, const vector<Tower *> &towers, const int current_gold, int health_point) {
    win.clear();
    win.draw_img("./Assets/background.png");
    win.draw_rect(Rectangle(Point(421, 414 + 6 * 60), Point(480, 473 + 6 * 60)), WHITE);
    win.draw_rect(Rectangle(Point(421 - 60, 414), Point(480 - 60, 473)), WHITE);
    win.draw_rect(Rectangle(Point(421, 414), Point(480, 473)), WHITE);
    win.draw_rect(Rectangle(Point(421 + 60 + 60, 414), Point(480 + 60 + 60, 473)), WHITE);
    win.draw_rect(Rectangle(Point(421 + 9 * 60, 414), Point(480 + 9 * 60, 473)), WHITE);
    for (const auto &tower : towers) {
        win.draw_img(tower->tower_picture,
                     Rectangle(tower->position - tower->size / 2, tower->position + tower->size / 2), NULL_RECT, 0);
    }
    win.show_text("Gold: " + to_string(current_gold), Point(200, 220), RGB(20, 50, 100), FONT_SANSSERIF, 50);
    win.show_text("HP: " + to_string(health_point), Point(1000, 220), RGB(20, 50, 100), FONT_SANSSERIF, 50);
    win.draw_img("./RSDL/example/assets/cursor.png",
                 Rectangle(get_current_mouse_position() - Point(15, 15), 30, 30));
    win.update_screen();
    delay(5);
}

int main(int argc, char const *argv[]) {

    try {
        Window win = Window(1365, 1024, "Map");
        vector<Tower *> towers;
        int gold = 100;
        int health_point = 100;

        while (process_event(win.poll_for_event(), towers, &win, gold, health_point)) {
            render(win, towers, gold, health_point);
        }
    } catch (string &exception) {
        cerr << "EXCEPTION: " << exception << endl;
        exit(1);
    }

    return 0;
}