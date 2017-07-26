#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
class Seek : public IBehaviour
{
public:
	Seek(float fWeighting);
	~Seek();

	Vector2 Update(Agents* agent, float deltaTime);

private:
	Vector2 m_targetPos;

};