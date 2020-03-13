#include "Books.h"
using namespace std;

Books::Books(int book_id, const std::string &book_title, int author_id, const std::string &book_genres,
             const std::vector<Authors>& authors) {
    id = book_id;
    title = book_title;
    book_author = find_author_by_id(authors, author_id);
    genres = book_genres;
}

Authors find_author_by_id(const std::vector<Authors>& authors, int author_id) {
    for(auto author : authors){
        if(author.get_id() == author_id) {
            return  author;
        }
    }
    return Authors();
}


