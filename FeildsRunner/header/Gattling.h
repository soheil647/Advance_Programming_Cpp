#ifndef FEILDSRUNNER_GATTLING_H
#define FEILDSRUNNER_GATTLING_H


#include "Tower.h"
#include "Bullet.h"
#include "../RSDL/src/rsdl.hpp"

class Gattling : public Tower {
private:

public:
    Gattling(std::string _name, Point _position, Point _size, std::string _tower_picture, int _cost, int bullet_speed,
             std::string bullet_picture, int _fire_rate);
//    void update()

};


#endif //FEILDSRUNNER_GATTLING_H
