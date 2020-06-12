#include "../header/ratings.hpp"
using namespace std;

Ratings::Ratings(const std::string& _unique_id, float _location_rating, float _cleanliness_rating, float _staff_rating,
                 float _facilities_rating, float _value_for_money_rating, float _overall_rating) {
    unique_id = _unique_id;
    location_rating = _location_rating;
    cleanliness_rating = _cleanliness_rating;
    staff_rating = _staff_rating;
    facilities_rating = _facilities_rating;
    value_for_money_rating = _value_for_money_rating;
    overall_rating = _overall_rating;
}

void Ratings::show_rating() {
    cout << setprecision(2) << fixed;
    cout << "location: " << location_rating << endl;
    cout << "cleanliness: " << cleanliness_rating << endl;
    cout << "staff: " << staff_rating << endl;
    cout << "facilities: " << facilities_rating << endl;
    cout << "value_for_money: " <<  value_for_money_rating << endl;
    cout << "overal_rating: " <<  overall_rating << endl;
}

Ratings::Ratings(const std::string& hotel_id, float _overall_Rating) {
    unique_id = hotel_id;
    overall_rating = _overall_Rating;
}

std::string Ratings::get_hotel_id() { return unique_id; }
float Ratings::get_overall_rate(){ return overall_rating; }

float Ratings::find_weighted_rate(RatingWeights *weights) {
    return weights->find_personal_rating_for_hotel(location_rating, cleanliness_rating, staff_rating, facilities_rating, value_for_money_rating);
}
