#ifndef FEILDSRUNNER_MISSILE_H
#define FEILDSRUNNER_MISSILE_H

#include "MapExceptions.h"
#include "Tower.h"
#include "../RSDL/src/rsdl.hpp"
#include <utility>
#include <iostream>


#define MISSILE_PICTURE_LEVEL1 "./Assets/towers/missile1.png"
#define MISSILE_PICTURE_LEVEL2 "./Assets/towers/missile2.png"
#define MISSILE_PICTURE_LEVEL3 "./Assets/towers/missile3.png"

class Missile : public Tower {
public:
    Missile(Point _position, const std::string& _tower_picture = MISSILE_PICTURE_LEVEL1 , int _cost = 70, Point _size = Point(100, 100),
    int bullet_damage = 75, int bullet_speed = 40,
    const std::string& bullet_picture = "", int _fire_rate = 3000);

    void update();
};


#endif //FEILDSRUNNER_MISSILE_H
