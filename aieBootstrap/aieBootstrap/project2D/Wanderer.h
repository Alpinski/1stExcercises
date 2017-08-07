#pragma once
#include "Agents.h"
#include "DecisionQuestion.h"

class Wanderer : public Agents
{
public:
	//--------------------------------------------------
	//default constructor and destructor
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	Wanderer();
	~Wanderer();
	//--------------------------------------------------
	//Update function for the wanderer agent
	//
	//Parameters: takes in a float
	//
	//Returns:
	//
	//--------------------------------------------------
	void update(float fDeltaTime);
	//--------------------------------------------------
	//Draw function of the wanderer
	//
	//Parameters: takes in a renderer2d
	//
	//Returns:
	//
	//--------------------------------------------------
	void Draw(aie::Renderer2D * m_2dRenderer);
private:
	DecisionQuestion* m_pRoot;
};

