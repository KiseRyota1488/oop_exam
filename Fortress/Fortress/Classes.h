#pragma once
#include <iostream>
using namespace std;

class Shooter 
{
private:
	string ammoLabel;
	int ammoAmount = 0;
public:
	Shooter(){}
	Shooter(string ammoLabel, int ammoAmount) : ammoLabel(ammoLabel), ammoAmount(ammoAmount)
	{
	}

	virtual void Shoot() = 0;

	void SetAmount(int value)
	{
		this->ammoAmount = value;
	}

	void SetLabel(string label)
	{
		this->ammoLabel = label;
	}

	int GetAmount()
	{
		return ammoAmount;
	}

	string GetLabel()
	{
		return ammoLabel;
	}

	void ReduceAmmo()
	{
		ammoAmount--;
	}

};

class Archer : public Shooter
{
public:
	Archer(){}
	Archer(string ammoLabel,int ammoAmount) : Shooter(ammoLabel,ammoAmount) 
	{
		this->SetAmount(0);
		this->SetLabel("Archer");
	}
	
	void Shoot() override
	{
		cout << "Archer shooted with arrows\n";
		ReduceAmmo();
	}

};

class Ranger : public Shooter
{
public:
	Ranger() {}
	Ranger(string ammoLabel, int ammoAmount) : Shooter(ammoLabel, ammoAmount)
	{
		this->SetAmount(ammoAmount);
		this->SetLabel(ammoLabel);
	}

	void Shoot() override
	{
		cout << "Ranger shooted with arrows\n";
		ReduceAmmo();
	}

};

class Catapult : public Shooter
{
public:
	Catapult(){}
	Catapult(string ammoLabel, int ammoAmount) : Shooter(ammoLabel, ammoAmount)
	{
		this->SetLabel(ammoLabel);
		this->SetAmount(ammoAmount);
	}

	void Shoot() override
	{
		cout << "Catapult shooted with stones\n";
		ReduceAmmo();
	}

};

class ArcherTower : public Archer, public Ranger
{
private:
	int ammoStack = 0;
public:
	ArcherTower() : Archer() , Ranger()
	{
		Archer("Archer", 0);
		Ranger("Ranger", 0);
	}

	void Shoot() override
	{
		cout << "Archer tower shooted with arrows\n";
		Archer::ReduceAmmo();
		Ranger::ReduceAmmo();
		SetAmmoStack();
	}

	void SetAmmoStack()
	{
		ammoStack = 0;
		ammoStack += Archer::GetAmount() + Ranger::GetAmount();
	}

	int GetAmmoStack()
	{
		return ammoStack;
	}
};

class Fortress : public ArcherTower, public Catapult
{
private:
	int hp = 0;

public:
	Fortress() : ArcherTower(), Catapult()
	{
		ArcherTower();
		
		Catapult("Catapult",0);
		Catapult::SetLabel("Catapult");
	}

	int GetHp()
	{
		return hp;
	}

	void SetHp(int value)
	{
		hp = value;
	}

	void ReduceHp(int value)
	{
		hp-= value;
	}

	void AddAmmo()
	{
		int ammo[3] = { 0 };
		cout << "Enter archer ammo: ";
		cin >> ammo[0];
		cout << "Enter ranger ammo: ";
		cin >> ammo[1];
		cout << "Enter catapult ammo: ";
		cin >> ammo[2];

		Archer::SetAmount(ammo[0]);
		Ranger::SetAmount(ammo[1]);
		Catapult::SetAmount(ammo[2]);

		ArcherTower::SetAmmoStack();
	}

};

