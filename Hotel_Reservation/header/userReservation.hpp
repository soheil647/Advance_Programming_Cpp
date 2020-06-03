#ifndef HOTEL_RESERVATION_USERRESERVATION_HPP
#define HOTEL_RESERVATION_USERRESERVATION_HPP

#include <string>
#include <iostream>

class userReservation {
private:
    int id;
    std::string hotel_id;
    std::string room_type;
    int quantity;
    int cost;
    int check_in;
    int check_out;
public:
    userReservation(int _id, const std::string& _hotel_id, const std::string& _room_type, int _quantity, int _cost, int _check_in, int _check_out);

    void print_reserve();

    int get_id();
    int get_cost();
    std::string get_hotel();

    void burn_reservation();
};


#endif //HOTEL_RESERVATION_USERRESERVATION_HPP
