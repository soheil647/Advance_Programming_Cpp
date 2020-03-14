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


class Google_read {
private:
    std::vector<Authors> authors;
    std::vector<Books> books;
    std::vector<User> users;
    std::vector<Reviews> reviews;


    static bool compare_by_title(Books book1, Books book2);
    static std::vector<std::string> read_csv_file(const std::string &filePath, int &columnsNumber);

    void parse_books_csv(const std::string &books_file_path);
    void parse_authors_csv(const std::string &author_file_path);
    void parse_users_csv(const std::string &users_file_path);
    void parse_reviews_csv(const std::string &reviews_file_path);

    Reviews find_review_by_id(int review_id);
    User find_user_by_id(int user_id);
    Authors find_author_by_id(int author_id);
    Books find_book_by_id(int book_id);
    std::vector<Books> find_books_by_author_name(const std::string &author_name);

    float find_user_credit(int user_id);
    void show_books_by_order(const std::string &genre, const std::vector<Books> &my_shelf_books);
    void find_best_book(float &average_rate, int &best_book_id);
    void find_best_reviewer(int &number_of_likes, int &best_reviewer_user_id);
    std::vector<int> find_recommend_book(int user_id, float &recommend_book_rate, int &recommend_book_id);

public:
    Google_read(const std::string &authors_filepath, const std::string &books_filepath,
                const std::string &users_filePath, const std::string &review_filepath);


    void show_author_info(int author_id);

    void show_sorted_shelf(int user_id, const std::string &shelf_type, const std::string &genre);

    void show_user_credit(int user_id);

    void show_best_book();

    void show_best_reviewer();

    void show_recommended_books(int user_id);
};










#endif //OBJECRORIENTEDDESIGN_GOOGLE_READ_H
