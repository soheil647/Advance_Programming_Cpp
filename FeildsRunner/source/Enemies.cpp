#include <algorithm>
#include "../header/Enemies.h"

using namespace std;

Enemies::Enemies(Point _location, int _health, int _speed, int _reward, int _damage, const std::string& _picture) {
    health = _health;
    speed = _speed;
    reward = _reward;
    damage = _damage;
    picture = _picture;
    location = _location;
    passed_path = 1;
}

int Enemies::move(Window *map_window, const std::vector<Point>& path, int passed_time, int player_health, int& gold) {
    if(this->location.x != 0 && this->location.y != 0) {
        gold += this->destroy();
        map_window->draw_img(this->picture,
                             Rectangle(this->location - Point(20, 20), this->location + Point(20, 20)));
        return find_next_move(path, passed_time, player_health);
    }
    return player_health;
}

int Enemies::find_next_move(const std::vector<Point> &path, int passed_time, int player_health) {
    if(passed_time % (100/speed) == 0) {
        if (passed_path == path.size()) {
            return reach_end(player_health);
        }
        else if (location.x == path[passed_path].x && location.y == path[passed_path].y)
            passed_path += 1;
        else if (location.x != path[passed_path].x)
            location = location + Point(1, 0);
        else if (location.y != path[passed_path].y)
            location = location + Point(0, 1);
    }
    return player_health;
}

Point Enemies::get_location() {
    return this->location;
}

void Enemies::lose_health(int bullet_damage) {
    this->health -= bullet_damage;

}

int Enemies::destroy(){
    if(this->health <= 0){
        this->location = Point(0,0);
        return this->reward;
    }
    return 0;
}

int Enemies::reach_end(int player_health){
    player_health -= this->damage;
    this->location = Point(0, 0);
    return player_health;
}