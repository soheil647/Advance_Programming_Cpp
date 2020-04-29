#ifndef FEILDSRUNNER_MAPEXCEPTIONS_H
#define FEILDSRUNNER_MAPEXCEPTIONS_H


#include <exception>
#include <string>
#include "rsdl.hpp"

#define BUILD_TOWER_ERROR_SOUND "./Assets/song/error1.wav"
#define BUILD_TOWER_ERROR_CODE 1

#define UPDATE_TOWER_ERROR_SOUND "./Assets/song/error1.wav"
#define UPDATE_TOWER_ERROR_CODE 2

#define NO_KEY_PRESS_SOUND "./Assets/song/error2.wav"
#define NO_KEY_PRESS_CODE 3

#define WRONG_KEY_PRESS_SOUND "./Assets/song/error2.wav"
#define WRONG_KEY_PRESS_CODE 4

#define TOWER_MAX_LEVEL_SOUND "./Assets/song/error1.wav"
#define TOWER_MAX_LEVEL_CODE 5

#define LOCATION_FOR_TOWER_FULL_SOUND "./Assets/song/error1.wav"
#define LOCATION_FOR_TOWER_FULL_CODE 6

#define NO_GOLD_SOUND "./Assets/song/error2.wav"
#define NO_GOLD_CODE 7

class MapExceptions : public std::exception {
private:
    int error_code;
    std::string error_text;

public:
    MapExceptions(int _error_code);
    void handle_exception_sound(Window* window);

};


#endif //FEILDSRUNNER_MAPEXCEPTIONS_H
