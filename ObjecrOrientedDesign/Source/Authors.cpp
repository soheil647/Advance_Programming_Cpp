#include "Authors.h"

using namespace std;

Authors::Authors(int author_id, const string& author_name, const string& author_gender, const string& member_since,
                 int author_birth_year, const string& author_birth_place, const string& author_genres) {
    id = author_id;
    name = author_name;
    gender = author_gender;
    date = member_since;
    year_of_birth = author_birth_year;
    place_of_birth = author_birth_place;
    parse_genres(author_genres);
}


void Authors::parse_genres(const string& genres_string) {
    string parsed;
    stringstream genres_string_stream(genres_string);

    while (getline(genres_string_stream,parsed,'$'))
    {
        genres.push_back(parsed);
    }
}

