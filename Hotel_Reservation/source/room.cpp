#include "../header/room.hpp"

Room::Room(const std::string& _id, int _price) {
    id = _id;
    price = _price;
    check_in = 0;
    check_out = 0;
    reserved = false;
}

bool Room::reserve_room(int time_in, int time_out) {
    if(time_in > time_out || check_in < time_in < check_out || check_in < time_out < check_out || reserved)
        return false;
    check_in = time_in;
    check_out = time_out;
    reserved = true;
    return true;
}

std::string Room::get_id() {
    return id;
}

void Room::reset_room_reservation() {
    this->check_in = 0;
    this->check_out = 0;
    this->reserved = false;
}
