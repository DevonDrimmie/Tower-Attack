 #include "libs.h"

void initDetective(TargetCop *s, int x, int y)
{
    s->location.x = x;
    s->location.y = y;
    s->icon = 'D';
    s->waitTime = 10;
    s->canShoot = 10;
    s->damage = 25;
}

void initSergeant(RadialCop *s, int x, int y)
{
    s->location.x = x;
    s->location.y = y;
    s->icon = 'S';
    s->radius = 2;
    s->waitTime = 3;
    s->canShoot = 3;
    s->damage = 10;
}

void initCaptain(RadialCop *s, int x, int y)
{
    s->location.x = x;
    s->location.y = y;
    s->icon = 'C';
    s->radius = 2;
    s->waitTime = 4;
    s->canShoot = 4;
    s->damage = 15;
}

char determineCopType(Cop * toBeTested)
{
    if(!toBeTested)
    {
        return '!';
    }
    if(toBeTested->Detective)
    {
        return 'd';
    } else if(toBeTested->Sergeant)
    {
        return 's';
    } else if(toBeTested->Captain)
    {
        return 'c';
    } else
    {
        return '!';
    } 
}
