#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Grid.h"
#include "Player.h"
#include "StateMachine.h"
#include "AI.h"
#include "Player2.h"

class DecisionTree;

class Application2D : public aie::Application {
public:
	


	Application2D();
	virtual ~Application2D();
	//--------------------------------------------------
	//runs all the functions inside and creates the player, rock,etc
	//Parameters:
	//Returns:
	//--------------------------------------------------
	virtual bool startup();
	//--------------------------------------------------
	//Deletes everything that was created by the startup function
	//Parameters:
	//Returns:
	//--------------------------------------------------
	virtual void shutdown();
	//--------------------------------------------------
	//Updates player and rock in accordance with delta time
	//Parameters:
	//			takes in a float
	//Returns:
	//--------------------------------------------------
	virtual void update(float deltaTime);
	//--------------------------------------------------
	//main draw function draws everything, starts the renderer and ends it.
	//Parameters:
	//Returns:
	//--------------------------------------------------
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	AI*					m_AI;
	StateMachine*		m_StateMachine;
	Player*				m_pPlayer;
	DecisionTree*		m_pDecisionTree;
	Grid*				m_Grid;
	//Player2*			m_pPlayer2;

	float m_cameraX, m_cameraY;
	float m_timer;

};