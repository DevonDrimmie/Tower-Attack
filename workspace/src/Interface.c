#include "libs.h"


void startCurses()
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    
    init_pair(3, COLOR_WHITE, COLOR_BLACK);


}

void drawStore() 
{
    clear();
     for (int i = 5; i < 100; i++)    //Draws outline
     {
         mvaddch(5, i, '|');       
         mvaddch(40, i, '|');
     }
     for (int j = 5; j <= 40; j++)
     {
         mvaddch(j, 5, '-');
         mvaddch(j, 100, '-');
     }
     for (int k = 5; k < 100; k++)
     {
        mvaddch(35, k, '-');
     }

     attroff(COLOR_PAIR(1));
     init_pair(2, COLOR_YELLOW, COLOR_BLACK);
     attron(COLOR_PAIR(2));
     attron(A_BOLD | A_BLINK);   //Turn on blinking

     mvprintw(5, 40, "WELCOME TO THE BLACK MARKET!");
     mvprintw(7, 40,  "HIRE ANY GANGSTER YOU WISH");
     attroff(A_BOLD | A_BLINK);
     //attroff(COLOR_PAIR(2));
     //attron(COLOR_PAIR(3));
     mvprintw(9, 7, "1:aka * THUG");
     mvprintw(10, 9, "COST: 5 Coins");
     mvprintw(11, 9, "HEALTH: 50 Hit Points");
     mvprintw(12, 9, "ATTRIBUTES: Plain generic ");
     mvprintw(15, 7,"2: aka @ HENCHMAN");
     mvprintw(16, 9, "COST: 20 Coins");
     mvprintw(17, 9, "HEALTH: 75 Hit Points");
     mvprintw(18, 9, "ATTRIBUTES: Moves 20%% Faster than the Cop Firing Speed.");
     mvprintw(21, 7,"3: aka # GETAWAY DRIVER");
     mvprintw(22, 9, "COST: 30 Coins");
     mvprintw(23, 9, "HEALTH: 30 Hit Points");
     mvprintw(24, 9, "ATTRIBUTES: Fastest Gangster." );
     mvprintw(27, 7,"4: aka & HEAVY");
     mvprintw(28, 9, "COST: 50 Coins");
     mvprintw(29, 9, "HEALTH: 120 Hit Points");
     mvprintw(30, 9, "ATTRIBUTES: Highest Health Of All Gangsters");

     mvprintw(9, 69, "        _              ");
     mvprintw(10, 69, "     .-T |   _    HIRE ");
     mvprintw(11, 69, "     | | |  / |   GANGSTERS");
     mvprintw(12, 69, "     | | | / /`|     .");
     mvprintw(13, 69, "  _  | | |/ / /      .");
     mvprintw(14, 69, "  \\`\\| '.' / /       .");
     mvprintw(15, 69, "   \\ \\`-. '--|       .");
     mvprintw(16, 69, "    \\        |       .");
     mvprintw(17, 69, "     \\  .`  /       TO");
     mvprintw(18, 69, "      |  F |       LIVE");
     mvprintw(19, 69, "      |  R |       LONG");
     mvprintw(20, 69, "      |  E |         &");
     mvprintw(21, 69, "      |  E |       PROSPER");
     mvprintw(22, 69, "      |  D |      ");
     mvprintw(23, 69, "      |  O |      ");
     mvprintw(24, 69, "      |  M |      ");

     mvprintw(34, 7, "Enter Gangster Number and Amount (ex: 1x5) OR Type \"play\" to Proceed!");
}

