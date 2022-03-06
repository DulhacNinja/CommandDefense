#include "Enemy.h"
#include "EnemiesStructures.h"
#include "Wave.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
void Wave::SetName(char nume[])
{
	strcpy_s(name, nume);
}
char* Wave::GetName()
{
	return name;
}
void Wave::SetNumberOfEnemies(int number)
{
	//how to throw exceptions in c++, ceva cu throw si try si catch, please explain

	numberOfEnemies = number;
}
int Wave::GetNumberOfEnemies()
{
	return numberOfEnemies;
}
void Wave::SetStartingHealth(int number)
{
	//how to throw exceptions in c++, ceva cu throw si try si catch, please explain

	startingHealth = number;
}
int Wave::GetStartingHealth()
{
	return startingHealth;
}
void Wave::SetMoneyPerEnemy(float number)
{
	moneyPerEnemy = number;
}
float Wave::GetMoneyPerEnemy()
{
	return moneyPerEnemy;
}
//hai ca dam commit

