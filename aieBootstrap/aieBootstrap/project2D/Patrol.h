#pragma once
#include "BaseState.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include "IBehaviour.h"
#include <vector>
#include "Follow.h"

class Agents;

class Patrol : public BaseState
{
public:
	Patrol();
	~Patrol();

	void OnEnter(StateMachine* pMachine);

	void OnUpdate(Agents* pAgent, float fDeltaTime, StateMachine* pMachine);

	void OnDraw(Renderer2D* m_2dRenderer);

	void OnExit(StateMachine* pMachine);
private:

	vector<IBehaviour*> m_behaviours;

	Follow*		m_pFollow;
	int			m_nNextNode;
	Grid*		m_pGrid;
	Vector2		m_v2Pos;
	AStar*		m_pAStar;


	DynamicArray<AstarNode*> m_path;

};

