#include "../header/room.hpp"

using namespace std;

Room::Room(const std::string& _id, int _price, const std::string& _type) {
    id = _id;
    price = _price;
    check_in = 0;
    check_out = 0;
    reserved = false;
    type = _type;
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

int Room::get_price() { return this->price;}

void Room::print_information(int size){
    cout << "room: " << this->type << " ";
    cout << "quantity: " << size << " ";
    cout << "cost: " << size * this->price << " ";
    cout << "check_in " << this->check_in << " ";
    cout << "check_out " << this->check_out << endl;
}

bool Room::check_availability(int check_in_time, int check_out_time) {
    return !(this->check_in < check_in_time < this->check_out && this->check_in < check_out_time < this->check_out);
}
