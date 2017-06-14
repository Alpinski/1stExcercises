#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "QuadTree.h"

class Enemy;
class Quadtree;

class Application2D : public aie::Application 
{
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	void UpdateEnemies(float deltatime);

	aie::Texture* m_mouseTexture;
	aie::Texture* m_mouseRadius;

	Enemy** m_apEnemyList;
	int m_MaxEnemiesPerRow;
	int m_MaxEnemiesPerColumn;
	int m_EnemyCount;

	Vector2 m_v2MousePos;
	float m_fMouseRadius;

	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;

	QuadTree* m_pQuadTree;
};