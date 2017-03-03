#include "libs.h"

void drawMap(char ** levelMap)
{
    int i,j,boo,gboo;
    char * currentLine;
    boo = 0;
    gboo = 0;
    currentLine= malloc(sizeof(char) * MAX_LEVEL_WIDTH);
    start_color();
    init_pair(2, COLOR_CYAN, COLOR_CYAN);
    init_pair(3, COLOR_WHITE, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5,COLOR_GREEN, COLOR_GREEN);
    init_pair(6,COLOR_BLACK,COLOR_BLACK);
    init_pair(7,COLOR_YELLOW,COLOR_YELLOW);
    init_pair(8, COLOR_RED, COLOR_BLACK);
    
    for(i = 0; i < MAX_LEVEL_HEIGHT; i++)
    { 
        /*Potential buffer overflow, we will revise this in later QA*/
        strcpy(currentLine,levelMap[i]);
		for(j = 0; j < MAX_LEVEL_WIDTH; j++)
		{
		    if(currentLine[j] == 'o')
		    {
		        attron(COLOR_PAIR(6));
		        mvaddch(i,j,' ');
		        attroff(COLOR_PAIR(6));
		    }else if(currentLine[j] == '-' || currentLine[j] == '|')
		    {
		        attron(COLOR_PAIR(4));
		        mvaddch(i,j,'-');
		        attroff(COLOR_PAIR(4));
		    }else if(currentLine[j] == '.')
		    {
		      	attron(COLOR_PAIR(3));
		      	mvaddch(i,j,' ');
		      	attron(COLOR_PAIR(3));
		    } else if(currentLine[j] == '^')
		    {
		        attron(COLOR_PAIR(5));
		         if(gboo == 0){
		        	mvaddch(i,j,'^');
		        	gboo=1;
		        }
		        else if(gboo == 1){
		        	mvaddch(i,j,' ');
		        	gboo = 0;
		        }
		        attroff(COLOR_PAIR(5));
		    }
		    else if(currentLine[j] == 'Q')
		    {
		        attron(COLOR_PAIR(2));
		        if(boo != 2){
		        	mvaddch(i,j,'~');
		        	boo++;
		        }
		        else if(boo == 2){
		        	mvaddch(i,j,' ');
		        	boo = 0;
		        }
		        attroff(COLOR_PAIR(2));
		    }
		    else if(currentLine[j] == 'm')
		    {
		        attron(COLOR_PAIR(7));
		        mvaddch(i,j,'o');
		        attroff(COLOR_PAIR(7));
		    }
		    else if(currentLine[j] == '*')
		    {
		    	attron(COLOR_PAIR(8));
		        mvaddch(i,j,'*');
		        attroff(COLOR_PAIR(8));
		    }
		    else
		    {
		        attron(COLOR_PAIR(3));
		        mvaddch(i,j,' ');
		        attroff(COLOR_PAIR(3));
		    }
		}
	}
}

void drawAllCops(Cop **toDraw)
{
    for(int i = 0; i < numOfCopsInLevel; i++)
    {
        drawCop(toDraw[i]);
    }
    
    // int i = 0;
    // while(toDraw[i])
    // {
    //     drawCop(toDraw[i++]);
    // }
}

/*
This function draws call the cops that are in the level to the screen
*/
void drawCop(Cop *toDraw)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    if(toDraw->Detective)
    {
        mvaddch(toDraw->Detective->location.y, toDraw->Detective->location.x, toDraw->Detective->icon);
    } else if(toDraw->Sergeant)
    {
        mvaddch(toDraw->Sergeant->location.y, toDraw->Sergeant->location.x, toDraw->Sergeant->icon);
    } else if(toDraw->Captain)
    {
        mvaddch(toDraw->Captain->location.y, toDraw->Captain->location.x, toDraw->Captain->icon);
    }
    attroff(COLOR_PAIR(1));
    //move(20, 20);
}

