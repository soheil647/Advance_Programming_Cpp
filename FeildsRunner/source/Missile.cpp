#include "../header/Missile.h"

using namespace std;

Missile::Missile(Point _position, const std::string& _tower_picture, int _cost, Point _size, int bullet_damage,
                   int bullet_speed, const std::string& bullet_picture, int _fire_rate)
        : Tower(_position, _tower_picture, _cost, _size, bullet_damage, bullet_speed, bullet_picture, _fire_rate) {
    level = 1;
}

void Missile::update() {
    if(level != 3) {
        if (level == 1)
            this->tower_picture = MISSILE_PICTURE_LEVEL2;
        if (level == 2)
            this->tower_picture = MISSILE_PICTURE_LEVEL3;

        this->bullet_damage += 70;
        this->cost = 60;
        level++;
    } else
        throw MapExceptions(TOWER_MAX_LEVEL_CODE);
}
