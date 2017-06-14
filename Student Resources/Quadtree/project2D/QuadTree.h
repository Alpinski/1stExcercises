#pragma once
#include "Vector2.h"
#include <list>
#include "Renderer2D.h"
using namespace std;
using namespace aie;

class QuadNode;
class Enemy;

class QuadTree
{
public:
	QuadTree(Vector2 v2TopLeft, Vector2 v2BottomRight);
	~QuadTree();

	void AddEnemy(Enemy* pEnemy);
	void Draw(Renderer2D* pRenderer);

	list<Enemy*>* GetEnemiesInRange(Vector2 v2Centre, float fRadius);


private:
	QuadNode* m_pRootNode;
	list<Enemy*>* m_pEnemyList;

	void CheckNodesRecursively(QuadNode* pNode, Vector2 v2Centre, float fRadius);
};

