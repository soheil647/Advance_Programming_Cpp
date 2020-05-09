#ifndef INHERITANCE_POLYMORPHISM_JSON_JSONINT_HPP
#define INHERITANCE_POLYMORPHISM_JSON_JSONINT_HPP

#include "JsonElement.hpp"

class JsonInt : public JsonElement {
private:
    std::string key;
    int value;
public:
    JsonInt(int _id, const std::string& _key, int _value);
    void print(int baseTab);


    std::string getKey();
};


#endif //INHERITANCE_POLYMORPHISM_JSON_JSONINT_HPP
