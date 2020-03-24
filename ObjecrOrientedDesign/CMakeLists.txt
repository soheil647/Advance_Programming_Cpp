cmake_minimum_required(VERSION 3.15)
project(ObjecrOrientedDesign)

set(CMAKE_CXX_STANDARD 11)

add_executable(ObjecrOrientedDesign Source/main.cpp Source/Books.cpp Header/Books.h Source/Authors.cpp Header/Authors.h Source/Reviews.cpp Header/Reviews.h Source/User.cpp Header/User.h Source/Google_read.cpp Header/Google_read.h Source/Follow_edges.cpp Header/Follow_edges.h)