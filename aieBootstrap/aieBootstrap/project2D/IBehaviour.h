#pragma once
#include "Vector2.h"
class Agents;

class IBehaviour
{
public:
	IBehaviour(float fWeighting) 
	{
		m_fWeighting = fWeighting;
	}
	virtual ~IBehaviour() {};

	virtual Vector2 Update(Agents* agent, float fDeltaTime) = 0;

	float m_fWeighting;
private:

};