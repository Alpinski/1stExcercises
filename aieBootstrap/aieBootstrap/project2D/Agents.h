#pragma once
#include "Vector2.h"
#include "IBehaviour.h"
#include "LinkedList.h"
#include "Renderer2D.h"
#include "StateMachine.h"
#include "Patrol.h"
class Agents
{
public:
	Agents();
	~Agents();

	virtual void update(float deltaTime) = 0;

	virtual void Draw(aie::Renderer2D* m_2dRenderer) = 0;
	Vector2* m_position;
protected:

	

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;


	Patrol*				m_pPatrol;
	StateMachine*		m_pStateActions;

	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	

	float m_timer = 0;
};

