#include "../header/costFilter.hpp"
using namespace std;

CostFilter::CostFilter(float _min_price, float _max_price, const string &filter_name) : Filter(filter_name){
    min_price = _min_price;
    max_price = _max_price;
}

vector<Hotel *> CostFilter::apply(const vector<Hotel *> &hotels_list) {
    vector<Hotel *> new_hotels_list;
    for(auto hotel : hotels_list){
        if(hotel->check_average_price(min_price, max_price))
            new_hotels_list.push_back(hotel);
    }
    return new_hotels_list;
}
