#include "Player.h"
#include "DecisionButtonPressed.h"
#include "DecisionWander.h"
#include "DecisionNothingPressed.h"
Player::Player()	
{
	m_pRoot = new DecisionButtonPressed();
	m_pRoot->m_pTrueDecision = new DecisionWander();
	m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
}


Player::~Player()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

void Player::update(float fDeltaTime)
{
	m_pRoot->MakeDecision(this, fDeltaTime);
}

void Player::Draw(aie::Renderer2D * m_2dRenderer)
{	
	m_2dRenderer->drawBox(m_position.x, m_position.y, 50, 50);
}
