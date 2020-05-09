#ifndef INHERITANCE_POLYMORPHISM_JSON_JSONSTRING_HPP
#define INHERITANCE_POLYMORPHISM_JSON_JSONSTRING_HPP

#include "JsonElement.hpp"

class JsonString : public JsonElement{
private:
    std::string key;
    std::string value;

public:
    JsonString(int _id, const std::string& _key, const std::string& _value);
    void print(int baseTab);

    std::string getKey();
};


#endif //INHERITANCE_POLYMORPHISM_JSON_JSONSTRING_HPP
