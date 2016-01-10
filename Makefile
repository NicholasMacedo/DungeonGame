all:
	gcc -Wall -std=c99 -pedantic src/main.c src/memoryFunctions.c src/drawingFunctions.c src/gameplayFunctions.c src/parsingFunctions.c -Iinclude -o bin/runMe -lncurses -g
