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
    reserve_id += 1;
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

//void User::check_duplicate_filter(const string& filter_type){
//    for(auto filter : filters)
//        if(filter->get_name() == filter_type)
//            delete filter;
//
//}
