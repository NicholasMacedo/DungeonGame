#ifndef _NMACEDOV_A3H
#define _NMACEDOV_A3H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <curses.h>

struct dungeonRooms
{
    struct dungeonRoomDoors * doorArray;
    struct dungeonRoomItems * itemArray;
    struct heroInfo * heroLoc;
    int roomLength;
    int roomWidth;
    int itemAmount;
    int doorAmount;
    int heroAmount;
    int setupHeroX;
    int setupHeroY;
    int numMonster;
}dungeonRooms;

struct dungeonRoomDoors
{
    char direction;
    int wallLoc;
}dungeonRoomDoors;

struct dungeonRoomItems
{
    char itemType;
    int x;
    int y;
}dungeonRoomItems;

struct heroInfo
{
    int x;
    int y;
}heroInfo;

struct hero
{
    int x;
    int y;
    char actionChar;
    char oldChar;
    int goldAmount;
    int magicAmount;
    int potionAmount;
    int weaponAmount;
    int monsterAmount;
    int healthAmount;
}hero;

/*
 drawDungeonRoom: Used to draw the dungeon room. Used 6 times.
 Pre: Takes in the parsed info struct array, current room number its drawing and a Y and X refrence.
 Post: Draws room to screen and returns nothing because its a void.
*/
void drawDungeonRoom(struct dungeonRooms*, int, int, int);

/**
 drawDungeonRoomsCase: Sets up the drawing functions using a case based on room number in for loop.
 Pre: The dungeonRoomArray for information to pass to drawing functions and roomNumber
 Post: Nothing returned and calls board drawing functions to draw the board.
*/
void drawDungeonRoomsCase(struct dungeonRooms*, int);

/***
 drawDungeonRoomDoor: Draws the dungeon room door's.
 Pre: The dungeonRoomArray for information as to where the doors go roomNumber and the X and Y refrence number.
 Post: nothing is returned but doors are drawn to screen.
*/
void drawDungeonRoomDoor(struct dungeonRooms*, int, int, int);

/****
 drawDungeonRoomItems: Draws the dungeon room items.
 Pre: The dungeonRoomArray for information as to where the items go roomNumber and the X and Y refrence number.
 Post: Nothing is returned and items are drawn to screen.
*/
void drawDungeonRoomItems(struct dungeonRooms*, int, int, int);

/*****
 freeFunction: Frees the previously Malloced space.
 Pre: The dungeonRoomArray to free.
 Post: Nothing is returned and memory is freed.
*/
void freeFunction(struct dungeonRooms*);

/******
 heroActions: Carries out the movement and all the actions after that.
 Pre: The dungeonRoomArray for information (eg Monster) and the currHeroInfo array to house needed information.
 Post: Returns currHeroInfo strucr that houses information needed for the final printf and other mecanics.
*/
struct hero heroActions(struct dungeonRooms*, struct hero);

/*******
 lineParsing: Takes like of file given from main and parses it into the proper struct location and variables.
 Pre: The dungeonRoomArray struct to put the information into, the file line from main and the roomNumber.
 Post: Returns the dungeonRoomArray struct and sorted information into it.
*/
struct dungeonRooms* lineParsing (struct dungeonRooms*, char*, int);

/*********
 mallocFunction: Mallocs the needed space for the program variables.
 Pre: The dungeonRoomArray for mallocing.
 Post: Nothing is returned and mamory is allocated.
*/
void mallocFunction(struct dungeonRooms*);

/**********
 openFile: Opens the file for reading from.
 Pre: File name for opening from argv[1].
 Post: Nothing returned and the file is opened.
*/
FILE* openFile(char *);

/***********
 removeNewLine: Removes new line character from the file line easier for parsing.
 Pre: File line is needed.
 Post: Returns the file line without a newline.
*/
char* removeNewline(char*); //Removes New Line from file.

#endif
