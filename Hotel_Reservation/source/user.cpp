#include <algorithm>
#include "../header/user.hpp"
#include "../header/hotelExceptions.hpp"

using namespace std;

User::User(const std::string &_email, const std::string &_username, const std::string &_password) {
    email = _email;
    username = _username;
    password = _password;
    wallet = 0;
    wallet_history.push_back(wallet);
    reserve_id = 1;
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

    std::cout << this->wallet << std::endl;
    reverse(this->wallet_history.begin(), this->wallet_history.end());
    for (unsigned int i = 1; i < history_count; i++)
        std::cout << this->wallet_history[i] << std::endl;
    reverse(this->wallet_history.begin(), this->wallet_history.end());
}

void User::reserve_rooms(const std::string &_hotel_id, const std::string &_room_type, int _quantity, int price,
        int _check_in, int _check_out){
    reserves.push_back(new userReservation(reserve_id, _hotel_id, _room_type, _quantity, price, _check_in, _check_out));
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

