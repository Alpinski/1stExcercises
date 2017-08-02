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
	if (m_position.x >= 1415)
		m_position.x = 0;
	if (m_position.y >= 695)
		m_position.y = 0;
	if (m_position.x <= -25)
		m_position.x = 1415;
	if (m_position.y <= -25)
		m_position.y = 695;
	m_pRoot->MakeDecision(this, fDeltaTime);
}

void Wanderer::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawCircle(m_position.x, m_position.y, 50, 50);
}