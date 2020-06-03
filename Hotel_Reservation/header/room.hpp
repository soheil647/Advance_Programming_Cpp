#ifndef HOTEL_RESERVATION_ROOM_HPP
#define HOTEL_RESERVATION_ROOM_HPP

#include <string>

class Room {
private:
    int price;
    int check_in;
    int check_out;
    std::string id;
    bool reserved;
public:
    Room(const std::string &_id, int _price);
    bool reserve_room(int time_in, int time_out);
    std::string get_id();
    void reset_room_reservation();
};


#endif //HOTEL_RESERVATION_ROOM_HPP
