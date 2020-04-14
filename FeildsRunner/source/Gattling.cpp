#include "../header/Gattling.h"

#include <utility>

Gattling::Gattling(std::string _name, Point _position, Point _size, std::string _tower_picture, int _cost,
                   int bullet_speed,
                   std::string bullet_picture, int _fire_rate)
        : Tower(std::move(_name), _position, _size, std::move(_tower_picture), _cost, bullet_speed, std::move(bullet_picture),
                _fire_rate) {

}
