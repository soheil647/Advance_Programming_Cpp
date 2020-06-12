#ifndef HOTEL_RESERVATION_USER_HPP
#define HOTEL_RESERVATION_USER_HPP


#include <string>
#include <vector>
#include <iostream>
#include "userReservation.hpp"
#include "costFilter.hpp"
#include "roomFilter.hpp"
#include "starFilter.hpp"
#include "cityFilter.hpp"

class User {
private:
    std::string username;
    std::string email;
    std::string password;
    float wallet{};
    std::vector<float> wallet_history;
    std::vector<userReservation*> reserves;
    int reserve_id{};
    std::vector<Filter*> filters{};
    int hashed_password;

    static void check_star_filter(int min_star, int max_star);
    static void check_cost_filter(float min_price, float max_price);
    static int hash_password(const std::string &Combine);
public:
    User(const std::string& _email, const std::string& _username, const std::string& _password);
    User(const User& new_user);
    bool operator==(const User& user);
    bool compare_login(const std::string& _email, const std::string& _password);
    void charging_wallet(float amount);

    void show_wallet_history(int count);

    std::string get_username();

    float get_wallet();

    void reserve_rooms(const std::string &_hotel_id, const std::vector<Room*>& reserved_rooms);

    void show_reserves();

    void decreasing_wallet(float amount);

    userReservation * delete_reserve(int id);

    userReservation* find_reserve_by_id(int id);

    void add_city_filter(std::vector<std::string> args);

    void add_star_filter(std::vector<std::string> args);

    void add_cost_filter(const std::vector<std::string>& args);

    void add_room_filter(const std::vector<std::string>& args);

    void delete_filters();

    std::vector<Filter*> get_filters();

};


#endif //HOTEL_RESERVATION_USER_HPP
