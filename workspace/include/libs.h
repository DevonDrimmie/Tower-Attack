#ifndef HEADER_FILE
#define HEADER_FILE
#define _BSD_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include <assert.h>
#include "HelpfulUtilities.h"
#include "ProjectileType.h"
#include "CopType.h"
#include "CopInterface.h"
#include "Parse.h"
#include "Interface.h"
#include "Draw.h"
#include "GangsterType.h"
#include "Projectiles.h"
#include "GameLoop.h"
#include "Linked.h"
#include "GameState.h"


#define MAX_LEVEL_HEIGHT 25
#define MAX_LEVEL_WIDTH 94
#define MAX_NUM_COPS 12
#define MAX_NUM_GANGSTERS 30
#define MAX_NUM_PROJECTILES 500

#define MAXBUFFERSIZE 50
#define PART_SIZE 15
#define THUG_PRICE 5
#define HENCHMAN_PRICE 20
#define GETAWAY_DRIVER_PRICE 30
#define HEAVY_PRICE 50
#define WRONG_SELECTION 4
#define CHOSE_THUG 0
#define CHOSE_HENCHMAN 1
#define CHOSE_GETAWAY_DRIVER 2
#define CHOSE_HEAVY 3
#define XERROR 7
#define YERROR 38
#define XINVENTORY 70
#define YINVENTORY 30



int numOfCopsInLevel;
int numOfProjectilesInLevel;
int coins;


int tempCOLLISION;

#endif
