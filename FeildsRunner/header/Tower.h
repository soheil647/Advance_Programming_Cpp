#ifndef FEILDSRUNNER_GAME_TOWER_H
#define FEILDSRUNNER_GAME_TOWER_H

#include <string>
#include <utility>
#include "MapExceptions.h"
#include "Enemies.h"

#define GATLING "gatling"
#define GATLING_FIRE_SOUND "./Assets/song/gatling.wav"
#define MISSILE "missile"
#define MISSILE_FIRE_SOUND "./Assets/song/missile.wav"
#define TESLA "tesla"
#define TESLA_FIRE_SOUND "./Assets/song/tesla.wav"
#define GLUE "glue"
#define GLUE_FIRE_SOUND "./Assets/song/glue.wav"

#define TOWER_SIZE Point(100, 100)
#define GATTLING_PARAMETER "./Assets/towers/Gattling/", 55, 40, 35, 0,35, 40 , "./Assets/circle.png", 1000, "gatling"
#define MISSILE_PARAMETER "./Assets/towers/Missile/", 70, 60, 75, 50,70, 40 , "./Assets/circle.png", 3000, "missile"
#define TESLA_PARAMETER "./Assets/towers/Tesla/", 120, 100, 700, 0,1000, 50 , "./Assets/circle.png", 1500, "tesla"
#define GLUE_PARAMETER "./Assets/towers/Glue/", 60, 45, 40, 30, 10, 40, "./Assets/circle.png", 2000, "glue"
#define GLUE_SLOW_PARAMETER 2500, 500
#define SLOW_PARAMETER 0, 0
#define FIRE "fire"

#define BUILD_GATTLING_KEY 'g'
#define BUILD_MISSILE_KEY 'm'
#define BUILD_TESLA_KEY 't'
#define BUILD_GLUE_KEY 'l'

#define TOWER_RANGE 150

#define RENDER_TIME 10

#define STUBBORN "stubborn"
#define GATLING "gatling"

class Tower {
private:
    std::string name;
    int level;
    Point position{};
    std::string tower_picture_file;
    std::string tower_picture;
    int cost{};
    int bullet_speed;
    int bullet_area;
    int bullet_update_damage;
    int fire_rate;
    int fire_time;
    Enemies* previous_target;
    int slow_duration;
    int slow_upgrade_duration;
    int bullet_damage;
    std::string bullet_picture;
    int update_cost;
    bool bullet_fired;
    Point bullet_position;

    bool previous_target_in_range();
    Enemies *find_enemie_in_range(const std::vector<Enemies *> &enemies);
    std::vector<Enemies *> find_enemies_in_area(Point enemie_location, const std::vector<Enemies*>& enemies);
    void do_area_damage(const std::vector<Enemies *> &target_enemies);
    void do_area_slow(const std::vector<Enemies *> &target_enemies);
    void draw(Window* map_window);
    void play_fire_sound(Window *map_window);
    void fire_bullet(Window *map_window);
public:
    Tower(Point _position, const std::string& _tower_picture_file, int _cost, int _update_Cost, int _bullet_damage, int _bullet_area, int _bullet_update_damage,
          int _bullet_speed, const std::string& _bullet_picture, int _fire_rate, const std::string& _name, int _slow_duration, int _slow_upgrade_duration);

    Point get_position();
    int update(int gold);
    static Tower* build(int &gold, char pressed_key, Point mouse_clicked_location);
    void fire(const std::vector<Enemies *>& enemies, Window* map_window);

};


#endif //FEILDSRUNNER_GAME_TOWER_H
