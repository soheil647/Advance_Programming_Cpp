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
#include "defaultPriceFilter.hpp"
#include "ratingWeights.hpp"

#define CITY_FILTER "city"
#define COST_FILTER "cost"
#define STAR_FILTER "star"
#define ROOM_FILTER "room"
#define DEFAULT_FILTER "default"

typedef bool (*sort_func)(Hotel *lhs, Hotel *rhs);

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
    int hashed_password{};
    bool default_filter{};
    bool (* sort_function)(Hotel* lhs, Hotel* rhs);
    std::vector<Ratings*> given_rating;
    RatingWeights* rating_weights;
    //TODO: std::function<int (int)>
    static void check_star_filter(int min_star, int max_star);
    static void check_cost_filter(float min_price, float max_price);
    static int hash_password(const std::string &Combine);
    bool check_default_filter_status();
    enum sort_property {invalid_property, id, name, star_rating, city, standard_price, deluxe_price, luxury_price, premium_price, average_price, rating_personal};
    enum sort_order {invalid_order, ascending, descending};
    static sort_property resolve_sort_property(const std::string& sort_property);
    static sort_order resolve_sort_order(const std::string& sort_order);
    void sort_by_id(const std::string &order);
    void sort_by_name(const std::string &order);
    void sort_by_star_rating(const std::string &order);
    void sort_by_city(const std::string &order);
    void sort_by_standard_price(const std::string &order);
    void sort_by_deluxe_price(const std::string &order);
    void sort_by_luxury_price(const std::string &order);
    void sort_by_premium_price(const std::string &order);
    void sort_by_average_price(const std::string &order);
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
    void status_default_filter_price(const std::string& status);
    void save_sort_order(const std::string& sort_property, const std::string& order);

    sort_func get_sort_function();

    bool check_default_filter();

    void save_rating_weights(const std::string& status ,float location, float cleanliness, float staff, float facilities, float value_for_money);

    void show_rating_weights();

    void off_rating_weights();

    void add_rating(const std::string& hotel_id, float overall_rating);

    void sort_by_rating_personal(const std::string &order);

    bool check_hotel_rating(Hotel *lhs, Hotel *&rhs);
};


#endif //HOTEL_RESERVATION_USER_HPP
