#include "JsonBuilder.hpp"
#include <iostream>

int main()
{
    try
    {
        JsonBuilder jsonBuilder;

        jsonBuilder.addStringToObject(0, "color", "red");
        jsonBuilder.addIntegerToObject(0, "diameter", 25);
        int coursesId = jsonBuilder.addContainerToObject(0, "courses", "array");
        jsonBuilder.addStringToArray(coursesId, "AP");
        jsonBuilder.addStringToArray(coursesId, "DM");
        jsonBuilder.addIntegerToArray(coursesId, 5);
        int gradesId = jsonBuilder.addContainerToObject(0, "grades", "array");
        jsonBuilder.addIntegerToArray(gradesId, 20);
        int infoId = jsonBuilder.addContainerToObject(0, "info", "object");
        jsonBuilder.addStringToObject(infoId, "name", "hosna");
        jsonBuilder.addStringToObject(infoId, "email", "hsazarmsa@gmail.com");
        jsonBuilder.print(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

