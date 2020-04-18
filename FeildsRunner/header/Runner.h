#ifndef FEILDSRUNNER_RUNNER_H
#define FEILDSRUNNER_RUNNER_H


#include "Enemies.h"
#include <vector>

class Runner : public Enemies {
public:
    Runner(Point _location, int _health = 250, int _speed = 1, int _reward = 6, int _damage = 1,
           const std::string &_picture = "./Assets/enemies/runner.png");
};


#endif //FEILDSRUNNER_RUNNER_H
