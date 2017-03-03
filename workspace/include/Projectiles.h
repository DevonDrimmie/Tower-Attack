#include "libs.h"
//projectiles.h

void deleteProjectile(Projectile * toBeDeleted);

Projectile ** allocateProjectiles();

void renderProjectiles(char ** levelMap, Projectile ** activeProjectiles);

void renderSingleTargetProjectile(char ** levelMap, Projectile * toRender);

void renderSingleRadialProjectile(char ** levelMap, Projectile * toRender);

void launchTargetProjectile(Cop ** policeBarracks, Projectile ** activeProjectiles, char **levelMap);

void launchRadialProjectile(Cop **policeBarracks, Projectile ** activeProjectiles);

Projectile * createNewTargetProjectile(Cop * firingCop, char **levelMap);

Projectile * createNewRadialProjectile(Cop * firingCop, int xOff, int yOff);

void checkCanShoot(Cop **policeBarracks, Projectile **activeProjectiles, int clockCount, char **levelMap);

void removeProjectile(Projectile **activeProjectiles, int index);

void checkAge(Projectile **activeProjectiles, int index);

void checkBoundsForTargetProjectiles(Projectile **activeProjectiles, int index);

void detectCollision(Gangster * toCheck, Projectile ** activeProjectiles);

void createNewBurst(Projectile ** activeProjectiles, Cop * FiringCop);

void insertNewBurstIntoActiveProjectiles(Projectile ** activeProjectiles, Projectile ** burstToInsert);

int determineProjectileVelocity(Projectile * toSet,int direction);
