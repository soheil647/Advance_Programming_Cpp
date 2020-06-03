#include "JsonBuilder.hpp"
#include <iostream>

int main()
{
    try
    {
        JsonBuilder jsonBuilder;
        int ballonId = jsonBuilder.addContainerToObject(0, "ballon", "array");
        jsonBuilder.addStringToObject(ballonId, "color", "red");
        jsonBuilder.print(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
