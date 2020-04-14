cmake_minimum_required(VERSION 3.15)
project(FeildsRunner)

set(CMAKE_CXX_STANDARD 11)

add_executable(FeildsRunner source/main.cpp RSDL/src/rsdl.cpp RSDL/src/rsdl.hpp source/Tower.cpp header/Tower.h source/Bullet.cpp header/Bullet.h source/Gattling.cpp header/Gattling.h)