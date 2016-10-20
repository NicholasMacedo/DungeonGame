/**************************gameplayFunctions.c****************************
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

struct hero heroActions(struct dungeonRooms* dungeonRoomArray, struct hero currHeroInfo)
{
    int i;
    int yPos;
    int xPos;
    int oldX;
    int oldY;
    char nextSpot;
    int monsterDMG;

    getyx(stdscr,yPos,xPos);

    oldX = xPos;
    oldY = yPos;

    //Switches off of user input and carries out logic for moving
    switch (currHeroInfo.actionChar)
    {
        case 'w':
            nextSpot = mvinch(yPos - 1,xPos);
            if (nextSpot == '+' || nextSpot == '#' || nextSpot == '.' || nextSpot =='*' || nextSpot == '?' || nextSpot == '%' || nextSpot == '!' || nextSpot == ')')
            {
                yPos = yPos - 1;

                if (nextSpot == '*')
                {
                    currHeroInfo.goldAmount ++;
                }
                else if (nextSpot == '?')
                {
                    currHeroInfo.magicAmount ++;
                }
                else if (nextSpot == '!')
                {
                    currHeroInfo.healthAmount = currHeroInfo.healthAmount  + 2;
                    currHeroInfo.potionAmount ++;
                }
                else if (nextSpot == ')')
                {
                    currHeroInfo.weaponAmount ++;
                }
                else
                {
                }
            }
            else if ((nextSpot == 'M') && (currHeroInfo.weaponAmount > 0))
            {
                srand(time(NULL));
                monsterDMG = (rand()%5)+1;
                currHeroInfo.healthAmount = currHeroInfo.healthAmount - monsterDMG;
                attron(COLOR_PAIR(2));
                mvprintw(yPos-1,xPos,"*");
                attroff(COLOR_PAIR(2));
                if (currHeroInfo.healthAmount < 1)
                {
                    currHeroInfo.actionChar = 'q';
                }
                dungeonRoomArray[0].numMonster --;
                currHeroInfo.monsterAmount ++;
            }
            else
            {
            }
            break;

        case 'a':
            nextSpot = mvinch(yPos,xPos - 1);
            if (nextSpot == '+' || nextSpot == '#' || nextSpot == '.' || nextSpot =='*' || nextSpot == '?' || nextSpot == '%' || nextSpot == '!' || nextSpot == ')')
            {
                xPos = xPos - 1;
                if (nextSpot == '*')
                {
                    currHeroInfo.goldAmount ++;
                }
                else if (nextSpot == '?')
                {
                    currHeroInfo.magicAmount ++;
                }
                else if (nextSpot == '!')
                {
                    currHeroInfo.healthAmount = currHeroInfo.healthAmount  + 2;
                    currHeroInfo.potionAmount ++;
                }
                else if (nextSpot == ')')
                {
                    currHeroInfo.weaponAmount ++;
                }
                else
                {
                }
            }
            else if ((nextSpot == 'M') && (currHeroInfo.weaponAmount > 0))
            {
                srand(time(NULL));
                monsterDMG = (rand()%5)+1;
                currHeroInfo.healthAmount = currHeroInfo.healthAmount - monsterDMG;
                attron(COLOR_PAIR(2));
                mvprintw(yPos,xPos-1,"*");
                attroff(COLOR_PAIR(2));
                if (currHeroInfo.healthAmount < 1)
                {
                    currHeroInfo.actionChar = 'q';
                }
                dungeonRoomArray[0].numMonster --;
                currHeroInfo.monsterAmount ++;
            }
            else
            {
            }
            break;

        case 's':
            nextSpot = mvinch(yPos+1,xPos);
            if (nextSpot == '+' || nextSpot == '#' || nextSpot == '.' || nextSpot =='*' || nextSpot == '?' || nextSpot == '%' || nextSpot == '!' || nextSpot == ')')
            {
                yPos = yPos + 1;
                if (nextSpot == '*')
                {
                    currHeroInfo.goldAmount ++;
                }
                else if (nextSpot == '?')
                {
                    currHeroInfo.magicAmount ++;
                }
                else if (nextSpot == '!')
                {
                    currHeroInfo.healthAmount = currHeroInfo.healthAmount  + 2;
                    currHeroInfo.potionAmount ++;
                }
                else if (nextSpot == ')')
                {
                    currHeroInfo.weaponAmount ++;
                }
                else
                {
                }
            }
            else if ((nextSpot == 'M') && (currHeroInfo.weaponAmount > 0))
            {
                srand(time(NULL));
                monsterDMG = (rand()%5)+1;
                currHeroInfo.healthAmount = currHeroInfo.healthAmount - monsterDMG;
                attron(COLOR_PAIR(2));
                mvprintw(yPos+1,xPos,"*");
                attroff(COLOR_PAIR(2));
                if (currHeroInfo.healthAmount < 1)
                {
                    currHeroInfo.actionChar = 'q';
                }
                dungeonRoomArray[0].numMonster --;
                currHeroInfo.monsterAmount ++;
            }
            else
            {
            }
            break;

        case 'd':
            nextSpot = mvinch(yPos,xPos + 1);
            if (nextSpot == '+' || nextSpot == '#' || nextSpot == '.' || nextSpot =='*' || nextSpot == '?' || nextSpot == '%' || nextSpot == '!' || nextSpot == ')')
            {
                xPos = xPos + 1;
                if (nextSpot == '*')
                {
                    currHeroInfo.goldAmount ++;
                }
                else if (nextSpot == '?')
                {
                    currHeroInfo.magicAmount ++;
                }
                else if (nextSpot == '!')
                {
                    currHeroInfo.healthAmount = currHeroInfo.healthAmount  + 2;
                    currHeroInfo.potionAmount ++;
                }
                else if (nextSpot == ')')
                {
                    currHeroInfo.weaponAmount ++;
                }
                else
                {
                }
            }
            else if ((nextSpot == 'M') && (currHeroInfo.weaponAmount > 0))
            {
                srand(time(NULL));
                monsterDMG = (rand()%5)+1;
                currHeroInfo.healthAmount = currHeroInfo.healthAmount - monsterDMG;
                attron(COLOR_PAIR(2));
                mvprintw(yPos,xPos+1,"*");
                attroff(COLOR_PAIR(2));
                if (currHeroInfo.healthAmount < 1)
                {
                    currHeroInfo.actionChar = 'q';
                }
                dungeonRoomArray[0].numMonster --;
                currHeroInfo.monsterAmount ++;
            }
            else
            {
            }
            break;

        default:
            mvprintw(0,0,"#");
    }

    for (i=0;i <20; i++)
    {
        mvprintw(59,i+1," ");
    }
    for (i=0;i<currHeroInfo.healthAmount; i++)
    {
        attron(COLOR_PAIR(4));
        mvprintw(59,i+1,"&");
        attroff(COLOR_PAIR(4));
    }

    if (currHeroInfo.oldChar == '*' || currHeroInfo.oldChar == '?' || currHeroInfo.oldChar == '!' || currHeroInfo.oldChar == ')')
    {
        attron(COLOR_PAIR(6));
        mvprintw(oldY,oldX,".");
        attroff(COLOR_PAIR(6));
    }
    else if (currHeroInfo.oldChar == '#')
    {
        mvprintw(oldY,oldX,"%c",currHeroInfo.oldChar);
    }
    else
    {
        attron(COLOR_PAIR(6));
        mvprintw(oldY,oldX,"%c", currHeroInfo.oldChar);
        attroff(COLOR_PAIR(6));
    }
    currHeroInfo.oldChar = mvinch(yPos,xPos);
    mvprintw(yPos,xPos,"@");
    move(yPos,xPos);
    refresh();
    currHeroInfo.y = yPos;
    currHeroInfo.x = xPos;

    if (dungeonRoomArray[0].numMonster == 0)
    {
        currHeroInfo.actionChar = 'q';
    }

    return(currHeroInfo);
}
