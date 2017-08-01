#include "DecisionButtonPressed.h"
#include "Input.h"
#include "Agents.h"
using namespace aie;



DecisionButtonPressed::DecisionButtonPressed()
{
}


DecisionButtonPressed::~DecisionButtonPressed()
{
}

void DecisionButtonPressed::MakeDecision(Agents * pAgent, float fDeltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_SPACE))
	{
		m_pTrueDecision->MakeDecision(pAgent, fDeltaTime);
	}
	else
	{
		m_pFalseDecision->MakeDecision(pAgent, fDeltaTime);
	}
}
