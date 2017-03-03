
/* This applies to the following init functions:
 * Requires: the address of a Gangster or a pointer to a Gangster
 * Guarantees: memory allocated with default values for the specific gangster type */
Gangster * initThug ();

Gangster * initHenchman ();

Gangster * initDriver ();

Gangster * initHeavy ();

int getX (Gangster * G);

int getY (Gangster * G);

int getHealth(Gangster * G);

/* Applies to any of the above:
 * Requires: a gangster type that has been allocated
 * Guarantees: memory allocated for a gangster is freed */
void destroyG (Gangster * G);

void printG (Gangster * G);

float getMove(Gangster * G);

void modMove(Gangster * G);

void drawGangster(Gangster * G);

int moveGangster (Gangster *G, char ** levelMap);
