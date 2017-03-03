#include "../include/libs.h"


FILE * openFile(char * fileName)
{
	FILE * fp = NULL;
	
	numOfCopsInLevel = 0;

	char * pathName = NULL;
	pathName = malloc(sizeof(char)*50);

	if(!pathName)
	{
		//malloc failure
		return NULL;
	}
	/* Buffer overflow? possibly exploitable; says mccaughan*/
	strcpy(pathName, "src/mapConfig/");
	fileName = strcat(pathName, fileName);

	fp = fopen(fileName, "r");

	free(fileName);

	if(!fp)
	{
		return NULL;
	} else {
		return fp;
	}
}


char ** allocateLevel(void)
{
	int i;
	char ** levelMap = NULL;
	levelMap = malloc(sizeof(char*)* MAX_LEVEL_HEIGHT);

	if(!levelMap)
	{
		//malloc failure
		return NULL;
	}

	for(i = 0; i < MAX_LEVEL_HEIGHT; i++)
	{
		levelMap[i] = NULL;
		levelMap[i] = malloc(sizeof(char)* MAX_LEVEL_WIDTH);
		levelMap[i][0] = '\0';
		if(!levelMap[i])
		{
			//malloc failure
			return NULL;
		}
	}
	return levelMap;
}

/*width may not have been freed*/
void destroyLevel(char ** levelMap)
{
	int i;
	for(i = 0; i < MAX_LEVEL_HEIGHT; i++)
	{
		free(levelMap[i]);
	}
	free(levelMap);
}


char ** parseMap(char ** levelMap, FILE * fp)
{
	int lineNum = 0;
	char * inputBuffer = NULL;
	inputBuffer = malloc(sizeof(char) * MAX_LEVEL_WIDTH + 1);
	if(!inputBuffer || !fp)
	{
		//bad file pointer or malloc failure
		return NULL;
	}
	
	while(fgets(inputBuffer, MAX_LEVEL_WIDTH, fp))
	{
		if(strcmp(inputBuffer, "!!!\n") == 0) {
			return levelMap;
		} else
		{
		    strcpy(levelMap[lineNum++], inputBuffer);
		}
	}
	return levelMap;
}

void printMapTest(char ** levelMap)
{
	int i;
	for(i = 0; i < MAX_LEVEL_HEIGHT; i++)
	{
		printf("%s", levelMap[i]);
	}
}


Cop ** parseAllCopInfo(FILE * fp, Cop ** policeBarracks)
{
	if(!fp)
	{
		//bad file pointer 
		return NULL;
	}
	char * inputBuffer = NULL;
	int index = 0;
	inputBuffer = malloc(sizeof(char) * MAX_LEVEL_WIDTH + 1);
    
	while(fgets(inputBuffer, MAX_LEVEL_WIDTH, fp))
	{
		policeBarracks[index++] = parseSingleCop(inputBuffer);
	}
	return policeBarracks;
}


Cop * parseSingleCop(char * toParse)
{
	if(strcmp("\n", toParse) == 0)
	{
		return NULL;
	}
	char * token = NULL;
	token = malloc(sizeof(char)*25);
	char type;
	int xCoord;
	int yCoord;

	token = strtok(toParse, ",");
	type = token[0];

	token = strtok(NULL, ",");
	xCoord = atoi(token);

	token = strtok(NULL, ",");
	yCoord = atoi(token);
	
	numOfCopsInLevel++;

	return createSingleCop(type, xCoord, yCoord);
}


Cop ** allocateCops(void)
{
	int i;
	Cop ** policeBarracks = NULL;
	policeBarracks = malloc(sizeof(Cop*)*MAX_NUM_COPS);
	if(!policeBarracks)
	{
		//malloc failure 
		return NULL;
	}

	for(i = 0; i < MAX_NUM_COPS; i++)
	{
		policeBarracks[i] = NULL;
	}
	return policeBarracks;
}


Cop * createSingleCop(char type, int xCoord, int yCoord)
{
	Cop * newGuy;
	newGuy = malloc(sizeof(Cop));
	if(!newGuy)
	{
		//malloc failure
		return NULL;
	}
	
	newGuy->Detective = malloc(sizeof(TargetCop));
	
    if(type == 'D')
    {
    	newGuy->Detective = malloc(sizeof(TargetCop));
		initDetective(newGuy->Detective, xCoord, yCoord);
		newGuy->Sergeant = NULL;
		newGuy->Captain = NULL;
	} 
	else if(type == 'S')
	{
		newGuy->Sergeant = malloc(sizeof(RadialCop));
		initSergeant(newGuy->Sergeant, xCoord, yCoord);
		newGuy->Detective = NULL;
		newGuy->Captain = NULL;
	} 
	else if(type == 'C')
	{
		newGuy->Captain = malloc(sizeof(RadialCop));
		initCaptain(newGuy->Captain, xCoord, yCoord);
		newGuy->Detective = NULL;
		newGuy->Sergeant = NULL;
	}
	return newGuy;
}

void printAllCops(Cop ** policeBarracks)
{
	int i;

	for(i = 0; i < MAX_NUM_COPS; i++) 
	{
		if(policeBarracks[i]) 
		{
			if(policeBarracks[i]->Detective) 
			{
				printf("Detective: X pos: %d Y pos: %d\n", policeBarracks[i]->Detective->location.x, policeBarracks[i]->Detective->location.y);
			} 
			else if(policeBarracks[i]->Sergeant) 
			{
				printf("Sergeant: X pos: %d Y pos: %d\n", policeBarracks[i]->Sergeant->location.x, policeBarracks[i]->Sergeant->location.y);
			} 
			else if(policeBarracks[i]->Captain)
			{
				printf("Captain: X pos: %d Y pos: %d\n", policeBarracks[i]->Captain->location.x, policeBarracks[i]->Captain->location.y);
			} 
			else {
				printf("Could not find cop type in 'PrintAllCops'");
			}
	    }
	}
}
