#include "Seek.h"
#include "Input.h"
#include "Agents.h"
using namespace aie;

Seek::Seek(float fWeighting) : IBehaviour(fWeighting)
{
}


Seek::~Seek()
{
}

Vector2 Seek::Update(Agents * agent, float deltaTime)
{
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2MousePos(nMouseX - 50, nMouseY - 125);
	Vector2 v2Dir =  v2MousePos - agent->Getposition();
	v2Dir.Normalise();

	return v2Dir * 700.0f * deltaTime;
}

