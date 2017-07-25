#include "Player.h"
#include "Defines.h"
#include "Patrol.h"

Player::Player()
{
	m_pStateMachine = new StateMachine();
	m_pStateMachine->AddState(0, new Patrol());
	m_pStateMachine->PushState(0);
}


Player::~Player()
{
}

void Player::update(float fDeltaTime)
{
	m_pStateMachine->Update(this, fDeltaTime);
}

void Player::Draw(aie::Renderer2D * m_2dRenderer)
{	
	for (int i = 0; i < m_path.Size(); ++i)
	{
		GridNode* pNode = (GridNode*)m_path[i];
		m_2dRenderer->setRenderColour(0x00FF00FF);
		m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	}

	m_2dRenderer->drawBox(m_v2Pos.x, m_v2Pos.y, 50, 50);
}


void Player::MovementUpdate(float Deltatime)
{

}
