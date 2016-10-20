/**************************parsingFunctions.c****************************
Student Name: Nicholas Macedo              Student Number: 
Date: March 13th 2015                      Course Name: CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/
#include "a3.h"

FILE* openFile(char * fileName)
{
    FILE* filePointer = fopen(fileName,"r");
    if (filePointer == NULL)
    {
        printf("Cannot open the file %s\n", fileName);
        exit(1);
    }
    return(filePointer);
}

char* removeNewline(char* fileLine)
{
    int i;
    int fileLineLen;

    fileLineLen = strlen(fileLine);

    for (i = 0; i < fileLineLen; i++)
    {
        if (fileLine[i] == '\n')
        {
            fileLine[i] = '\0';
        }
    }

    return(fileLine);
}

struct dungeonRooms* lineParsing(struct dungeonRooms* dungeonRoomArray, char * fileLine, int roomNum)
{
    char * tempStr;
    int doorNum = 0;
    int itemNum = 0;
    int heroNum = 0;

    doorNum = dungeonRoomArray[roomNum].doorAmount;
    itemNum = dungeonRoomArray[roomNum].itemAmount;
    heroNum = dungeonRoomArray[roomNum].heroAmount;

    tempStr = strtok(fileLine, " ");

    //Tokenizes on spaces and looks at first part of string for sorting into proper catagory
    while (tempStr != NULL)
    {
        switch (tempStr[0])
        {
            case 'd':
                sscanf(tempStr,"d%c%d", &dungeonRoomArray[roomNum].doorArray[doorNum].direction, &dungeonRoomArray[roomNum].doorArray[doorNum].wallLoc);
                doorNum = doorNum + 1;
                break;

            case 'g':
                sscanf(tempStr,"g%d,%d", &dungeonRoomArray[roomNum].itemArray[itemNum].x, &dungeonRoomArray[roomNum].itemArray[itemNum].y);
                dungeonRoomArray[roomNum].itemArray[itemNum].itemType = 'g';
                itemNum = itemNum + 1;
                break;

            case 'M':
                 dungeonRoomArray[roomNum].itemArray[itemNum].x = 0;
                 dungeonRoomArray[roomNum].itemArray[itemNum].y = 0;
                sscanf(tempStr,"M%d,%d", &dungeonRoomArray[roomNum].itemArray[itemNum].x, &dungeonRoomArray[roomNum].itemArray[itemNum].y);
                dungeonRoomArray[roomNum].itemArray[itemNum].itemType = 'M';
                itemNum = itemNum + 1;
                break;

            case 'm':
                sscanf(tempStr,"m%d,%d", &dungeonRoomArray[roomNum].itemArray[itemNum].x, &dungeonRoomArray[roomNum].itemArray[itemNum].y);
                dungeonRoomArray[roomNum].itemArray[itemNum].itemType = 'm';
                itemNum = itemNum + 1;
                break;

            case 's':
                sscanf(tempStr,"s%d,%d", &dungeonRoomArray[roomNum].itemArray[itemNum].x, &dungeonRoomArray[roomNum].itemArray[itemNum].y);
                dungeonRoomArray[roomNum].itemArray[itemNum].itemType = 's';
                itemNum = itemNum + 1;
                break;

            case 'w':
                sscanf(tempStr,"w%d,%d", &dungeonRoomArray[roomNum].itemArray[itemNum].x, &dungeonRoomArray[roomNum].itemArray[itemNum].y);
                dungeonRoomArray[roomNum].itemArray[itemNum].itemType = 'w';
                itemNum = itemNum + 1;
                break;

            case 'p':
                sscanf(tempStr,"p%d,%d", &dungeonRoomArray[roomNum].itemArray[itemNum].x, &dungeonRoomArray[roomNum].itemArray[itemNum].y);
                dungeonRoomArray[roomNum].itemArray[itemNum].itemType = 'p';
                itemNum = itemNum + 1;
                break;

            case 'h':
                sscanf(tempStr,"h%d,%d", &dungeonRoomArray[roomNum].heroLoc[0].x, &dungeonRoomArray[roomNum].heroLoc[0].y);
                heroNum = heroNum +1;
                break;

            case ' ':
                break;

            default:
                sscanf(tempStr,"%dX%d", &dungeonRoomArray[roomNum].roomWidth, &dungeonRoomArray[roomNum].roomLength);
        }

        tempStr = strtok(NULL, " ");
    }

    dungeonRoomArray[roomNum].doorAmount = doorNum;
    dungeonRoomArray[roomNum].itemAmount = itemNum;
    dungeonRoomArray[roomNum].heroAmount = heroNum;
    return(dungeonRoomArray);
}
