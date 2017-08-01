#pragma once
#include "BaseDecision.h"
#include "Agents.h"
class DecisionWander : public BaseDecision
{
public:
	DecisionWander();
	virtual ~DecisionWander();

	void MakeDecision(Agents* pAgent, float fDeltaTime);
private:
	float m_fTimer;
};

