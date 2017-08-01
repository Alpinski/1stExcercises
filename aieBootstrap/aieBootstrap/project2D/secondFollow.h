#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"

class secondFollow : public IBehaviour
{
public:
	secondFollow();
	~secondFollow();

	Vector2 Update(Agents* agent, float fDeltaTime);


private:
	int			m_nNextNode;
	Grid*		m_pGrid;
	//Vector2		m_v2Pos;
	AStar*		m_pAStar;


	DynamicArray<AstarNode*> m_path;
};

