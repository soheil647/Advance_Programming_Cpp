#include "../JsonBuilder.hpp"

using namespace std;


void JsonBuilder::print(int id) {
//    checkParentId(id);
    cout << "{" << endl;
    for (JsonElement *element : this->elements) {
        if (element->get_id() == id) {
            element->print(1);
        }

    }

    cout << "}" << endl;
}

void JsonBuilder::addStringToObject(int parentId, const std::string &key, const std::string &value) {
    int haveChild = findChildIdString(parentId, key, value);
    if(haveChild == 1)
        return;

    JsonElement *new_element = new JsonString(parentId, key, value);
    this->elements.push_back(new_element);
}

void JsonBuilder::addIntegerToObject(int parentId, const std::string &key, int value) {
    int haveChild = findChildIdInt(parentId, key, value);
    if(haveChild == 1)
        return;

    JsonElement *new_element = new JsonInt(parentId, key, value);
    this->elements.push_back(new_element);
}

int JsonBuilder::addContainerToObject(int parentId, const std::string &key, const std::string &type) {

    int childId = findChildIdContainer(parentId, key, type);
    if(childId != -1)
        return childId;

    checkParentId(parentId);
    checkDuplicateKey(key);
    if (type == "object") {
        auto *new_element = new JsonObject(parentId, key);
        this->elements.push_back(new_element);
        return new_element->getSelfId();
    }
    if (type == "array") {
        auto *new_element = new JsonArray(parentId, key);
        this->elements.push_back(new_element);
        return new_element->getSelfId();
    }
    throw undefinedType();
}

void JsonBuilder::addStringToArray(int parentId, const std::string &value) {
   int haveChild = findChildIdString(parentId, "", value);
   if(haveChild == 1)
       return;
   checkParentId(parentId);
}

void JsonBuilder::addIntegerToArray(int parentId, int value) {
    int haveChild = findChildIdInt(parentId, "", value);
    if(haveChild == 1)
        return;
    checkParentId(parentId);
}


int JsonBuilder::addContainerToArray(int parentId, const std::string& type){

    int child = findChildIdContainer(parentId, "", type);
    if(child != -1)
        return child;
    checkParentId(parentId);

    if (type == "object") {
        auto *new_element = new JsonObject(parentId, "");
        this->elements.push_back(new_element);
        return new_element->getSelfId();
    }
    if (type == "array") {
        auto *new_element = new JsonArray(parentId, "");
        this->elements.push_back(new_element);
        return new_element->getSelfId();
    }
    throw undefinedType();
}

void JsonBuilder::checkParentId(int parentId){
    if(elements.empty())
        return;
    for(JsonElement* element : this->elements)
        if (element->get_id() == parentId)
            return;

    throw idException();
}

void JsonBuilder::checkDuplicateKey(const string& key){
    for(JsonElement* element : this->elements)
        if(element->getKey() == key)
            throw duplicateKey();
}

int JsonBuilder::findChildIdContainer(int parentId, const string& key, const string& type){
    for (JsonElement *element : this->elements) {
        if (element->getSelfId() == parentId) {
            int newID = element->addContainer(parentId, key, type);
            return newID;
        }
        for (JsonElement *childElement : element->getElements()) {
            if (childElement->getSelfId() == parentId) {
                int newID = childElement->addContainer(parentId, key, type);
                return newID;
            }
        }
    }
    return -1;
}

int JsonBuilder::findChildIdInt(int parentId, const string& key, int value){
    for (JsonElement *element : this->elements) {
        if (element->getSelfId() == parentId) {
            element->addInt(parentId, key, value);
            return 1;
        }
        for (JsonElement *childElement : element->getElements()) {
            if (childElement->getSelfId() == parentId) {
                childElement->addInt(parentId, key, value);
                return 1;
            }
        }
    }
    return -1;
}

int JsonBuilder::findChildIdString(int parentId, const string& key, const string& value){
    for (JsonElement *element : this->elements) {
        if (element->getSelfId() == parentId) {
            element->addString(parentId, key, value);
            return 1;
        }
        for (JsonElement *childElement : element->getElements()) {
            if (childElement->getSelfId() == parentId) {
                childElement->addString(parentId, key, value);
                return 1;
            }
        }
    }
    return -1;
}