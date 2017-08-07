#pragma once
#include "IBehaviour.h"
#include <vector>
using namespace std;

class Agents;

//-----------------------------------------------------
//The base class for decisions
//
//parameters:
//
//return:
//
//-----------------------------------------------------
class BaseDecision
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
	BaseDecision() {}
	//-----------------------------------------------------
	//Default Destructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	~BaseDecision() {}
	//-----------------------------------------------------
	//virtaul function for making decisions
	//
	//parameters: takes in and agent and a float
	//
	//return:
	//
	//-----------------------------------------------------
	virtual void MakeDecision(Agents* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_behaviourList;
};

