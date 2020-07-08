#ifndef HOTEL_RESERVATION_STARFILTER_HPP
#define HOTEL_RESERVATION_STARFILTER_HPP

#include "hotel.hpp"
#include "filter.hpp"

class StarFilter : public Filter{
private:
    int min_star;
    int max_star;
public:
    StarFilter(int _min_star, int _max_star, const std::string& filter_name="star");
    virtual std::vector<Hotel*> apply(const std::vector<Hotel*>& hotels_list);

};


#endif //HOTEL_RESERVATION_STARFILTER_HPP
