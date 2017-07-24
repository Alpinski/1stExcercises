#pragma once
#include "Agents.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"

class Player : public Agents
{
public:
	Player(Grid* pGrid);
	~Player();

	void Draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);
	void MovementUpdate(float Deltatime);

private:

	int m_nNextNode;

	Grid*		m_pGrid;
	Vector2		m_v2Pos;
	AStar*		m_pAStar;

	DynamicArray<AstarNode*> m_path;
};

