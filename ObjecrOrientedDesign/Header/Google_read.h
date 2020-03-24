#ifndef OBJECRORIENTEDDESIGN_GOOGLE_READ_H
#define OBJECRORIENTEDDESIGN_GOOGLE_READ_H

#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include "Books.h"
#include "Authors.h"
#include "User.h"
#include "Reviews.h"
#include "Follow_edges.h"


class Google_read {
private:
    std::vector<Authors> authors;
    std::vector<Books> books;
    std::vector<User> users;
    std::vector<Reviews> reviews;
    std::vector<Follow_edges> follow_edges;

    static bool compare_by_title(Books book1, Books book2);
    static bool rate_cmp(Books a, Books b)
    {
        return a.get_rate() > b.get_rate();
    }
    static std::vector<Books> sort_by_rate(std::vector<Books> my_books);

    static std::vector<std::string> read_csv_file(const std::string &filePath, int &columnsNumber);
    void parse_books_csv(const std::string &books_file_path);
    void parse_authors_csv(const std::string &author_file_path);
    void parse_users_csv(const std::string &users_file_path);
    void parse_reviews_csv(const std::string &reviews_file_path);
    void parse_follow_edges_csv(const std::string &follow_edges_file_path);
    static int count_string_in_csv_line_comma_delimiter(const std::string& line);

    Reviews find_review_by_id(int review_id);
    User find_user_by_id(int user_id);
    Authors find_author_by_id(int author_id);
    Books find_book_by_id(int book_id);
    std::vector<Books> find_books_by_author_name(const std::string &author_name);
    std::vector<int> find_user_follow_edge(std::vector<int>& checked_users_id, int user_id);
    std::vector<int> find_3_best_books_of_user(int user_id);
    std::vector<int> find_reviews_by_book_id(int book_id);
    static int find_most_common_element_in_vector(const std::vector<int>& ids);

    float find_user_credit(int user_id);
    void show_books_by_order(const std::string &genre, const std::vector<Books> &my_shelf_books);
    void find_best_book(float &average_rate, int &best_book_id);
    void find_best_reviewer(int &number_of_likes, int &best_reviewer_user_id);
    std::vector<int> find_recommend_book(int user_id, float &recommend_book_rate, int &recommend_book_id);
    int find_recommend_complex_book(int user_id);

public:
    Google_read(const std::string &authors_filepath, const std::string &books_filepath,
                const std::string &users_filepath, const std::string &review_filepath,
                const std::string &follow_edges_filepath);


    void show_author_info(int author_id);

    void show_sorted_shelf(int user_id, const std::string &shelf_type, const std::string &genre);

    void show_user_credit(int user_id);

    void show_best_book();

    void show_best_reviewer();

    void show_recommended_books(int user_id);

    void show_recommended_complex_books(int user_id);
};










#endif //OBJECRORIENTEDDESIGN_GOOGLE_READ_H
