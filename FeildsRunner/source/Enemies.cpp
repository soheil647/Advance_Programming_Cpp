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

void Enemies::move(Window *map_window, const std::vector<Point>& path, int passed_time) {
    map_window->draw_img(this->picture,
                         Rectangle(this -> location - Point(20, 20), this -> location + Point(20, 20)));
    find_next_move(path, passed_time);
}

void Enemies::find_next_move(const std::vector<Point> &path, int passed_time) {
    if(passed_time % (100/speed) == 0) {
        if (passed_path > path.size())
            location = location;
        else if (location.x == path[passed_path].x && location.y == path[passed_path].y)
            passed_path += 1;
        else if (location.x != path[passed_path].x)
            location = location + Point(1, 0);
        else if (location.y != path[passed_path].y)
            location = location + Point(0, 1);
    }

}
