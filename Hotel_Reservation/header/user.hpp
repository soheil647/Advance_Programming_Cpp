#ifndef HOTEL_RESERVATION_USER_HPP
#define HOTEL_RESERVATION_USER_HPP


#include <string>
#include <vector>
#include <iostream>

class User {
private:
    std::string username;
    std::string email;
    std::string password;
    float wallet{};
    std::vector<float> wallet_history;

public:
    User(const std::string& _email, const std::string& _username, const std::string& _password);
    User(const User& new_user);
    bool operator==(const User& user);
    bool compare_login(const std::string& _email, const std::string& _password);
    void charging_wallet(float amount);

    void show_wallet_history(int count);

    std::string get_username();
};


#endif //HOTEL_RESERVATION_USER_HPP
