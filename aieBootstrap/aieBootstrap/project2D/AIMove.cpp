#include "AIMove.h"
#include "Defines.h"
#include "Seek.h"
#include "Follow.h"
#include "IBehaviour.h"
#include "Agents.h"
#include "Flee.h"


AIMove::AIMove()
{
	m_behaviourList.push_back(new Seek(0.75f));
	m_behaviourList.push_back(new Flee(0.25f));
}


AIMove::~AIMove()
{
	for (unsigned int i = 0; i < m_behaviourList.size(); ++i)
	{
		delete m_behaviourList[i];
	}
}

void AIMove::OnEnter(StateMachine * pMachine)
{
}

void AIMove::OnUpdate(Agents * pAgent, float fDeltaTime, StateMachine * pMachine)
{
	Vector2 v2TotalForce;

	for (unsigned int i = 0; i < m_behaviourList.size(); ++i)
	{
		Vector2 currentForce = m_behaviourList[i]->Update(pAgent, fDeltaTime);
		currentForce = currentForce * m_behaviourList[i]->m_fWeighting;
	
		v2TotalForce = v2TotalForce + currentForce;

		float fMagnitude = v2TotalForce.Magnitude();
		if (fMagnitude > 10.0f)
		{ 
			v2TotalForce.Normalise();
			v2TotalForce = v2TotalForce * 10.0f;
			break;
		}	
	}


	Vector2 v2Facing;
	v2Facing = v2TotalForce;
	v2Facing.Normalise();
	pAgent->setAngle(v2Facing);

	pAgent->SetPosition(pAgent->Getposition() + v2TotalForce);
}

void AIMove::OnDraw(Renderer2D * m_2dRenderer)
{

}

void AIMove::OnExit(StateMachine * pMachine)
{
}
