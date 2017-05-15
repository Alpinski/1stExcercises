#pragma once
class Pointers
{
public:
	Pointers();
	~Pointers();

	void SetName(char* m_Name);
	char* GetName ();

	void SetHealth(int m_Health);
	int GetHealth();

protected:
	char* m_Name;
	int m_Health;
};

