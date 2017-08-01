#include "DecisionWander.h"
#include <iostream>
#include "Wander.h"
#include "IBehaviour.h"
using namespace std;

DecisionWander::DecisionWander()
{
	m_fTimer = 0.0f;
	m_behaviourList.push_back(new Wander());
}


DecisionWander::~DecisionWander()
{
}

void DecisionWander::MakeDecision(Agents * pAgent, float fDeltaTime)
{
	for (unsigned int i = 0; i < m_behaviourList.size(); ++i)
	{
		m_behaviourList[i]->Update(pAgent, fDeltaTime);
	}
}
