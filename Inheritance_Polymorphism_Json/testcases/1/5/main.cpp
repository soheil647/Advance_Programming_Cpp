#include "JsonBuilder.hpp"
#include <iostream>

int main()
{
    try
    {
        JsonBuilder jsonBuilder;
        int ballonId = jsonBuilder.addContainerToObject(0, "a", "something");
        jsonBuilder.addStringToObject(0, "a", "b");
        jsonBuilder.print(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
