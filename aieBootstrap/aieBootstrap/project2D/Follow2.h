#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"



class Follow2 : public IBehaviour
	
{
public:
	Follow2();
	~Follow2();

	Vector2 Update(Agents* agent, float fDeltaTime);


private:
	int			m_nNextNode;
	Grid*		m_pGrid;
	//Vector2		m_v2Pos;
	AStar*		m_pAStar;


	DynamicArray<AstarNode*> m_path;
};

