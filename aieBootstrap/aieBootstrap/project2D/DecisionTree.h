#pragma once
#include "DecisionQuestion.h"

class Entity;

class DecisionTree
{
public:
	DecisionTree();
	~DecisionTree();

	void Update(Entity* pEntity, float fDeltaTime);
private:
	DecisionQuestion* m_pRoot;
};

