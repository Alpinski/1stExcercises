#pragma once
#include "Agents.h"

#include "DecisionQuestion.h"

class Wanderer : public Agents
{
public:
	Wanderer();
	~Wanderer();
	void update(float fDeltaTime);
	void Draw(aie::Renderer2D * m_2dRenderer);
private:
	DecisionQuestion* m_pRoot;
};

