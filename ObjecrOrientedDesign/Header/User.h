#ifndef OBJECRORIENTEDDESIGN_USER_H
#define OBJECRORIENTEDDESIGN_USER_H

#include <string>
#include <vector>
#include <sstream>

class User {
private:
    int id{};
    std::string name;
    std::string place_of_birth;
    std::string member_since;
    std::vector<int> favorite_authors;
    std::vector<std::string> favorite_genres;
    std::vector<int> want_to_read;
    std::vector<int> currently_reading;
    std::vector<int> read;

    static std::vector<int> parse_$_delimiter_numbers(const std::string &authors_string);
    static std::vector<std::string> parse_$_delimiter_string(const std::string &genres_string);
public:
    User(int user_id, const std::string &user_name, const std::string &user_birth_place,
         const std::string &user_member_since,
         const std::string &user_favorite_authors, const std::string &user_favorite_genres,
         const std::string &user_want_to_read,
         const std::string &user_currently_reading, const std::string &user_read);
    User() = default;

    std::string get_name() { return name; };
    int get_id() { return id; };
    std::vector<int> get_want_to_read_books() { return want_to_read; };
    std::vector<int> get_currently_reading_books() { return currently_reading; };
    std::vector<int> get_read_books() { return read; };
    std::string get_member_since() { return member_since; };
    std::string get_place_of_birth() { return place_of_birth; };
    std::vector<std::string> get_favorite_genres() { return favorite_genres; };
    std::vector<int> get_favorite_authors() { return favorite_authors; };


    std::vector<int> find_shelf_book_for_user(const std::string& shelf_type);
};




#endif //OBJECRORIENTEDDESIGN_USER_H
