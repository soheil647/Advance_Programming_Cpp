#include "JsonBuilder.hpp"
#include <iostream>


int main()
{
    try
    {
        JsonBuilder jsonBuilder;
        int ballonId = jsonBuilder.addContainerToObject(0, "ballon", "array");
        jsonBuilder.addStringToArray(ballonId, "red");
        jsonBuilder.addIntegerToArray(ballonId, 25);
        int featuresId = jsonBuilder.addContainerToArray(ballonId, "object");
        jsonBuilder.addStringToObject(featuresId, "shape", "beautiful");
        jsonBuilder.addStringToObject(featuresId, "quality", "perfect material");
        jsonBuilder.addIntegerToObject(featuresId, "ballonRate", 5);
        jsonBuilder.print(featuresId);
        jsonBuilder.print(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
