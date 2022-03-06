#include <iostream>
#include "EnemyController.h"
//can't have 2 main() functions, you silly goose
int main()
{
    Point initialLocation;
    initialLocation.x = 10;
    initialLocation.y = 10;
        
    EnemyController controller;
    controller.Init(10, 2, initialLocation);

    controller.Move();//no enemies yet -> should not do anything

    for (int i = 0; i < 5; i++)
        controller.SpawnEnemy();

    controller.DamageAll();
    controller.DamageAll();
    controller.DamageAll();

    int killed = controller.CountKilledEnemies();
    std::cout << "Killed :" << killed << " enemies" << std::endl;

    controller.Uninit();

    return 0;
}
//hai ca dam commit