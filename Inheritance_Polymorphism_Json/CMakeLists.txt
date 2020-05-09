cmake_minimum_required(VERSION 3.15)
project(Inheritance_Polymorphism_Json)

set(CMAKE_CXX_STANDARD 11)

add_executable(Inheritance_Polymorphism_Json main.cpp source/JsonBuilder.cpp source/JsonElement.cpp header/JsonElement.hpp source/JsonString.cpp header/JsonString.hpp source/JsonInt.cpp header/JsonInt.hpp source/JsonObject.cpp header/JsonObject.hpp source/JsonArray.cpp header/JsonArray.hpp header/idException.hpp header/duplicateKey.hpp header/undefinedType.hpp)