#pragma once
#include "IBehaviour.h"
#include <vector>
using namespace std;

class Agents;

class BaseDecision
{
public:
	BaseDecision() {}
	~BaseDecision() {}

	virtual void MakeDecision(Agents* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_behaviourList;
};

