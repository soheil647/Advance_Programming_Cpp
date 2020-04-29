#ifndef FEILDSRUNNER_ENEMIES_H
#define FEILDSRUNNER_ENEMIES_H


#include <string>
#include <vector>
#include "rsdl.hpp"

#define RENDER_TIME 10
#define DEATH_SOUND "./Assets/song/death.wav"

#define UP "up.png"
#define DOWN "down.png"
#define RIGHT "right.png"

#define STUBBORN "stubborn"

class Enemies {
private:
    std::string name;
    int health;
    int speed;
    int reward;
    int damage;
    std::string picture;
    std::string moving_side;
    Point location{};
    int passed_path;
    int initial_health;
    bool is_glued;
    int slowed_time_passed;
    int initial_speed;

    int reach_end(int player_health);
    int find_next_move(const std::vector<Point> &path, int passed_time, int player_health);
    int destroy(Window* map_window);
public:
    Enemies(Point _location, int _health, int _speed, int _reward, int _damage, const std::string& _picture_path, const std::string& _name);
    Enemies() = default;
    Point get_location();
    std::string get_name();
    int move(Window * map_window, const std::vector<Point>& path, int passed_time, int player_health, int& gold);
    void lose_health(int bullet_damage);
    void lose_speed(int bullet_damage, int slow_duration);


};

#endif //FEILDSRUNNER_ENEMIES_H
