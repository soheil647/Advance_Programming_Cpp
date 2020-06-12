#ifndef HOTEL_RESERVATION_HOTEL_HPP
#define HOTEL_RESERVATION_HOTEL_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include "hotelExceptions.hpp"
#include "room.hpp"

class Hotel {
private:
    struct Rating;
    std::string unique_id;
    std::string property_name;
    int hotel_star_rating{};
    std::string hotel_overview;
    std::string property_amenities;
    std::string city;
    float latitude{};
    float longitude{};
    std::string image_url;
    int number_standard_room{};
    int number_deluxe_room{};
    int number_luxury_room{};
    int number_premium_room{};
    int standard_room_price{};
    int deluxe_room_price{};
    int luxury_room_price{};
    int premium_room_price{};
    std::vector<Room*> standard_rooms;
    std::vector<Room*> deluxe_rooms;
    std::vector<Room*> luxury_rooms;
    std::vector<Room*> premium_rooms;
    std::vector<std::map<std::string,std::string>> comments;
    std::vector<Rating> ratings;

    void parse_hotel_information(const std::vector<std::string> &hotel_information);
    void assign_rooms_ids();
    enum RoomType {standard, deluxe, luxury, premium, invalid_type};
    static RoomType resolve_room_type(const std::string& room_type);
    static std::vector<Room *> print_reserved_rooms(const std::vector<Room *>& reserved_rooms);
    static void reset_reserved_rooms(const std::vector<Room *>& reserved_rooms);
    std::vector<Room *> get_rooms_of_type(const std::string &room_type);
    float find_average_price();
public:
    Hotel(const std::vector<std::string> &information_path);
    std::string get_id();
    bool check_city_name(const std::string& city_name);

    void get_new_comment(const std::string &username, const std::string &comment);
    void get_new_rating(float location, float cleanliness, float staff, float facilities, float value_for_money, float overall_Rating);
    void show_comments();
    void show_ratings();
    std::vector<Room *> reserve_rooms(const std::string& room_type, int room_quantity, int check_in, int check_out);
    int get_room_price(const std::string &room_type);
    static void reset_reserve(const std::vector<Room *>& reserved_rooms);

    bool check_star(int min_star, int max_star);
    bool check_average_price(float min_price, float max_price);
    bool check_available_room(const std::string& room_type, int quantity, int check_in, int check_out);

    void print_hotel();

    void print_summery_of_hotel();
};


#endif //HOTEL_RESERVATION_HOTEL_HPP
