#include "Wander.h"
#include <random>
#include <time.h>
#include "Agents.h"
Wander::Wander() : IBehaviour(1.0f)
{
	m_dWanderJitter = 10.0;
	m_dWanderRadius = 80.0;
	m_dWanderDistance = 120.0;
}

Wander::~Wander()
{
}

Vector2 Wander::Update(Agents * agent, float fDeltaTime)
{
	m_vWanderTarget += Vector2(RandomClamped() * m_dWanderJitter, RandomClamped() * m_dWanderJitter);
	m_vWanderTarget.Normalise();
	m_vWanderTarget = m_vWanderTarget * m_dWanderRadius;

	//Vector2 targetLocal = m_vWanderTarget + Vector2(m_dWanderDistance, 0);

	Vector2 targetWorld = m_vWanderTarget + agent->getAngle() * m_dWanderDistance;
	targetWorld.Normalise();

	agent->SetPosition(agent->Getposition() + targetWorld * fDeltaTime * 100);
	return targetWorld;
}

int Wander::RandomClamped()
{
	//int random_integer;
	//int lowest = 2, highest = 5;
	//int range = (highest - lowest) + 1;
	//for (int index = 0; index<20; index++) 
	//{
	//	random_integer = lowest + int(range*rand() / (RAND_MAX + 1.0));
	//}
	//return random_integer;
	return rand() % 5 - 2;
}