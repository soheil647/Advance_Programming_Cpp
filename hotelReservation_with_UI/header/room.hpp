#ifndef HOTEL_RESERVATION_ROOM_HPP
#define HOTEL_RESERVATION_ROOM_HPP

#include <string>
#include <iostream>

class Room {
private:
    int price;
    int check_in;
    int check_out;
    std::string id;
    bool reserved;
    std::string type;
public:
    Room(const std::string &_id, int _price, const std::string& _type);
    bool reserve_room(int time_in, int time_out);
    std::string get_id();
    int get_price();
    void reset_room_reservation();

    void print_information(int size);

    bool check_availability(int check_in_time, int check_out_time);
};


#endif //HOTEL_RESERVATION_ROOM_HPP
