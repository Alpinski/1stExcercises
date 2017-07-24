#include "Player.h"
#include "Defines.h"


Player::Player(Grid* pGrid)
{
	m_pGrid = pGrid;

	m_pAStar = new AStar(GRID_SIZE *GRID_SIZE);

	m_pAStar->SetHeuristic(&CalculateHeuristic);

	m_nNextNode = 0;
}


Player::~Player()
{
	delete m_pAStar;
}

void Player::Draw(aie::Renderer2D * m_2dRenderer)
{
	for (int i = 0; i < m_path.Size(); ++i)
	{
		GridNode* pNode = (GridNode*)m_path[i];
		m_2dRenderer->setRenderColour(0x00FF00FF);
		m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	}

	m_2dRenderer->drawBox(m_v2Pos.x , m_v2Pos.y, 50, 50);
}

void Player::update(float fDeltaTime)
{
	

	m_path.Clear();
	m_pAStar->CalculatePath(m_pGrid->getNode(1),m_pGrid->getNode(158), &m_path);

	if (m_nNextNode >= m_path.Size())
	{
		m_nNextNode = 0;
	}

	Vector2 dest = ((GridNode*)m_path[m_nNextNode])->m_v2Pos;
	Vector2 dir = dest - m_v2Pos;
	dir.Normalise();
	m_v2Pos = m_v2Pos + dir * PLAYER_SPEED * fDeltaTime;

	Vector2 dist = dest - m_v2Pos;
	float Dist = dist.Magnitude();
	if (Dist < 10)
	{
		++m_nNextNode;
	}
}

void Player::MovementUpdate(float Deltatime)
{
}
