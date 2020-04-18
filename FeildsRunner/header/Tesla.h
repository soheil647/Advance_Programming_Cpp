#ifndef FEILDSRUNNER_TESLA_H
#define FEILDSRUNNER_TESLA_H


#include "MapExceptions.h"
#include "Tower.h"
#include "../RSDL/src/rsdl.hpp"
#include <utility>
#include <iostream>


#define TESLA_PICTURE_LEVEL1 "./Assets/towers/tesla1.png"
#define TESLA_PICTURE_LEVEL2 "./Assets/towers/tesla2.png"
#define TESLA_PICTURE_LEVEL3 "./Assets/towers/tesla3.png"

class Tesla : public Tower {

public:
    Tesla(Point _position, const std::string& _tower_picture = TESLA_PICTURE_LEVEL1, int _cost = 120, Point _size = Point(100, 100), int bullet_damage = 700,
                       int bullet_speed = 50, const std::string& bullet_picture = "", int _fire_rate = 1500);
    void update();
};


#endif //FEILDSRUNNER_TESLA_H
