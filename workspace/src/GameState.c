#include "libs.h"

int winState (List * inPlay)
{
    Gangster * temp;
    /* iterate over the linked list of gangsters*/
    for (int i = 0; i < Size(inPlay); i++)
    {
        /* get the current item*/
        temp = Peek(i, inPlay);
        /* if the x and y are at the end of the map then the player has won */
        if ((getX(temp)==69) && (getY(temp)==6))
        {
            return 1;
        }
        /* else win is false */
    }
    return 0;
}

int lossState (List * inPlay, int inventory[])
{
    /* evaluate if the inPlay array is empty and if the inventory has been exhausted*/
    return Empty(inPlay) && (inventory[0] == 0) && (inventory[1] == 0) && (inventory[2] == 0) && (inventory[3] == 0);
}
