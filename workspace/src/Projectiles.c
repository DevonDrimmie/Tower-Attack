#include "libs.h"

//projectiles

//will render all projectiles and update 2D char array.
void renderProjectiles(char ** levelMap, Projectile ** activeProjectiles)
{
    //do we pass in the array of projectiles as well?
    int i;
    //is numOfProjectilesInLevel not the same as MAX_NUM_PROJECTILES?
    for(i = 0; i < numOfProjectilesInLevel; i++)
    {
        if(activeProjectiles[i])
        {
            //a projectile is present at this index.
            //printf("RENDER AT x: %d, y: %d\n", activeProjectiles[i]->xCoord, activeProjectiles[i]->yCoord);
            if(activeProjectiles[i]->age == -1)
            {
                renderSingleTargetProjectile(levelMap, activeProjectiles[i]);
                checkBoundsForTargetProjectiles(activeProjectiles, i);
                
            } else
            {
                renderSingleRadialProjectile(levelMap, activeProjectiles[i]);
                checkAge(activeProjectiles, i);
            }
            
        }
    }
}

 

void renderSingleTargetProjectile(char ** levelMap, Projectile * toRender)
{
    mvaddch(toRender->yCoord, toRender->xCoord, '+');
    
    //toRender->xCoord += toRender->xVelocity;
    //toRender->yCoord += toRender->yVelocity;
    
    toRender->xCoord++;  //should be using velocity here.
    // toRender->yCoord++;
}

void renderSingleRadialProjectile(char **levelMap, Projectile *toRender)
{
    toRender->xCoord += toRender->xVelocity;
    toRender->yCoord += toRender->yVelocity;
    mvaddch(toRender->yCoord, toRender->xCoord, '+');
}

Projectile ** allocateProjectiles()
{
    int i;
    Projectile ** activeProjectiles = NULL;
	activeProjectiles = malloc(sizeof(Projectile*)*MAX_NUM_PROJECTILES);
	
	if(!activeProjectiles)
	{
	    //malloc failure
	    return NULL;
	}
	
    for(i = 0; i < MAX_NUM_PROJECTILES; i++)
    {
        activeProjectiles[i] = NULL;
    }
    
    return activeProjectiles;
}


Projectile * createNewTargetProjectile(Cop * firingCop, char **levelMap)
{
    Projectile * newProjectile = NULL;
    int xLoc = -1;
    //printf("CREATED NEW PROJECTILE!");
    
    newProjectile = malloc(sizeof(Projectile));
    
    if(!newProjectile)
    {
        //malloc failure
        return NULL;
    }
    if(firingCop->Detective)
    {
        newProjectile->xCoord = firingCop->Detective->location.x;
        newProjectile->yCoord = firingCop->Detective->location.y;
        newProjectile->damage = firingCop->Detective->damage;
        //change these QA as you see fit, will make the default projectiles more exciting
        for(int i = 0; i < 69; i++)
        {
            if(levelMap[i][firingCop->Detective->location.y] == '.')
            {
                xLoc = i;
                break;
            }
        }
        if(xLoc > firingCop->Detective->location.x)
        {
            newProjectile->xVelocity = 1;
        } else
        {
            newProjectile->xVelocity = -1;
        }
        newProjectile->yVelocity = 0;
        newProjectile->age = -1;
        numOfProjectilesInLevel++;
    } else
    {
        printf("fatal error in 'createNewTargetProjectile.\n");
        exit(0);
    }
    
    return newProjectile;
}

