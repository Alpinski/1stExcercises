#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "AstarNode.h"
#include "Defines.h"
#include <algorithm>
#include "GridNode.h"

class AStar;

class Grid
{
public:
	Grid();
	~Grid();

	static void Create();

	static void Destroy();

	static Grid* GetInstance();

	void DrawGrid(aie::Renderer2D * m_2dRenderer);

	GridNode* getNode(int index);

	GridNode* GetGrid(int nIndex);

private:

	aie::Renderer2D*	m_2dRenderer;

	GridNode** m_ppGrid;
	AStar* m_pAStar;

	static Grid* m_pInstance;
};


static int CalculateHeuristic(AstarNode * pNode, AstarNode * pEnd)
{

	int differenceX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int differenceY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;


	differenceX = abs(differenceX);
	differenceY = abs(differenceY);

	//Diagonal shortcut

	//if (differenceX > differenceY)
	//	return 1 * (differenceX + differenceY) + (sqrt(2) - 2 * 1) * min(differenceX, differenceY);
	//else
	//	return 1 * (differenceY + differenceX) + (sqrt(2) - 2 * 1) * min(differenceY, differenceX);

	return COST_HORVER * (differenceX + differenceY) + ((int)sqrt(COST_DIAGONAL) - COST_DIAGONAL * COST_HORVER) * min(differenceX, differenceY);

	//if (differenceX > differenceY)
	//{
	//	return (COST_DIAGONAL * differenceY) + COST_HORVER * (differenceX - differenceY);
	//}
	//else
	//{
	//	return (COST_DIAGONAL * differenceX) + COST_HORVER * (differenceY - differenceX);
	//}

	//Manhattan Distance
	//return COST_HORVER * (differenceX + differenceY);

	//Euclidean Distance
	//D * sqrt(dx * dx + dy * dy)
	//return sqrt((differenceX - differenceX)^COST_HEURISTIC_DIAGONAL + (differenceY * differenceY)^COST_HEURISTIC_DIAGONAL);
}