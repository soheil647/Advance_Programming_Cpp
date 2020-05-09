#ifndef INHERITANCE_POLYMORPHISM_JSON_JSONOBJECT_HPP
#define INHERITANCE_POLYMORPHISM_JSON_JSONOBJECT_HPP


#include "JsonElement.hpp"
#include "JsonString.hpp"
#include "JsonInt.hpp"
#include "JsonArray.hpp"

class JsonObject : public JsonElement {
private:
    int selfId{};
    std::string key;
    std::vector<JsonElement*> elements;
    static int nextID;
public:
    JsonObject(int _id, const std::string& _key);
    void print(int baseTab);
    void addString(int parentID, const std::string& string_key, const std::string& value);
    void addInt(int parentId, const std::string& int_key, int value);
    int addContainer(int parentId, const std::string &container_key, const std::string &type);
    int getSelfId();

    std::vector<JsonElement *> getElements();

    std::string getKey();
};


#endif //INHERITANCE_POLYMORPHISM_JSON_JSONOBJECT_HPP
