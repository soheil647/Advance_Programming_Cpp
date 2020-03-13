#ifndef OBJECRORIENTEDDESIGN_USER_H
#define OBJECRORIENTEDDESIGN_USER_H

#include <string>
#include <vector>
#include <sstream>
#include "Authors.h"
#include "Books.h"

class User {
private:
    int id;
    std::string name;
    std::string place_of_birth;
    std::string member_since;
    std::vector<Authors> favorite_authors;
    std::vector<std::string> favorite_genres;
    std::vector<Books> want_to_read;
    std::vector<Books> currently_reading;
    std::vector<Books> read;
public:
    User(int user_id, const std::string &user_name, const std::string &user_birth_place,
         const std::string &user_member_since,
         const std::string &user_favorite_authors, const std::string &user_favorite_genres,
         const std::string &user_want_to_read,
         const std::string &user_currently_reading, const std::string &user_read,
         const std::vector<Authors> &all_authors, const std::vector<Books> &all_books);
    User() = default;

    std::string get_name() { return name; };
    int get_id() { return id; };
    std::vector<Books> get_want_to_read_books() { return want_to_read; };

    std::vector<Books> find_shelf_book_for_user(const std::string& shelf_type);
};

std::vector<int> parse_$_delimiter_numbers(const std::string &authors_string);

std::vector<Authors>
find_favorite_authors(const std::vector<Authors> &authors, const std::string &user_favorite_authors);

std::vector<std::string> parse_$_delimiter_string(const std::string &genres_string);

std::vector<Books> find_related_books(const std::string &user_books_string, const std::vector<Books> &books);


#endif //OBJECRORIENTEDDESIGN_USER_H
