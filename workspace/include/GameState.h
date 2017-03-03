/* Given a List * ( of in play elements) determine if any item within the list has reached the end of the level h 7, 71*/
int winState (List * inPlay);

/* Given a List * (in play elements) and array (representative of the inventory) determine if the gameloop should stop*/
int lossState (List * inPlay, int inventory[]);