void drawInventory (int inventory[]) 
{
	/* creates a colour pair of white  text on black background and turns on its use */
	init_pair(69, COLOR_BLACK, COLOR_WHITE);
	attron(COLOR_PAIR(69));
	/* prints the contents of the inventory in a readable way for the user*/
	mvprintw(2,76, "Inventory");
	mvprintw(3,73, "(1) * Thug\t: %d", inventory[0]);
	mvprintw(4,73, "(2) @ Henchman : %d", inventory[1]);
	mvprintw(5,73, "(3) # Driver\t: %d", inventory[2]);
	mvprintw(6,73, "(4) & Heavy\t: %d", inventory[3]);
	attroff(COLOR_PAIR(69));
	
}


void drawCredits()
{
	
	for(int yOff = 50; yOff > -33; yOff--)
	{
		clear();
		mvprintw(yOff, 30,           "Thanks you for playing Prison Break.");
		mvprintw(2 + yOff, 30,       "        Executive Producers:");
		mvprintw(3 + yOff, 30,       "           Lucas Giancola");
		mvprintw(4 + yOff, 30,       "           Benjamin Cecile");
		mvprintw(5 + yOff, 30,       "           Jordan Smith");
		mvprintw(6 + yOff, 30,       "           Dominic Gagné");
		mvprintw(7 + yOff, 30,       "           Haroon Salimi");
		mvprintw(8 + yOff, 30,       "           Munaj Syed");
		mvprintw(9 + yOff, 30,       "           Adnan Ahmed");
		mvprintw(10 + yOff, 30,      "           Mohamed Mohyeldin");
		mvprintw(11 + yOff, 30,      "           Devon Miller");
		mvprintw(13 + yOff, 30,      "        Detectives:");
		mvprintw(14 + yOff, 30,      "           Lucas Giancola");
		mvprintw(15 + yOff, 30,      "           Dominic Gangé");
		mvprintw(17 + yOff, 30,      "        Gangsters:");
		mvprintw(18 + yOff, 30,      "           Jordon Smith");
		mvprintw(19 + yOff, 30,      "           Mohamed Mohyeldin");
		mvprintw(21 + yOff, 30,      "        Game Loop:");
		mvprintw(22 + yOff, 30,      "           Benjamin Cecile");
		mvprintw(23 + yOff, 30,      "           Haroon Salimi");
		mvprintw(24 + yOff, 30,      "           Jordon Smith");
		mvprintw(26 + yOff, 30,      "        Documentation:");
		mvprintw(27 + yOff, 30,      "           Munaj Syed");
		mvprintw(28 + yOff, 30,      "           Adnan Ahmed");
		mvprintw(30 + yOff, 30,      "        Level Creator & Debugger:");
		mvprintw(31 + yOff, 30,      "           Devon Miller");
		refresh();
		timeout(200);
		if (getch() > 0)
		{
			break;
		}
	}
	timeout(-1);
	clear();
}

void displayHealthOfGangsters(List * inPlay, int numGangsters)
{
    int i;
    char icon;
    init_pair(68, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(68));
    Gangster * toView;
    for(i = 0; i < numGangsters; i++)
    {
    	if (i < 17) {
    		mvprintw(7,73, "                ");
    		mvprintw(7,76, "Showing %d/%d", i+1, numGangsters);
	        toView = Peek(i, inPlay);
	        icon = toView->icon;
	        if (icon == '*') 
	        {
	       		mvprintw(8 + i,74, "Thug      %d: %d", i+1,toView->health);
	        }
	        else if (icon == '@')
	        {
	        	mvprintw(8 + i,74, "Henchman  %d: %d", i+1,toView->health);	
	        }
	        else if (icon == '#')
	        {
	        	mvprintw(8 + i,74, "Driver    %d: %d", i+1,toView->health);	
	        }
	        else if (icon == '&') 
	        {
	        	mvprintw(8 + i,74, "Heavy     %d: %d", i+1,toView->health);
	        }
	        //mvprintw(8 + i,73, "Gangster %c %d: %d", i+1,toView->health);
    	}
    	else 
    	{
    		mvprintw(7,73, "                ");
    		mvprintw(7,74, "Showing %d/%d", 17, numGangsters);
    	}
    }
    attroff(COLOR_PAIR(68));
}
