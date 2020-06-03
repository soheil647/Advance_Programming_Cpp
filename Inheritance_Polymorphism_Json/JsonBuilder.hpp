#ifndef __JSON_BUILDER_H__
#define __JSON_BUILDER_H__

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "header/JsonElement.hpp"
#include "header/JsonString.hpp"
#include "header/JsonInt.hpp"
#include "header/JsonObject.hpp"
#include "header/JsonArray.hpp"

#include "header/duplicateKey.hpp"
#include "header/idException.hpp"
#include "header/undefinedType.hpp"

class JsonBuilder
{
private:
    std::vector<JsonElement*> elements;

    void checkParentId(int parentId);
    int findChildIdContainer(int parentId, const std::string &key, const std::string &type);
    int findChildIdInt(int parentId, const std::string &key, int value);
    int findChildIdString(int parentId, const std::string &key, const std::string &value);
    void checkDuplicateKey(const std::string &key);

public:
    JsonBuilder() = default;
    void addStringToObject(int parentId, const std::string& key, const std::string& value);
    void addIntegerToObject(int parentId, const std::string& key, int value);
    int addContainerToObject(int parentId, const std::string& key, const std::string& type);
    void addStringToArray(int parentId, const std::string& value);
    void addIntegerToArray(int parentId, int value);
    int addContainerToArray(int parentId, const std::string& type);
    void print(int id);
};

#endif 