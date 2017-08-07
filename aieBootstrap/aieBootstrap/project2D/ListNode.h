#pragma once

template <typename T>
class ListNode
{

public: 
	//--------------------------------------------------
	//default constructor and destructor
	//
	//Parameters:constructor takes in a float
	//
	//Returns:(2 * parentIndex) + whichChild;
	//
	//--------------------------------------------------
	ListNode() {};
	~ListNode() {};

	T data;
	ListNode* next;
	ListNode* prev;
};