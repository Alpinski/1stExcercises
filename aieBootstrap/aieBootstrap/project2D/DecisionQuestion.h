#pragma once

#include "BaseDecision.h"

class DecisionQuestion : public BaseDecision
{
public:

	virtual void MakeDecision(Agents* pAgent, float fDeltaTime) = 0;


	BaseDecision* m_pTrueDecision;
	BaseDecision* m_pFalseDecision;
};