#include "AStar.h"



AStar::AStar()
{
}


AStar::~AStar()
{
}

bool AStar::CalculatePath(AstarNode * pStart, AstarNode * pEnd, vector<AstarNode*>* finishedPath)
{
	//reset everything incase there was a previous path.
	//add start node to open list.

	//While there are still nodes in the open list
		//Get the node form the open list with the lowest f score
		//remove that node from the open list
		//add that node to the closed list

		//if current node is the end node, we are finished.
			//build path(remember it is backwards so we need to fix that)
			//return that we found a valid path

		//loop through all current Node's neighbours
			//skip neighbours that are already in the closed list

			//if neighbour is already in open list
				//check if this current path is better than old path(lower f score)
					//update G score
					//update f score
					//update prev node pointer

			//else (neightbour not in open list)
				//calculate G score
				//calculate H score
				//calculate F score
				//ser prev node pointer
				//add neighbour to open list
	
	//no path found if we got to here, so return false

	return false;
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