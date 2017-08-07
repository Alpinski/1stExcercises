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
	//--------------------------------------------------
	// default Constructor and destructor
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	Grid();
	~Grid();
	//--------------------------------------------------
	// creates the grid that will be used for path finding
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	static void Create();
	//--------------------------------------------------
	// destroys the previously created grid
	//
	//Parameters: takes in AstarNode
	//
	//Returns:
	//
	//--------------------------------------------------
	static void Destroy();
	//--------------------------------------------------
	// Gets the instance of the grid
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	static Grid* GetInstance();
	//--------------------------------------------------
	// draws the created grid
	//
	//Parameters: takes in renderer2d
	//
	//Returns:
	//
	//--------------------------------------------------
	void DrawGrid(aie::Renderer2D * m_2dRenderer);
	//--------------------------------------------------
	// Gets the node
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	GridNode* getNode(int index);
	//--------------------------------------------------
	// gets the grid
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	GridNode* GetGrid(int nIndex);

private:

	aie::Renderer2D*	m_2dRenderer;

	GridNode** m_ppGrid;
	AStar* m_pAStar;

	static Grid* m_pInstance;
};

//--------------------------------------------------
// calculates the heuristic of the path
//
//Parameters: takes in AstarNode
//
//Returns:
//
//--------------------------------------------------
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

	//return COST_HORVER * (differenceX + differenceY) + ((int)sqrt(COST_DIAGONAL) - COST_DIAGONAL * COST_HORVER) * min(differenceX, differenceY);

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
	return sqrt((differenceX - differenceX)^COST_HEURISTIC_DIAGONAL + (differenceY * differenceY)^COST_HEURISTIC_DIAGONAL);
}