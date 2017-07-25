#include "Follow.h"
#include "Defines.h"
#include "Grid.h"

Follow::Follow()
{
	m_pGrid = Grid::GetInstance();
	m_pAStar = new AStar(GRID_SIZE *GRID_SIZE);
	m_pAStar->SetHeuristic(CalculateHeuristic);

	m_nNextNode = 0;
}


Follow::~Follow()
{
	delete m_pAStar;
}

bool Follow::Update(Agents * agent, float fDeltaTime)
{

	

	m_path.Clear();
	m_pAStar->CalculatePath(m_pGrid->getNode(1), m_pGrid->getNode(158), &m_path);

	if (m_nNextNode >= m_path.Size())
	{
		m_nNextNode = 0;
	}

	Vector2 dest = ((GridNode*)m_path[m_nNextNode])->m_v2Pos;
	Vector2 dir = dest - agent->m_v2Pos;
	dir.Normalise();
	m_v2Pos = m_v2Pos + dir * 500.0f * fDeltaTime;

	Vector2 dist = dest - m_v2Pos;
	float Dist = dist.Magnitude();
	if (Dist < 10)
	{
		++m_nNextNode;
	}
	return false;
}
