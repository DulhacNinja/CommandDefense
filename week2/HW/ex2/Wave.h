#pragma once

#include "Enemy.h"
#include "EnemiesStructures.h"

class Wave
{
private:
	char name[30];
	int numberOfEnemies;
	int startingHealth;
	float moneyPerEnemy;
public:
	void SetName(char nume[]);
	char* GetName();

	void SetNumberOfEnemies(int number);
	int GetNumberOfEnemies();

	void SetStartingHealth(int number);
	int GetStartingHealth();

	void SetMoneyPerEnemy(float number);
	float GetMoneyPerEnemy();
};
//hai ca dam commit
