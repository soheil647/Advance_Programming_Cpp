#include "../Header/Books.h"
using namespace std;

Books::Books(int book_id, const std::string &book_title, int temp_author_id, const std::string &book_genres) {
    id = book_id;
    title = book_title;
    author_id = temp_author_id;
    genres = book_genres;
}

Books::Books(int book_id, float book_rate) {
    id = book_id;
    rate = book_rate;
}




