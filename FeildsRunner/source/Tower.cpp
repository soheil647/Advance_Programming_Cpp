#include "../header/Tower.h"
#include "../header/Enemies.h"

using namespace std;

Tower::Tower(Point _position, const std::string &_tower_picture_level1, const std::string &_tower_picture_level2,
             const std::string &_tower_picture_level3, int _cost, int _update_cost, int _bullet_damage,int _bullet_area,
             int _bullet_update_damage, int _bullet_speed,
             const std::string &_bullet_picture, int _fire_rate) {

    position = _position;
    tower_picture_level2 = _tower_picture_level2;
    tower_picture_level3 = _tower_picture_level3;
    tower_picture = _tower_picture_level1;
    cost = _cost;
    update_cost = _update_cost;
    bullet_damage = _bullet_damage;
    bullet_area = _bullet_area;
    bullet_update_damage = _bullet_update_damage;
    bullet_speed = _bullet_speed;
    bullet_picture = _bullet_picture;
    fire_rate = _fire_rate;
    level = 1;
    fire_time = 0 ;
}

int Tower::update(int gold) {
    if(gold >= this->update_cost) {
        if (level != 3) {
            if (level == 1)
                this->tower_picture = tower_picture_level2;
            if (level == 2)
                this->tower_picture = tower_picture_level3;

            this->bullet_damage += bullet_update_damage;
            this->cost = update_cost;
            level++;
            return gold - this->cost;
        } else throw MapExceptions(TOWER_MAX_LEVEL_CODE);
    } else throw MapExceptions(NO_GOLD_CODE);
}

Tower *Tower::build(int &gold, char pressed_key, Point mouse_clicked_location) {
    auto *new_tower = new Tower(mouse_clicked_location, GATTLING_PARAMETER);
    if (pressed_key == BUILD_GATTLING_KEY)
        new_tower = new Tower(mouse_clicked_location, GATTLING_PARAMETER);
    else if (pressed_key == BUILD_MISSILE_KEY)
        new_tower = new Tower(mouse_clicked_location, MISSILE_PARAMETER);
    else if (pressed_key == BUILD_TESLA_KEY)
        new_tower = new Tower(mouse_clicked_location, TESLA_PARAMETER);
    else if (pressed_key == BUILD_GLUE_KEY)
        new_tower = new Tower(mouse_clicked_location, GLUE_PARAMETER);
    else throw MapExceptions(BUILD_TOWER_ERROR_CODE);
    if(gold < new_tower->cost ) throw MapExceptions(NO_GOLD_CODE);
    gold -= new_tower->cost;
    return new_tower;
}

void Tower::draw(Window *map_window) {
    map_window->draw_img(this->tower_picture,
                         Rectangle(this->position - TOWER_SIZE / 2, this->position + TOWER_SIZE / 2));
}

void Tower::fire(const vector<Enemies *> &enemies, Window* map_window, int passed_time) {
    fire_time++;
    if (fire_time == fire_rate/RENDER_TIME) {
        fire_time = 0;
        Enemies *target_enemie = find_enemie_in_range(enemies);
        if (target_enemie != nullptr) {
            if (this->bullet_area != 0) {
                for (auto enemie : this->find_enemies_in_area(this->position)) {
                    cout << enemie->get_location().x;
                    enemie->lose_health(this->bullet_damage);
                    map_window->draw_img(this->bullet_picture, Rectangle(target_enemie->get_location()-Point(20,20), 30, 30));
                }
            } else{
                target_enemie->lose_health(this->bullet_damage);
                map_window->draw_img(this->bullet_picture, Rectangle(target_enemie->get_location()-Point(20,20), 30, 30));
            }
        }
    }
}
vector<Enemies*> Tower::find_enemies_in_area(Point location){
    vector<Enemies*> enemies;
    for (int i = 0; i < this->bullet_area; i++) {
        for (int j = 0; j < this->bullet_area; j++) {
            for (auto enemie : enemies) {
                if ((enemie->get_location().x == location.x + i &&
                     enemie->get_location().y == location.y + j) ||
                    (enemie->get_location().x == location.x + i &&
                     enemie->get_location().y == location.y - j) ||
                    (enemie->get_location().x == location.x - i &&
                     enemie->get_location().y == location.y + j) ||
                    (enemie->get_location().x == location.x - i &&
                     enemie->get_location().y == location.y - j))
                    enemies.push_back(enemie);
            }
        }
    }
    return enemies;
}

Enemies *Tower::find_enemie_in_range(const vector<Enemies *> &enemies) {
    for (int i = 0; i < TOWER_RANGE; i++) {
        for (int j = 0; j < TOWER_RANGE; j++) {
            for (auto enemie : enemies) {
                if ((enemie->get_location().x == this->position.x + i &&
                    enemie->get_location().y == this->position.y + j) ||
                    (enemie->get_location().x == this->position.x + i &&
                    enemie->get_location().y == this->position.y - j) ||
                    (enemie->get_location().x == this->position.x - i &&
                    enemie->get_location().y == this->position.y + j) ||
                    (enemie->get_location().x == this->position.x - i &&
                    enemie->get_location().y == this->position.y - j))
                    return enemie;
            }
        }
    }
    return nullptr;
}

Point Tower::get_position() {
    return this->position;
}
