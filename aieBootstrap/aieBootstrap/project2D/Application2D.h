#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Grid.h"
#include "Player.h"
#include "StateMachine.h"

class DecisionTree;

class Application2D : public aie::Application {
public:
	


	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	StateMachine*		m_StateMachine;
	Player*				m_pPlayer;
	DecisionTree*		m_pDecisionTree;
	Grid*				m_Grid;

	float m_cameraX, m_cameraY;
	float m_timer;

};