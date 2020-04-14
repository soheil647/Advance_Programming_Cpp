#ifndef FEILDSRUNNER_BULLET_H
#define FEILDSRUNNER_BULLET_H


#include <string>

class Bullet {
protected:
    int speed;
    std::string picture;
public:
    Bullet(int _speed, std::string _picture);
//    virtual void move_bullet() = 0;
};


#endif //FEILDSRUNNER_BULLET_H
