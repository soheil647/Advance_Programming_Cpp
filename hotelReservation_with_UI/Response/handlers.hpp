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

class CheckLogin : public RequestHandler {
private:
    ReservationSystem* my_app;
public:
    explicit CheckLogin(ReservationSystem* app){my_app = app;};
    Response *callback(Request *) override;

};

class Home : public RequestHandler {
private:
    ReservationSystem* my_app;
public:
    explicit Home(ReservationSystem* app){my_app = app;};
    Response *callback(Request *) override;
};

class DoFilter : public RequestHandler {
private:
    ReservationSystem* my_app;
public:
    explicit DoFilter(ReservationSystem* app){my_app = app;};
    Response *callback(Request *) override;
};

class Wallet : public RequestHandler {
private:
    ReservationSystem* my_app;
public:
    explicit Wallet(ReservationSystem* app){my_app = app;};
    Response *callback(Request *) override;
};

class HotelDetail : public RequestHandler {
private:
    ReservationSystem* my_app;
public:
    explicit HotelDetail(ReservationSystem* app){my_app = app;};
    Response *callback(Request *) override;
};

class AddWallet : public RequestHandler {
private:
    ReservationSystem* my_app;
public:
    explicit AddWallet(ReservationSystem* app){my_app = app;};
    Response *callback(Request *) override;
};
#endif //HOTELRESERVATION_WITH_UI_HANDLERS_HPP
