#include "../header/Tower.h"

#include <utility>


Tower::Tower(std::string _name, Point _position, Point _size, std::string _tower_picture, int _cost, int _bullet_speed,
             std::string _bullet_picture, int _fire_rate) {
    name = std::move(_name);
    position = _position;
    size = _size;
    tower_picture = std::move(_tower_picture);
    cost = _cost;
    bullet_speed = _bullet_speed;
    bullet_picture = std::move(_bullet_picture);
    fire_rate = _fire_rate;
}
