#ifndef OBJECRORIENTEDDESIGN_AUTHORS_H
#define OBJECRORIENTEDDESIGN_AUTHORS_H

#include <string>
#include <vector>
#include <sstream>

class Authors {
private:
    int id{};
    std::string name;
    std::string gender;
    std::string date;
    int year_of_birth{};
    std::string place_of_birth;
    std::vector<std::string> genres;

    void parse_genres(const std::string& genres_string);

public:
    Authors(int author_id, const std::string& author_name, const std::string& author_gender, const std::string& member_since,
            int author_birth_year, const std::string& author_birth_place, const std::string& author_genres);
    Authors() = default;
    std::string get_name() { return name; };
    int get_year_of_birth() { return year_of_birth; };
    std::string get_place_of_birth() { return place_of_birth; };
    std::string get_member_since() { return date; };
    std::vector<std::string> get_genres() { return genres; };
    int get_id() { return id; };
};



#endif //OBJECRORIENTEDDESIGN_AUTHORS_H
