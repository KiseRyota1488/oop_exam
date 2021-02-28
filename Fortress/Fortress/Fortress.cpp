#include <iostream>
#include "Classes.h"
#include <iomanip>
#include <ctime>

using namespace std;

char GameOverCondition(int, int, int);

void PrintMenu(Fortress fortress);

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
		PrintMenu(fortress);

		int choice;
		if (fortress.ArcherTower::GetAmmoStack() > 0 && fortress.Catapult::GetAmount() > 0)
			choice = rand() % 2 + 1;
		else if (fortress.ArcherTower::GetAmmoStack() <= 0 && fortress.Catapult::GetAmount() > 0)
			choice = 2;
		else if (fortress.ArcherTower::GetAmmoStack() > 0 && fortress.Catapult::GetAmount() <= 0)
			choice = 1;
		else
			choice = 3;

		switch (choice)
		{
		case 1:
		{
			fortress.ArcherTower::Shoot();
			fortress.ReduceHp(1);
			break;
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

		key = '1';

		system("PAUSE");
		if (GameOverCondition(fortress.GetAmmoStack(), fortress.Catapult::GetAmount(), fortress.GetHp()) != '3')
		{
			system("cls");
			PrintMenu(fortress);
			switch (GameOverCondition(fortress.GetAmmoStack(), fortress.Catapult::GetAmount(), fortress.GetHp()))
			{
			case '0':
			{
				cout << "\nYou lost. Empire won!\n";
				break;
			}
			case '1':
			{
				cout << "\nEZ. Empire was defeated!\n";
				break;
			}
			case '2':
			{
				cout << "\nEmpire was defeated, but we lost all our soldiers!\n";
				break;
			}
			default:
				break;
			}
			key = '2';
			system("PAUSE");
		}

		system("cls");
	} while (key != '2');

	

}

char GameOverCondition(int archerTowerAmmo, int catapultAmmo, int fortHp)
{
	if (archerTowerAmmo <= 0 && catapultAmmo <= 0 && fortHp > 0)
		return '0';
	else if ((archerTowerAmmo > 0 || catapultAmmo > 0) && fortHp <= 0)
		return '1';
	else if (archerTowerAmmo <= 0 && catapultAmmo <= 0 && fortHp <= 0)
		return '2';
	else
		return '3';
}

void PrintMenu(Fortress fortress)
{
	fortress.ArcherTower::SetAmmoStack();
	cout << "\t\tBATTLE\n" << setw(20) << left << "Archer tower"
		<< "\nAmmo amount: " << setw(20) << left << fortress.ArcherTower::GetAmmoStack() << endl
		<< setw(20) << left << fortress.Catapult::GetLabel()
		<< "\nAmmo amount: " << setw(20) << left << fortress.Catapult::GetAmount()
		<< right << "Fortress HP: " << fortress.GetHp() << endl;
}