#include "../header/cityFilter.hpp"

using namespace std;

vector<Hotel *> CityFilter::apply(const vector<Hotel *>& hotels_list) {
    vector<Hotel *> new_list_hotels;
    for(auto hotel : hotels_list){
        if(hotel->check_city_name(city_name))
            new_list_hotels.push_back(hotel);
    }
    return new_list_hotels;
}

CityFilter::CityFilter(const string& _city_name, const string& filter_name) : Filter(filter_name) {
    city_name = _city_name;
}
