#pragma once
#include "Vector2.h"

#include "IBehaviour.h"
class Wander : public IBehaviour
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
	Wander();
	~Wander();
	//--------------------------------------------------
	//update for wander behaviour
	//
	//Parameters: takes in Agents and float
	//
	//Returns:
	//
	//--------------------------------------------------
	Vector2 Update(Agents* agent, float fDeltaTime);
	//--------------------------------------------------
	//random number generartor between highest and lowest
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	int RandomClamped();

private:
	
	Vector2 m_vWanderTarget;
	double m_dWanderRadius;
	double m_dWanderDistance;
	double m_dWanderJitter;
};
