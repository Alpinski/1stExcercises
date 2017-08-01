#pragma once
#include "Vector2.h"

#include "IBehaviour.h"
class Wander : public IBehaviour
{
public:
	Wander();
	~Wander();

	Vector2 Update(Agents* agent, float fDeltaTime);
	int RandomClamped();

private:
	
	Vector2 m_vWanderTarget;
	double m_dWanderRadius;
	double m_dWanderDistance;
	double m_dWanderJitter;
};
