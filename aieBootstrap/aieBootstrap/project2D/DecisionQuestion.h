#pragma once

#include "BaseDecision.h"

class DecisionQuestion : public BaseDecision
{
public:
	//-----------------------------------------------------
	//Makes decision based on which button is pressed
	//
	//parameters: takes in an agent also takes in a float
	//
	//return:
	//
	//-----------------------------------------------------
	virtual void MakeDecision(Agents* pAgent, float fDeltaTime) = 0;


	BaseDecision* m_pTrueDecision;
	BaseDecision* m_pFalseDecision;
};