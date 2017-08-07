#pragma once
#include "BaseDecision.h"
#include "Agents.h"
class DecisionWander : public BaseDecision
{
public:
	//-----------------------------------------------------
	//default constructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	DecisionWander();
	//-----------------------------------------------------
	//virtual destructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	virtual ~DecisionWander();
	//-----------------------------------------------------
	//Makes decision based on which button is pressed
	//
	//parameters: takes in an agent also takes in a float
	//
	//return:
	//
	//-----------------------------------------------------
	void MakeDecision(Agents* pAgent, float fDeltaTime);
private:
	float m_fTimer;
};

