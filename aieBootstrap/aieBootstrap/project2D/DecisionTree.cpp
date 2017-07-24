#include "DecisionTree.h"
#include "DecisionButtonPressed.h"
#include "Decisionprint.h"
#include "DecisionNothingPressed.h"



DecisionTree::DecisionTree()
{
	m_pRoot = new DecisionButtonPressed();
	m_pRoot->m_pTrueDecision = new Decisionprint();
	m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
}


DecisionTree::~DecisionTree()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

void DecisionTree::Update(Entity * pEntity, float fDeltaTime)
{
	m_pRoot->MakeDecision(pEntity, fDeltaTime);
}