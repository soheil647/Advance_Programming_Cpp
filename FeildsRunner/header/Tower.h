#ifndef FEILDSRUNNER_GAME_TOWER_H
#define FEILDSRUNNER_GAME_TOWER_H

#include <string>
#include "../RSDL/src/rsdl.hpp"
#include <utility>


class Tower {
protected:
public:
    Tower(std::string _name, Point _position, Point _size, std::string _tower_picture, int _cost, int _bullet_speed,
          std::string _bullet_picture, int _fire_rate);

//    virtual void fire(int damage, int fire_rate) = 0;
//    virtual void upgrade(int _cost) = 0;
    Point size{};
    Point position{};
    std::string name;
    std::string tower_picture;
    int cost{};
    int bullet_speed;
    std::string bullet_picture;
    int fire_rate;
};


#endif //FEILDSRUNNER_GAME_TOWER_H
