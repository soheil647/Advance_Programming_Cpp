#include "../header/Tower.h"



Tower::Tower(Point _position, std::string _tower_picture, int _cost, Point _size, int _bullet_damage, int _bullet_speed,
             std::string _bullet_picture, int _fire_rate) {
    position = _position;
    tower_picture = std::move(_tower_picture);
    cost = _cost;
    size = _size;
    bullet_damage = _bullet_damage;
    bullet_speed = _bullet_speed;
    bullet_picture = std::move(_bullet_picture);
    fire_rate = _fire_rate;
    level = 1;
}
