#ifndef OBJECRORIENTEDDESIGN_REVIEWS_H
#define OBJECRORIENTEDDESIGN_REVIEWS_H

#include "Authors.h"
#include "Books.h"
#include "User.h"
#include "Google_read.h"


class Reviews {
private:
    int id;
    Books book;
    User user;
    int rating;
    std::string date;
    int number_of_likes;
public:
    Reviews(int review_id, int book_id, int user_id, int review_rate, const std::string &review_date, int review_number_of_like,
            const std::vector<Books>& all_books, const std::vector<User>& all_users);
    Reviews() = default;

    User get_user() { return user; };
    int get_number_of_likes() { return number_of_likes; };
};



#endif //OBJECRORIENTEDDESIGN_REVIEWS_H