void drawInstructions()
{
    attron(A_BOLD);
    mvprintw(9,15,"                  PRISON BREAK INSTRUCTIONS  ");
    attroff(A_BOLD);
    mvprintw(11,15," OBJECTIVE: Get a member of your Gang to the Escape Zone.");
    mvprintw(12,15," * You start out with 150 coins, which can be used to purchase            ");
    mvprintw(13,15,"   Gangsters from the Black Market.                                ");
    mvprintw(14,15," * Once you have bought Gangsters, entering \"play\" will begin the game.    ");
    mvprintw(15,15," * You will need to strategically spawn Gangsters using Keys:");
    mvprintw(16,15,"       (1) Thug | (2) Henchman | (3) Getaway Driver | (4) Heavy  ");
    mvprintw(17,15," * The Cops will try to stop your Gang from reaching the Escape Zone by firing at them.");
    mvprintw(18,15," * The Level is won when a member of your Gang reaches the Escape Zone.");
    mvprintw(19,15," * Once all the levels are won, the Prison Break is complete.");
    mvprintw(21,15,"           PRESS ANY KEY TO ENTER THE BLACK MARKET");
    move(0,0);
}

void drawStart() 
{
    mvprintw(10,15,"  *****  *****   *  *****  *****  *****    ");
    mvprintw(11,15,"  *   *  *   *   *  *      *   *  *   *    ");
    mvprintw(12,15,"  *****  *****   *  *****  *   *  *   *    ");
    mvprintw(13,15,"  *      *   *   *      *  *   *  *   *    ");
    mvprintw(14,15,"  *      *   **  *  *****  *****  *   *    ");
    mvprintw(15,15,"");
    mvprintw(16,15,"   *****  *****   *****  *****  *   *    ");
    mvprintw(17,15,"   *   *  *   *   *      *   *  * *      ");
    mvprintw(18,15,"   *****  *****   *****  *****  *        ");
    mvprintw(19,15,"   *   *  *   *   *      *   *  * *      ");
    mvprintw(20,15,"   *****  *   **  *****  *   *  *   *    ");
    mvprintw(21,15,"  ");
    mvprintw(22,15,"     PRESS ANY KEY TO CONTINUE");
    mvprintw(23,15,"  ");    
    move(0,0);
}

void drawLevelWin()
{
    mvprintw(10,15,"*      *****  *     *  *****  *           ");
    mvprintw(11,15,"*      *      *     *  *      *           ");
    mvprintw(12,15,"*      *****   *   *   *****  *           ");
    mvprintw(13,15,"*      *        * *    *      *           ");
    mvprintw(14,15,"*****  *****     *     *****  *****       ");
    mvprintw(15,15,"");
    mvprintw(16,15,"   *****  *****   *****  *****  *  *      ");
    mvprintw(17,15,"   *   *  *       *   *    *    *  *      ");
    mvprintw(18,15,"   *****  *****   *****    *    *  *      ");
    mvprintw(19,15,"   *   *  *       *   *    *              ");
    mvprintw(20,15,"   *****  *****   *   *    *    *  *      ");
    mvprintw(22,15,"     PRESS ANY KEY TO CONTINUE");    
}

char drawLevelLost()
{
    char option;
    
    mvprintw(10,15,"*      *****  *     *  *****  *            ");
    mvprintw(11,15,"*      *      *     *  *      *            ");
    mvprintw(12,15,"*      *****   *   *   *****  *            ");
    mvprintw(13,15,"*      *        * *    *      *            ");
    mvprintw(14,15,"*****  *****     *     *****  *****        ");
    mvprintw(15,15,"");
    mvprintw(16,15,"   *      *****   *****  *****  *  *       ");
    mvprintw(17,15,"   *      *   *   *        *    *  *       ");
    mvprintw(18,15,"   *      *   *   *****    *    *  *       ");
    mvprintw(19,15,"   *      *   *       *    *               ");
    mvprintw(20,15,"   *****  *****   *****    *    *  *       ");
    mvprintw(22,15,"      RE TRY LEVEL? (Y/N)");
    
    option = getch();
    
    return(option);
}

