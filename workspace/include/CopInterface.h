#include "libs.h"

//This function sets up the information for the Detective cop
void initDetective(TargetCop *s, int x, int y);

//This function sets up the information for the Sargent cop
void initSergeant(RadialCop *s, int x, int y);

//This function sets up the information for the Captain cop
void initCaptain(RadialCop *s, int x, int y);

//Returns the character that corresponds to the type of the provided cop
char determineCopType(Cop * toBeTested);
