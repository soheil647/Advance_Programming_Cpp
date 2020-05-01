#include "../header/Tower.h"

using namespace std;

Tower::Tower(Point _position, const std::string &_tower_picture_file, int _cost, int _update_cost, int _bullet_damage,
             int _bullet_area,
             int _bullet_update_damage, int _bullet_speed,
             const std::string &_bullet_picture, int _fire_rate, const string &_name, int _slow_duration,
             int _slow_upgrade_duration) {

    name = _name;
    position = _position;
    bullet_position = _position;
    tower_picture_file = _tower_picture_file;
    cost = _cost;
    update_cost = _update_cost;
    bullet_damage = _bullet_damage;
    bullet_area = _bullet_area;
    bullet_update_damage = _bullet_update_damage;
    bullet_speed = _bullet_speed;
    bullet_picture = _bullet_picture;
    fire_rate = _fire_rate;
    level = 1;
    fire_time = 0;
    previous_target = nullptr;
    slow_duration = _slow_duration;
    slow_upgrade_duration = _slow_upgrade_duration;
    tower_picture = tower_picture_file + to_string(level);
    bullet_fired = false;
    bullet_speed = 2;
}

int Tower::update(int gold) {
    if (gold >= this->update_cost) {
        if (level != 3) {
            this->bullet_damage += bullet_update_damage;
            this->slow_duration += this->slow_upgrade_duration;
            this->cost = update_cost;
            level++;
            return gold - this->cost;
        } else throw MapExceptions(TOWER_MAX_LEVEL_CODE);
    } else throw MapExceptions(NO_GOLD_CODE);
}

Tower *Tower::build(int &gold, char pressed_key, Point mouse_clicked_location) {
    auto *new_tower = new Tower(mouse_clicked_location, GATTLING_PARAMETER, SLOW_PARAMETER);
    if (pressed_key == BUILD_GATTLING_KEY)
        new_tower = new Tower(mouse_clicked_location, GATTLING_PARAMETER, SLOW_PARAMETER);
    else if (pressed_key == BUILD_MISSILE_KEY)
        new_tower = new Tower(mouse_clicked_location, MISSILE_PARAMETER, SLOW_PARAMETER);
    else if (pressed_key == BUILD_TESLA_KEY)
        new_tower = new Tower(mouse_clicked_location, TESLA_PARAMETER, SLOW_PARAMETER);
    else if (pressed_key == BUILD_GLUE_KEY)
        new_tower = new Tower(mouse_clicked_location, GLUE_PARAMETER, GLUE_SLOW_PARAMETER);
    else throw MapExceptions(BUILD_TOWER_ERROR_CODE);
    if (gold < new_tower->cost) throw MapExceptions(NO_GOLD_CODE);
    gold -= new_tower->cost;
    return new_tower;
}

void Tower::draw(Window *map_window) {
    map_window->draw_img(this->tower_picture,
                         Rectangle(this->position - TOWER_SIZE / 2, this->position + TOWER_SIZE / 2));
}

void Tower::fire(const vector<Enemies *> &enemies, Window *map_window) {
    fire_time++;
    if (fire_time == fire_rate / RENDER_TIME) {
        fire_time = 0;
        Enemies *target_enemie = find_enemie_in_range(enemies);
        if (target_enemie != nullptr) {
            play_fire_sound(map_window);
            if (this->bullet_area != 0) {
                vector<Enemies *> targeted_enemies = this->find_enemies_in_area(target_enemie->get_location(), enemies);
                if (slow_duration != 0)
                    do_area_slow(targeted_enemies);
                else
                    do_area_damage(targeted_enemies);
            } else if (!(target_enemie->get_name() == STUBBORN && this->name == GATLING)) {
                target_enemie->lose_health(this->bullet_damage);
                map_window->draw_img(this->bullet_picture,
                                     Rectangle(target_enemie->get_location() - Point(20, 20), 30, 30));
            }
            this->bullet_fired = true;
        }
    }
    fire_bullet(map_window);
    if (fire_time <= 2 * RENDER_TIME && find_enemie_in_range(enemies) != nullptr)
        this->tower_picture = this->tower_picture_file + FIRE + to_string(level) + ".png";
    else
        this->tower_picture = this->tower_picture_file + to_string(level) + ".png";
    this->draw(map_window);
}

