#include "../header/JsonObject.hpp"

using namespace std;

int JsonObject::nextID = 0;

JsonObject::JsonObject(int _id, const std::string &_key) :JsonElement(_id, nextID * 100 + 2) {
    key = _key;
    selfId = nextID * 100 + 2;
    nextID += 1;
}

void JsonObject::print(int baseTab) {
    string tabs;
    for(int i = 0; i < baseTab; i++)
        tabs += "    ";
    if(!key.empty())
        cout << tabs << "\"" << key << "\"" << ": " << "{" << endl;
    else
        cout << tabs << "{" << endl;
    for (JsonElement *element : elements) {
        element->print(baseTab + 1);
    }

    cout << tabs << "}" << endl;
}

void JsonObject::addString(int parentId, const std::string &string_key, const std::string &value) {
    for (JsonElement *element : this->elements) {
        if (element->getSelfId() == parentId) {
            element->addString(parentId, string_key, value);
            return;
        }
    }
    JsonElement* new_element = new JsonString(selfId, string_key, value);
    elements.push_back(new_element);
}

void JsonObject::addInt(int parentId, const std::string &int_key, int value) {
    for (JsonElement *element : this->elements) {
        if (element->getSelfId() == parentId) {
            element->addInt(parentId, key, value);
            return;
        }
    }
    JsonElement* new_element = new JsonInt(selfId, int_key, value);
    elements.push_back(new_element);
}

int JsonObject::getSelfId() {
    return selfId;
}

int JsonObject::addContainer(int parentId, const std::string &container_key, const std::string &type) {
    if(type == "object") {
        auto *new_element = new JsonObject(parentId, container_key);
        this->elements.push_back(new_element);
        return new_element->getSelfId();
    }
    if(type == "array"){
        auto *new_element = new JsonArray(parentId, container_key);
        this->elements.push_back(new_element);
        return new_element->getSelfId();
    }
}

vector<JsonElement *> JsonObject::getElements() {
    return this->elements;
}


string JsonObject::getKey() {
    return this->key;
}