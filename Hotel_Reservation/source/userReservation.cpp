#include "../header/userReservation.hpp"
using namespace std;

userReservation::userReservation(int _id, const std::string& _hotel_id, const std::string& _room_type, int _quantity, int price,
                                 int _check_in, int _check_out) {
    id = _id;
    hotel_id = _hotel_id;
    room_type = _room_type;
    quantity = _quantity;
    cost = price * _quantity;
    check_in = _check_in;
    check_out = _check_out;
}

void userReservation::print_reserve(){
    cout << "id: " << id << " ";
    cout << "hotel: " << hotel_id << " ";
    cout << "room: " << room_type << " ";
    cout << "quantity: " << quantity << " ";
    cout << "cost: " << cost << " ";
    cout << "check_in: " << check_in << " ";
    cout << "check_out: " << check_out << endl;
}

int userReservation::get_id() { return this->id;}

int userReservation::get_cost() { return cost;}

void userReservation::burn_reservation() {
    this->id = -1;
}

std::string userReservation::get_hotel() { return hotel_id;}

