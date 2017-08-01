#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "DecisionTree.h"
#include "Idle.h"
#include "Patrol.h"
using namespace aie;



Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();

	m_shipTexture = new Texture("./textures/ship.png");

	m_font = new Font("./font/consolas.ttf", 32);

	m_audio = new Audio("./audio/powerup.wav");

	//m_StateMachine = new StateMachine();

	Grid::Create();

	m_AI = new AI();

	m_pPlayer = new Player();

	//m_pPlayer2 = new Player2();

	m_pDecisionTree = new DecisionTree();



	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	return true;
}

void Application2D::shutdown() 
{
	delete m_audio;
	delete m_font;
	delete m_shipTexture;
	delete m_AI;
	Grid::Destroy();
	delete m_2dRenderer;
	//delete m_pPlayer2;
	//delete m_Grid;
	delete m_pDecisionTree;
	delete m_pPlayer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;


	//m_StateMachine->Update(deltaTime);

	// input example
	Input* input = Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	// example of audio
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
		m_audio->play();

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();

	m_pPlayer->update(deltaTime);
	//m_pPlayer2->update(deltaTime);
	m_AI->update(deltaTime);
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(-50, -125);

	// begin drawing sprites
	m_2dRenderer->begin();

	Grid::GetInstance()->DrawGrid(m_2dRenderer);
	m_pPlayer->Draw(m_2dRenderer);
//	m_pPlayer2->Draw(m_2dRenderer);
	m_AI->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 550);
	m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}