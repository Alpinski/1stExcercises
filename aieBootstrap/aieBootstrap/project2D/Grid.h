#pragma once

struct GridNode;

class AStar;

class Grid
{
public:
	Grid();
	~Grid();

	bool GNode();

	void DrawGrid();

private:
	aie::Renderer2D*	m_2dRenderer;

	GridNode** m_ppGrid;
	AStar* m_pAStar;
};

