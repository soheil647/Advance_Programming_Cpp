#include "User.h"

using namespace std;

vector<int> parse_$_delimiter_numbers(const string &str) {
    string parsed;
    stringstream strstream(str);
    vector<int> seperated_numbers;

    while (getline(strstream, parsed, '$')) {
        seperated_numbers.push_back(stoi(parsed));
    }
    return seperated_numbers;
}

vector<string> parse_$_delimiter_string(const std::string &genres_string) {
    string parsed;
    stringstream strstream(genres_string);
    vector<string> seperated_genres;

    while (getline(strstream, parsed, '$')) {
        seperated_genres.push_back(parsed);
    }
    return seperated_genres;
}

User::User(int user_id, const string &user_name, const string &user_birth_place,
           const string &user_member_since,
           const string &user_favorite_authors, const string &user_favorite_genres,
           const string &user_want_to_read,
           const string &user_currently_reading, const string &user_read,
           const vector<Authors> &all_authors, const vector<Books> &all_books) {
    id = user_id;
    name = user_name;
    place_of_birth = user_birth_place;
    member_since = user_member_since;
    favorite_authors = find_favorite_authors(all_authors, user_favorite_authors);
    favorite_genres = parse_$_delimiter_string(user_favorite_genres);
    want_to_read = find_related_books(user_want_to_read, all_books);
    currently_reading = find_related_books(user_currently_reading, all_books);
    read = find_related_books(user_read, all_books);
}

std::vector<Books> User::find_shelf_book_for_user(const std::string& shelf_type) {
    if(shelf_type == "want_to_read")
        return want_to_read;
    else if(shelf_type == "currently_reading")
        return currently_reading;
    else if(shelf_type == "read")
        return read;
    return std::vector<Books>();
}

vector<Authors> find_favorite_authors(const vector<Authors> &authors, const string &user_favorite_authors) {
    vector<Authors> favorite_authors;
    vector<int> favorite_authors_ids = parse_$_delimiter_numbers(user_favorite_authors);
    for (int i : favorite_authors_ids) {
        for (auto author : authors) {
            if (author.get_id() == i) {
                favorite_authors.push_back(author);
            }
        }
    }
    return favorite_authors;
}

vector<Books> find_related_books(const string &user_books_string, const vector<Books> &books) {
    vector<int> book_ids = parse_$_delimiter_numbers(user_books_string);
    vector<Books> user_books;
    for (int i : book_ids) {
        for (auto book : books) {
            if (book.get_id() == i) {
                user_books.push_back(book);
            }
        }
    }
    return user_books;
}
