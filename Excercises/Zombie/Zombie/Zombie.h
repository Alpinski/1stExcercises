#pragma once
class Zombie
{
public:
	Zombie();
	~Zombie();

	//--------------------------------------------------
	//Health, attack and occupation getters and setters.
	//--------------------------------------------------
	void SetHealth(int nHealth);
	int GetHealth();

	void SetAttack(int nAttack);
	int GetAttack();

	char* GetOccupation();

private:
	int m_nHealth;
	int m_nAttack;
	char* m_szOccupation;
};

