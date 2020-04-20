#include "../header/MapExceptions.h"

using namespace std;

MapExceptions::MapExceptions(int _error_code) {
    error_code = _error_code;
}

void MapExceptions::handle_exception_sound(Window *window) {
    if(error_code == BUILD_TOWER_ERROR_CODE) {
        window->play_sound_effect(BUILD_TOWER_ERROR_SOUND);
        cout << "Build Error" << endl;
    }

    if(error_code == UPDATE_TOWER_ERROR_CODE) {
        window->play_sound_effect(UPDATE_TOWER_ERROR_SOUND);
        cout << "Update Error" << endl;
    }


    if(error_code == WRONG_KEY_PRESS_CODE) {
        window->play_sound_effect(WRONG_KEY_PRESS_SOUND);
        cout << "Wrong Key Error" << endl;
    }

    if(error_code == NO_KEY_PRESS_CODE) {
        window->play_sound_effect(NO_KEY_PRESS_SOUND);
        cout << "No Key Error" << endl;
    }

    if(error_code == TOWER_MAX_LEVEL_CODE) {
        window->play_sound_effect(TOWER_MAX_LEVEL_SOUND);
        cout << "Max Level Error" << endl;
    }

    if(error_code == LOCATION_FOR_TOWER_FULL_CODE){
        window->play_sound_effect(LOCATION_FOR_TOWER_FULL_SOUND);
        cout << "Location is full" << endl;
    }

    if(error_code == NO_GOLD_CODE){
        window->play_sound_effect(NO_GOLD_SOUND);
        cout << "No Gold" << endl;
    }
}

