#include <algorithm>
#include "../header/user.hpp"
#include "../header/hotelExceptions.hpp"

using namespace std;

User::User(const std::string &_email, const std::string &_username, const std::string &_password) {
    email = _email;
    username = _username;
    password = _password;
    hashed_password = hash_password(password);
    wallet = 0;
    wallet_history.push_back(wallet);
    reserve_id = 1;
    default_filter = true;
    sort_function = [](Hotel *lhs, Hotel *rhs) { return lhs->get_id() < rhs->get_id(); };
    rating_weights = new RatingWeights("false");
    estimated_weights = nullptr;
}


int User::hash_password(const string &Combine) {
    unsigned int hash = 0;

    const unsigned int VALUE = Combine.length();
    for (auto Letter : Combine)
    {
        srand(VALUE*Letter);
        hash += 33 + rand() % 92;
    }
    return hash;
}

bool User::operator==(const User &user) {
    return user.email == this->email || user.username == this->username;
}

User::User(const User &new_user) {
    email = new_user.email;
    username = new_user.username;
    password = new_user.password;
    wallet = 0;
    reserves = new_user.reserves;
    reserve_id = new_user.reserve_id;
    wallet_history.push_back(0);
    default_filter = new_user.default_filter;
    sort_function = new_user.sort_function;
    rating_weights = new_user.rating_weights;
    estimated_weights = new_user.estimated_weights;
}

bool User::compare_login(const std::string &_email, const std::string &_password) {
    return this->email == _email && this->password == _password;
}

void User::charging_wallet(float amount) {
    this->wallet += amount;
    this->wallet_history.push_back(this->wallet);
}

void User::decreasing_wallet(float amount) {
    this->wallet -= amount;
    this->wallet_history.push_back(this->wallet);
}

void User::show_wallet_history(int count) {
    unsigned int history_count = (count > this->wallet_history.size()) ? this->wallet_history.size() : count;
    cout << setprecision(0) << fixed;
    std::cout << this->wallet << std::endl;
    reverse(this->wallet_history.begin(), this->wallet_history.end());
    for (unsigned int i = 1; i < history_count; i++)
        std::cout << this->wallet_history[i] << std::endl;
    reverse(this->wallet_history.begin(), this->wallet_history.end());
}

void User::reserve_rooms(const std::string &_hotel_id, const vector<Room *>& reserved_rooms) {
    reserves.push_back(new userReservation(reserve_id, _hotel_id, reserved_rooms));
    if(check_default_filter_status())
        filters.push_back(new DefaultPriceFilter(reserves));
    reserve_id += 1;
}
bool User::check_default_filter_status(){
    int reserve_count = 0;
    for(userReservation* reserve : reserves){
        if(reserve->get_id() > 0)
            reserve_count += 1;
    }
    for(auto filter : filters){
        if(filter->get_name() == ROOM_FILTER)
            return false;
    }
    return reserve_count >= 10 && default_filter;
}

void User::show_reserves(){
    if(reserves.empty())
        throw Hotel_Exceptions(EMPTY);
    reverse(this->reserves.begin(), this->reserves.end());
    for(userReservation* reserve : reserves){
        if(reserve->get_id() > 0)
            reserve->print_reserve();
    }
    reverse(this->reserves.begin(), this->reserves.end());
}
userReservation* User::delete_reserve(int id) {
    userReservation* reserve = find_reserve_by_id(id);
    this->wallet += float(reserve->get_cost()) / 2;
    this->wallet_history.push_back(this->wallet);
    reserve->burn_reservation();
    return reserve;
}

userReservation* User::find_reserve_by_id(int id){
    for(auto reserve : reserves)
        if(reserve->get_id() == id)
            return reserve;
    throw Hotel_Exceptions(NOT_FOUND);
}

string User::get_username() { return this->username; }

float User::get_wallet() { return this->wallet; }

void User::add_city_filter(std::vector<std::string> args) {
        string city_name;
        for(int i = 0; i < args.size(); i += 2) {
            if (args[i] == "city")
                city_name = args[i + 1];
            else
                throw Hotel_Exceptions(BAD_REQUEST);
        }
        filters.push_back(new CityFilter(city_name));
}

void User::add_star_filter(std::vector<std::string> args) {
    int min_star = 0, max_star = 0;
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "min_star")
            min_star = stoi(args[i + 1]);
        else if (args[i] == "max_star")
            max_star = stoi(args[i + 1]);
        else
            throw Hotel_Exceptions(BAD_REQUEST);

    }
    check_star_filter(min_star, max_star);
    for(int i = 0; i < filters.size(); i++)
        if (filters[i]->get_name() == "star")
            filters.erase(filters.begin() + i);
    filters.push_back(new StarFilter(min_star, max_star));
}

