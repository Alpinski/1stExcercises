#pragma once
class Knight
{
private:
	char name[32];
	int health;
	int level;

	Vector position;
	Sword sword;

public:
	void createKnight();
	void printKnight();
	void setName(char newName[32]);
	void doDmagae(int damage);
	void setLevel(int newLevel);
	void setPosition(float x, float y);
	void setSwordName(char swordName[32]);
	void setSwordDamage(int swordDamage);
};