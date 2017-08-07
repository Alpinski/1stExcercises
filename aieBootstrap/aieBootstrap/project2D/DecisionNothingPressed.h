#pragma once
#include "BaseDecision.h"
#include "Agents.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include "IBehaviour.h"
#include <vector>
#include "Follow.h"
class DecisionNothingPressed : public BaseDecision
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
	DecisionNothingPressed();
	//-----------------------------------------------------
	//Default destructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	virtual ~DecisionNothingPressed();
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

