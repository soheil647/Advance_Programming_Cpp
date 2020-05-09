#include "../header/JsonInt.hpp"

using namespace std;

JsonInt::JsonInt(int _id, const std::string &_key, int _value) : JsonElement(_id){
    key = _key;
    value = _value;
}

void JsonInt::print(int baseTab) {
    string tabs;
    for(int i = 0; i < baseTab; i++)
        tabs += "\t";
    cout << tabs << "\"" << key << "\"" << ": " << value << "," << endl;
}


string JsonInt::getKey() {
    return this->key;
}