char drawGameLost()
{
    char option;

    mvprintw(10,15,"*****  *****  *     *  *****               ");
    mvprintw(11,15,"*      *   *  * * * *  *                   ");
    mvprintw(12,15,"*  **  *****  *  *  *  *****               ");
    mvprintw(13,15,"*   *  *   *  *     *  *                   ");
    mvprintw(14,15,"*****  *   *  *     *  *****               ");
    mvprintw(15,15,"");
    mvprintw(16,15,"   *****  *     *  *****  *****   *        ");
    mvprintw(17,15,"   *   *  *     *  *      *   *   *        ");
    mvprintw(18,15,"   *   *   *   *   *****  *****   *        ");
    mvprintw(19,15,"   *   *    * *    *      *   *            ");
    mvprintw(20,15,"   *****     *     *****  *   **  *        ");
    mvprintw(22,15,"        PLAY AGAIN? (Y/N)");

    option = getch();

    return(option);  
}

char drawGameWin()
{
    char option;

    mvprintw(10,15,"*****  *****  *****  *****    *****   *****  *****  *****  *  *   ");
    mvprintw(11,15,"*      *   *  *   *  *        *   *   *   *    *    *      *  *   ");
    mvprintw(12,15,"*      *   *  *   *  *  **    *****   *****    *    *****  *  *   ");
    mvprintw(13,15,"*      *   *  *   *  *   *    *   *   *   *    *        *         ");
    mvprintw(14,15,"*****  *****  *   *  *****    *   **  *   *    *    *****  *  *   ");
    mvprintw(15,15,"");
    mvprintw(16,15,"        *   *  *****  *   *    *****  *****   *****        ");
    mvprintw(17,15,"         * *   *   *  *   *    *   *  *   *   *            ");
    mvprintw(18,15,"          *    *   *  *   *    *****  *****   *****        ");
    mvprintw(19,15,"          *    *   *  *   *    *   *  *   *   *            ");
    mvprintw(20,15,"          *    *****  *****    *   *  *   **  *****        " );
    mvprintw(22,15,"");
    mvprintw(23,15,"             *****  *****   *****  *****  *  *              ");
    mvprintw(24,15,"             *      *   *   *      *      *  *      ");
    mvprintw(25,15,"             *****  *****   *****  *****  *  *           ");
    mvprintw(26,15,"             *      *   *   *      *              ");
    mvprintw(27,15,"             *      *   **  *****  *****  *  *         ");
    mvprintw(28,15,"");
    mvprintw(29,15,"                   PLAY AGAIN? (Y/N)");

    option = getch();

    return(option);  
}

void getInfo(int * gangsterSelection)    //made a change from int to void.
{
    int i = 0; 
    int increase = 0;
    char buffer[MAXBUFFERSIZE];
    char * token;
    char * tempType;
    char * tempAmount;

    while ((strncmp(buffer, "play", 10) != 0) || (gangsterSelection[CHOSE_THUG] + gangsterSelection[CHOSE_HENCHMAN] 
             + gangsterSelection[CHOSE_GETAWAY_DRIVER] + gangsterSelection[CHOSE_HEAVY])== 0)
    {
        if (coins < 5)    // If they don't have enough coins, give them a message.
        {
            mvprintw(YERROR, XERROR, "NO MORE FUNDS, PLEASE CONTINUE TO GAME PLAY");
        }
        mvprintw(36, 78,"                     ");
        mvprintw(37, 7,"                     ");
        tempType = malloc(sizeof(char) * PART_SIZE);
        assert(tempType != NULL);
        tempAmount = malloc(sizeof(char) * PART_SIZE);
        assert(tempAmount != NULL);
    

        mvprintw(36, 78,"Coins available: %d", coins);
        mvprintw(YINVENTORY, XINVENTORY,"YOUR INVENTORY");
        mvprintw(YINVENTORY + 1, XINVENTORY,"THUGS: %d HENCHMAN: %d", gangsterSelection[CHOSE_THUG], gangsterSelection[CHOSE_HENCHMAN]);
        mvprintw(YINVENTORY + 2, XINVENTORY,"GETAWAY DRIVER: %d HEAVY: %d", gangsterSelection[CHOSE_GETAWAY_DRIVER], gangsterSelection[CHOSE_HEAVY]);
        
        move(37,7);

        getnstr(buffer, 10);

        if (strncmp(buffer, "play", 10) == 0)  //check to see if the game is over.
        {
            continue;
        }

        token = strtok(buffer, "x");   //Delimiter.
        if (token != NULL) 
        {
            strcpy(tempType, token);
        }
        token = strtok(NULL, "\0");
        if (token != NULL)
        {
            strcpy(tempAmount, token);
        }

        i = parse(tempType, tempAmount, &coins);  // i takes in which gangster was add to.
    
        if (i < WRONG_SELECTION)
        {
            increase = atoi(tempAmount);    //updating the gangster array.
            if (increase != 0)
            {
                gangsterSelection[i] += increase;
            }
        }
        refresh();
        free(tempType);
        free(tempAmount);
    }
    return;
}

