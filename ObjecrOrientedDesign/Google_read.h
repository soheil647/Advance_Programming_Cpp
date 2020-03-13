#ifndef OBJECRORIENTEDDESIGN_GOOGLE_READ_H
#define OBJECRORIENTEDDESIGN_GOOGLE_READ_H

#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "Books.h"
#include "Authors.h"
#include "User.h"
#include "Reviews.h"
#include "Books.cpp"
#include "Authors.cpp"
#include "User.cpp"
#include "Reviews.cpp"


class Google_read {
private:
    std::vector<Authors> authors;
    std::vector<Books> books;
    std::vector<User> users;
    std::vector<Reviews> reviews;

public:
    Google_read(const std::string &authors_filepath, const std::string &books_filepath,
                const std::string &users_filePath, const std::string &review_filepath);
    std::vector<Authors> get_all_authors() { return authors; };
    std::vector<Books> get_all_books() { return books; };
    std::vector<User> get_all_users() { return users; };

    std::vector<Books> find_books_by_author_name(const std::string& author_name);

    void show_author_info(int author_id);
    void show_sorted_shelf(int user_id, const std::string &shelf_type, const std::string& genre);
    void show_user_credit(int user_id);
    void show_best_book();
};

std::vector<std::string> read_csv_file(const std::string &filePath, int &columnsNumber);

std::vector<Books> parse_books_csv(const std::string &books_file_path, const std::vector<Authors> &all_authors);

std::vector<Authors> parse_authors_csv(const std::string &author_file_path);

std::vector<User> parse_users_csv(const std::string &users_file_path, const std::vector<Authors> &all_authors,
                                  const std::vector<Books> &all_books);

std::vector<Reviews> parse_reviews_csv(const std::string &reviews_file_path, const std::vector<User> &all_users,
                                      const std::vector<Books> &all_books)


User find_user_by_id(int user_id, const vector<User>& all_users);

Books find_book_by_id(int book_id, const std::vector<Books>& all_books);

bool compare_by_title(Books book1, Books book2);

void show_books_by_order(const std::string& genre, const std::vector<Books>& my_books);




#endif //OBJECRORIENTEDDESIGN_GOOGLE_READ_H
