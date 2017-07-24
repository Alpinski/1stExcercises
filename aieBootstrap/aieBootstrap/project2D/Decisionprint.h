#pragma once
#include "BaseDecision.h"
class Decisionprint : public BaseDecision
{
public:
	Decisionprint();
	virtual ~Decisionprint();

	void MakeDecision(Entity* pEntity, float fDeltaTime);
private:
	float m_fTimer;
};

