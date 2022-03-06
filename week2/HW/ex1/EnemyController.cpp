#include "EnemyController.h"
#include "Enemy.h" 
// to actualy use the field Enemy declared in the header by forward declaration, we use the field here



void EnemyController::Init(int maximumEnemies, int step, Point initialLocation)
{
    maxEnemies = maximumEnemies;
    stepSize = step;
    startingLocation.x = initialLocation.x;
    startingLocation.y = initialLocation.y;
}
void EnemyController::Uninit()
{
    maxEnemies = 0;
    stepSize = 0;
    startingLocation.x = 0;
    startingLocation.y = 0;
    //delete(enemies);
    //what do I do?
}
void EnemyController::Move()
{
     for(int i=0;i<maxEnemies;i++)
     {
         if(!(enemies[i].IsDead()))
         enemies[i].Move(direction, stepSize);
     }
}
void EnemyController::DamageAll()
{
    for(int i=0;i<maxEnemies;i++)
     {
         if(!(enemies[i].IsDead()))
         enemies[i].Shoot(dmg);
     }
}
//hai ca dam commit
int EnemyController::CountKilledEnemies()
{
    int dead=0;
   for(int i=0;i<maxEnemies;i++)
     {
         if(enemies[i].IsDead())
         dead++;
     } 
     return dead;
}
bool EnemyController::SpawnEnemy() //if it can add the new enemy with ENEMY_HEALTH health value returns true, otherwise false
{
    int alive=0;
   for(int i=0;i<maxEnemies;i++)
     {
         if(!(enemies[i].IsDead()))
         alive++;
     } 
    if(alive<maxEnemies)
    return true;
    return false;
}