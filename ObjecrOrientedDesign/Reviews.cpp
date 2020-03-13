#include "Reviews.h"

using namespace std;

Reviews::Reviews(int review_id, int book_id, int user_id, int review_rate, const string &review_date, int review_number_of_like,
                 const vector<Books>& all_books, const vector<User>& all_users) {
    id = review_id;
    book = find_book_by_id(book_id, all_books);
    user = find_user_by_id(user_id, all_users);
    rating = review_rate;
    date = review_date;
    number_of_likes = review_number_of_like;
}
