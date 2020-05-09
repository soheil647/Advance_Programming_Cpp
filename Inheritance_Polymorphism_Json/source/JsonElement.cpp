#include "../header/JsonElement.hpp"

int JsonElement::get_id() {
    return id;
}

JsonElement::JsonElement(int _id, int _childId) {
    id = _id;
    childIds.push_back(_childId);
}

void JsonElement::addString(int parentId, const std::string &string_key, const std::string &value) {
}

int JsonElement::addContainer(int parentId, const std::string &key, const std::string &type) {

}

int JsonElement::getSelfId() {
    return -1;
}

std::vector<JsonElement *> JsonElement::getElements() {
    return std::vector<JsonElement *>();
}

void JsonElement::addInt(int parentId, const std::string &int_key, int value) {

}

std::string JsonElement::getKey() {
    return "";
}
