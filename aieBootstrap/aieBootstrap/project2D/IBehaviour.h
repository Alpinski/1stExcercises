#pragma once
#include "Vector2.h"
#include <cmath>
class Agents;
//base class for behaviours
class IBehaviour
{
public:
	//--------------------------------------------------
	//default constructor and destructor
	//
	//Parameters:constructor takes in a float
	//
	//Returns:(2 * parentIndex) + whichChild;
	//
	//--------------------------------------------------
	IBehaviour(float fWeighting) 
	{
		m_fWeighting = fWeighting;
	}
	virtual ~IBehaviour() {};
	//--------------------------------------------------
	//update function for behaviours
	//
	//Parameters: takes in an Agent and float
	//
	//Returns:
	//
	//--------------------------------------------------
	virtual Vector2 Update(Agents* agent, float fDeltaTime) = 0;

	float m_fWeighting;
private:

};