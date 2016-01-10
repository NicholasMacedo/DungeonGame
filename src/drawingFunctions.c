/**************************drawingFunctions.c****************************
Student Name: Nicholas Macedo - Van Horne    Student Number: 0889469
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

void drawDungeonRoomsCase(struct dungeonRooms* dungeonRoomArray, int roomNum)
{
    int refY;
    int refX;
    int i;

    //Draws Static Hallways
    for (i=0; i<76; i++)
    {
        if (i < 48)
        {
            mvprintw(i,0,"#");
        }
        mvprintw(28,i,"#");
        mvprintw(56,i,"#");
        mvprintw(0,i,"#");
    }

    //Loops through rooms and calls functions to draw rooms and items.
    for (i=0; i < 6; i ++)
    {
        switch (i)
        {
            case 0:
                refY = 1;
                refX = 1;
                roomNum = 0;
                drawDungeonRoom(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomDoor(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomItems(dungeonRoomArray,roomNum,refY,refX);
                break;

            case 1:
                roomNum = 1;
                refY = 1;
                refX = dungeonRoomArray[0].roomWidth + 7;
                drawDungeonRoom(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomDoor(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomItems(dungeonRoomArray,roomNum,refY,refX);
                break;

            case 2:
                roomNum = 2;
                refY = 1;
                refX = refX + dungeonRoomArray[1].roomWidth + 6;
                drawDungeonRoom(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomDoor(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomItems(dungeonRoomArray,roomNum,refY,refX);
                break;

            case 3:
                roomNum = 3;
                refY = 29;
                refX = 1;
                drawDungeonRoom(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomDoor(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomItems(dungeonRoomArray,roomNum,refY,refX);
                break;

            case 4:
                roomNum = 4;
                refY = 29;
                refX = refX + dungeonRoomArray[3].roomWidth + 6;
                drawDungeonRoom(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomDoor(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomItems(dungeonRoomArray,roomNum,refY,refX);
                break;

            case 5:
                roomNum = 5;
                refY = 29;
                refX = refX + dungeonRoomArray[4].roomWidth + 6;
                drawDungeonRoom(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomDoor(dungeonRoomArray,roomNum,refY,refX);
                drawDungeonRoomItems(dungeonRoomArray,roomNum,refY,refX);
                break;

            default:
                mvprintw(0,0,"#");
        }
    }
    return;
}

void drawDungeonRoom(struct dungeonRooms* dungeonRoomArray, int roomNum, int refY, int refX)
{
    int i;
    int k;
    int tempX = 0;
    int tempY;

    //draw the first line of the room
    mvprintw(refY,refX-1,"#");
    mvaddch(refY,refX,ACS_ULCORNER);

    for (i=1; i != dungeonRoomArray[roomNum].roomWidth + 1; i++)
    {
        mvprintw(refY,i+refX,"#");
        mvaddch(refY,i+refX,ACS_HLINE);
    }
    mvprintw(refY,i+refX,"#");
    mvaddch(refY,i+refX,ACS_URCORNER);
    mvprintw(refY,i+refX+1,"#");

    //draw the walls and center of the room
    for (i=1; i != dungeonRoomArray[roomNum].roomLength + 1; i++)
    {
        mvprintw(i+refY,refX-1,"#");
        mvaddch(i+refY,refX,ACS_VLINE);
        for (k=0; k != dungeonRoomArray[roomNum].roomWidth + 1; k++)
        {
            attron(COLOR_PAIR(6));
            mvprintw(i+refY,k+refX+1,".");
            attroff(COLOR_PAIR(6));
        }
        mvaddch(i+refY,k+refX,ACS_VLINE);
        mvprintw(i+refY,k+refX+1,"#");
    }

    //draw the last line of the room and extends the hallways to the master line
    mvaddch(i+refY,refX,ACS_LLCORNER);
    mvprintw(i+refY+1,refX,"#");
    do
    {
        tempY = i + refY + tempX;
        mvprintw(tempY,refX-1,"#");
        tempX = tempX + 1;
    }while (((tempY > 0) && (tempY <28)) || ((tempY> 28) && (tempY < 56)));

    tempY = 0;
    tempX = 0;

    for (k=1; k < dungeonRoomArray[roomNum].roomWidth + 1; k++)
    {
        mvaddch(i+refY,k+refX,ACS_HLINE);
        mvprintw(i+refY+1,k+refX,"#");
    }
    mvaddch(i+refY,k+refX,ACS_LRCORNER);
    mvprintw(i+refY+1,k+refX,"#");

    do
    {
        tempY = i + refY + tempX;
        mvprintw(tempY,k+refX+1,"#");
        tempX = tempX + 1;
    }while (((tempY > 0) && (tempY <28)) || ((tempY> 28) && (tempY < 56)));

    return;
}

void drawDungeonRoomItems(struct dungeonRooms* dungeonRoomArray, int roomNum, int refY, int refX)
{
    int i;
    refY = refY + 1;
    refX = refX + 1;

    for (i=0;i<dungeonRoomArray[roomNum].itemAmount; i++)
    {
        switch (dungeonRoomArray[roomNum].itemArray[i].itemType)
        {
            case 'g':
                attron(COLOR_PAIR(2));
                mvprintw(refY+dungeonRoomArray[roomNum].itemArray[i].y, refX+dungeonRoomArray[roomNum].itemArray[i].x,"*");
                attroff(COLOR_PAIR(2));
                break;

            case 'M':
                attron(COLOR_PAIR(1));
                mvprintw(refY+dungeonRoomArray[roomNum].itemArray[i].y, refX+dungeonRoomArray[roomNum].itemArray[i].x,"M");
                dungeonRoomArray[0].numMonster ++;
                attroff(COLOR_PAIR(1));
                break;

            case 'm':
                attron(COLOR_PAIR(3));
                mvprintw(refY+dungeonRoomArray[roomNum].itemArray[i].y, refX+dungeonRoomArray[roomNum].itemArray[i].x,"?");
                attroff(COLOR_PAIR(3));
                break;

            case 's':
                attron(COLOR_PAIR(6));
                mvprintw(refY+dungeonRoomArray[roomNum].itemArray[i].y, refX+dungeonRoomArray[roomNum].itemArray[i].x,"%%");
                attroff(COLOR_PAIR(6));
                break;

            case 'w':
                attron(COLOR_PAIR(5));
                mvprintw(refY+dungeonRoomArray[roomNum].itemArray[i].y, refX+dungeonRoomArray[roomNum].itemArray[i].x,")");
                attroff(COLOR_PAIR(5));
                break;

            case 'p':
                attron(COLOR_PAIR(4));
                mvprintw(refY+dungeonRoomArray[roomNum].itemArray[i].y, refX+dungeonRoomArray[roomNum].itemArray[i].x,"!");
                attroff(COLOR_PAIR(4));
                break;

            default:
            mvprintw(0,0,"#");

        }
    }

    for (i=0; i<dungeonRoomArray[roomNum].heroAmount; i++)
    {
        mvprintw(refY+dungeonRoomArray[roomNum].heroLoc[0].y, refX+dungeonRoomArray[roomNum].heroLoc[0].x,"@");
    }

    return;
}

void drawDungeonRoomDoor(struct dungeonRooms* dungeonRoomArray, int roomNum, int refY, int refX)
{
    int i;
    int tempX;
    int tempY;
    
    attron(COLOR_PAIR(6));
    for (i = 0; i < dungeonRoomArray[roomNum].doorAmount; i++)
    {
        switch (dungeonRoomArray[roomNum].doorArray[i].direction)
        {
            case 'n':
                tempY = refY;
                tempX = refX + dungeonRoomArray[roomNum].doorArray[i].wallLoc;
                mvprintw(tempY, tempX, "+");
                break;

            case 's':
                tempY = refY + dungeonRoomArray[roomNum].roomLength + 1;
                tempX = refX + dungeonRoomArray[roomNum].doorArray[i].wallLoc;
                mvprintw(tempY, tempX, "+");
                break;

            case 'e':
                tempY = refY + dungeonRoomArray[roomNum].doorArray[i].wallLoc;
                tempX = refX + dungeonRoomArray[roomNum].roomWidth +1;
                mvprintw(tempY, tempX, "+");
                break;

            case 'w':
                tempY = refY + dungeonRoomArray[roomNum].doorArray[i].wallLoc;
                tempX = refX;
                mvprintw(tempY, tempX, "+");
                break;

            default:
            mvprintw(0,0,"#");

        }
    }
    attroff(COLOR_PAIR(6));
    return;
}
