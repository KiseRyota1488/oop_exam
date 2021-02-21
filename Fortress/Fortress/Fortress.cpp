#include <iostream>
#include "Classes.h"
#include <iomanip>
#include <ctime>

using namespace std;

enum Classes
{
	ArcherTower = 1,
	Catapult
};

int main()
{
	srand(time(0));
	Fortress fortress;

	cout << "\tBattle preparing ...\n Add ammo for squads\n ...\n";
	fortress.AddAmmo();
	cout << "Enter fortress gate HP: ";
	int hp;
	cin >> hp;
	fortress.SetHp(hp);

	system("cls");

	char key;
	do
	{
		cin >> key;
		cout << "\t\tBATTLE\n" << setw(20) << left << "Archer tower"
			<< "\nAmmo amount: " << setw(20) << left << fortress.ArcherTower::GetAmmoStack() << endl
			<< setw(20) << left << fortress.Catapult::GetLabel()
			<< "\nAmmo amount: " << setw(20) << left << fortress.Catapult::GetAmount() 
			<< right<<"Fortress HP: " << fortress.GetHp() << endl;

		Classes curClass = ArcherTower;

		switch (curClass)
		{
		case ArcherTower:
		{
			fortress.ArcherTower::Shoot();
			fortress.ReduceHp(1);
			break;
		}
		case Catapult:
		{
			fortress.Catapult::Shoot();
			fortress.ReduceHp(2);
			break;
		}
		default:
			break;
		}
		
		system("PAUSE");
		system("cls");
		
	} while (key != '5');


	cout << "\nCome and play again!";
}
