#pragma once
#include"Zombie.h"
#include"Vampire.h"

class Game
{

public:
	Game(int nZombieCount, int nVampireCount);
	~Game();

	bool Update();

private:
	//--------------------------------------------
	//Pointer to Zombie and Vampire class.
	//--------------------------------------------
	Zombie** m_apZombies;
	Vampire** m_apVampires;

	//--------------------------------------------
	//Amount of zombies and Vampires
	//--------------------------------------------
	int m_nZombieCount;
	int m_nVampireCount;
	//--------------------------------------------
	//Amount of Zombies and Vampires left.
	//--------------------------------------------
	int m_nZombiesLeft;
	int m_nVampiresLeft;
};

