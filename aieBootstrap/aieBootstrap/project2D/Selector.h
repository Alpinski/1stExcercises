#pragma once

#include "Composite.h"
#include "BehaviourNode.h"

class Selector : public Composite
{
	EBehaviourResult Execute()
	{
		for (unsigned int i = 0; i < Children.size(); ++i)
		{
			if (Children[i]->Execute() == EBHEAVIOUR_SUCCESS)
			{
				return EBHEAVIOUR_SUCCESS;
			}
		}
		return EBEHAVIOUR_FAILURE;
	}
};