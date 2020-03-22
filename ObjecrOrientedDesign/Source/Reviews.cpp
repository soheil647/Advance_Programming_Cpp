#include "Reviews.h"

using namespace std;

Reviews::Reviews(int review_id, int temp_book_id, int temp_user_id, int review_rate, const string &review_date,
                 int review_number_of_like) {
    id = review_id;
    book_id = temp_book_id;
    user_id = temp_user_id;
    rating = review_rate;
    date = review_date;
    number_of_likes = review_number_of_like;
}
