#include "../header/JsonString.hpp"

using namespace std;

JsonString::JsonString(int _id, const std::string &_key, const std::string &_value) : JsonElement(_id){
    this->key = _key;
    this->value = _value;
}


void JsonString::print(int baseTab) {
    string tabs;
    for(int i = 0; i < baseTab; i++)
        tabs += "\t";
    cout << tabs << "\"" << key << "\"" << ": " << "\"" << value << "\"" << "," << endl;
}

string JsonString::getKey() {
    return this->key;
}
