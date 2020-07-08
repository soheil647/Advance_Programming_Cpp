#include "../header/userReservation.hpp"
using namespace std;

userReservation::userReservation(int _id, const std::string& _hotel_id, const std::vector<Room*>& _reserved_rooms) {
    id = _id;
    hotel_id = _hotel_id;
    reserved_rooms = _reserved_rooms;
    cost = float(reserved_rooms.size() * reserved_rooms[0]->get_price());
}

void userReservation::print_reserve(){
    cout << "id: " << id << " ";
    cout << "hotel: " << hotel_id << " ";
    reserved_rooms[0]->print_information(reserved_rooms.size());
}

int userReservation::get_id() { return this->id;}

void userReservation::burn_reservation() {
    this->id = -1;
}

std::string userReservation::get_hotel() { return hotel_id;}

float userReservation::get_cost() { return cost;}

std::vector<Room *> userReservation::get_reserve_rooms() { return reserved_rooms;}

