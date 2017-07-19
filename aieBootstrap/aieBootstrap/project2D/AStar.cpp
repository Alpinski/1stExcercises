#include "AStar.h"
#include "GridNode.h"
#include <cmath>



AStar::AStar(int nMaxNodes)
{
	m_ClosedList = new bool[nMaxNodes];
	m_nMaxNodes = nMaxNodes;

}

AStar::~AStar()
{
	delete[] m_ClosedList;
}

bool AStar::CalculatePath(AstarNode * pStart, AstarNode * pEnd, DynamicArray<AstarNode*>* finishedPath)
{

	

	//clear open list.
	m_OpenList.Clear();
	//set all elements in closed list to false
	memset(m_ClosedList, 0, sizeof(bool) * m_nMaxNodes);

	//set start nodes G score to zero
	pStart->m_nGScore = 0;
	//calculate start nodes hScore(for now set to zero)
	pStart->m_nHScore = myHeuristic(pStart, pEnd);
	//calculate start nodes fScore
	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;
	//set start node's m_preivious to null
	pStart->m_pPrevious = nullptr;
	// Add start node to open list
	m_OpenList.Push(pStart);
	

	//While there are still nodes in the open list
	while (m_OpenList.GetSize() > 0)
	{

		//Get the node form the open list with the lowest f score
		//remove that node from the open list
		AstarNode* pCurrentNode = m_OpenList.Remove();
		

		//add that node to the closed list
		m_ClosedList[pCurrentNode->m_nIndex] = true;

		//if current node is the end node, we are finished.
		if (pCurrentNode == pEnd)
		{
			//build path(remember it is backwards so we need to fix that)
			{
				AstarNode* pNode = pEnd;
				do
				{
					finishedPath->pushFront(pNode);
					pNode = pNode->m_pPrevious;
				} while (pNode);
			//return true to indicate that we found a valid path
				return true;
			}
		}

		
	//loop through all current Node's neighbours
		for (int i = 0; i < pCurrentNode->m_AdjacentList.Size(); ++i)
		{

			//skip neighbours that are already in the closed list
			AstarNode* pNeighbour = pCurrentNode->m_AdjacentList[i]->m_pEndNode;
			int nCost = pCurrentNode->m_AdjacentList[i]->m_nCost;

			//skip walls
			if (pNeighbour->m_bBlocked)
			{
				continue;
			}

			if (m_ClosedList[pNeighbour->m_nIndex])
			{
				continue;
			}
			//if neighbour is already in open list
			if (m_OpenList.Contains(pNeighbour))
			{
				//check if this current path is better than old path(lower f score)
				if (pCurrentNode->m_nFScore + nCost < pNeighbour->m_nFScore)
				{
					//update G score
					pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;
					//update f score
					pNeighbour->m_nFScore = pCurrentNode->m_nGScore + pCurrentNode->m_nHScore;
					//update prev node pointer
					pNeighbour->m_pPrevious = pCurrentNode;
				}
			}
			//else (neightbour not in open list)
			else
			{
				//calculate G score
				pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;
				//calculate H score
				pNeighbour->m_nHScore = myHeuristic(pNeighbour, pEnd);
				//calculate F score
				pNeighbour->m_nFScore = pCurrentNode->m_nGScore + pCurrentNode->m_nHScore;
				//ser prev node pointer
				pNeighbour->m_pPrevious = pCurrentNode;
				//add neighbour to open list
				m_OpenList.Push(pNeighbour);
			}
		}
	}
	//no path found if we got to here, so return false
	return false;
}

int AStar::GetHeuristic(AstarNode* pNode, AstarNode* pEnd)
{
	return CalculateHeuristic(pNode, pEnd);
}

void AStar::SetHeuristic(CalcHeuristic DasHeuristic)
{
	myHeuristic = DasHeuristic;
}

//void AStar::SortOpenList()
//{
//	for (size_t i = 0; i < m_OpenList.size(); ++i)
//	{
//		for (size_t j = 0; j < m_OpenList.size() - 1; ++j)
//		{
//			if (m_OpenList[j]->m_nFScore > m_OpenList[j + 1]->m_nFScore)
//			{
//				AstarNode*swap = m_OpenList[j];
//				m_OpenList[j] = m_OpenList[j + 1];
//				m_OpenList[j + 1] = swap;
//			}
//		}
//	}
//}