Projectile * createNewRadialProjectile(Cop * firingCop, int xOff, int yOff)
{
    Projectile * newProjectile = NULL;
    
    newProjectile = malloc(sizeof(Projectile));
    
    if(!newProjectile)
    {
        return NULL;
    }
    if(firingCop->Sergeant)
    {
        newProjectile->xCoord = firingCop->Sergeant->location.x + xOff;
        newProjectile->yCoord = firingCop->Sergeant->location.y + yOff;
        newProjectile->damage = firingCop->Sergeant->damage;
        numOfProjectilesInLevel++;
    } else if(firingCop->Captain)
    {
        newProjectile->xCoord = firingCop->Captain->location.x + xOff;
        newProjectile->yCoord = firingCop->Captain->location.y + yOff;
        newProjectile->damage = firingCop->Captain->damage;
        numOfProjectilesInLevel++;
    } else
    {
        printf("Fatal error in createNewRadialProjectile.\n");
        exit(0);
    }
    
    newProjectile->age = 1;
    newProjectile->xVelocity = 1;  //set these to one for now, talk to Lucas about what they should be
    newProjectile->yVelocity = 1;
    
    return newProjectile;
}


void addNewProjectileToRoster(Projectile ** activeProjectiles, Projectile * newProjectile)
{
    //mvprintw(36,5, "ADDING TO ROSTER. NUM PROJECTILES: %d", numOfProjectilesInLevel);
    int i;
    for(i = 0; i < MAX_NUM_PROJECTILES; i++)
    {
        if(!activeProjectiles[i])
        {
            // mvprintw(i, 50, "newProjectile xLocation: %d newProjectile yLocation: %d", newProjectile->xCoord, newProjectile->yCoord);
            //empty slot found, insert projectile here.
            activeProjectiles[i] = newProjectile;
            break;
        }
    }
}


void launchTargetProjectile(Cop ** policeBarracks, Projectile ** activeProjectiles, char **levelMap)
{
    int i;
    for(i = 0; i < MAX_NUM_COPS; i++)
    {
        if(policeBarracks[i])
        {
            //police present here, find out if right type.
            if(determineCopType(policeBarracks[i]) == 'd')
            {
                //they are the right type.  Fire.
                addNewProjectileToRoster(activeProjectiles, createNewTargetProjectile(policeBarracks[i], levelMap));
            }
        }
    }
}

void launchRadialProjectile(Cop **policeBarracks, Projectile **activeProjectiles)
{
    int i;
    for(i = 0; i < MAX_NUM_COPS; i++)
    {
        if(policeBarracks[i])
        {
            if(determineCopType(policeBarracks[i]) == 's' || determineCopType(policeBarracks[i]) == 'c')
            {
                createNewBurst(activeProjectiles, policeBarracks[i]);
            }
        }
    }
}

void removeProjectile(Projectile **activeProjectiles, int index)
{
    activeProjectiles[index] = NULL;
    numOfProjectilesInLevel--;
}

void checkBoundsForTargetProjectiles(Projectile **activeProjectiles, int index) 
{
    if(activeProjectiles[index]->xCoord < 0 || activeProjectiles[index]->xCoord > 69)
    {
        removeProjectile(activeProjectiles, index);
    }else if (activeProjectiles[index]->yCoord < 0 || activeProjectiles[index]->yCoord > MAX_LEVEL_HEIGHT)
    {
        removeProjectile(activeProjectiles, index);
    }
}

void checkAge(Projectile **activeProjectiles, int index)
{
    if(activeProjectiles[index]->age == 0)
    {
        removeProjectile(activeProjectiles, index);
        return;
    }
    activeProjectiles[index]->age--;
}

void checkCanShoot(Cop **policeBarracks, Projectile **activeProjectiles, int clockCount, char **levelMap)
{
    if(clockCount % 8 == 0)
    {
    //sergeants shoot
        launchRadialProjectile(policeBarracks, activeProjectiles);
        //createNewBurst()
    }
    if(clockCount % 10 == 0)
    {
    //captains shoot
        launchRadialProjectile(policeBarracks, activeProjectiles);
    }
    if(clockCount % 10 == 0)
    {
    //detectives shoot
        launchTargetProjectile(policeBarracks, activeProjectiles, levelMap);
    }
}

void deleteProjectile(Projectile * toBeDeleted)
{
    free(toBeDeleted);
}



