#ifndef FEILDSRUNNER_MAP_H
#define FEILDSRUNNER_MAP_H


#include "../RSDL/src/rsdl.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <time.h>

#include "../source/MapExceptions.cpp"
#include "../source/Tower.cpp"
#include "../source/Enemies.cpp"

#define RENDER_TIME 10

#define HALF_SQUARE_LENGTH 30
#define SQUARE_LENGTH 60
#define FIRST_SQUARE_X 120
#define FIRST_SQUARE_Y 180

#define INITIAL_GOLD 200
#define INITIAL_HEALTH 100


#define FONT_TEXT_SANSSERIF "./Assets/OpenSans.ttf"

#define BUILD_GATTLING_KEY 'g'
#define BUILD_MISSILE_KEY 'm'
#define BUILD_TESLA_KEY 't'
#define BUILD_GLUE_KEY 'l'
#define UPDATE_TOWER_KEY 'u'
#define KEY_BINDING vector<char>
#define KEYS BUILD_GATTLING_KEY, BUILD_MISSILE_KEY, BUILD_TESLA_KEY, BUILD_GLUE_KEY, UPDATE_TOWER_KEY

#define BUILD_NEW_TOWER_SOUND "./RSDL/example/assets/sound.wav"
#define UPDATE_TOWER_SOUND "./RSDL/example/assets/sound.wav"

#define NUMBER_OF_ENEMIES_TYPE 4
#define RUNNER_PARAMETER 250, 50, 6, 1, "./Assets/enemies/runner.png"
#define STUBBORN_RUNNER_PARAMETER 400, 30, 10, 4, "./Assets/enemies/stubborn-runner.png"
#define SUPPERTROOPER 500, 25, 8, 4, "./Assets/enemies/supertrooper.png"
#define SCRAMBLER 100, 90, 4, 2, "./Assets/enemies/scrambler.png"



class Map {
private:
    std::vector<Tower *> towers;
    std::vector<Enemies *> enemies;
    Window *map_window;
    int gold;
    int health;
    int wave_number{};
    bool wave_finished;
    std::vector<Point> path;
    std::vector<std::vector<int>> enemies_count;
    std::vector<vector<Enemies>> enemies_each_round;
    int passed_time;
    int respawned_enemie;

    void read_input_file();

    static Point find_square_middle_point(Point location);

    bool find_square_emptiness(Point location_middle_square);
    void map_squares_to_middle_points();
    Tower* find_tower_from_location(Point location);
    void process_left_click_event(Point mouse_position);
    void find_enemies_for_each_round();
    void shuffle_enemies_of_each_round();

    bool build_tower(char pressed_key, Point mouse_clicked_location);
    bool update_tower(Point mouse_location);
    bool process_pressed_key_command(char pressed_key, Point mouse_clicked_location);

    void process_wave();
    bool is_three_second_passed();
    bool is_time_in_second_passed(int time);


public:
    Map(Window *_map_window);

    bool process_event();
    void render();

    bool count_remaining_enemies();
};


#endif //FEILDSRUNNER_MAP_H
