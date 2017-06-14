#include "QuadNode.h"
#include <memory>
#include "HelperFunctions.h"
#include "Enemy.h"

QuadNode::QuadNode(float fLeft, float fTop, float fRight, float fBottom)
{
	m_v2TopLeft.x = fLeft;
	m_v2TopLeft.y = fTop;
	m_v2BottomRight.x = fRight;
	m_v2BottomRight.y = fBottom;

	m_pEnemy = nullptr;

	memset(m_apNodes, 0, sizeof(QuadNode*) * QUAD_COUNT);

}

QuadNode::~QuadNode()
{
	for (int i = 0; i < QUAD_COUNT; ++i)
	{
		if (m_apNodes[i])
		{
			delete m_apNodes[i];
			m_apNodes[i] = nullptr;
		}
	}
}

void QuadNode::AddEnemy(Enemy * pEnemy)
{
	//If child Nodes exist
		//loop thrugh all child nodes and check (isInside())whichchild the enemy belongs in.
			// When we find the node it's inside: recursively call this addenemy() on that node (M_apnodes[i]->ADDenemy())
	//else
		//if no enemy child
			//Set enemy child to be pEnemy
		//else ()there is already am enemy
			//We need to subdivide this node into 4 subnodes and make them children .
			// We need to move the existing enemy pointer into one of the children.
			//then finally put pEnemy in the correct child
	
			//Create 4 nodes using new keyword
			//AddEnemy(m_penemy); //Re-adding the existing that is already in this node.
			//m_pEnemy = nullptr;
			//AddEnemy(pEnemy);

	if (m_apNodes[0] != nullptr)
	{
		for (int i = 0; i < QUAD_COUNT; ++i)
		{
			if (m_apNodes[i]->isInside(pEnemy->GetPos()))
			{
				m_apNodes[i]->AddEnemy(pEnemy);
				break;
			}
		}
	}
	else 
	{
		if (!this->m_pEnemy)
		{
			this->m_pEnemy = pEnemy;
		}
		else
		{
			float Width = m_v2TopLeft.x - m_v2BottomRight.x;
			float Height = m_v2TopLeft.y - m_v2BottomRight.y;

			m_apNodes[0] = new QuadNode(m_v2TopLeft.x, m_v2TopLeft.y, m_v2TopLeft.x + (Width / 2), m_v2TopLeft.y + (Height/2));
			m_apNodes[1] = new QuadNode(m_v2TopLeft.x + (Width / 2), m_v2TopLeft.y, m_v2TopLeft.x + Width, m_v2TopLeft.y + (Height / 2));
			m_apNodes[2] = new QuadNode(m_v2TopLeft.x + (Width / 2), m_v2TopLeft.y + (Height / 2), m_v2BottomRight.x + Width, m_v2BottomRight.y + (Height / 2));
			m_apNodes[3] = new QuadNode(m_v2TopLeft.x + (Width / 2), m_v2TopLeft.y + (Height / 2), m_v2BottomRight.x, m_v2BottomRight.y);

			AddEnemy(this->m_pEnemy);
			AddEnemy(pEnemy);

			this->m_pEnemy = nullptr;
		}
	}

}

bool QuadNode::isInside(Vector2 v2Pos)
{
	//point vs aabb collision test

	if (m_v2BottomRight.x >= v2Pos.x && m_v2BottomRight.y <= v2Pos.y && m_v2TopLeft.x >= v2Pos.x && m_v2TopLeft.y <= v2Pos.y)
	{
		return false;
	}
	

	return false;
}

void QuadNode::Draw(Renderer2D * m_2dRenderer)
{
	DrawSquare(m_2dRenderer, m_v2TopLeft, m_v2BottomRight);

	for (int i = 0; i < QUAD_COUNT; ++i)
	{
		if (m_apNodes[i])
		{
			m_apNodes[i]->Draw(m_2dRenderer);
		}
	}

}
