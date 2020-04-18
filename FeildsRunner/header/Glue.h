#ifndef FEILDSRUNNER_GLUE_H
#define FEILDSRUNNER_GLUE_H


#include "MapExceptions.h"
#include "Tower.h"
#include "../RSDL/src/rsdl.hpp"
#include <utility>


#define GLUE_PICTURE_LEVEL1 "./Assets/towers/glue1.png"
#define GLUE_PICTURE_LEVEL2 "./Assets/towers/glue2.png"
#define GLUE_PICTURE_LEVEL3 "./Assets/towers/glue3.png"

class Glue : public Tower{
private:

public:
    Glue(Point _position, const std::string& _tower_picture = GLUE_PICTURE_LEVEL1, int _cost = 55, Point _size = Point(100, 100),
    int bullet_damage = 35, int bullet_speed = 40,
            const std::string& bullet_picture = "", int _fire_rate = 2000);

    void update();
};


#endif //FEILDSRUNNER_GLUE_H
