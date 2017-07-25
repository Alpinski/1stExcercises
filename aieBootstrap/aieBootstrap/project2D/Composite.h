#pragma once
#include "BehaviourNode.h"
#include <vector>

using namespace std;

class Composite : public BehaviourNode
{
protected:

	vector<BehaviourNode*> Children;

};
