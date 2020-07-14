#ifndef HOTEL_RESERVATION_HOTELEXCEPTIONS_HPP
#define HOTEL_RESERVATION_HOTELEXCEPTIONS_HPP

#include <exception>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

#define DUPLICATE_USER "User already Taken"
#define NOT_FOUND "Not Found"
#define BAD_REQUEST "Bad Request"
#define PERMISSION_DENIED "Permission Denied"
#define EMPTY "Empty"
#define NO_RATING "No Rating"
#define NOT_ENOUGH_CREDIT "Not Enough Credit"
#define NOT_ENOUGH_ROOM "Not Enough Room"
#define INSUFFICIENT_RATINGS "Insufficient Ratings"

class Hotel_Exceptions : public std::exception {
private:
public:
    std::string error;
    explicit Hotel_Exceptions(const std::string& _error);
//    const char* what() const throw() override { return error;}
    std::string handle_error(){std::cout << error << std::endl; return error;}
};


#endif //HOTEL_RESERVATION_HOTELEXCEPTIONS_HPP
