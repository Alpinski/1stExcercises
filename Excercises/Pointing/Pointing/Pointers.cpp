#include "Pointers.h"

#include <iostream>

using namespace std;

void main()
{

}

Pointers::Pointers()
{
}


Pointers::~Pointers()
{
}

void Pointers::SetName(char* Name)
{
	delete m_Name;

	int length = strlen(Name);
	m_Name = new char[length + 1];
	strcpy(m_Name, Name);
}

char* Pointers::GetName()
{
	return m_Name;
}

void Pointers::SetHealth(int Health)
{
	Health = 1000;
}

int Pointers::GetHealth() 
{
	return m_Health;
}