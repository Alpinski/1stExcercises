#pragma once

#include "Vector2.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Enemy
{
public:
	Enemy(float posX, float posY);
	~Enemy();

	void Draw(Renderer2D* m_2dRenderer);

	// Set the enemy to be angry at the player.
	// This will change its appearance.
	void SetAngry(bool bAngry);

	const Vector2& GetPos();

private:
	Texture* m_pNormalTexture;
	Texture* m_pAngryTexture;
	
	Vector2 m_Pos;
	bool m_bAngry;
};


