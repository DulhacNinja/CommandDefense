#include "Enemy.h"
#include "EnemiesStructures.h"
#include "Wave.h"
#include "Global.h"

int CompareEnemies(Wave a, Wave b)
{
	if (a.GetNumberOfEnemies() == b.GetNumberOfEnemies())
		return 0;
	else if (a.GetNumberOfEnemies() < b.GetNumberOfEnemies())
		return -1;
	else return 1;
}
int CompareMoney(Wave a, Wave b)
{
	if (a.GetMoneyPerEnemy() == b.GetMoneyPerEnemy())
		return 0;
	else if (a.GetMoneyPerEnemy() < b.GetMoneyPerEnemy())
		return -1;
	else return 1;
}