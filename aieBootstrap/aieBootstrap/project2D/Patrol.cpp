#include "Patrol.h"
#include "Defines.h"


Patrol::Patrol()
{
	m_behaviourList.push_back(new Follow());

}


Patrol::~Patrol()
{
	for (unsigned int i = 0; i < m_behaviourList.size(); ++i)
	{
		delete m_behaviourList[i];
	}
}

void Patrol::OnEnter(StateMachine * pMachine)
{
	m_nNextNode = 0;
}

void Patrol::OnUpdate(Agents* pAgent, float fDeltaTime, StateMachine* pMachine)
{
	for (unsigned int i = 0; i < m_behaviourList.size(); ++i)
	{
		m_behaviourList[i]->Update(pAgent, fDeltaTime);
	}
}

void Patrol::OnDraw(Renderer2D * m_2dRenderer)
{

}

void Patrol::OnExit(StateMachine * pMachine)
{
}