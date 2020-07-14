#ifndef HOTELRESERVATION_WITH_UI_HANDLERS_HPP
#define HOTELRESERVATION_WITH_UI_HANDLERS_HPP

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "../header/reservationSystem.hpp"

class Login : public RequestHandler {
public:
    Response *callback(Request *) override;
};

class Adder : public RequestHandler {
public:
    Response *callback(Request *) override;
};

class CheckSignUp : public RequestHandler {
private:
    ReservationSystem* my_app;
public:
    explicit CheckSignUp(ReservationSystem* app){my_app = app;};
    Response *callback(Request *) override;
};

#endif //HOTELRESERVATION_WITH_UI_HANDLERS_HPP
