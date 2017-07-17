#pragma once
#include"AstarNode.h"
#include "Heap.h"
using namespace std;
class AStar
{
public:
	AStar();
	~AStar();

	bool CalculatePath(AstarNode* pStart, AstarNode* pEnd, vector<AstarNode*>* finishedPath);

	//void SortOpenList();

private:
	Heap<AstarNode*> m_OpenList;
	vector<bool> m_ClosedList;
};

