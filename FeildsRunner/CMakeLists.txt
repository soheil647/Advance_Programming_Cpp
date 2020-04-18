cmake_minimum_required(VERSION 3.15)
project(FeildsRunner)

set(CMAKE_CXX_STANDARD 11)

add_executable(FeildsRunner source/main.cpp RSDL/src/rsdl.cpp RSDL/src/rsdl.hpp source/Tower.cpp header/Tower.h source/Gattling.cpp header/Gattling.h source/Glue.cpp header/Glue.h source/Tesla.cpp header/Tesla.h source/Missile.cpp header/Missile.h source/Enemies.cpp header/Enemies.h source/Runner.cpp header/Runner.h source/Map.cpp header/Map.h source/MapExceptions.cpp header/MapExceptions.h)