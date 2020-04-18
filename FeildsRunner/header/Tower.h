#ifndef FEILDSRUNNER_GAME_TOWER_H
#define FEILDSRUNNER_GAME_TOWER_H

#include <string>
#include "../RSDL/src/rsdl.hpp"
#include <utility>


class Tower {
protected:
    int level;
public:
    Tower(Point _position, std::string _tower_picture, int _cost, Point _size, int _bullet_damage,
            int _bullet_speed, std::string _bullet_picture, int _fire_rate);

//    virtual void fire(int damage, int fire_rate) = 0;
    virtual void update() = 0;
    Point size{};
    Point position{};
    std::string tower_picture;
    int cost{};
    int bullet_speed;
    int bullet_damage;
    std::string bullet_picture;
    int fire_rate;
};


#endif //FEILDSRUNNER_GAME_TOWER_H
