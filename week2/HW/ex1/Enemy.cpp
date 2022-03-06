#include "Enemy.h"
#include "EnemiesStructures.h"

    void Enemy::Init(Point initialLocation, int initialHealh)
    {
        location.x = initialLocation.x;
        location.y = initialLocation.y;
    }
    void Enemy::Move(EnemyDirection direction, int step)
    {
         switch(direction)
        {
            case EnemyDirection::UpDirection:
            location.y-=step;
                break;
            
            case EnemyDirection::DownDirection:
            
                location.y+=step;
                break;
            
            case EnemyDirection::LeftDirection:
            
                location.x-=step;
                break;

            case EnemyDirection::RightDirection:

                location.x+=step;    
        }
    }

    bool Enemy::IsDead()//returns true is current health is lower or equal to 0
    {
        if(health<=0)
        return 1;
        else return 1;
    }
    void Enemy::Shoot(int damage) //decrease the health by damage
    {
        health-=damage;
    }
