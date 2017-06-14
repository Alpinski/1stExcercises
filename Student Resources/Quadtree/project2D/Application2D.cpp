#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Enemy.h"
#include "HelperFunctions.h"

#include <list>
#include <stdio.h>
#include <time.h>

using namespace aie;

// Used to arrange enemies in a square grid that fills most of the screen
#define SCREEN_PADDING_X 200
#define SCREEN_PADDING_Y 200
#define ENEMY_SPACING 100

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();
	setVSync(false);



	srand((unsigned int)time(nullptr));

	// Load in the textures that we want to use
	m_font = new Font("./font/consolas.ttf", 16);
	m_mouseTexture = new Texture("./textures/Player.png");
	m_mouseRadius = new Texture("./textures/Sight.png");

	// Defaults for mouse X and Y
	m_v2MousePos.x = 0.0f;
	m_v2MousePos.y = 0.0f;
	m_fMouseRadius = 100.0f;

	Vector2 v2LevelTopLeft;
	v2LevelTopLeft.x = 0.0f;
	v2LevelTopLeft.y = 0.0f;
	Vector2 v2LevelBottomRight;
	v2LevelBottomRight.x = (float)SCREEN_WIDTH;
	v2LevelBottomRight.y = (float)SCREEN_HEIGHT;

	m_pQuadTree = new QuadTree(v2LevelTopLeft, v2LevelBottomRight);

	// Spawn a grid of slightly randomly placed enemies.
	// First calculate how many enemies we can fit on the screen.
	m_MaxEnemiesPerRow = (SCREEN_WIDTH - SCREEN_PADDING_X) / ENEMY_SPACING;
	m_MaxEnemiesPerColumn = (SCREEN_HEIGHT - SCREEN_PADDING_Y) / ENEMY_SPACING;
	m_EnemyCount = m_MaxEnemiesPerRow * m_MaxEnemiesPerColumn;

	// Create the enemies
	m_apEnemyList = new Enemy*[m_MaxEnemiesPerRow * m_MaxEnemiesPerColumn];
	for (int x = 0; x < m_MaxEnemiesPerRow; ++x)
	{
		for (int y = 0; y < m_MaxEnemiesPerColumn; ++y)
		{
			int index = (y * m_MaxEnemiesPerRow) + x;
			float posX = (float)SCREEN_PADDING_X + (x * ENEMY_SPACING);
			float posY = (float)SCREEN_PADDING_Y + (y * ENEMY_SPACING);

			posX += -ENEMY_SPACING + rand() % (ENEMY_SPACING * 2);
			posY += -(ENEMY_SPACING / 2) + rand() % (ENEMY_SPACING);

			m_apEnemyList[index] = new Enemy(posX, posY);
			m_pQuadTree->AddEnemy(m_apEnemyList[index]);
		}
	}

	return true;
}

void Application2D::shutdown() 
{
	// DELETE EVERYTHING!!!
	for (int i = 0; i < m_EnemyCount; ++i)
	{
		delete m_apEnemyList[i];
	}
	delete m_apEnemyList;
	delete m_pQuadTree;
	delete m_mouseTexture;
	delete m_font;
	delete m_2dRenderer;
	
}

void Application2D::update(float deltaTime) 
{
	// input example
	Input* input = Input::getInstance();

	// Get the mouse X and Y position
	int mouseX;
	int mouseY;
	input->getMouseXY(&mouseX, &mouseY);
	m_v2MousePos.x = (float)mouseX;
	m_v2MousePos.y = (float)mouseY;

	// Update all the enemies
	UpdateEnemies(deltaTime);

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pQuadTree->Draw(m_2dRenderer);

	// Draw mouse texture
	m_2dRenderer->drawSprite(m_mouseRadius, m_v2MousePos.x, m_v2MousePos.y);
	m_2dRenderer->drawSprite(m_mouseTexture, m_v2MousePos.x, m_v2MousePos.y);

	// output some text, uses the last used colour
	char buffer[32];
	sprintf_s(buffer, 32, "FPS: %d", getFPS());
	m_2dRenderer->drawText(m_font, "Enemies within range of the mouse turn red.", 10, SCREEN_HEIGHT - 24);
	m_2dRenderer->drawText(m_font, "This is linearly checking the distance to every enemy which is slow!", 10, SCREEN_HEIGHT - 48);
	m_2dRenderer->drawText(m_font, "(The distance check has been artificially slowed down in this project to make this even more obvious)", 10, SCREEN_HEIGHT - 72);
	m_2dRenderer->drawText(m_font, "A Quadtree would reduce the number of distance checks and would make this a lot faster.", 10, SCREEN_HEIGHT - 96);
	m_2dRenderer->drawText(m_font, buffer, 10, SCREEN_HEIGHT - 120);

	// Draw enemies
	for (int i = 0; i < m_EnemyCount; ++i)
	{
		m_apEnemyList[i]->Draw(m_2dRenderer);
	}

	// done drawing sprites
	m_2dRenderer->end();
}

// Update all the enemies so they become aggresive if the mouse cursor is within a certain distance of them.
// Change them back to normal once the mouse leaves that area
void Application2D::UpdateEnemies(float deltatime)
{
	//Reset all enemies
	for (int i = 0; i < m_EnemyCount; ++i)
	{
		m_apEnemyList[i]->SetAngry(false);
	}

	//Linear trawl through all the enemies in the level to check if they are close to the mouse
	//If so make them angry. This is slow!
	/*for (int i = 0; i < m_EnemyCount; ++i)
	{
		float fDist = Vector2::GetDistance(m_apEnemyList[i]->GetPos(), m_v2MousePos);
		if (fDist < m_fMouseRadius)
			m_apEnemyList[i]->SetAngry(true);
	}*/

	//Use Quadtree here instead to find enemies that are roughly nearby and then do the distance check just on those ones to confirm.

	//<BEGIN PSEUDOCODE>

	list<Enemy*> * pList = m_pQuadTree->GetEnemiesInRange(m_v2MousePos, m_fMouseRadius);

	for (auto iterator = pList->begin(); iterator != pList->end(); ++iterator)
	{
		Enemy* pEnemy = *iterator;
		if (pEnemy)
		{
				float fDist = Vector2::GetDistance(pEnemy->GetPos(), m_v2MousePos);
			if (fDist < m_fMouseRadius)
				pEnemy->SetAngry(true);
		}
	}

	//END LOOP
	//<END PSEUDOCODE>
}
