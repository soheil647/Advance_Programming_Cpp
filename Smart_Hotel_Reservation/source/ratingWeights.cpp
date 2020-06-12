#include "../header/ratingWeights.hpp"

using namespace std;

RatingWeights::RatingWeights(const std::string &_status, float _location_weight, float _cleanliness_weight,
                             float _staff_weight,
                             float _facilities_weight, float _value_for_money_weight) {
    status = _status;
    location_weight = _location_weight;
    cleanliness_weight = _cleanliness_weight;
    staff_weight = _staff_weight;
    facilities_weight = _facilities_weight;
    value_for_money_weight = _value_for_money_weight;

}

RatingWeights::RatingWeights(const std::string &_status) {
    status = _status;
}

void RatingWeights::show_weights() {
    if (status == "false")
        cout << "active " << status << endl;
    else {
        cout << setprecision(2) << fixed;
        cout << "active " << status << " ";
        cout << "location " << location_weight << " ";
        cout << "cleanliness " << cleanliness_weight << " ";
        cout << "staff " << staff_weight << " ";
        cout << "facilities " << facilities_weight << " ";
        cout << "value_for_money " << value_for_money_weight << endl;
    }
}

bool RatingWeights::check_status() { return status == "true"; }

float RatingWeights::find_personal_rating_for_hotel(float location_rating, float cleanliness_rating, float staff_rating,
                                                    float facilities_rating, float value_for_money_rating) {
    float sum = 0;
    float sum_of_weights = 0;
    sum += location_rating * location_weight;
    sum += cleanliness_rating * cleanliness_weight;
    sum += staff_rating * staff_weight;
    sum += facilities_rating * facilities_weight;
    sum += value_for_money_rating * value_for_money_weight;
    sum_of_weights = location_weight + cleanliness_weight + staff_weight + facilities_weight + value_for_money_weight;

    return sum/sum_of_weights;
}
