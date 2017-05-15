#include "KKnight.h"
#include "SSword.h"
#include "V3.h"
#include <iostream>

using namespace std;

	void Knight::createKnight()
	{

		//initialise my knight
		strcpy_s(name, 32, "Arthur");
		health = 1000;
		level = 100;
		position = { 5.0f, 3.0f };
		sword.createSword();
	}

	void Knight::printKnight()
	{
		cout << "Brave " << name << " stands before you!" << endl;
		cout << "He has " << health << " health. He is level " << level << endl;
		cout << "His position is " << position.x << ", " << position.y << endl;
		sword.printSword();
		cout << endl;
	}

	void Knight::setName(char newName[32])
	{
		strcpy_s(name, 32, newName);
	}

	void Knight::doDmagae(int damage)
	{
		if (damage > 0)
			health -= damage;
	}

	void Knight::setLevel(int newLevel)
	{
		level = newLevel;
	}

	void Knight::setPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void Knight::setSwordName(char swordName[32])
	{
		setSwordName(swordName);
	}

	void Knight::setSwordDamage(int swordDamage)
	{
		setSwordDamage(swordDamage);
	}