#pragma once
#include "Agents.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include "StateMachine.h"
#include "DecisionQuestion.h"

class Player : public Agents
{
public:
	Player();
	~Player();

	void update(float deltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);

private:
	DecisionQuestion* m_pRoot;
	
	int			m_nNextNode;
	Grid*		m_pGrid;


	DynamicArray<AstarNode*> m_path;
};

