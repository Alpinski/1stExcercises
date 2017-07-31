#pragma once
#include "Agents.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include "IBehaviour.h"
#include <vector>
#include "Follow.h"

class Agents;

class Patrol2 :	public BaseState	
{
public:
	Patrol2();
	~Patrol2();

	void OnEnter(StateMachine* pMachine);

	void OnUpdate(Agents* pAgent, float fDeltaTime, StateMachine* pMachine);

	void OnDraw(Renderer2D* m_2dRenderer);

	void OnExit(StateMachine* pMachine);
private:


	int			m_nNextNode;
	Grid*		m_pGrid;
	Vector2		m_v2Pos;
	AStar*		m_pAStar;


	DynamicArray<AstarNode*> m_path;

};

