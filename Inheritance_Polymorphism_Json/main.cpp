#include "header/JsonBuilder.hpp"

int main()
{
    JsonBuilder jsonBuilder;

    jsonBuilder.addStringToObject(0, "color", "red");
    jsonBuilder.addIntegerToObject(0, "diameter", 25);
    int coursesId = jsonBuilder.addContainerToObject(0, "courses", "array");
    jsonBuilder.addStringToArray(coursesId, "AP");
    jsonBuilder.addStringToArray(coursesId, "DM");
    jsonBuilder.addIntegerToArray(coursesId, 5);
//
    int gradesId = jsonBuilder.addContainerToObject(0, "grades", "array");
    jsonBuilder.addIntegerToArray(gradesId, 20);

    int newid = jsonBuilder.addContainerToArray(gradesId,"array");
    jsonBuilder.addIntegerToArray(newid, 10);
    jsonBuilder.addStringToArray(newid, "DM");

    int infoId = jsonBuilder.addContainerToObject(0, "info", "object");
    jsonBuilder.addStringToObject(infoId, "name", "hosna");
    jsonBuilder.addIntegerToObject(infoId, "score", 2);
    jsonBuilder.addStringToObject(infoId, "email", "hsazarmsa@gmail.com");


    int myId = jsonBuilder.addContainerToObject(infoId, "ss", "object");

    jsonBuilder.addIntegerToObject(myId, "age", 19);
    jsonBuilder.addIntegerToObject(myId, "tt", 2);
    jsonBuilder.addStringToObject(myId, "email", "hsazarmsa@gmail.com");


//    int thisID = jsonBuilder.addContainerToObject(myId, "dd", "object");
//    jsonBuilder.addIntegerToObject(thisID, "tt", 2);

    jsonBuilder.print(0);
}

/*
    result:
    {
        "color": "red",
        "diameter": 25,
        "courses": [
            "AP",
            "DM",
            5
        ],
        "grades": [
            20
        ],
        "info": {
            "name": "hosna",
            "email": "hsazarmsa@gmail.com"
        }
    }
*/