#pragma once
#include <vector>

struct AstarNode;

struct AstarEdge
{
	AstarNode* m_pEndNode;
	int m_nCost;
};

struct AstarNode
{
public:
	AstarNode()
	{
		m_pPrevious = 0;
		m_nGScore = 0;
		m_nHScore = 0;
		m_nFScore = 0;
	}

	virtual ~AstarNode() 
	{
		for (size_t i = 0; i < m_AdjacentList.Size(); ++i)
		{
			delete m_AdjacentList[i];
		}
	}

	AstarNode* m_pPrevious;

	int m_nGScore;
	int m_nHScore;
	int m_nFScore;

	vector<AstarEdge*> m_AdjacentList;
};