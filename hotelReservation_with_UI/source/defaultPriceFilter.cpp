#include "../header/defaultPriceFilter.hpp"

using namespace std;

DefaultPriceFilter::DefaultPriceFilter(const std::vector<userReservation *> &_reservation, const string &filter_name)
    :Filter(filter_name){
            reservations = _reservation;
    }

vector<Hotel *> DefaultPriceFilter::apply(const vector<Hotel *> &hotels_list) {
    vector<vector<Room*>> all_rooms;
    for(auto reserve : reservations){
        all_rooms.push_back(reserve->get_reserve_rooms());
    }
    vector<int> prices;
    for(const auto& user_reserves : all_rooms){
        for(auto room : user_reserves){
            prices.push_back(room->get_price());
        }
    }
    float mean = find_mean(prices);
    float variance = find_variance(prices);

    vector<Hotel *> new_hotels_list;
    for(auto hotel : hotels_list){
        if(hotel->check_default_price(mean, variance))
            new_hotels_list.push_back(hotel);
    }
    return new_hotels_list;
}

float DefaultPriceFilter::find_mean(const vector<int>& prices){
    int sum = 0;
    for(auto price : prices){
        sum += price;
    }
    return float(float(sum)/prices.size());
}

float DefaultPriceFilter::find_variance(const vector<int>& prices){
    float mean = find_mean(prices);
    float mse = 0;
    for(auto price : prices){
        mse += pow(price - mean, 2);
    }
    return sqrt(mse/float((prices.size()-1)));
}
