#pragma once
#include "AstarNode.h"
#include "Heap.h"

using namespace std;
class AStar
{
public:
	AStar(int nMaxNodes);
	~AStar();

	bool CalculatePath(AstarNode* pStart, AstarNode* pEnd, DynamicArray<AstarNode*>* finishedPath);
	int CalculateHeuristic(AstarNode* pNode, AstarNode* pEnd);
	//void SortOpenList();

private:
	Heap m_OpenList;
	bool* m_ClosedList;
	int m_nMaxNodes;
};

