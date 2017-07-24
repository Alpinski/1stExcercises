#pragma once

class Entity;

class BaseDecision
{
public:
	BaseDecision() {}
	~BaseDecision() {}

	virtual void MakeDecision(Entity* pEntity, float fDeltaTime) = 0;
};

