#ifndef SMART_HOTEL_RESERVATION_RATINGWEIGHTS_HPP
#define SMART_HOTEL_RESERVATION_RATINGWEIGHTS_HPP


#include <string>
#include <iostream>
#include <iomanip>

class RatingWeights {
private:
    std::string status;
    float location_weight{};
    float cleanliness_weight{};
    float staff_weight{};
    float facilities_weight{};
    float value_for_money_weight{};
public:
    RatingWeights(const std::string& _status, float _location_weight, float _cleanliness_weight, float _staff_weight,
                  float _facilities_weight, float _value_for_money_weight);
    RatingWeights(const std::string& _status);

    void show_weights();

    bool check_status();

    float find_personal_rating_for_hotel(float location_rating, float cleanliness_rating, float staff_rating,
                                         float facilities_rating, float value_for_money_rating);
};


#endif //SMART_HOTEL_RESERVATION_RATINGWEIGHTS_HPP
