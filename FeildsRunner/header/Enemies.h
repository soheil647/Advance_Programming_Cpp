#ifndef FEILDSRUNNER_ENEMIES_H
#define FEILDSRUNNER_ENEMIES_H


#include <string>
#include <vector>
#include "../RSDL/src/rsdl.hpp"

class Enemies {
private:
    void find_next_move(const std::vector<Point>& path, int passed_time);
public:
    int health;
    int speed;
    int reward;
    int damage;
    std::string picture;
    Point location{};
    int passed_path;

    Enemies(Point _location, int _health, int _speed, int _reward, int _damage, const std::string& _picture);
    Enemies() = default;

    void move(Window * map_window, const std::vector<Point>& path, int passed_time);
};

#endif //FEILDSRUNNER_ENEMIES_H
