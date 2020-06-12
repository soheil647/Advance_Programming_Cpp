cmake_minimum_required(VERSION 3.15)
project(Smart_Hotel_Reservation)

set(CMAKE_CXX_STANDARD 11)

add_executable(Smart_Hotel_Reservation main.cpp source/hotel.cpp header/hotel.hpp source/reservationSystem.cpp header/reservationSystem.hpp source/user.cpp header/user.hpp source/hotelExceptions.cpp header/hotelExceptions.hpp source/room.cpp header/room.hpp source/userReservation.cpp header/userReservation.hpp source/filter.cpp header/filter.hpp source/cityFilter.cpp header/cityFilter.hpp source/starFilter.cpp header/starFilter.hpp source/costFilter.cpp header/costFilter.hpp source/roomFilter.cpp header/roomFilter.hpp source/defaultPriceFilter.cpp header/defaultPriceFilter.hpp source/ratings.cpp header/ratings.hpp source/ratingWeights.cpp header/ratingWeights.hpp)