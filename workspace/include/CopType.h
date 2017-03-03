#include "libs.h"
/*
This struct is just for the Detectives
*/
typedef struct
{
	Coord location;
	char icon;
	int radius;
	int waitTime; //Constant number so we know what value to put it back to after it shoots
	/* canShoot starts at the number of ticks it waits before it shoots (2 for sargent, 4 for Captain) 
	 each time the game ticks, it subtracts 1 from this.  
	 Once this number is 0, the cop shoots and the number is reset to the original value */
	int canShoot;
	int damage;
	Projectile projectiles[16];
}RadialCop;

/*
This struct is for sargents and captains
*/
typedef struct
{
	Coord location;
	char icon;
	int waitTime; //Constant number so we know what value to put it back to after it shoots
	/* canShoot starts at the number of ticks it waits before it shoots (2 for sargent, 4 for Captain) 
	 each time the game ticks, it subtracts 1 from this.  
	 Once this number is 0, the cop shoots and the number is reset to the original value */
	int canShoot; 
	int damage;
	Projectile **projectiles;
}TargetCop;

typedef struct Officer {
	/* We should have 3 separate cops, Detective, Sergeant and Captain instead of rCop and tCop.  More useful */
	TargetCop *Detective;
	RadialCop *Sergeant;
	RadialCop *Captain;
}Cop;
