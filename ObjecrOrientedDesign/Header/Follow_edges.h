#ifndef OBJECRORIENTEDDESIGN_FOLLOW_EDGES_H
#define OBJECRORIENTEDDESIGN_FOLLOW_EDGES_H

#include <vector>
#include <string>

class Follow_edges {
private:
    int id{};
    int following{};
    std::vector<int> followers;

    static std::vector<int> parse_$_delimiter_numbers(const std::string &followers_string);
public:
    Follow_edges(int follow_edge_id, int follow_edge_following, const std::string& follow_edge_followers);

    int get_following() { return following; };
    std::vector<int> get_followers() { return followers; };
};


#endif //OBJECRORIENTEDDESIGN_FOLLOW_EDGES_H
