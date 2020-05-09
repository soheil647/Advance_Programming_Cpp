#ifndef INHERITANCE_POLYMORPHISM_JSON_UNDEFINEDTYPE_HPP
#define INHERITANCE_POLYMORPHISM_JSON_UNDEFINEDTYPE_HPP

#include <exception>

class undefinedType: public std::exception {
    const char* what() const throw() override { return "Undefined Type.\n";}
};

#endif //INHERITANCE_POLYMORPHISM_JSON_UNDEFINEDTYPE_HPP
