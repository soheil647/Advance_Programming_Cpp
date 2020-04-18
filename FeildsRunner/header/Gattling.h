#ifndef FEILDSRUNNER_GATTLING_H
#define FEILDSRUNNER_GATTLING_H


#include "MapExceptions.h"
#include "Tower.h"
#include "../RSDL/src/rsdl.hpp"
#include <utility>
#include <iostream>

#define GATTLING_PICTURE_LEVEL1 "./Assets/towers/gattling1.png"
#define GATTLING_PICTURE_LEVEL2 "./Assets/towers/gattling2.png"
#define GATTLING_PICTURE_LEVEL3 "./Assets/towers/gattling3.png"

class Gattling : public Tower {

public:
    Gattling(Point _position, const std::string& _tower_picture = GATTLING_PICTURE_LEVEL1 , int _cost = 55, Point _size = Point(100, 100),
             int bullet_damage = 35, int bullet_speed = 40,
             const std::string& bullet_picture = "", int _fire_rate = 1000);
    void update();
};


#endif //FEILDSRUNNER_GATTLING_H
