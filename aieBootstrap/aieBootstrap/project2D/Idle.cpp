#include "Idle.h"
#include "Player.h"
#include "Input.h"

using namespace aie;

Idle::Idle()
{
	m_timer = 0;
}


Idle::~Idle()
{
}

void Idle::OnEnter(StateMachine * pMachine)
{
	m_timer = 0;
}

void Idle::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	m_timer += fDeltaTime;
	Input* input = Input::getInstance();
	if (input->wasKeyPressed(INPUT_KEY_P))
	{

		if (m_timer < 3)
		{
			
		}
	}

}

void Idle::OnDraw(Renderer2D * m_2dRenderer)
{
}

void Idle::OnExit(StateMachine * pMachine)
{
}
