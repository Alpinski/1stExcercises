#pragma once
#include "Agents.h"
class StateMachine;

class AI : public Agents
{
public:
	AI();
	~AI();

	void update(float deltaTime);
	void Draw(Renderer2D* pRenderer);

private:
	StateMachine* m_pStateMachine;
};

