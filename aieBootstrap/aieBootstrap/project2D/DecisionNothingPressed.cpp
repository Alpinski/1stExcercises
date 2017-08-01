#include "DecisionNothingPressed.h"
#include <iostream>
using namespace std;


DecisionNothingPressed::DecisionNothingPressed()
{
	m_behaviourList.push_back(new Follow());
}


DecisionNothingPressed::~DecisionNothingPressed()
{
	for (unsigned int i = 0; i < m_behaviourList.size(); ++i)
	{
		delete m_behaviourList[i];
	}
}

void DecisionNothingPressed::MakeDecision(Agents * pAgent, float fDeltaTime)
{

	for (unsigned int i = 0; i < m_behaviourList.size(); ++i)
	{
		m_behaviourList[i]->Update(pAgent, fDeltaTime);
	}
}
