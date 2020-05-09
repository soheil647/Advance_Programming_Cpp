#ifndef INHERITANCE_POLYMORPHISM_JSON_IDEXCEPTION_HPP
#define INHERITANCE_POLYMORPHISM_JSON_IDEXCEPTION_HPP

#include <exception>

class idException: public std::exception {
    const char* what() const throw() override { return "Invalid id.\n";}
};
#endif //INHERITANCE_POLYMORPHISM_JSON_IDEXCEPTION_HPP
