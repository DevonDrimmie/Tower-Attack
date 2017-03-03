/**************************************************************
Arguments: name of file, as string

Purpose: To create file stream.

Return Values: File pointer on success, NULL on failure.
**************************************************************/
FILE * openFile(char * fileName);


/**************************************************************
Arguments: None.

Purpose: To allocate memory for map.

Return Values: Clean 2D array of chars on success, NULL on malloc failure.
**************************************************************/
char ** allocateLevel(void);


/**************************************************************
Arguments: 2D char array of map

Purpose: To free the memory taken by map.

Return Values: None.
**************************************************************/
void destroyLevel(char ** levelMap);


/**************************************************************
Arguments: 2D malloc'd char array of the map, uninitialized, and a pointer to the config file.

Purpose: To parse the config file contents before the delimeter(just the map, not the cops).

Return Values: On success, returns a 2D char array which represents a level.  On malloc failure, returns null.
**************************************************************/
char ** parseMap(char ** levelMap, FILE * fp);


/**************************************************************
Arguments: 2D char array of a level.

Purpose: To make sure the parse worked.  For testing purposes mainly.

Return Values: None.
**************************************************************/
void printMapTest(char ** levelMap);


/**************************************************************
Arguments: Pointer to config file, and a Malloc'd array of pointers to Cops.

Purpose: To parse the config file AFTER the delimiter has been reached, and populate the 'Cops' array.

Return Values: On success, an array of pointers to Cops. On malloc failure, returns null.
**************************************************************/
Cop ** parseAllCopInfo(FILE * fp, Cop ** policeBarracks);


/**************************************************************
Arguments: String containing pertinent Cop info to be parsed.

Purpose: To parse one line from the config file and organize into a Cop instance.

Return Values: On success, a new Cop instance with relevant info.  On malloc failure, null.
**************************************************************/
Cop * parseSingleCop(char * toParse);


/**************************************************************
Arguments: None.

Purpose: To allocate memory for the Cops.

Return Values: On Success, an array of pointers to Cops, initialized to null.
**************************************************************/
Cop ** allocateCops(void);


/**************************************************************
Arguments: Char type of the Cop to be instantiated, and his x and y coords as ints.

Purpose: To create a new instance of Cop

Return Values: On success, a new pointer to a new Cop with the passed in attributes. On malloc failure, null.
**************************************************************/
Cop * createSingleCop(char type, int xCoord, int yCoord);


/**************************************************************
Arguments: Array of Cops

Purpose: To print contents of all Cops instances.  Mainly for testing purposes.

Return Values: None.
**************************************************************/
void printAllCops(Cop ** policeBarracks);
