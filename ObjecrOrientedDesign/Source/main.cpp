#include "Google_read.h"

using namespace std;

vector<string> parse_input_command(const string& line);

int main(int argv, char *argc[]) {
    string assets_address = "./" + string(argc[1]);
    Google_read all_data = Google_read(assets_address + "/authors.csv", assets_address + "/books.csv",
                                       assets_address + "/users.csv", assets_address + "/reviews.csv");
    string line;
    while(getline(cin, line)) {
        vector<string> command = parse_input_command(line);
        if (command[0] == "show_author_info")
            all_data.show_author_info(stoi(command[1]));
        if (command[0] == "show_sorted_shelf")
            all_data.show_sorted_shelf(stoi(command[1]), command[2], command[3]);
        if (command[0] == "credit")
            all_data.show_user_credit(stoi(command[1]));
        if (command[0] == "best_book")
            all_data.show_best_book();
        if (command[0] == "best_reviewer")
            all_data.show_best_reviewer();
        if (command[0] == "recommend_first_approach")
            all_data.show_recommended_books(stoi(command[1]));
    }
}

vector<string> parse_input_command(const string& line) {
    string word;
    vector<string> command;
        stringstream ss(line);
        while (ss) {
            ss >> word;
            command.push_back(word);
        }
    return command;
}