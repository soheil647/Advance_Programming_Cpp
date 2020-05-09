#ifndef INHERITANCE_POLYMORPHISM_JSON_DUPLICATEKEY_HPP
#define INHERITANCE_POLYMORPHISM_JSON_DUPLICATEKEY_HPP

#include <exception>

class duplicateKey: public std::exception {
    const char* what() const throw() override { return "Duplicate key.\n";}
};

#endif //INHERITANCE_POLYMORPHISM_JSON_DUPLICATEKEY_HPP