void User::check_star_filter(int min_star, int max_star){
    if((min_star < 1 || min_star > 5) || (max_star < 1 || max_star > 5))
        throw Hotel_Exceptions(BAD_REQUEST);
    if(min_star > max_star)
        throw Hotel_Exceptions(BAD_REQUEST);
}

void User::add_cost_filter(const std::vector<std::string>& args) {
    float min_price = 0, max_price = 0;
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "min_price")
            min_price = stof(args[i + 1]);
        else if (args[i] == "max_price")
            max_price = stof(args[i + 1]);
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    check_cost_filter(min_price, max_price);
    filters.push_back(new CostFilter(min_price, max_price));
}


void User::check_cost_filter(float min_price, float max_price){
    if(min_price < 0 || max_price < 0)
        throw Hotel_Exceptions(BAD_REQUEST);
    if(min_price > max_price)
        throw Hotel_Exceptions(BAD_REQUEST);
}

void User::add_room_filter(const std::vector<std::string>& args) {
    int quantity = 0, check_in = 0, check_out = 0;
    string room_type;
    for(int i = 0; i < args.size(); i += 2) {
        if (args[i] == "quantity")
            quantity = stoi(args[i + 1]);
        else if (args[i] == "check_in")
            check_in = stoi(args[i + 1]);
        else if (args[i] == "check_out")
            check_out = stoi(args[i + 1]);
        else if (args[i] == "type")
            room_type = args[i + 1];
        else
            throw Hotel_Exceptions(BAD_REQUEST);
    }
    filters.push_back(new RoomFilter(room_type, quantity, check_in, check_out));
}

void User::delete_filters() {
    filters.clear();
}

std::vector<Filter *> User::get_filters() { return filters;}

void User::status_default_filter_price(const std::string& status) {
    if(status == "true")
        default_filter = true;
    else if(status == "false")
        default_filter = false;
    else
        throw Hotel_Exceptions(BAD_REQUEST);
}

