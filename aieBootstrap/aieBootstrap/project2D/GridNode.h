#pragma once
#include "AstarNode.h"
#include "Vector2.h"

struct GridNode : public AstarNode
{
public:
	GridNode() {};
	~GridNode() {};

	GridNode(Vector2 pos, int nIndexX, int nIndexY) : AstarNode()
	{
		m_v2Pos = pos;
		m_nIndexX = nIndexX;
		m_nIndexY = nIndexY;
	}

	int m_nIndexX;
	int m_nIndexY;

	Vector2 m_v2Pos;
};