#include "Map.cpp"

using namespace std;

int main(int argc, char const *argv[]) {

        Window win = Window(1365, 1024, "Map");
        Map my_map = Map(&win);

        while (my_map.process_event()) {
            my_map.render();
        }

    return 0;
}


