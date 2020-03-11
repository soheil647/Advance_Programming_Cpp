#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Date.h"
#include "Date.cpp"

using namespace std;

vector<string> readCsvFile(const string &filePath, int columnsNumber);
void parse();

int main() {
    vector<string> ss =  readCsvFile("./Assets/books.csv", 4);
//    for (string i : ss)
//        cout << i << endl;
//    Date date = parse_date_object("September 1 2013");
//    cout << date.get_month();

    parse();
}



vector<string> readCsvFile(const string &filePath, int columnsNumber) {

    ifstream inputFile(filePath);
    if (inputFile.fail()) {
        cerr << "Error Opening the file" << endl;
        inputFile.close();
        exit(1);
    }
    vector<string> row;
    string line, word, temp;

    getline(inputFile, line);
    columnsNumber = count(line.begin(), line.end(), ',') + 1;
    while (getline(inputFile, line)) {
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
    }
    return row;
}

//std::vector<std::string> parse_genres(const std::string& genres_string) {
//
//    // Used to split string around spaces.
//    istringstream ss(genres_string);
//
//    // Traverse through all words
//    for(int i = 0; i < 3 && ss; i++){
//        string word;
//        ss >> word;
//        if(i == 0)
//            month = word;
//        if(i == 1)
//            day = stoi(word);
//        if(i == 2)
//            year = stoi(word);
//    }
//}