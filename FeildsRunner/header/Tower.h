#ifndef FEILDSRUNNER_GAME_TOWER_H
#define FEILDSRUNNER_GAME_TOWER_H

#include <string>
#include "../RSDL/src/rsdl.hpp"
#include <utility>
#include "MapExceptions.h"
#include "Enemies.h"


#define TOWER_SIZE Point(100, 100)
#define GATTLING_PARAMETER "./Assets/towers/gattling1.png", "./Assets/towers/gattling2.png", "./Assets/towers/gattling3.png", 55, 40, 35, 0,35, 40 , "./Assets/circle.png", 1000
#define MISSILE_PARAMETER "./Assets/towers/missile1.png", "./Assets/towers/missile2.png", "./Assets/towers/missile3.png", 70, 60, 75, 50,70, 40 , "./Assets/circle.png", 3000
#define TESLA_PARAMETER "./Assets/towers/tesla1.png", "./Assets/towers/tesla2.png", "./Assets/towers/tesla3.png", 120, 100, 700, 0,1000, 50 , "./Assets/circle.png", 1500
#define GLUE_PARAMETER "./Assets/towers/glue1.png", "./Assets/towers/glue2.png", "./Assets/towers/glue3.png", 55, 45, 35, 40, 30,40, "./Assets/circle.png", 2000


#define BUILD_GATTLING_KEY 'g'
#define BUILD_MISSILE_KEY 'm'
#define BUILD_TESLA_KEY 't'
#define BUILD_GLUE_KEY 'l'

#define TOWER_RANGE 150

#define RENDER_TIME 10

class Tower {
private:
    int level;
    Point position{};
    std::string tower_picture;
    std::string tower_picture_level2;
    std::string tower_picture_level3;
    int cost{};
    int update_cost;
    int bullet_speed;
    int bullet_damage;
    int bullet_area;
    int bullet_update_damage;
    std::string bullet_picture;
    int fire_rate;
    int fire_time;
public:
    Tower(Point _position, const std::string& _tower_picture_level1, const std::string& _tower_picture_level2,
          const std::string& _tower_picture_level3, int _cost, int _update_Cost, int _bullet_damage, int _bullet_area, int _bullet_update_damage,
          int _bullet_speed, const std::string& _bullet_picture, int _fire_rate);

    Point get_position();
    int update(int gold);
    static Tower* build(int &gold, char pressed_key, Point mouse_clicked_location);
    void draw(Window* map_window);
    void fire(const std::vector<Enemies *>& enemies, Window* map_window, int passed_time);

    Enemies *find_enemie_in_range(const std::vector<Enemies *> &enemies);

    std::vector<Enemies *> find_enemies_in_area(Point location);
};


#endif //FEILDSRUNNER_GAME_TOWER_H
