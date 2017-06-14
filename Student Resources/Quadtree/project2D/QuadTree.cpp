#include "QuadTree.h"
#include "QuadNode.h"
#include "HelperFunctions.h"


QuadTree::QuadTree(Vector2 v2TopLeft, Vector2 v2BottomRight)
{
	m_pRootNode = new QuadNode(v2TopLeft.x, v2TopLeft.y, v2BottomRight.x, v2BottomRight.y);
	m_pEnemyList = new list<Enemy*>();
}


QuadTree::~QuadTree()
{
	if (m_pEnemyList)
	{
		delete m_pEnemyList;
		m_pEnemyList = nullptr;

	}
	if (m_pRootNode)
	{
		delete m_pRootNode;
		m_pRootNode = nullptr;
	}
}

void QuadTree::AddEnemy(Enemy * pEnemy)
{
	if (m_pRootNode)
	{
		m_pRootNode->AddEnemy(pEnemy);
	}
}

void QuadTree::Draw(Renderer2D * pRenderer)
{
	if (m_pRootNode)
	{
		m_pRootNode->Draw(pRenderer);
	}
}

list<Enemy*>* QuadTree::GetEnemiesInRange(Vector2 v2Centre, float fRadius)
{
	m_pEnemyList->clear();

	CheckNodesRecursively(m_pRootNode, v2Centre, fRadius);

	return m_pEnemyList;
}

void QuadTree::CheckNodesRecursively(QuadNode * pNode, Vector2 v2Centre, float fRadius)
{
	//find all enemiesin the quads
	//use CircleSquareCollision() in HF.h
	//recursively call this function on all child nodes in a for loop.
	if (pNode)
	{
		if (CircleSquareCollision(v2Centre, fRadius, pNode->m_v2BottomRight, pNode->m_v2TopLeft))
		{
			if (pNode->m_pEnemy)
			{
				m_pEnemyList->push_back(pNode->m_pEnemy);
			}
			for (int i = 0; i < QUAD_COUNT; ++i)
			{
				CheckNodesRecursively(pNode->m_apNodes[i], v2Centre, fRadius);
			}
		}
	}
}
