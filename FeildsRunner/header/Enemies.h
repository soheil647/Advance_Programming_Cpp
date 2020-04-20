#ifndef FEILDSRUNNER_ENEMIES_H
#define FEILDSRUNNER_ENEMIES_H


#include <string>
#include <vector>
#include "../RSDL/src/rsdl.hpp"

class Enemies {
private:
    int health;
    int speed;
    int reward;
    int damage;
    std::string picture;
    Point location{};
    int passed_path;

    int reach_end(int player_health);
    int find_next_move(const std::vector<Point> &path, int passed_time, int player_health);
    int destroy();
public:
    Enemies(Point _location, int _health, int _speed, int _reward, int _damage, const std::string& _picture);
    Enemies() = default;
    Point get_location();

    int move(Window * map_window, const std::vector<Point>& path, int passed_time, int player_health, int& gold);
    void lose_health(int bullet_damage);

};

#endif //FEILDSRUNNER_ENEMIES_H
