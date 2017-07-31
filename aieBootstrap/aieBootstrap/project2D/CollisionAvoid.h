#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
class CollisionAvoid : public IBehaviour
{
public:
	CollisionAvoid(float fWeighting);
	~CollisionAvoid();

	Vector2 Update(Agents* agent, float deltaTime);

private:
	Vector2 m_targetPos;
};

