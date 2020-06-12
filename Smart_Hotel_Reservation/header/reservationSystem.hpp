#ifndef HOTEL_RESERVATION_RESERVATIONSYSTEM_HPP
#define HOTEL_RESERVATION_RESERVATIONSYSTEM_HPP

#include "hotel.hpp"
#include "user.hpp"
#include "hotelExceptions.hpp"

class ReservationSystem {
private:
    std::vector<Hotel*> hotels;
    std::vector<User*> users;
    User* logged_user;

    void parse_rating(const std::string &file_path_rating);
    void parse_hotel(const std::string &file_path_hotel);
    static std::vector<std::string> read_csv_file(const std::string &file_path, int &columns_number);
    void find_command_action(std::stringstream& arg, const std::string& method, const std::string& command);
    Hotel *find_hotel_by_id(const std::string &hotel_id);
    enum Methods {invalid_method, POST, GET, DELETE};
    enum Commands {invalid_command, signup, login, logout, wallet, show_hotels, filters, reserves, comments, ratings, default_price_filter, sort, manual_weights};
    enum Filters {invalid_filter, city, star, cost, room};
    enum GetHotelType{one, all, invalid};
    static Methods resolve_method(const std::string& method);
    static Commands resolve_command(const std::string& command);
    static std::vector<std::string> resolve_arguments(std::stringstream &arg);
    static Filters resolve_filter_type(const std::vector<std::string> &args);
    static GetHotelType resolve_hotel_command(const std::vector<std::string> &args);
    void get_hotels(std::stringstream &arg);
    void print_one_hotel(const std::vector<std::string> &args);
    std::vector<Hotel *> filter_hotels();
    void print_filter_hotels();
    bool check_default_filter();
    void post_sort(std::stringstream &arg);
    void check_logged_user();

    void post_signup(std::stringstream &arg);
    void post_login(std::stringstream &arg);
    void post_logout(std::stringstream &arg);
    void post_wallet(std::stringstream &arg);
    void post_comments(std::stringstream &arg);
    void get_wallet(std::stringstream &arg);
    void get_comments(std::stringstream &arg);
    void get_ratings(std::stringstream &arg);
    void post_rating(std::stringstream &arg);
    void post_reserves(std::stringstream &arg);
    void delete_reserve(std::stringstream &arg);
    void get_reserves(std::stringstream &arg);
    void post_filters(std::stringstream &arg);
    void delete_filters(std::stringstream &arg);
    void post_default_filter_price(std::stringstream &arg);
public:
    ReservationSystem(const std::string& file_path_hotel, const std::string& file_path_rating);
    void parse_command(std::stringstream& input_line);

    void post_manual_weights(std::stringstream &arg);

    void get_manual_weights(std::stringstream &arg);
};


#endif //HOTEL_RESERVATION_RESERVATIONSYSTEM_HPP
