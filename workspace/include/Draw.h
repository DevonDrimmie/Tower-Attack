/*Takes the 2d array of the map and prints it out to the Ncurses screen*/
void drawMap(char ** parseOutput);

/*
Function: Takes in an array of cops that need to be drawn to the map and draws them
Params:
    -toDraw: The array of cops to draw
    -numOfCops: The number of cops in the array
*/
void drawAllCops(Cop **toDraw);

/*
Function: Takes in a single cop and draws it to  the screen */
void drawCop(Cop *toDraw);

/*
Function: Takes in an array that is representative of the player's inventory
that is, an array that is representative of the number of units (gangsters) a player can play*/
void drawInventory (int inventory[]);

void displayHealthOfGangsters(List * inPlay, int numGangsters);

void drawCredits();
