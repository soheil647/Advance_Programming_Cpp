#ifndef HOTEL_RESERVATION_ROOMFILTER_HPP
#define HOTEL_RESERVATION_ROOMFILTER_HPP

#include "hotel.hpp"
#include "filter.hpp"

class RoomFilter : public Filter{
private:
    std::string room_type;
    int quantity;
    int check_in;
    int check_out;
public:
    RoomFilter(const std::string& _room_type, int _quantity, int _check_in, int _check_out, const std::string& filter_name="room");
    virtual std::vector<Hotel*> apply(const std::vector<Hotel*>& hotels_list);

};


#endif //HOTEL_RESERVATION_ROOMFILTER_HPP
