#pragma once
#include "DynamicArray.h"

struct AstarNode;

using namespace std;

struct AstarEdge
{
	AstarNode* m_pEndNode;
	int m_nCost;
};

struct AstarNode
{
public:
	AstarNode(int nIndex)
	{
		m_bBlocked = false;
		m_pPrevious = nullptr;
		m_nGScore = 0;
		m_nHScore = 0;
		m_nFScore = 0;
		m_nIndex = nIndex;
	}

	virtual ~AstarNode() 
	{
		for (int i = 0; i < m_AdjacentList.Size(); ++i)
		{
			delete m_AdjacentList[i];
		}
	}

	AstarNode* m_pPrevious;

	int m_nGScore;
	int m_nHScore;
	int m_nFScore;

	int m_nIndex;
	bool m_bBlocked;

	DynamicArray<AstarEdge*> m_AdjacentList;
};