#include "Grid.h"
#include "Defines.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include <cmath>


Grid* Grid::m_pInstance = nullptr;

Grid::Grid()
{
	m_ppGrid = new GridNode*[GRID_SIZE * GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;
			//calculate position of node in game world
			Vector2 pos(x * NODE_SIZE, y * NODE_SIZE);
			//create the node
			m_ppGrid[index] = new GridNode(pos, index, x, y);

			if (x % 3 == 0 && y != 5)
			{
				m_ppGrid[index]->m_bBlocked = true;
			}
		}
	}

	//connect up adjacent nodes
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;
			GridNode* currentNode = m_ppGrid[index];
			//adjacent nodes
			// -------------
			// |   | 3 |   |
			// -------------
			// | 0 | M | 2 |
			// -------------
			// |   | 1 |   |
			// -------------
			for (int a = 0; a < 4; ++a)
			{
				int localX = x;
				int localY = y;

				if (a % 2 == 0)
				{
					localX += a - 1;
				}
				else
				{
					localY += a - 2;
				}

				if (localX < 0 || localX >= GRID_SIZE)
				{
					continue;
				}
				if (localY < 0 || localY >= GRID_SIZE)
				{
					continue;
				}

				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				AstarEdge* pEdge = new AstarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = COST;

				currentNode->m_AdjacentList.pushBack(pEdge);
			}
			//diagonal nodes
			// -------------
			// | 1 |   | 2 |
			// -------------
			// |   | M |   |
			// -------------
			// | 0 |   | 3 |
			// -------------
			for (int d = 0; d < 4; ++d)
			{
				int localX = x;
				int localY = y;

				if (d % 2 == 0)
				{
					localX += d - 1;
					localY += d - 1;
				}
				else
				{
					localX += d - 2;
					localY -= d - 2;
				}

				if (localX < 0 || localX >= GRID_SIZE)
				{
					continue;
				}

				if (localY < 0 || localY >= GRID_SIZE)
				{
					continue;
				}

				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				AstarEdge* pEdge = new AstarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = COST_DIAGONAL;

				currentNode->m_AdjacentList.pushBack(pEdge);
			}
		}
	}
}


Grid::~Grid()
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}
	delete[] m_ppGrid;
}

void Grid::DrawGrid(aie::Renderer2D * m_2dRenderer)
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;

		if (m_ppGrid[i]->m_bBlocked)
		{
			m_2dRenderer->setRenderColour(BLACK);
		}
		else
		{
			m_2dRenderer->setRenderColour(WHITE);
		}

		m_2dRenderer->drawBox(x, y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);

		for (int a = 0; a < m_ppGrid[i]->m_AdjacentList.Size(); ++a)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

			float otherX = otherNode->m_v2Pos.x;
			float otherY = otherNode->m_v2Pos.y;
			m_2dRenderer->setRenderColour(BLACK);
			m_2dRenderer->drawLine(x, y, otherX, otherY, EDGE_THICKNESS);
			m_2dRenderer->setRenderColour(0x0000FFFF);
		}
	}

	//Draw path
	
}

GridNode* Grid::getNode(int index)
{
	return m_ppGrid[index];
}

GridNode* Grid::GetGrid(int nIndex)
{
	return m_ppGrid[nIndex];
}

void Grid::Create()
{
	if (!m_pInstance)
	{
		m_pInstance = new Grid();
	}
}

void Grid::Destroy()
{
	delete m_pInstance;
}

Grid* Grid::GetInstance()
{
	return m_pInstance;
}