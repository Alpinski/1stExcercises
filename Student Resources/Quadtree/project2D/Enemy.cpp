#include "Enemy.h"

#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

Enemy::Enemy(float posX, float posY)
{
	m_pNormalTexture = new Texture("./textures/agent_search.png");
	m_pAngryTexture = new Texture("./textures/agent_angry.png");
	m_Pos.x = posX;
	m_Pos.y = posY;
	m_bAngry = false;
}

Enemy::~Enemy()
{
	delete m_pNormalTexture;
	delete m_pAngryTexture;
}

void Enemy::Draw(Renderer2D* m_2dRenderer)
{
	if(m_bAngry)
		m_2dRenderer->drawSprite(m_pAngryTexture, m_Pos.x, m_Pos.y);
	else
		m_2dRenderer->drawSprite(m_pNormalTexture, m_Pos.x, m_Pos.y);
}

// Set the enemy to be angry at the player.
// This will change its appearance.
void Enemy::SetAngry(bool bAngry)
{
	//Change the enemy's state.
	m_bAngry = bAngry;
}

const Vector2& Enemy::GetPos()
{
	return m_Pos;
}

