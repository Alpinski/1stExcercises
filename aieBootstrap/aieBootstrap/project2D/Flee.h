#pragma once
#include "IBehaviour.h"
class Flee :public IBehaviour
{
public:
	//--------------------------------------------------
	// default constructor
	//
	//Parameters: takes in a float
	//
	//Returns:
	//
	//--------------------------------------------------
	Flee(float fWeighting);
	//--------------------------------------------------
	//default destrucctor
	//
	//Parameters:  takes in a AstarNode
	//
	//Returns:
	//
	//--------------------------------------------------
	~Flee();
	//--------------------------------------------------
	// update function for flee
	//
	//Parameters:  takes in Agents amd a float
	//
	//Returns:
	//
	//--------------------------------------------------
	Vector2 Update(Agents* agent, float deltaTime);
};

