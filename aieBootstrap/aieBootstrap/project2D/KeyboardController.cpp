#include "KeyboardController.h"
#include "Input.h"

using namespace aie;

KeyboardController::KeyboardController() : IBehaviour(1.0f)
{
}


KeyboardController::~KeyboardController()
{
}

bool KeyboardController::update(Agents * agent, float deltaTime)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
	{
		
	}

	return true;
}
