#pragma once
#include "BaseDecision.h"
#include "Agents.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include "IBehaviour.h"
#include <vector>
#include "Follow.h"
class DecisionNothingPressed : public BaseDecision
{
public:
	DecisionNothingPressed();
	virtual ~DecisionNothingPressed();

	void MakeDecision(Agents* pAgent, float fDeltaTime);
};

