#include "../header/Runner.h"
using namespace std;

Runner::Runner(Point _location, int _health, int _speed, int _reward, int _damage, const std::string &_picture)
        : Enemies(_location, _health, _speed, _reward, _damage, _picture) {

}

//void Runner::move(Window *map_window, vector<Point> path) {
//    map_window->draw_img(this->picture,
//                         Rectangle(this -> location - Point(20, 20), this -> location + Point(20, 20)));
//    find_next_move(path);
//}

//void Runner::find_next_move(const std::vector<Point>& path) {
//    cout << passed_path << " " << path.size() << endl;
//    if(passed_path > path.size()) {
//        cout << location << endl;
//        location = location;
//    }
//    else if(location.x == path[passed_path].x && location.y == path[passed_path].y)
//        passed_path += 1;
//    else if(location.x != path[passed_path].x)
//        location = location + Point(speed, 0);
//    else if(location.y != path[passed_path].y)
//        location = location + Point(0, speed);
//}
