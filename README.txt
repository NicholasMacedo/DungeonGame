/**************************README.txt****************************
Student Name: Nicholas Macedo - Van Horne    Student Number: 0889469
Date: March 13th 2015                        Course Name: CIS2500
****************************************************************************/
    
    
                    ======Program Information======
    This program uses Rogue information to produce a dungeon looting game. The game must run 
    with terminal in full windowed mode (not small window) with size 10 font in order to see the board. 
    The controlls and symbols directory is below. In order to run the program must be given a file on the
    commandline. This file must house the information for the rooms given in the special format specified.
    More information on the input file to be given below. To win the game without exiting with 'q' kill all
    the monsters or be killed. Program stats are displayed at the end.
    
        
                    ======Running The Program======
    The A3 directory has five sub-directories which are bin,include,assets,docs and src. The bin
    directory houses the runMe, the include houses the a3.h, the docs houses the txt files used for
    testing the program during development and the src houses the .c files.
                                    
    The Source code for the game can be found in the "../A3/src" directory.
    The code is split up in to various .c files. The main function is housed in the 
    file main.c. The other c files contain the functions that are used within the code.
    The many .c files can be opened using the program nano in the correct directory with the command 
    "nano -c <name of C file here>.c" in the LXTerminal.
   
    The program can be compiled using the "make" command in the A3 directory of the game.
    The Makefile houses the compiling commands and can be found in the A3 folder and opened using
    "nano -I Make" on the LXTerminal in the correct directory (../A3).

    The program can be run using the command "./runMe <Location&NameOfFile>" on the command line
    in the LXTerminal after being compiled and changing to the bin foulder inside of
    the etch foulder. (../A3/bin). or using ./bin/runme <Location&NameOfFile> in the A3 foulder (../A3)

    
                    ======Program Use/Commands======
    Program Use/Commands:
      w - Move the character up one place.
      a - Move the character to the left one place.
      s - Move the character down one place.
      d - Move the character right one place.
      q - Exit the program before completing the quest.
     
    Program Symbols:
      * (Yellow)      - Gold to be collected by the hero by walking on it.
      ? (Blue)        - Magic Scroll.
      M (Green)       - Monster for the hero to fight to win the game and for loot.
      % (Black)       - Stairs.
      ! (Red)         - Potions that heal the hero's health bar in the lower left corner.
      @ (Black/White) - Your Hero.
      ) (Magenta)     - A Weapon. You need these to be able to fight the monsters! They are passave and don't do damage if you are 
                       not holding a weapon. Once you are holding a weapon you are able to engage the monsters.

     

                    ======Program Enhancements======
    Hallways - Hallways allow the user to walk the hero to the room to provide the ultimate dungeon explorer feel. 
               There are three rows that are hardcoded in to the max room dimensions and the other hallways are dynamically
               set based on the size of the room.
    Combat   - Combat was implemented by giving the user health (Default at 6 and can increase by 2 using potions). Every time
               the hero moves on an M a random number is generated between 1 and 5 for the monster's attack and is subtracted from
               the hero's health. The monster dies upon encounter with the hero and produces a gold coin as a reward for killing it.
    Colour   - Colour was added for the user to easily understand the UI of the game to enhanse game play and lower the amount of learning
               needed to completely understand the game.
    Item Use - Potions give the player health. Weapons are needed in order to attack the monsters. 

                    ======Program Known Limitations======
    Error in the location of items and doors in the input file. Meaning that if the door is not located in the
    wall then it will not print correctly. The same goes for items. This being that if the item is mistakenly placed
    in the wall or not in the room at all. The program will place the item in the specified place. There is error checking
    for spaces in the input file but not for the actual location given. 
    
    Another Program Limitation is that there cannot be any error in the file entered in the command line. This being the location or if the file
    does not exist. Errors like this might end in a segfault. 