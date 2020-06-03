#ifndef HOTEL_RESERVATION_USER_HPP
#define HOTEL_RESERVATION_USER_HPP


#include <string>
#include <vector>
#include <iostream>
#include "userReservation.hpp"

class User {
private:
    std::string username;
    std::string email;
    std::string password;
    float wallet{};
    std::vector<float> wallet_history;
    std::vector<userReservation*> reserves;
    int reserve_id{};

public:
    User(const std::string& _email, const std::string& _username, const std::string& _password);
    User(const User& new_user);
    bool operator==(const User& user);
    bool compare_login(const std::string& _email, const std::string& _password);
    void charging_wallet(float amount);

    void show_wallet_history(int count);

    std::string get_username();

    float get_wallet();

    void reserve_rooms(const std::string &_hotel_id, const std::string &_room_type, int _quantity, int price,
            int _check_in, int _check_out);

    void show_reserves();

    void decreasing_wallet(float amount);

    userReservation * delete_reserve(int id);

    userReservation* find_reserve_by_id(int id);
};


#endif //HOTEL_RESERVATION_USER_HPP
