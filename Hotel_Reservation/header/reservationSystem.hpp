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

    static std::vector<std::string> read_csv_file(const std::string &file_path, int &columns_number);
    void find_command_action(std::stringstream& arg, const std::string& method, const std::string& command);
    enum Methods {invalid_method, POST, GET, DELETE};
    enum Commands {invalid_command, signup, login, logout, wallet, show_hotels, filters, reserves, comments, ratings};
    static Methods resolve_method(const std::string& method);
    static Commands resolve_command(const std::string& command);
    static std::vector<std::string> resolve_arguments(std::stringstream &arg);

    void post_signup(std::stringstream &arg);
    void post_login(std::stringstream &arg);
    void post_logout(std::stringstream &arg);
    void post_wallet(std::stringstream &arg);
    void post_comments(std::stringstream &arg);
    Hotel *find_hotel_by_id(const std::string &hotel_id);
    void get_wallet(std::stringstream &arg);
    void get_comments(std::stringstream &arg);
    void get_ratings(std::stringstream &arg);
public:
    ReservationSystem(const std::string& file_path);
    void parse_command(std::stringstream& input_line);

    void post_rating(std::stringstream &arg);
};


#endif //HOTEL_RESERVATION_RESERVATIONSYSTEM_HPP