void removeNewline(char buffer[])
{
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
        }
    }  
}

int parse(char * tempType, char * tempAmount, int * coins)
{
    int totalPrice = 0;
    int tempLoad = 0;
    mvprintw(YERROR, XERROR, "                                                 ");

    if (strcmp(tempType,"1") == 0)
    {
        tempLoad = atoi(tempAmount);
        if (tempLoad >= 0)
        {
            totalPrice = THUG_PRICE * tempLoad;
            if (totalPrice <= *coins)
            {
                *coins = *coins - totalPrice;
                return(CHOSE_THUG);
            }
            else
            {
                mvprintw(YERROR,XERROR,"NOT Enough Coins!");
            }
        }
        else
        {
            mvprintw(YERROR, XERROR,"Invalid Purchase Try Again");
        }
    }
    else if (strcmp(tempType,"2") == 0)
    {
        tempLoad = atoi(tempAmount);
        if (tempLoad >= 0)
        {
            totalPrice = HENCHMAN_PRICE * tempLoad;
            //mvprintw(1,1,"%d", totalPrice);
            if (totalPrice <= *coins)
            {
                *coins = *coins - totalPrice;
                return(CHOSE_HENCHMAN);
            }
            else
            {
                mvprintw(YERROR,XERROR,"NOT Enough Coins!");
            }
        }
        else{
            mvprintw(YERROR, XERROR,"Invalid Purchase Try Again");
        }
               
    }
    else if (strcmp(tempType,"3") == 0)
    {
        tempLoad = atoi(tempAmount);
        if (tempLoad >= 0)
        {
            totalPrice = GETAWAY_DRIVER_PRICE * tempLoad;
            if (totalPrice <= *coins)
            {
                *coins = *coins - totalPrice;
                return(CHOSE_GETAWAY_DRIVER);
            }
            else
            {
                mvprintw(YERROR,XERROR,"NOT Enough Coins!");
            }
        }
        else{
            mvprintw(YERROR, XERROR,"Invalid Purchase Try Again");
        }  
    }
    else if (strcmp(tempType,"4") == 0)
    {
        tempLoad = atoi(tempAmount);
        if (tempLoad >= 0)
        {
            totalPrice = HEAVY_PRICE * tempLoad;
            if (totalPrice <= *coins)
            {
                *coins = *coins - totalPrice;
                return(CHOSE_HEAVY);
            }
            else
            {
                mvprintw(YERROR,XERROR,"NOT Enough Coins!");
            }
        }
        else{
            mvprintw(YERROR, XERROR,"Invalid Purchase Try Again");
        }        
    }
    else 
    {
        mvprintw(YERROR, XERROR,"Invalid Purchase Try Again");  
    } 
    refresh();
    return(WRONG_SELECTION);
}

void endCurses()
{
    refresh();
    endwin();
}
