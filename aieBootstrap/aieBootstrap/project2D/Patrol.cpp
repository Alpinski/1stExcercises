#include "Patrol.h"
#include "Defines.h"


Patrol::Patrol()
{
	m_pFollow = new Follow();
	m_behaviours.push_back(m_pFollow);
}


Patrol::~Patrol()
{
	delete m_pFollow;
}

void Patrol::OnEnter(StateMachine * pMachine)
{
	m_nNextNode = 0;
}

void Patrol::OnUpdate(Agents* pAgent, float fDeltaTime, StateMachine* pMachine)
{
	for (unsigned int i = 0; i < m_behaviours.size(); ++i)
	{
		m_behaviours[i]->Update(pAgent, fDeltaTime);
	}
}

void Patrol::OnDraw(Renderer2D * m_2dRenderer)
{

}

void Patrol::OnExit(StateMachine * pMachine)
{
}