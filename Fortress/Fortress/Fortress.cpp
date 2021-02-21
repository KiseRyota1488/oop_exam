#include <iostream>
#include "Classes.h"
#include <iomanip>
#include <ctime>

using namespace std;



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
		cout << "\t\tBATTLE\n" << setw(20) << left << "Archer tower"
			<< "\nAmmo amount: " << setw(20) << left << fortress.ArcherTower::GetAmmoStack() << endl
			<< setw(20) << left << fortress.Catapult::GetLabel()
			<< "\nAmmo amount: " << setw(20) << left << fortress.Catapult::GetAmount() 
			<< right<<"Fortress HP: " << fortress.GetHp() << endl;

		fortress.ArcherTower::SetAmmoStack();
		int choice = rand() % 2+1;
		switch (choice)
		{
		case 1:
		{
			fortress.ArcherTower::Shoot();
			fortress.ReduceHp(1);
	/		break;
		}
		case 2:
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
		key = '1';
	} while (key != '5');


	cout << "\nCome and play again!";
}
