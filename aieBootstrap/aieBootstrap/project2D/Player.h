#pragma once
#include "Agents.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include "StateMachine.h"

class Player : public Agents
{
public:
	Player();
	~Player();

	void Draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);
	void MovementUpdate(float Deltatime);

private:
	StateMachine* m_pStateMachine;
	int			m_nNextNode;
	Grid*		m_pGrid;
	Vector2		m_v2Pos;


	DynamicArray<AstarNode*> m_path;
};

