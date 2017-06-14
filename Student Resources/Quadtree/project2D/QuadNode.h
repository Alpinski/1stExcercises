#pragma once
#include "Vector2.h"
#include "Renderer2D.h"
using namespace aie;
class Enemy;

// Quad tree is always divided into 4
#define QUAD_COUNT 4

class QuadNode
{
public:
	QuadNode(float fLeft, float fTop, float fRight, float fBottom);
	~QuadNode();

	void AddEnemy(Enemy* pEnemy);
	bool isInside(Vector2 v2Pos);
	void Draw(Renderer2D* m_2dRenderer);

	Vector2 m_v2TopLeft;
	Vector2 m_v2BottomRight;

	Enemy* m_pEnemy;

	QuadNode* m_apNodes[QUAD_COUNT];


};

