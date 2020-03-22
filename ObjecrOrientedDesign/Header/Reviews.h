#ifndef OBJECRORIENTEDDESIGN_REVIEWS_H
#define OBJECRORIENTEDDESIGN_REVIEWS_H

#include <vector>
#include <string>


class Reviews {
private:
    int id{};
    int book_id{};
    int user_id{};
    int rating{};
    std::string date;
    int number_of_likes{};
public:
    Reviews(int review_id, int temp_book_id, int temp_user_id, int review_rate, const std::string &review_date,
            int review_number_of_like);

    Reviews() = default;

    int get_id() { return id; };
    int get_user_id() { return user_id; };
    int get_book_id() { return book_id; };
    int get_rating() { return rating; };
    int get_number_of_likes() { return number_of_likes; };
    std::string get_date() { return date; };
};



#endif //OBJECRORIENTEDDESIGN_REVIEWS_H
