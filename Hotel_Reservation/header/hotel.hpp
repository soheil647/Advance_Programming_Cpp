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
    std::vector<std::string> property_amenities;
    std::string city;
    float latitude{};
    float longitude{};
    std::string image_url;
    std::map<std::string, int> number_of_rooms;
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

    void parse_properties(const std::string &properties);
    void parse_hotel_information(const std::vector<std::string> &hotel_information);
    void assign_rooms_ids();
    enum RoomType {standard, deluxe, luxury, premium, invalid_type};
    static RoomType resolve_room_type(const std::string& room_type);
public:
    Hotel(const std::vector<std::string> &information_path);
    std::string get_id();

    void get_new_comment(const std::string &username, const std::string &comment);
    void get_new_rating(float location, float cleanliness, float staff, float facilities, float value_for_money, float overall_Rating);
    void show_comments();
    void show_ratings();
    void reserve_rooms(const std::string& room_type, int room_quantity, int check_in, int check_out);

    static void print_reserved_rooms(const std::vector<Room *>& reserved_rooms);

    static void reset_reserved_rooms(const std::vector<Room *>& reserved_rooms);
};


#endif //HOTEL_RESERVATION_HOTEL_HPP
