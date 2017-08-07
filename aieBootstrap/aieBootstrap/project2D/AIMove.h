#pragma once
#include "BaseState.h"
#include "Vector2.h"
#include "AStar.h"
#include "GridNode.h"
#include "IBehaviour.h"
#include <vector>
#include "Follow.h"

class AIMove : public BaseState
{
public:
	//-----------------------------------------------------
	//Default constructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	AIMove();
	//-----------------------------------------------------
	//default destructor
	//
	//parameters:
	//
	//return:
	//
	//-----------------------------------------------------
	~AIMove();
	//--------------------------------------------------
	//Determines what will happen, when you enter the state 
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//Returns:
	//		None
	//--------------------------------------------------
	void OnEnter(StateMachine* pMachine);
	//--------------------------------------------------
	//Updates the state you are on in accordance with delta time(if there is anything to even update).
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//			Also takes in a float.
	//Returns:
	//		None
	//--------------------------------------------------
	void OnUpdate(Agents* pAgent, float fDeltaTime, StateMachine* pMachine);
	//--------------------------------------------------
	//Initiates the renderer to draw the object of your choosing
	//
	//Parameters:
	//			Takes in  renderer2d which is what allows you to render anything in the game
	//Returns:
	//		None
	//--------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);
	//--------------------------------------------------
	//Determines what will happen, when you exit the state 
	//
	//Parameters:
	//			Takes in statemachine pointer which allows you to use the functions in state machine(eg. pMachine->Draw)
	//Returns:
	//		None
	//--------------------------------------------------
	void OnExit(StateMachine* pMachine);

private:


	int			m_nNextNode;
	Grid*		m_pGrid;
	Vector2		m_v2Pos;
	AStar*		m_pAStar;


	DynamicArray<AstarNode*> m_path;
};