vector<Enemies *> Tower::find_enemies_in_area(Point enemie_location, const std::vector<Enemies *> &enemies) {
    vector<Enemies *> enemies_in_area;
    for (int i = -this->bullet_area / 2; i < this->bullet_area / 2; i++) {
        for (int j = -this->bullet_area / 2; j < this->bullet_area / 2; j++) {
            for (auto enemie : enemies) {
                if ((enemie->get_location().x == enemie_location.x + i &&
                     enemie->get_location().y == enemie_location.y + j)) {
                    enemies_in_area.push_back(enemie);
                }
            }
        }
    }
    return enemies_in_area;
}

Enemies *Tower::find_enemie_in_range(const vector<Enemies *> &enemies) {
    if (this->previous_target != nullptr && previous_target_in_range())
        return previous_target;
    for (int i = -TOWER_RANGE / 2; i < TOWER_RANGE / 2; i++) {
        for (int j = -TOWER_RANGE / 2; j < TOWER_RANGE / 2; j++) {
            for (auto enemie : enemies) {
                if ((enemie->get_location().x == this->position.x + i &&
                     enemie->get_location().y == this->position.y + j)) {
                    previous_target = enemie;
                    return enemie;
                }
            }
        }
    }
    return nullptr;
}

Point Tower::get_position() {
    return this->position;
}

bool Tower::previous_target_in_range() {
    for (int i = -TOWER_RANGE / 2; i < TOWER_RANGE / 2; i++) {
        for (int j = -TOWER_RANGE / 2; j < TOWER_RANGE / 2; j++) {
            if ((this->previous_target->get_location().x == this->position.x + i &&
                 this->previous_target->get_location().y == this->position.y + j)) {
                return true;
            }
        }
    }
    return false;
}

void Tower::do_area_damage(const vector<Enemies *> &target_enemies) {
    for (auto enemie : target_enemies) {
        enemie->lose_health(this->bullet_damage);
    }
}


void Tower::do_area_slow(const vector<Enemies *> &target_enemies) {
    for (auto enemie : target_enemies) {
        enemie->lose_speed(this->bullet_damage, this->slow_duration);
    }
}

void Tower::play_fire_sound(Window *map_window) {
    if (this->name == GATLING)
        map_window->play_sound_effect(GATLING_FIRE_SOUND);
    if (this->name == MISSILE)
        map_window->play_sound_effect(MISSILE_FIRE_SOUND);
    if (this->name == TESLA)
        map_window->play_sound_effect(TESLA_FIRE_SOUND);
    if (this->name == GLUE)
        map_window->play_sound_effect(GLUE_FIRE_SOUND);
}

void Tower::fire_bullet(Window *map_window) {
    if (bullet_fired) {
        Point previous_target_position = previous_target->get_location();
        if (bullet_position.x == previous_target_position.x && bullet_position.y == previous_target_position.y) {
            bullet_fired = false;
            bullet_position = this->position;
        }
        if((previous_target_position.x != 0 && previous_target_position.x != 1) || (previous_target_position.y != 0 && previous_target_position.y != 1)) {
            if (bullet_position.y < previous_target_position.y)
                bullet_position.y += bullet_speed;
            else if (bullet_position.y > previous_target_position.y)
                bullet_position.y -= bullet_speed;
            if (bullet_position.x < previous_target_position.x)
                bullet_position.x += bullet_speed;
            else if (bullet_position.x > previous_target_position.x)
                bullet_position.x -= bullet_speed;
            map_window->draw_img(this->bullet_picture,
                                 Rectangle(bullet_position - Point(20, 20), 30, 30));
        }
    }
}