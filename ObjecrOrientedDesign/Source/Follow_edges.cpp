#include <sstream>
#include "../Header/Follow_edges.h"

using namespace std;

Follow_edges::Follow_edges(int follow_edge_id, int follow_edge_following, const string& follow_edge_followers) {
    id = follow_edge_id;
    following = follow_edge_following;
    followers = parse_$_delimiter_numbers(follow_edge_followers);
}

std::vector<int> Follow_edges::parse_$_delimiter_numbers(const std::string &followers_string) {
    string parsed;
    stringstream str_stream(followers_string);
    vector<int> separated_numbers;

    while (getline(str_stream, parsed, '$')) {
        separated_numbers.push_back(stoi(parsed));
    }
    return separated_numbers;
}
