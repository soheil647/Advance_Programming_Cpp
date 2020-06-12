#include "../header/starFilter.hpp"
using namespace std;

StarFilter::StarFilter(int _min_star, int _max_star, const std::string &filter_name) :Filter(filter_name){
    min_star = _min_star;
    max_star = _max_star;
}

vector<Hotel *> StarFilter::apply(const vector<Hotel *> &hotels_list) {
    vector<Hotel *> new_hotels_list;
    for(auto hotel : hotels_list){
        if(hotel->check_star(min_star, max_star))
            new_hotels_list.push_back(hotel);
    }
    return new_hotels_list;
}
