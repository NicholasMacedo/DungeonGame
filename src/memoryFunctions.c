/**************************memoryFunctions.c****************************
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

void mallocFunction(struct dungeonRooms* dungeonRoomArray)
{
    int i;

    for (i=0; i<6; i++)
    {
        dungeonRoomArray[i].doorArray = malloc(sizeof(dungeonRoomDoors)*4);
        dungeonRoomArray[i].itemArray = malloc(sizeof(dungeonRoomItems)*50);
        dungeonRoomArray[i].heroLoc = malloc(sizeof(heroInfo)*2);
    }
    return;
}

void freeFunction(struct dungeonRooms* dungeonRoomArray)
{
    int i;

    for (i=0; i<6; i++)
    {
        free(dungeonRoomArray[i].doorArray);
        free(dungeonRoomArray[i].itemArray);
        free(dungeonRoomArray[i].heroLoc);
    }
    return;
}
