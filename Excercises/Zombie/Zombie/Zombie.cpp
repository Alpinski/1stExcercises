#include "Zombie.h"
#include <iostream>





Zombie::Zombie()
{
	//--------------------------------------------
	//Zombie random Health and Attack
	//--------------------------------------------
	m_nHealth = (rand() % 51) + 50;
	m_nAttack = (rand() % 11) + 10;

	//--------------------------------------------
	//Randomizes occupations.
	//--------------------------------------------
	int nRandOcc = rand() % 10;
	switch (nRandOcc)
	{
		case 0:		m_szOccupation = "Zombie ";				break;
		case 1:		m_szOccupation = "Runner Zombie ";		break;
		case 2:		m_szOccupation = "Walker Zombie ";		break;
		case 3:		m_szOccupation = "Voodoo Zombie ";		break;
		case 4:		m_szOccupation = "Melting Zombie ";		break;
		case 5:		m_szOccupation = "Carrier Zombie ";		break;
		case 6:		m_szOccupation = "Stalker Zombie ";		break;
		case 7:		m_szOccupation = "Radioactive Zombie ";	break;
		case 8:		m_szOccupation = "Spitter Zombie ";		break;
		case 9:		m_szOccupation = "Suicide Zombie ";		break;
	}
}


Zombie::~Zombie()
{
}

//--------------------------------------------
//Sets Health.
//--------------------------------------------
void Zombie::SetHealth(int nHealth)
{
	m_nHealth = nHealth;
}

//--------------------------------------------
//Gets Healt.
//--------------------------------------------
int Zombie::GetHealth()
{
	return m_nHealth;
}

//--------------------------------------------
//Sets Attack.
//--------------------------------------------
void Zombie::SetAttack(int nAttack)
{
	m_nAttack = nAttack;
}

//--------------------------------------------
//Gets Attack.
//--------------------------------------------
int Zombie::GetAttack()
{
	return m_nAttack;
}
//--------------------------------------------
//Gets Occupation.
//--------------------------------------------
char* Zombie::GetOccupation()
{
	return m_szOccupation;
}