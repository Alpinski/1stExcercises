#include "Wanderer.h"
#include "DecisionButtonPressed.h"
#include "DecisionWander.h"
#include "DecisionNothingPressed.h"



Wanderer::Wanderer()
{
	m_pRoot = new DecisionButtonPressed();
	m_pRoot->m_pTrueDecision = new DecisionWander();
	m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
}


Wanderer::~Wanderer()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

void Wanderer::update(float fDeltaTime)
{
	m_pRoot->MakeDecision(this, fDeltaTime);
}

void Wanderer::Draw(aie::Renderer2D* m_2dRenderer)
{
}