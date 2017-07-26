#pragma once
#include "IBehaviour.h"
class Flee :public IBehaviour
{
public:
	Flee(float fWeighting);
	~Flee();
	Vector2 Update(Agents* agent, float deltaTime);
};