void detectCollision(Gangster * toCheck, Projectile ** activeProjectiles)
{
    int i;
    
    //mvprintw(31,5, "MAX_NUM_PROJECTILES: %d", MAX_NUM_PROJECTILES);
    
    for(i = 0; i < MAX_NUM_PROJECTILES; i++) 
    {
        if(activeProjectiles[i])
        {
            //projectile is active.
            if(activeProjectiles[i]->yCoord == toCheck->location.y)
            {
                //they are in the same row.  Now check the column
                if(activeProjectiles[i]->xCoord == toCheck->location.x)
                {
                    //collision detected.
                    //mvprintw(29,5, "COLLISION DETECTED. DAMAGE: %d", activeProjectiles[i]->damage);
                    refresh();
                    toCheck->health -= activeProjectiles[i]->damage;
                    removeProjectile(activeProjectiles, i);
                    //usleep(1300000);
                }
            }
        }
    }
}

void createNewBurst(Projectile ** activeProjectiles, Cop * FiringCop)
{
    Projectile ** singleBurst = NULL;
    int i;
    
    //mvprintw(33,5, "NEW BURST GENERATED.");
    singleBurst = malloc(sizeof(Projectile*)*8);
    
    if(determineCopType(FiringCop) == 'c')
    {
        for(i = 0; i < 8; i++)
        {
            singleBurst[i] = malloc(sizeof(Projectile));
            singleBurst[i]->xCoord = FiringCop->Captain->location.x;
            singleBurst[i]->yCoord = FiringCop->Captain->location.y;
            singleBurst[i]->damage = FiringCop->Captain->damage;
            determineProjectileVelocity(singleBurst[i], i);
            singleBurst[i]->age = 2;
        }
    }
    else
    {
        //sarge
        for(i = 0; i < 8; i++)
        {
            singleBurst[i] = malloc(sizeof(Projectile));
            singleBurst[i]->xCoord = FiringCop->Sergeant->location.x;
            singleBurst[i]->yCoord = FiringCop->Sergeant->location.y;
            determineProjectileVelocity(singleBurst[i], i);
            singleBurst[i]->damage = FiringCop->Sergeant->damage;
            singleBurst[i]->age = 2;
        }
    }
    numOfProjectilesInLevel += 8;
    insertNewBurstIntoActiveProjectiles(activeProjectiles, singleBurst);
}


void insertNewBurstIntoActiveProjectiles(Projectile ** activeProjectiles, Projectile ** burstToInsert)
{
    /*FUNCTION REQUIRES BURST SIZE TO BE 8.  DO NOT CHANGE FUNCTION 'createNewBurst*/
    int i;
    for(i = 0; i < 8; i++)
    {
        addNewProjectileToRoster(activeProjectiles, burstToInsert[i]);
    }
}




int determineProjectileVelocity(Projectile * toSet,int direction)
{
    switch(direction)
    {
        case 0:
            toSet->xVelocity = -1;
            toSet->yVelocity = 0;
        break;
        
        case 1:
            toSet->xVelocity = -1;
            toSet->yVelocity = -1;
        break;
        
        case 2:
            toSet->xVelocity = 0;
            toSet->yVelocity = -1;
        break;
        
        case 3:
            toSet->xVelocity = 1;
            toSet->yVelocity = -1;
        break;
        
        case 4:
            toSet->xVelocity = -1;
            toSet->yVelocity = 1;
        break;
        
        case 5:
            toSet->xVelocity = 1;
            toSet->yVelocity = 0;
        break;
        
        case 6:
            toSet->xVelocity = 1;
            toSet->yVelocity = 1;
        break;
        
        case 7:
            toSet->xVelocity = 0;
            toSet->yVelocity = 1;
        break;
            
        default:
        printf("ERROR in determineProjectileVelocity\n"); 
        exit(0);
    }
    
    return 0;
}
