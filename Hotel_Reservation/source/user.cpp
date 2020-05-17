#include <algorithm>
#include "../header/user.hpp"
using namespace std;

User::User(const std::string& _email, const std::string& _username, const std::string& _password) {
    email = _email;
    username = _username;
    password = _password;
    wallet = 0;
    wallet_history.push_back(wallet);
}

bool User::operator==(const User& user) {
    return user.email == this->email || user.username == this->username;
}

User::User(const User &new_user) {
    email = new_user.email;
    username = new_user.username;
    password = new_user.password;
    wallet = 0;
    wallet_history.push_back(0);
}

bool User::compare_login(const std::string& _email, const std::string& _password) {
    return this->email == _email && this->password == _password;
}

void User::charging_wallet(float amount) {
    this->wallet += amount;
    this->wallet_history.push_back(this->wallet);
}

void User::show_wallet_history(int count) {
    unsigned int history_count = (count > this->wallet_history.size()) ? this->wallet_history.size() : count;

    std::cout << this->wallet << std::endl;
    reverse(this->wallet_history.begin(), this->wallet_history.end());
    for(unsigned int i = 1; i < history_count; i++)
        std::cout << this->wallet_history[i] << std::endl;
    reverse(this->wallet_history.begin(), this->wallet_history.end());
}

string User::get_username() { return this->username;}