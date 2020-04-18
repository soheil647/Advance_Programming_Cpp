#include "../header/Tesla.h"

using namespace std;


Tesla::Tesla(Point _position, const std::string& _tower_picture, int _cost, Point _size, int bullet_damage,
           int bullet_speed, const std::string& bullet_picture, int _fire_rate)
        : Tower(_position, _tower_picture, _cost, _size, bullet_damage, bullet_speed, bullet_picture, _fire_rate) {

}

void Tesla::update() {
    if(this->level != 3) {
        if (this->level == 1)
            this->tower_picture = TESLA_PICTURE_LEVEL2;
        if (this->level == 2)
            this->tower_picture = TESLA_PICTURE_LEVEL3;

        this->bullet_damage += 1000;
        this->cost = 100;
        this->level++;
    } else
        throw MapExceptions(TOWER_MAX_LEVEL_CODE);
}
