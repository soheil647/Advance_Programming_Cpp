#include <string>
#include <sstream>

#ifndef OBJECRORIENTEDDESIGN_DATE_H
#define OBJECRORIENTEDDESIGN_DATE_H


class Date {
private:
    std::string month;
    int day;
    int year;
public:
    Date(int d,std::string m,int y);
    Date();
    std::string get_month();
};

Date parse_date_object(const std::string& str);
#endif //OBJECRORIENTEDDESIGN_DATE_H
