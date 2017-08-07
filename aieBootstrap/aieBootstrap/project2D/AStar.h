#pragma once
#include "AstarNode.h"
#include "Heap.h"
#include "Grid.h"

typedef int(*CalcHeuristic)(AstarNode*, AstarNode*);

using namespace std;
class AStar
{
public:
	AStar(int nMaxNodes);
	~AStar();
	//--------------------------------------------------
	//calculates the shortest to a target location
	//
	//Parameters: takes in a AstarNode and a dynamicArray
	//
	//Returns:
	//
	//--------------------------------------------------
	bool CalculatePath(AstarNode* pStart, AstarNode* pEnd, DynamicArray<AstarNode*>* finishedPath);
	//Calculate heuristic uses function pointer
	//--------------------------------------------------
	// Gets the heuristic function
	//
	//Parameters:  takes in a AstarNode
	//
	//Returns:
	//
	//--------------------------------------------------
	int GetHeuristic(AstarNode* pNode, AstarNode* pEnd);
	//--------------------------------------------------
	// sets the heuristic function
	//
	//Parameters:  takes in a AstarNode
	//
	//Returns:
	//
	//--------------------------------------------------
	void SetHeuristic(CalcHeuristic);
	CalcHeuristic myHeuristic;

	//void SortOpenList();

private:
	Heap m_OpenList;
	bool* m_ClosedList;
	int m_nMaxNodes;
};