void User::save_sort_order(const std::string& sort_property, const std::string& order) {
    switch(resolve_sort_property(sort_property)) {
        case id:
            return sort_by_id(order);
        case name:
            return sort_by_name(order);
        case star_rating:
            return sort_by_star_rating(order);
        case city:
            return sort_by_city(order);
        case standard_price:
            return sort_by_standard_price(order);
        case deluxe_price:
            return sort_by_deluxe_price(order);
        case luxury_price:
            return sort_by_luxury_price(order);
        case premium_price:
            return sort_by_premium_price(order);
        case average_price:
            return sort_by_average_price(order);
        case rating_personal:
            return sort_by_rating_personal(order);
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

User::sort_property User::resolve_sort_property(const std::string &sort_property) {
    if( sort_property == "id" ) return id;
    if( sort_property == "name" ) return name;
    if( sort_property == "star_rating" ) return star_rating;
    if( sort_property == "city" ) return city;
    if( sort_property == "standard_room_price" ) return standard_price;
    if( sort_property == "deluxe_room_price" ) return deluxe_price;
    if( sort_property == "luxury_room_price" ) return luxury_price;
    if( sort_property == "premium_room_price" ) return premium_price;
    if( sort_property == "average_room_price") return average_price;
    if( sort_property == "rating_personal" ) return rating_personal;
    return invalid_property;
}

User::sort_order User::resolve_sort_order(const std::string &sort_order) {
    if( sort_order == "ascending" ) return ascending;
    if( sort_order == "descending" ) return descending;
    return invalid_order;
}

void User::sort_by_id(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) { return lhs->get_id() < rhs->get_id(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) { return lhs->get_id() > rhs->get_id(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_name(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) { return lhs->get_name() < rhs->get_name(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) { return lhs->get_name() > rhs->get_name(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_star_rating(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) { return lhs->get_star_rating() < rhs->get_star_rating(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) { return lhs->get_star_rating() > rhs->get_star_rating(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_city(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_city() == rhs->get_city())
                    return lhs->get_id() < rhs->get_id();
                else return lhs->get_city() < rhs->get_city();
            };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_city() == rhs->get_city())
                    return lhs->get_id() > rhs->get_id();
                else return lhs->get_city() > rhs->get_city();
            };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_standard_price(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_standard_price() == rhs->get_standard_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_standard_price() < rhs->get_standard_price(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_standard_price() == rhs->get_standard_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_standard_price() > rhs->get_standard_price(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_deluxe_price(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_deluxe_price() == rhs->get_deluxe_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_deluxe_price() < rhs->get_deluxe_price(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_deluxe_price() == rhs->get_deluxe_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_deluxe_price() > rhs->get_deluxe_price(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_luxury_price(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_luxury_price() == rhs->get_luxury_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_luxury_price() < rhs->get_luxury_price(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_luxury_price() == rhs->get_luxury_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_luxury_price() > rhs->get_luxury_price(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_premium_price(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_premium_price() == rhs->get_premium_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_premium_price() < rhs->get_premium_price(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_premium_price() == rhs->get_premium_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_premium_price() > rhs->get_premium_price(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

void User::sort_by_average_price(const std::string &order) {
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_average_price() == rhs->get_average_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_average_price() < rhs->get_average_price(); };
            break;
        }
        case descending: {
            sort_function = [](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_average_price() == rhs->get_average_price())
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_average_price() > rhs->get_average_price(); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}


void User::sort_by_rating_personal(const std::string &order) {
    estimate_weights();
    switch (resolve_sort_order(order)){
        case ascending: {
            sort_function = [=](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_rating(given_rating, rating_weights, estimated_weights) == rhs->get_rating(given_rating, rating_weights, estimated_weights))
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_rating(given_rating, rating_weights, estimated_weights) < rhs->get_rating(given_rating, rating_weights, estimated_weights); };
            break;
        }
        case descending: {
            sort_function = [=](Hotel *lhs, Hotel *rhs) {
                if(lhs->get_rating(given_rating, rating_weights, estimated_weights) == rhs->get_rating(given_rating, rating_weights, estimated_weights))
                    return lhs->get_id() < rhs->get_id();
                return lhs->get_rating(given_rating, rating_weights, estimated_weights) < rhs->get_rating(given_rating, rating_weights, estimated_weights); };
            break;
        }
        default:
            throw Hotel_Exceptions(BAD_REQUEST);
    }
}

function<bool(Hotel *, Hotel *)> User::get_sort_function() { return sort_function;}

bool User::check_default_filter() {
    for(auto filter : filters){
        if(filter->get_name() == DEFAULT_FILTER)
            return default_filter;
    }
    return false;
}

void User::save_rating_weights(const std::string& status ,float location, float cleanliness, float staff, float facilities, float value_for_money) {
    rating_weights = new RatingWeights(status, location, cleanliness, staff, facilities, value_for_money);
}

void User::show_rating_weights() {
    rating_weights->show_weights();
}

void User::off_rating_weights() {
    rating_weights = new RatingWeights("false");
}

void User::add_rating(const std::string& hotel_id, float location, float cleanliness, float staff, float facilities, float value_for_money, float overall_Rating) {
    given_rating.push_back(new Ratings(hotel_id, location, cleanliness, staff, facilities, value_for_money, overall_Rating));
}
double random_float(double min, double max) {
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}

void User::estimate_weights() {
    if (given_rating.size() < 5)
        return;
    vector<double> w;
    w.reserve(5);
    srand(time(0));
    for (int i = 0; i < 5; i++)
        w.push_back(random_float(1.0, 5.0));
    for(int k = 0; k < 1000; k++){
        vector<double> d;
        d.reserve(5);
        for (int i = 0; i < 5; i++)
            d.push_back(0);

        for(auto j : given_rating)
            for (int i = 0; i < 5; i++)
                d[i] += find_diffrantiate(j , w, i);
        for (int i = 0; i < 5; i++){
            w[i] = w[i] - 0.1 * d[i];
            w[i] = cut_float(w[i], 5.0, 1.0);
        }
    }
    estimated_weights = new RatingWeights("true", w[0], w[1], w[2], w[3], w[4]);
}

double User::find_diffrantiate(Ratings *const &user_rate, std::vector<double> weights, int count) {
    double y_hat = user_rate->find_weighted_overall(weights);
    weights[count] += 0.0001;
    double y_epsilon = user_rate->find_weighted_overall(weights);
    double y = user_rate->get_overall_rate();
    return ((find_error(y_epsilon, y) - find_error(y_hat, y))/0.0001);
}

double User::find_error(double y_hat, double y){
    return pow(abs(y_hat - y), 2);
}

double User::cut_float(double number, double high, double low){
    if(number >= high)
        return high;
    else if(number <= low)
        return low;
    else
        return number;
}

std::vector<float> User::get_wallet_history() {
    return wallet_history;
}


//void User::check_duplicate_filter(const string& filter_type){
//    for(auto filter : filters)
//        if(filter->get_name() == filter_type)
//            delete filter;
//
//}
