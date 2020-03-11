#include "Date.h"

using namespace std;

Date::Date(int d, string m, int y) {
    day = d;
    month = m;
    year = y;

}

string Date::get_month() {
    return month;
}

Date::Date() {
    day = 0;
    month = "";
    year = 0;
}

Date parse_date_object(const string& str) {
    // Used to split string around spaces.
    istringstream ss(str);
    int day = 0;
    string month;
    int year = 0;

    // Traverse through all words
    for(int i = 0; i < 3 && ss; i++){
        string word;
        ss >> word;
        if(i == 0)
            month = word;
        if(i == 1)
            day = stoi(word);
        if(i == 2)
            year = stoi(word);
    }
    Date date(day, month, year);
    return date;
}