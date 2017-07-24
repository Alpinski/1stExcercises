#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "AstarNode.h"



struct GridNode;

class AStar;

class Grid
{
public:
	Grid();
	~Grid();

	void DrawGrid(aie::Renderer2D * m_2dRenderer);

	GridNode* getNode(int index);

private:

	aie::Renderer2D*	m_2dRenderer;

	GridNode** m_ppGrid;
	AStar* m_pAStar;
};

	int CalculateHeuristic(AstarNode * pNode, AstarNode * pEnd);