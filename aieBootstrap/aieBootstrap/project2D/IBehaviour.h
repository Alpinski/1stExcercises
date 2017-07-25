#pragma once
class Agents;

class IBehaviour
{
public:
	IBehaviour() {}
	~IBehaviour() {}

	virtual bool Update(Agents* agent, float fDeltaTime) = 0;
};