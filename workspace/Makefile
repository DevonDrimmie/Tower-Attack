FLAGS = -std=c99 -Wall -pedantic -Iinclude -g

all: Parse.o CopImplementation.o Draw.o Interface.o GameLoop.o Projectiles.o Linked.o GangsterInterface.o Linked.o GameState.o
	gcc $(FLAGS) src/main.c bin/Parse.o bin/CopImplementation.o bin/Draw.o bin/Interface.o bin/GameLoop.o bin/Projectiles.o bin/GangsterInterface.o bin/Linked.o  bin/GameState.o -lncurses -o bin/exec 

test: GameState.o Linked.o GangsterInterface.o Parse.o Draw.o CopImplementation.o
	gcc $(FLAGS) src/testing.c bin/GameState.o bin/Linked.o bin/GangsterInterface.o bin/Parse.o bin/Draw.o bin/CopImplementation.o -lncurses -o bin/test

Parse.o:  
	gcc $(FLAGS) src/Parse.c -c && mv Parse.o bin

CopImplementation.o: 
	gcc $(FLAGS) -c src/CopImplementation.c && mv CopImplementation.o bin
	
Draw.o:
	gcc $(FLAGS) -c src/Draw.c && mv Draw.o bin

Interface.o:
	gcc $(FLAGS) -c src/Interface.c && mv Interface.o bin

GangsterInterface.o:
	gcc $(FLAGS) -c src/GangsterInterface.c && mv GangsterInterface.o bin
	
GameLoop.o:
	gcc $(FLAGS) -c src/GameLoop.c && mv GameLoop.o bin
	
Projectiles.o:
	gcc $(FLAGS) -c src/Projectiles.c && mv Projectiles.o bin

GameState.o:
	gcc $(FLAGS) -c src/GameState.c && mv GameState.o bin
	
Linked.o:
	gcc $(FLAGS) -c src/Linked.c && mv Linked.o bin
	
clean:
	rm bin/exec bin/*.o
	