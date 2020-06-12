#ifndef HOTEL_RESERVATION_USERRESERVATION_HPP
#define HOTEL_RESERVATION_USERRESERVATION_HPP

#include <string>
#include <iostream>
#include <vector>
#include "room.hpp"

class userReservation {
private:
    int id;
    std::string hotel_id;
    float cost;
    std::vector<Room*> reserved_rooms;
public:
    userReservation(int _id, const std::string& _hotel_id, const std::vector<Room*>& _reserved_rooms);
    void print_reserve();
    int get_id();
    std::string get_hotel();
    float get_cost();
    std::vector<Room*> get_reserve_rooms();
    void burn_reservation();

};


#endif //HOTEL_RESERVATION_USERRESERVATION_HPP
