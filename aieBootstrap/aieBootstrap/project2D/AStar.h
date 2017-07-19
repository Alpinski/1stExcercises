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

	bool CalculatePath(AstarNode* pStart, AstarNode* pEnd, DynamicArray<AstarNode*>* finishedPath);



	int GetHeuristic(AstarNode* pNode, AstarNode* pEnd);

	void SetHeuristic(CalcHeuristic);
	CalcHeuristic myHeuristic;

	//void SortOpenList();

private:
	Heap m_OpenList;
	bool* m_ClosedList;
	int m_nMaxNodes;
};

