#include "SSword.h"
#include "KKnight.h"
#include "V3.h"
#include <iostream>

using namespace std;

	void Sword::createSword()
	{
		//initialise knight's sword
		strcpy_s(name, 32, "excalibur");
		damage = 100;
	}
	void Sword::setName(char newName[32])
	{
		strcpy_s(name, 32, newName);
	}

	void Sword::setDamage(int newDamage)
	{
		damage = newDamage;
	}

	void Sword::printSword()
	{
		cout << "He wields " << name << " which deals " << damage << " damage" << endl;
	}
