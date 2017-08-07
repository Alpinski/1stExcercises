#pragma once
#include "IBehaviour.h"
class KeyboardController : public IBehaviour
{
	//not used
public:
	KeyboardController();
	~KeyboardController();

	bool update(Agents* agent, float deltaTime);

};

