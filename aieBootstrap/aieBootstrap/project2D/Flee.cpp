#include "Flee.h"
#include "Agents.h"


Flee::Flee(float fWeighting) : IBehaviour(fWeighting)
{
}


Flee::~Flee()
{
}

Vector2 Flee::Update(Agents * agent, float deltaTime)
{

	Vector2 v2FleePos(200.0f,200.0f);
	Vector2 v2Dir = agent->Getposition() - v2FleePos;
	float fMagnitude = v2Dir.Magnitude();
	v2Dir.Normalise();

	float DistScale = (fMagnitude / 200);
	if (DistScale > 1.0f)
		DistScale = 1.0f;
	m_fWeighting = 1.0f - DistScale;


	return v2Dir * 100.0f * deltaTime;
}
