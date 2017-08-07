#pragma once
#include "Agents.h"
class StateMachine;

class AI : public Agents
{
public:
	AI();
	~AI();
	//-----------------------------------------------------
	//Updates the ai agent
	//
	//parameters: takes in a float
	//
	//return:
	//
	//-----------------------------------------------------
	void update(float deltaTime);
	//-----------------------------------------------------
	//draws the agent ai
	//
	//parameters:
	//
	//return: returns m_v2Facing
	//
	//-----------------------------------------------------
	void Draw(Renderer2D* pRenderer);

private:
	StateMachine* m_pStateMachine;
};

