#include "libs.h"

int main()
{
    char checkExit;
    //Loop to play again if the user wants
    do
    {
        int level = 1; //For testing this value can be changed, but needs to be 1 for release
        char * levelName[4] = {"", "Level1.txt", "Level2.txt", "Level3.txt"};
        int inventory[4] = {0, 0, 0, 0};
        coins = 150;
        startCurses();
        curs_set(0);
        drawStart();
        getch();
        clear();
        drawInstructions();
        getch();
        clear();
        do
        {
            preGame(&level, levelName[level], inventory);
            //Remove the timeout
            timeout(-1);
            if (level > 0) {
                clear();
                drawLevelWin();
                getch();
                clear();
            }
        } while (0 < level && level < 4);
        clear();
        if (level == -1)
        {
            //The user has lost
            checkExit = drawGameLost();
        } 
        else
        {
            //Exit because the user has won the game
            //(Roll the credits?)
            
            checkExit = drawGameWin();
        }
        drawCredits();
        endCurses();
    } while (checkExit == 'y');
    return 0;
}

