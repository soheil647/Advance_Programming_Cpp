#ifndef SMART_HOTEL_RESERVATION_RATINGS_HPP
#define SMART_HOTEL_RESERVATION_RATINGS_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "ratingWeights.hpp"

class Ratings {
private:
    std::string unique_id;
    float location_rating{};
    float cleanliness_rating{};
    float staff_rating{};
    float facilities_rating{};
    float value_for_money_rating{};
    float overall_rating;
public:
    Ratings(const std::string& unique_id, float _location_rating, float _cleanliness_rating, float _staff_rating, float _facilities_rating,
            float _value_for_money_rating, float _overall_rating);
    Ratings(const std::string& hotel_id, float overall_Rating);

    void show_rating();
    std::string get_hotel_id();
    float get_overall_rate();

    float find_weighted_rate(RatingWeights *weights);
    double find_weighted_overall(const std::vector<double >& weights);
};


#endif //SMART_HOTEL_RESERVATION_RATINGS_HPP
