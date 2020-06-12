#ifndef HOTEL_RESERVATION_CITYFILTER_HPP
#define HOTEL_RESERVATION_CITYFILTER_HPP

#include "hotel.hpp"
#include "filter.hpp"

class CityFilter : public Filter{
private:
    std::string city_name;
public:
    CityFilter(const std::string& _city_name, const std::string& filter_name = "city");
    std::vector<Hotel*> apply(const std::vector<Hotel*>& hotels_list);

};


#endif //HOTEL_RESERVATION_CITYFILTER_HPP
