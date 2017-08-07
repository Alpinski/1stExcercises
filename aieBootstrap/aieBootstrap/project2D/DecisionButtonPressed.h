#pragma once
#include "DecisionQuestion.h"

class DecisionButtonPressed : public DecisionQuestion
{
public:
	//-----------------------------------------------------
	//Default constructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	DecisionButtonPressed();
	//-----------------------------------------------------
	//Default Destructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	virtual ~DecisionButtonPressed();
	//-----------------------------------------------------
	//Makes decision based on which button is pressed
	//
	//parameters: takes in an agent also takes in a float
	//
	//return:
	//
	//-----------------------------------------------------
	void MakeDecision(Agents* pAgent, float fDeltaTime);
};


