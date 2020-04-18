#include "Map.cpp"

using namespace std;

int main(int argc, char const *argv[]) {

        Window win = Window(1365, 1024, "Map");
        vector<Tower *> towers;
        vector<Enemies *> enemies;
        Map my_map = Map(towers, enemies, &win);

        auto start_time = std::chrono::system_clock::now();
        while (my_map.process_event(start_time)) {
            my_map.render();
        }

    return 0;
}


