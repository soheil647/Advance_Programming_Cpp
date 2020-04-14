#include "../header/Bullet.h"

#include <utility>

Bullet::Bullet(int _speed, std::string _picture) {
    speed = _speed;
    picture = std::move(_picture);
}
