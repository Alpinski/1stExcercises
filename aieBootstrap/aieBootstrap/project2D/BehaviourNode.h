#pragma once

enum EBehaviourResult
{

	EBEHAVIOUR_FAILURE = 0,
	EBHEAVIOUR_SUCCESS
	
};

class BehaviourNode
{
public:
	virtual EBehaviourResult Execute() = 0;
};