#pragma once
class Sword
{
private:
	char name[32];
	int damage;

public:
		void createSword();
		void setName(char newName[32]);
		void setDamage(int newDamage);
		void printSword();

};