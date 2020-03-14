#ifndef OBJECRORIENTEDDESIGN_BOOKS_H
#define OBJECRORIENTEDDESIGN_BOOKS_H

#include <string>
#include "Authors.h"

class Books {
private:
    int id{};
    std::string title;
    int author_id{};
    std::string genres;
public:
    Books(int book_id, const std::string &book_title, int temp_author_id, const std::string &book_genres);
    Books() = default;
    std::string get_title() { return title; };
    std::string get_genres() { return genres; };
    int get_author_id() { return author_id; };
    int get_id() { return id; };
};

#endif //OBJECRORIENTEDDESIGN_BOOKS_H
