#ifndef HOTEL_RESERVATION_COSTFILTER_HPP
#define HOTEL_RESERVATION_COSTFILTER_HPP

#include "hotel.hpp"
#include "filter.hpp"

class CostFilter : public Filter{
private:
    float min_price;
    float max_price;
public:
    CostFilter(float _min_price, float _max_price, const std::string& filter_name="cost");
    virtual std::vector<Hotel*> apply(const std::vector<Hotel*>& hotels_list);

};


#endif //HOTEL_RESERVATION_COSTFILTER_HPP
