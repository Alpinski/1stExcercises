#include "DecisionTree.h"
#include "DecisionButtonPressed.h"
#include "DecisionWander.h"
#include "DecisionNothingPressed.h"



DecisionTree::DecisionTree()
{
	m_pRoot = new DecisionButtonPressed();
	m_pRoot->m_pTrueDecision = new DecisionWander();
	m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
}


DecisionTree::~DecisionTree()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

void DecisionTree::Update(Agents * pAgent, float fDeltaTime)
{
	m_pRoot->MakeDecision(pAgent, fDeltaTime);
}