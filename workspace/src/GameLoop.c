#include "libs.h"

//Everything that needs to happen before the execution, graphical loop
void preGame(int * level, char * levelName, int * inventory)
{
    //Open the file to parse the map
    //Draw the store and get the inventory
    FILE * fp = openFile(levelName);
    
    tempCOLLISION = 0;
    
    char ** levelMap;
    Cop ** policeBarracks;
    Projectile ** activeProjectiles;
    
    activeProjectiles = allocateProjectiles();
    policeBarracks = allocateCops();
    levelMap = allocateLevel();
    levelMap = parseMap(levelMap, fp);
    parseAllCopInfo(fp, policeBarracks);
    
    fclose(fp);
    drawStore();
    getInfo(inventory);
    primaryGameLoop(level, levelMap, policeBarracks, activeProjectiles, inventory);
}

//game loop

void primaryGameLoop(int * level, char ** levelMap, Cop ** policeBarracks, Projectile ** activeProjectiles, int * inventory)
{
    Gangster * tempG = NULL;
    int clockCount = 0;
    List * inPlay = Initialize();
    char input;
    int i; // iterator for LL
      //fixes the store being leftover once game begins -D
    while (!winState(inPlay) && !lossState(inPlay, inventory))
    {
        //Draw the level and draw cop units overtop of it
        clear();
        drawMap(levelMap);
        drawInventory(inventory);
        drawAllCops(policeBarracks);
        // //Move and draw the gangsters on the map
        /*for (i = 0; i < Size(inPlay); i++) {
            tempG = Peek(i, inPlay);
            printG(tempG);
            moveGangster(tempG, levelMap);
            drawGangster(tempG);
            //checks for a collision between tempG and all activeProjectiles.
            //updates tempG's health accordingly.
            tempG->health--;
            tempG->health -= detectCollision(tempG, activeProjectiles);
        }
        //Draw projectiles (shots from police) on the level
        renderProjectiles(levelMap, activeProjectiles);
        //Checks if the clockCount is at a point when any of the cop can shoot
        checkCanShoot(policeBarracks, activeProjectiles, clockCount); 
        
        clockCount++;*/
        //Get the user input for a gangster
        timeout(50);
        input = getch();
        switch (input-'0')
        {
            //Hire a thug
            case 1:
                if (inventory[0] > 0) {
                    Insert(Size(inPlay), initThug(), inPlay);
                    inventory[0]--;
                }
                break;
            
            //Hire a henchman
            case 2:
                if (inventory[1] > 0) {
                    Insert(Size(inPlay), initHenchman(), inPlay);
                    inventory[1]--;
                }
                break;
            
            //Hire a driver
            case 3:
                if (inventory[2] > 0) {
                    Insert(Size(inPlay), initDriver(), inPlay);
                    inventory[2]--;
                }
                break;
            
            //Hire a heavy
            case 4:
                if (inventory[3] > 0) {
                    Insert(Size(inPlay), initHeavy(), inPlay);
                    inventory[3]--;
                }
                break;
            
            default:
                break;
        }
        
        for (i = 0; i < Size(inPlay); i++)
        {
            tempG = Peek(i, inPlay);
            if (getHealth(tempG) <= 0)
            {
                Remove(i, inPlay);
                continue;
            }
            moveGangster(tempG, levelMap);
            drawGangster(tempG);
            //checks for a collision between tempG and all activeProjectiles.
            //updates tempG's health accordingly.
            detectCollision(tempG, activeProjectiles);
        }
        displayHealthOfGangsters(inPlay, Size(inPlay));
        //Draw projectiles (shots from police) on the level
        renderProjectiles(levelMap, activeProjectiles);
        //Checks if the clockCount is at a point when any of the cop can shoot
        checkCanShoot(policeBarracks, activeProjectiles, clockCount, levelMap); 
        
        clockCount++;
        
        //move(tempG->location.y,tempG->location.x);
        //move(0,0);
        refresh();
        usleep(100000);
    }
    
    if (winState(inPlay)) 
    {
        if (*level == 1) coins += 200;
        else if (*level == 2) coins += 300;
        *level += 1;
    }
    else if (lossState(inPlay, inventory)) 
    {
        *level = -1;
    }
    
}



