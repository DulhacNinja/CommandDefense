#include <iostream>
#include "Enemy.h"
#include "EnemiesStructures.h"
#include "Wave.h"
#include "Global.h"
using namespace std;

/*
	Design a C++ class that reflects the properties of an wave of  enemies. The class should include the following:
 - methods to set and get the name of the wave
 - methods to set and get the number of enemies  (must be bigger than 0)
 - methods to set and get the starting health (bigger than 0)
 - methods to set and get the money per enemy (must be a float value)


	Create 2 global functions that compare two wave in terms of: number of enemies and money per enemy.
If two waves are equal the return value of such a function will be 0. If the first wave is bigger than the second one, the return value will be 1, otherwise -1.
	Make sure that you have the following:
a cpp file for the methods specific to the class 
a header file for the global functions
a cpp file for the global functions implementation




a main.cpp file that shows how the methods and global functions can be used.

*/
int main_ex2()
{
	// Nume de cartiere periculoase din orasul meu, Bacau
	Wave AlecuRuso, Letea;
	char nume1[] = "Lopatari";
	char nume2[] = "Caldarari";

	AlecuRuso.SetName(nume1);
	Letea.SetName(nume2);

	AlecuRuso.SetMoneyPerEnemy(50.0);
	Letea.SetMoneyPerEnemy(5.5);

	AlecuRuso.SetNumberOfEnemies(20);
	Letea.SetNumberOfEnemies(60);

	AlecuRuso.SetStartingHealth(70);
	Letea.SetStartingHealth(30);

	cout << "Zergii din Alecu Ruso:\n";
	cout << "Nume de meserie de zerg: ";
	cout << AlecuRuso.GetName() << "\n";
	cout << "Bani per zerg: ";
	cout << AlecuRuso.GetMoneyPerEnemy() << "\n";
	cout << "Numar de zergi: ";
	cout << AlecuRuso.GetNumberOfEnemies() << "\n";
	cout << "Viata per zerg: ";
	cout << AlecuRuso.GetStartingHealth() << "\n";

	cout << "\n";

	cout << "Zergii din Letea:\n";
	cout << "Nume de meserie de zerg: ";
	cout << Letea.GetName() << "\n";
	cout << "Bani per zerg: ";
	cout << Letea.GetMoneyPerEnemy() << "\n";
	cout << "Numar de zergi: ";
	cout << Letea.GetNumberOfEnemies() << "\n";
	cout << "Viata per zerg: ";
	cout << Letea.GetStartingHealth() << "\n";
	cout << "\n";

	enum compare
		{
			mai_mic = -1,
			egal,
			mai_mare
		};
	switch (CompareEnemies(Letea, AlecuRuso))
	{
	case mai_mic:
		cout << "Mai multi zergi sunt in wave-ul AlecuRuso \n";
		break;
	case egal:
		cout << "Ambele wave-uri au la fel de multi zergi \n";
		break;
	case mai_mare:
		cout << "Mai multi zergi sunt in wave-ul Letea \n";
	}
	switch (CompareMoney(Letea, AlecuRuso))
	{
	case mai_mic:
		cout << "Mai multi bani au zergii din wave-ul AlecuRuso \n";
		break;
	case egal:
		cout << "Ambele wave-uri au la fel de multi bani per zerg \n";
		break;
	case mai_mare:
		cout << "Mai multi bani au zergii din wave-ul Letea \n";
	}
    return 0;
}