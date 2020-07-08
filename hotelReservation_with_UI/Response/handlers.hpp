#ifndef HOTELRESERVATION_WITH_UI_HANDLERS_HPP
#define HOTELRESERVATION_WITH_UI_HANDLERS_HPP

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Login : public RequestHandler {
public:
    Response *callback(Request *) override;
};

class Adder : public RequestHandler {
public:
    Response *callback(Request *) override;
};

#endif //HOTELRESERVATION_WITH_UI_HANDLERS_HPP
