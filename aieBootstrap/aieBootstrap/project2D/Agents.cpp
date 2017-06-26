#include "Agents.h"
#include "Renderer2D.h"
#include "Texture.h"


Agents::Agents()
{
}


Agents::~Agents()
{
}


void Agents::update(float deltaTime)
{
	for (auto& behaviour : m_behaviours)
	{
		behaviour->Update(this, deltaTime);
	}
}

void Agents::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);
}

void Agents::MovementUpdate(float Deltatime)
{
	
}
