#pragma once
#include <iostream>
using namespace std;

class Shooter
{
private:
	string ammoLabel = 0;
	int ammoAmount = 0;
public:
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

};

class Archer : public Shooter
{
public:
	Archer(string ammoLabel,int ammoAmount) : Shooter(ammoLabel,ammoAmount) 
	{
		this->SetLabel("Archer");
	}
	
	void Shoot() override
	{
		cout << "Archer shooted with arrows\n";
	}

};

class Ranger : public Shooter
{
public:
	Ranger(string ammoLabel, int ammoAmount) : Shooter(ammoLabel, ammoAmount)
	{
		this->SetLabel("Ranger");
	}

	void Shoot() override
	{
		cout << "Ranger shooted with arrows\n";
	}

};

class Catapult : public Shooter
{
public:
	Catapult(string ammoLabel, int ammoAmount) : Shooter(ammoLabel, ammoAmount)
	{
		this->SetLabel("Catapult");
	}

	void Shoot() override
	{
		cout << "Catapult shooted with stones\n";
	}

};

class ArcherTower : public Archer, public Ranger
{
private:
	int ammoStack = 0;
public:
	ArcherTower() : Archer(Archer::GetLabel(), Archer::GetAmount()) , Ranger(Ranger::GetLabel(), Ranger::GetAmount())
	{
		ammoStack += Archer::GetAmount() + Ranger::GetAmount();
	}
};

class Fortress : public ArcherTower, public Catapult
{
private:
	int hp;

public:
	Fortress(int archer, int catapult, int ranger) : ArcherTower(), Catapult(Catapult::GetLabel(), Catapult::GetAmount())
	{
		Archer::SetAmount(archer);
		Ranger::SetAmount(ranger);
		Catapult::SetAmount(catapult);
		
	}

	switch()
	{
		
	}

};

