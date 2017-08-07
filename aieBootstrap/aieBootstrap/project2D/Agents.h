#pragma once
#include "Vector2.h"
#include "IBehaviour.h"
#include "LinkedList.h"
#include "Renderer2D.h"
#include "StateMachine.h"
#include "DecisionNothingPressed.h"
	
class Agents
{
public:
	//-----------------------------------------------------
	//default constructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	Agents();
	//-----------------------------------------------------
	//virtual destructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	virtual ~Agents() {};
	//-----------------------------------------------------
	//base update function for any agents
	//
	//parameters: takes in a float
	//
	//return:
	//
	//-----------------------------------------------------
	virtual void update(float deltaTime) = 0;
	//-----------------------------------------------------
	//base draw function for any agents
	//
	//parameters: takes in a renderer2d
	//
	//return:
	//
	//-----------------------------------------------------
	virtual void Draw(aie::Renderer2D* m_2dRenderer) = 0;
	//-----------------------------------------------------
	//Gets the position of an agent
	//
	//parameters:
	//
	//return: returns m_position
	//
	//-----------------------------------------------------
	Vector2 Getposition() {return m_position;}
	//-----------------------------------------------------
	//sets the position of an agent
	//
	//parameters: takes in a vector2
	//
	//return: 
	//
	//-----------------------------------------------------
	void SetPosition(Vector2 v2Pos) { m_position = v2Pos;}
	//-----------------------------------------------------
	//Sets the angle of an agent
	//
	//parameters: takes in a vector2
	//
	//return:
	//
	//-----------------------------------------------------
	void setAngle(Vector2 Facing)
	{
		m_v2Facing = Facing;
	}
	//-----------------------------------------------------
	//gets the angle of an agent
	//
	//parameters:
	//
	//return: returns m_v2Facing
	//
	//-----------------------------------------------------
	Vector2 getAngle()
	{
		return m_v2Facing;
	}

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;

	Vector2				m_v2Facing;
	StateMachine*		m_pStateMachine;
	Vector2				m_position;
	Vector2				m_force;
	Vector2				m_acceleration;
	Vector2				m_velocity;
	

	float m_timer = 0;
};

