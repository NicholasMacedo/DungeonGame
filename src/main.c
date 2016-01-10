/**************************main.c****************************
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

int main(int argc, char * argv[])
{
    //Dec of file that is being opened
    FILE* filePointer;
    char* fileName;
    char* fileLine;
    int roomNum = 0;
    int i;
    struct dungeonRooms * dungeonRoomArray;
    struct hero currHeroInfo;

    //Malloc Space for file parsing the information
    fileLine = malloc(sizeof(char)*150);
    fileName = malloc(sizeof(char)* strlen(argv[1]) + 1);
    dungeonRoomArray = malloc(sizeof(dungeonRooms)*6);
    mallocFunction(dungeonRoomArray);

    //check to see if right number of commandline argurments
    if (argc != 2)
    {
        printf("Wrong number of argurments.\n");
        return(2);
    }

    //sets fileName to argv
    strcpy(fileName,argv[1]);

    filePointer = openFile(fileName);

    //loops through the file until end of file
    while (fgets(fileLine, 150, filePointer) != NULL)
    {
       removeNewline(fileLine);
       dungeonRoomArray = lineParsing(dungeonRoomArray,fileLine,roomNum);
       roomNum = roomNum + 1;
    }

    //starts nCurses window when parsing is complete
    initscr();
    noecho();
    cbreak();
    start_color();

    init_pair(1,COLOR_GREEN,COLOR_WHITE);   //Monster Colour
    init_pair(2,COLOR_YELLOW,COLOR_WHITE);  //Gold Colour
    init_pair(3,COLOR_BLUE,COLOR_WHITE);    //Magic Colour
    init_pair(4,COLOR_RED,COLOR_WHITE);     //Potions & Health Colour
    init_pair(5,COLOR_MAGENTA,COLOR_WHITE); //Weapon Colour
    init_pair(6,COLOR_BLACK,COLOR_WHITE);   //Dot Colour

    //Setting initial values for currHeroInfo
    currHeroInfo.actionChar = ' ';
    currHeroInfo.oldChar = '.';
    currHeroInfo.goldAmount = 0;
    currHeroInfo.magicAmount = 0;
    currHeroInfo.potionAmount = 0;
    currHeroInfo.weaponAmount = 0;
    currHeroInfo.monsterAmount = 0;
    currHeroInfo.healthAmount = 6;

    //Draws the rooms to the screen
    mvprintw(58,1,"Hero Health:");
    for (i=0;i<currHeroInfo.healthAmount; i++)
    {
        mvprintw(59,i+1,"&");
    }

    drawDungeonRoomsCase(dungeonRoomArray,roomNum);
    move(2+dungeonRoomArray[0].heroLoc[0].y, 2+dungeonRoomArray[0].heroLoc[0].x);
    refresh();

    //Loops through the game until q or game ending conditions are met.
    while (currHeroInfo.actionChar != 'q')
    {
        currHeroInfo.actionChar = getch();
        currHeroInfo = heroActions(dungeonRoomArray,currHeroInfo);
    }

    //Closes the file and frees the memory used.
    fclose(filePointer);
    free(fileLine);
    free(fileName);
    freeFunction(dungeonRoomArray);
    free(dungeonRoomArray);
    endwin();

    //Prints reasons for game ending to the screen.
    printf("=-=-=-= Hero Stats =-=-=-=\n");
    if (dungeonRoomArray[0].numMonster == 0)
    {
        printf("***WIN*** Congrats on killing all the monsters! ***WIN***\n");
    }
    else if (currHeroInfo.healthAmount < 1)
    {
        printf("***LOSE*** You were slain by a monster! ***LOSE***\n");
    }
    else
    {
        printf("***EXIT***Thanks for playing! ***EXIT***\n");
    }
    printf("Amount of gold collected: %d\n", currHeroInfo.goldAmount);
    printf("Amount of magic scroll(s) collected: %d\n", currHeroInfo.magicAmount);
    printf("Amount of potion(s) collected: %d\n", currHeroInfo.potionAmount);
    printf("Amount of weapon(s) colledted: %d\n", currHeroInfo.weaponAmount);
    printf("Monster(s) Killed: %d\n", currHeroInfo.monsterAmount);
    printf("Hero's Health: %d\n", currHeroInfo.healthAmount);
    return(0);
}
