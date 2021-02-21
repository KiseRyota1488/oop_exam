#include <iostream>
#include "Classes.h"
#include <iomanip>

using namespace std;


int main()
{
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
		cout << "\t\tBATTLE\n";
		cout << setw(20) << left << "Archer tower"
			<< "\nAmmo amount: " << setw(20) << left << fortress.ArcherTower::GetAmmoStack() << endl
			<< setw(20) << left << fortress.Catapult::GetLabel()
			<< "\nAmmo amount: " << setw(20) << left << fortress.Catapult::GetAmount() 
			<< right<<"Fortress HP: " << fortress.GetHp() << endl;

		
		
		system("PUASE");
		system("cls");
		
	} while (key != '5');


	cout << "\nCome and play again!";
}
