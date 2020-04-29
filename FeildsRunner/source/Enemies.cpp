#include "../header/Enemies.h"

using namespace std;

Enemies::Enemies(Point _location, int _health, int _speed, int _reward, int _damage, const std::string& _picture_path, const string& _name) {
    name = _name;
    initial_health = _health;
    health = _health;
    speed = _speed;
    initial_speed = _speed;
    reward = _reward;
    damage = _damage;
    picture = _picture_path;
    location = _location;
    passed_path = 1;
    is_glued = false;
    slowed_time_passed = 0;
    moving_side = RIGHT;
}

int Enemies::move(Window *map_window, const std::vector<Point>& path, int passed_time, int player_health, int& gold) {
    if(this->location.x != 0 && this->location.y != 0) {
        gold += this->destroy(map_window);
        if(this->is_glued){
            slowed_time_passed -= RENDER_TIME;
            if(slowed_time_passed <= 0){
                is_glued = false;
                slowed_time_passed = 0;
                this->speed = this->initial_speed;
            }
        }
        map_window->draw_rect(Rectangle(this->location + Point(-50, -30),this->location + Point(this->initial_health/5, -30)), GREEN);
        map_window->draw_rect(Rectangle(this->location + Point(-50, -30),this->location + Point(this->health/5, -30)), RED);
        map_window->draw_img(this->picture + this->moving_side,
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
        else if (location.x != path[passed_path].x && location.x < path[passed_path].x) {
            location = location + Point(1, 0);
            this->moving_side = RIGHT;
        }
        else if (location.y != path[passed_path].y && location.y < path[passed_path].y) {
            location = location + Point(0, 1);
            this->moving_side = DOWN;
        }
        else if (location.y != path[passed_path].y && location.y > path[passed_path].y) {
            location = location + Point(0, -1);
            this->moving_side = UP;
        }
    }
    return player_health;
}

Point Enemies::get_location() {
    return this->location;
}

void Enemies::lose_health(int bullet_damage) {
    this->health -= bullet_damage;
}

int Enemies::destroy(Window* map_window){
    if(this->health <= 0){
        this->location = Point(0,0);
        map_window->play_sound_effect(DEATH_SOUND);
        return this->reward;
    }
    return 0;
}

int Enemies::reach_end(int player_health){
    player_health -= this->damage;
    this->location = Point(0, 0);
    return player_health;
}

void Enemies::lose_speed(int bullet_damage, int slow_duration) {
    if(this->name != STUBBORN) {
        if (!is_glued)
            this->speed = this->speed - (this->speed * bullet_damage) / 100;
        is_glued = true;
        slowed_time_passed = slow_duration;
    }
}

std::string Enemies::get_name() {
    return this->name;
}
