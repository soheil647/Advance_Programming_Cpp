#include "../Header/User.h"

using namespace std;

vector<int> User::parse_$_delimiter_numbers(const string &str) {
    string parsed;
    stringstream str_stream(str);
    vector<int> separated_numbers;

    while (getline(str_stream, parsed, '$')) {
        separated_numbers.push_back(stoi(parsed));
    }
    return separated_numbers;
}

vector<string> User::parse_$_delimiter_string(const std::string &genres_string) {
    string parsed;
    stringstream str_stream(genres_string);
    vector<string> separated_genres;

    while (getline(str_stream, parsed, '$')) {
        separated_genres.push_back(parsed);
    }
    return separated_genres;
}

User::User(int user_id, const string &user_name, const string &user_birth_place,
           const string &user_member_since,
           const string &user_favorite_authors, const string &user_favorite_genres,
           const string &user_want_to_read,
           const string &user_currently_reading, const string &user_read) {
    id = user_id;
    name = user_name;
    place_of_birth = user_birth_place;
    member_since = user_member_since;
    favorite_authors = parse_$_delimiter_numbers(user_favorite_authors);
    favorite_genres = parse_$_delimiter_string(user_favorite_genres);
    want_to_read = parse_$_delimiter_numbers(user_want_to_read);
    currently_reading = parse_$_delimiter_numbers(user_currently_reading);
    read = parse_$_delimiter_numbers(user_read);
}

std::vector<int> User::find_shelf_book_for_user(const std::string& shelf_type) {
    if(shelf_type == "want_to_read")
        return want_to_read;
    else if(shelf_type == "currently_reading")
        return currently_reading;
    else if(shelf_type == "read")
        return read;
    return std::vector<int>();
}

