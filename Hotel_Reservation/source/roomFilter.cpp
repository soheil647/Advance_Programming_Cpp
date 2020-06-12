#include "../header/roomFilter.hpp"
using namespace std;

RoomFilter::RoomFilter(const std::string &_room_type, int _quantity, int _check_in, int _check_out,
                       const std::string &filter_name) : Filter(filter_name){
    room_type = _room_type;
    quantity = _quantity;
    check_in = _check_in;
    check_out = _check_out;
}

vector<Hotel *> RoomFilter::apply(const vector<Hotel *> &hotels_list) {
    vector<Hotel *> new_hotels_list;
    for(auto hotel : hotels_list){
        if(hotel->check_available_room(room_type, quantity, check_in, check_out))
            new_hotels_list.push_back(hotel);
    }
    return new_hotels_list;
}
