#include "Agents.h"
#include "Texture.h"


Agents::Agents()
{
}


Agents::~Agents()
{
}


void Agents::update(float deltaTime)
{
	for (int i = 0; i < m_behaviours; ++i)
	{
		m_behaviours->Update(this, deltaTime);
	}
}

void Agents::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);
}

void Agents::MovementUpdate(float Deltatime)
{
	
}
