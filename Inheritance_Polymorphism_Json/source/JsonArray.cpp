#include "../header/JsonArray.hpp"

using namespace std;

int JsonArray::nextID = 0;

JsonArray::JsonArray(int _id, const std::string &_key) :JsonElement(_id, -nextID * 100 - 2) {
    key = _key;
    selfId = -nextID * 100 - 2;
    nextID += 1;
}

void JsonArray::addString(int parentId, const std::string &string_key, const std::string &value) {
    for (JsonElement *element : this->elements) {
        if (element->getSelfId() == parentId) {
            element->addString(parentId, string_key, value);
            return;
        }
    }
    allStrings.push_back(value);
}

void JsonArray::addInt(int parentId, const std::string &int_key, int value) {
    for (JsonElement *element : this->elements) {
        if (element->getSelfId() == parentId) {
            element->addInt(parentId, int_key, value);
            return;
        }
    }
    allInts.push_back(value);
}

int JsonArray::getSelfId() {
    return selfId;
}

string JsonArray::getKey() {
    return this->key;
}

int JsonArray::addContainer(int parentId, const std::string &container_key, const std::string &type) {

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
    return -1;
}

void JsonArray::print(int baseTab) {
    string tabs;
    for(int i = 0; i < baseTab; i++)
        tabs += "    ";
    if(!key.empty())
        cout << tabs << "\"" << key << "\"" << ": " << "[" << endl;
    else
        cout << tabs << "[" << endl;
    for(const string& element : allStrings) {
        cout << tabs << "    ";
        cout << "\"";
        cout << element << "\"" << "," << endl;
    }
    for(int element : allInts) {
        cout << tabs << "    ";
        cout << element << "," << endl;;
    }
    for(JsonElement* element : elements) {
        element->print(baseTab+1);
    }
    cout << tabs << "]" << endl;
}

vector<JsonElement *> JsonArray::getElements() {
    return this->elements;
}