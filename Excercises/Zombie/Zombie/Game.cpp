#include "Game.h"
#include <iostream>
#include <Windows.h>


using namespace std;

//--------------------------------------------
//Prototyping.
//--------------------------------------------
WORD GetConsoleTextAttribute(HANDLE hCon);

//--------------------------------------------
//Constructor for Zmbies and Vampires
//The amount of Zombies and Vampires.
//--------------------------------------------
Game::Game(int nZombieCount, int nVampireCount)
{
	m_apZombies = new Zombie*[10];

	for (int i = 0; i < nZombieCount; ++i)
	{
		m_apZombies[i] = new Zombie();
	}

	m_nZombieCount = nZombieCount;
	m_nZombiesLeft = nZombieCount;

	m_apVampires = new Vampire*[10];

	for (int i = 0; i < nVampireCount; ++i)
	{
		m_apVampires[i] = new Vampire();
	}

	m_nVampireCount = nVampireCount;
	m_nVampiresLeft = nVampireCount;
}

//------------------------------------------------
//The deconstructor, deletes Vampires and Zombies
//------------------------------------------------
Game::~Game()
{
	for (int i = 0; i < m_nZombieCount; ++i)
	{
		delete m_apZombies[i];
	}

	for (int i = 0; i < m_nVampireCount; ++i)
	{
		delete m_apVampires[i];
	}

	delete[] m_apZombies;
	delete[] m_apVampires;
}


bool Game::Update()
{
	//--------------------------------------------
	// BubbleSort for Vampires and Zombies.
	//--------------------------------------------
	if (m_nZombiesLeft > 1)
	{
		for (int i = 0; i < m_nZombiesLeft - 1; ++i)
		{
			for (int j = 0; j < (m_nZombiesLeft - 1); ++j)
			{
				if (m_apZombies[j]->GetHealth() > m_apZombies[j + 1]->GetHealth())
				{
					Zombie* temp = m_apZombies[j];
					m_apZombies[j] = m_apZombies[j + 1];
					m_apZombies[j + 1] = temp;
				}
			}
		}
	}
	if (m_nVampiresLeft > 1)
	{
		for (int i = 0; i < m_nVampiresLeft - 1; ++i)
		{
			for (int j = 0; j < (m_nVampiresLeft - 1); ++j)
			{
				if (m_apVampires[j]->GetHealth() > m_apVampires[j + 1]->GetHealth())
				{
					Vampire* temp = m_apVampires[j];
					m_apVampires[j] = m_apVampires[j + 1];
					m_apVampires[j + 1] = temp;
				}
			}
		}
	}

	//----------------------------------------------------------
	//The fight sequence for the Vampires vs Zombies
	//----------------------------------------------------------
		int nRandZombie = rand() % m_nVampireCount;
		int nRandVampire = rand() % m_nVampireCount;
		
		int nAttack = m_apZombies[nRandZombie]->GetAttack();
		int nVAttack = m_apVampires[nRandVampire]->GetAttack();

		int nHealth = m_apZombies[nRandZombie]->GetHealth();
		int nVHealth = m_apVampires[nRandVampire]->GetHealth();

		if (nHealth > 0 && nVHealth > 0)
		{
			int nNewHealth = nHealth - nVAttack;
			int nVNewHealth = nVHealth - nAttack;
			if (nRandZombie != nRandVampire)
			{
				m_apZombies[nRandZombie]->SetHealth(nNewHealth);
				m_apVampires[nRandVampire]->LifeSteal();

				m_apVampires[nRandVampire]->SetHealth(nVNewHealth);

				if (nNewHealth <= 0)
					{
						--m_nZombiesLeft;
					}
					if (nVNewHealth <= 0)
					{
						--m_nVampiresLeft;
					}	

					//--------------------------------------------
					//Fight Sequence results printed.
					//--------------------------------------------
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					const int saved_colors = GetConsoleTextAttribute(hConsole);
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)";
					SetConsoleTextAttribute(hConsole, saved_colors);
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << endl;
					cout << "A " << m_apZombies[nRandZombie]->GetOccupation() << "attacks a " << m_apVampires[nRandVampire]->GetOccupation();
					cout << "for " << nAttack << "damage, it has " << nVNewHealth << "Heatlth remaining" << endl;
					SetConsoleTextAttribute(hConsole, saved_colors);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "A " << m_apVampires[nRandVampire]->GetOccupation() << "attacks a " << m_apZombies[nRandZombie]->GetOccupation();
					cout << "for " << nVAttack << "damage, it has " << nNewHealth << "Heatlth remaining" << endl;
					SetConsoleTextAttribute(hConsole, saved_colors);
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)" << endl;
					SetConsoleTextAttribute(hConsole, saved_colors);
					cout << endl;
					
			}
		}
		else
		{
			//----------------------------------------------------------
			//Win condition for zombie and Vampire
			//----------------------------------------------------------
			if (nHealth > 0 && nVHealth > 0)
			{
				cout << "At the end of a hard fought battle they both still stand!" << endl;
			}
			else if (m_nZombiesLeft <= 0 || m_nVampiresLeft <= 0)
			{
				if (m_nZombiesLeft > 0 && m_nVampiresLeft <= 0)
				{
					cout << "The Zombies stand victorious!" << endl;
					return false;
				}
				else
				{
					cout << "The Vampires stand victorious!" << endl;
					return false;
				}
			}
		}
	return true;
}

WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
