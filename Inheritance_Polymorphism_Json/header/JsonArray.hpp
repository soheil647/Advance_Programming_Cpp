#ifndef INHERITANCE_POLYMORPHISM_JSON_JSONARRAY_HPP
#define INHERITANCE_POLYMORPHISM_JSON_JSONARRAY_HPP

#include "JsonElement.hpp"
#include "JsonInt.hpp"
#include "JsonString.hpp"
#include "JsonObject.hpp"

class JsonArray : public JsonElement{
private:
    int selfId{};
    std::string key;
    std::vector<JsonElement*> elements;
    std::vector<std::string> allStrings;
    std::vector<int> allInts;
    static int nextID;
public:
    JsonArray(int _id, const std::string& _key);
    void print(int baseTab);
    void addString(int parentId, const std::string& string_key, const std::string& value);
    void addInt(int parentId, const std::string& int_key, int value);
    int getSelfId();

    int addContainer(int parentId, const std::string &string_key, const std::string &type);

    std::vector<JsonElement *> getElements();

    std::string getKey();
};


#endif //INHERITANCE_POLYMORPHISM_JSON_JSONARRAY_HPP
