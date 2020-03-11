#include <string>
#include <vector>
#include <sstream>
#include "Date.h"

#ifndef OBJECRORIENTEDDESIGN_AUTHORS_H
#define OBJECRORIENTEDDESIGN_AUTHORS_H


class Authors {
private:
    int id;
    std::string name;
    std::string gender;
    Date date;
    int year_of_birth;
    std::string place_of_birth;
    std::vector<std::string> genres;

public:
    Authors(int author_id, const std::string& author_name, const std::string& author_gender, const std::string& member_since,
            int author_birth_year, const std::string& author_birth_place, const std::string& author_genres);
};


std::vector<std::string> parse_genres(const std::string& genres_string);

#endif //OBJECRORIENTEDDESIGN_AUTHORS_H
