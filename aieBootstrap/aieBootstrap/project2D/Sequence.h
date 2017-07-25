#pragma once

#include "Composite.h"
#include "BehaviourNode.h"

class Sequence : public Composite
{
	EBehaviourResult Execute()
	{
		for (unsigned int i = 0; i < Children.size(); ++i)
		{
			if (Children[i]->Execute() == EBEHAVIOUR_FAILURE)
			{
				return EBEHAVIOUR_FAILURE;
			}
		}
		return EBHEAVIOUR_SUCCESS;
	}
};