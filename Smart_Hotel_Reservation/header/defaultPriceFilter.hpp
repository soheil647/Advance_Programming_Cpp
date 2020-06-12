#ifndef SMART_HOTEL_RESERVATION_DEFAULTPRICEFILTER_HPP
#define SMART_HOTEL_RESERVATION_DEFAULTPRICEFILTER_HPP

#include "filter.hpp"
#include <math.h>
#include "userReservation.hpp"

class DefaultPriceFilter : public Filter{
private:
    std::vector<userReservation*> reservations;
    static float find_mean(const std::vector<int> &prices);
    static float find_variance(const std::vector<int> &prices);

public:
    DefaultPriceFilter(const std::vector<userReservation*>& _reservation, const std::string& filter_name = "default");
    virtual std::vector<Hotel*> apply(const std::vector<Hotel*>& hotels_list);

};


#endif //SMART_HOTEL_RESERVATION_DEFAULTPRICEFILTER_HPP
