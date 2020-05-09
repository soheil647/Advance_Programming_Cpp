#ifndef INHERITANCE_POLYMORPHISM_JSON_JSONELEMENT_HPP
#define INHERITANCE_POLYMORPHISM_JSON_JSONELEMENT_HPP

#include <iostream>
#include <string>
#include <vector>

class JsonElement {
private:
    int id{};
    std::vector<int> childIds;

public:
    JsonElement(int _id, int _childId = -1);
    virtual void print(int baseTab) = 0;
    int get_id();
    virtual int getSelfId();
    virtual void addString(int parentId, const std::string &string_key, const std::string &value);
    virtual void addInt(int parentId, const std::string &int_key, int value);
    virtual int addContainer(int parentId, const std::string& key, const std::string& type);
    virtual std::vector<JsonElement*> getElements();
    virtual std::string getKey();
};


#endif //INHERITANCE_POLYMORPHISM_JSON_JSONELEMENT_HPP
