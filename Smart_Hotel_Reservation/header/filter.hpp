#ifndef HOTEL_RESERVATION_FILTER_HPP
#define HOTEL_RESERVATION_FILTER_HPP

#include "hotel.hpp"

class Filter {
private:
    std::string name;

public:
    Filter(const std::string& _name);
    virtual std::vector<Hotel*> apply(const std::vector<Hotel*>& hotels_list) = 0;
    std::string get_name();
};


#endif //HOTEL_RESERVATION_FILTER_HPP
