#include "libs.h"
#define _BSD_SOURCE

/* Function to initialize a gangster struct to be a Thug type */
Gangster * initThug ()
{
    Gangster * temp;
    temp = malloc(sizeof(Gangster)*1);
    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    temp->health = 50;
    temp->cost = 5;
    temp->speed =  0.6;
    temp->movement = 0;
    temp->moveBefore = -1;
    temp->icon = '*';
    temp->location.x = 0;
    temp->location.y = 3;
    
    return temp;
}

/* Function to initialize a gangster struct to be a Henchman type */
Gangster * initHenchman ()
{
    Gangster * temp;
    temp = malloc(sizeof(Gangster)*1);
    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    temp->health = 75;
    temp->cost = 20;
    temp->speed =  0.75;
    temp->movement = 0;
    temp->moveBefore = -1;
    temp->icon = '@';
    temp->location.x = 0;
    temp->location.y = 3;   
    
    return temp;  
}

/* Function to initialize a gangster struct to be a Driver type */
Gangster * initDriver ()
{
    Gangster * temp;
    temp = malloc(sizeof(Gangster)*1);
    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    temp->health = 30;
    temp->cost = 30;
    temp->speed =  1.5;
    temp->movement = 0;
    temp->moveBefore = -1;
    temp->icon = '#';
    temp->location.x = 0;
    temp->location.y = 3;   
    
    return temp;
}

/* Function to initialize a gangster struct to be a Heavy type */
Gangster * initHeavy ()
{
    Gangster * temp;
    temp = malloc(sizeof(Gangster)*1);
    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    temp->health = 120;
    temp->cost = 50;
    temp->speed =  0.5;
    temp->movement = 0;
    temp->moveBefore = -1;
    temp->icon = '&'; 
    temp->location.x = 0;
    temp->location.y = 3;
    
    return temp;
}

/* Function to free memory allocated for a gangster struct */
void destroyG (Gangster * G)
{
    free(G);
}

/* Function to return X coordinate from a gangster struct */
int getX (Gangster * G)
{
    return G->location.x;
}

/* Function to return Y coordinate from a gangster struct */
int getY (Gangster * G)
{
    return G->location.y;
}

int getHealth(Gangster * G)
{
    return G->health;
}

/* prints a gangster's properties to the screen */
void printG (Gangster * G)
{
    mvprintw(25,5,"health: %d, cost %d, movement %f, icon %c, speed %f, (%d,%d)\n", G->health, G->cost, G->movement, G->icon, G->speed, G->location.y, G->location.x);
}

float getMove (Gangster * G)
{
    return G->movement;
}

void modMove (Gangster * G)
{
    G->movement += G->speed;
}

void drawGangster(Gangster *G)
{
    init_pair(15, COLOR_RED, COLOR_WHITE);
    attron(COLOR_PAIR(15));
    mvaddch(G->location.y, G->location.x, G->icon);
    attroff(COLOR_PAIR(15));
    //move(0, 0);
}


static void collisionCheck (Gangster * G, char ** levelMap)
{
    int y = getY(G);
    int x = getX(G);
    
    /*
    0: Up
    1: Right
    2: Down
    3: Left
    */
    
    //Check up for an empty space and do not move up if we previously moved down
    if ((levelMap[y-1][x] == '.' && G->moveBefore != 2) || levelMap[y-1][x] == 'Y')
    {
        G->location.y = y-1;
        G->moveBefore = 0;
    }
    //Check down for an empty space and do not move down if we previously moved up
    else if ((levelMap[y+1][x] == '.' && G->moveBefore != 0) || levelMap[y+1][x] == 'Y')
    {
        G->location.y = y+1;
        G->moveBefore = 2;
    }
    //Check right for an empty space and do not move right if we previously moved left
    else if ((levelMap[y][x+1] == '.' && G->moveBefore != 3) || levelMap[y][x+1] == 'Y')
    {
        G->location.x = x+1;
        G->moveBefore = 1;
    }
    //Check left for an empty space and do not move left if we previously moved right
    else if ((levelMap[y][x-1] == '.' && G->moveBefore != 1) || levelMap[y][x-1] == 'Y')
    {
        G->location.x = x-1;
        G->moveBefore = 3;
    }
}

int moveGangster (Gangster * G, char ** levelMap)
{
    // Modify the gangster's movement value
    modMove(G);
    // verify that the unit should be moving during this iteration
    if (getMove(G) > 1.0)
    {
        // subtract 1 from movement to maintain decimal place values 
        G->movement -= 1.0;
        // check the next move and move accordingly
        collisionCheck(G, levelMap);
        return 1;
    }
    else {
        return 0;
    }
    
}
