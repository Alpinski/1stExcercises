#include "AI.h"
#include "StateMachine.h"
#include "Renderer2D.h"
#include "AIMove.h"
using namespace aie;

AI::AI()
{
	m_pStateMachine = new StateMachine();
	m_pStateMachine->AddState(0, new AIMove());
	m_pStateMachine->PushState(0);
}

AI::~AI()
{
}

void AI::update(float deltaTime)
{
	m_pStateMachine->Update(this, deltaTime);
}

void AI::Draw(Renderer2D* pRenderer)
{
	pRenderer->setRenderColour(0xFF0000FF);
	pRenderer->drawCircle(m_position.x, m_position.y, 20.0f);
	pRenderer->setRenderColour(0xFFFFFFFF);
}
