#include "Decisionprint.h"
#include <iostream>
using namespace std;

Decisionprint::Decisionprint()
{
	m_fTimer = 0.0f;
}


Decisionprint::~Decisionprint()
{
}

void Decisionprint::MakeDecision(Entity * pEntity, float fDeltaTime)
{
	m_fTimer += fDeltaTime;
	system("cls");
	cout << "space has been pressed for" << m_fTimer << "Seconds" << endl;
}
