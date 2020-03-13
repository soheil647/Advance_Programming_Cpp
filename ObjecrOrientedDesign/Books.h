#ifndef OBJECRORIENTEDDESIGN_BOOKS_H
#define OBJECRORIENTEDDESIGN_BOOKS_H

#include <string>
#include "Authors.h"

class Books {
private:
    int id;
    std::string title;
    Authors book_author;
    std::string genres;
public:
    Books(int book_id, const std::string &book_title, int author_id, const std::string &book_genres,
          const std::vector<Authors>& authors);
    Books() = default;
    std::string get_title() { return title; };
    std::string get_genres() { return genres; };
    std::string get_author_name() { return book_author.get_name(); };
    std::string get_author_gender() { return book_author.get_gender(); };
    int get_id() { return id; };
    int get_author_id() { return book_author.get_id(); };
};

Authors find_author_by_id(const std::vector<Authors>& authors, int author_id);


#endif //OBJECRORIENTEDDESIGN_BOOKS_H
