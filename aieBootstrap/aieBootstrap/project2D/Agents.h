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
	virtual ~Agents() {};

	virtual void update(float deltaTime) = 0;

	virtual void Draw(aie::Renderer2D* m_2dRenderer) = 0;

	Vector2 Getposition() {return m_position;}

	void SetPosition(Vector2 v2Pos) { m_position = v2Pos;}
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;


	Patrol*				m_pPatrol;
	StateMachine*		m_pStateMachine;
	Vector2				m_position;
	Vector2				m_force;
	Vector2				m_acceleration;
	Vector2				m_velocity;
	

	float m_timer = 0;
};

