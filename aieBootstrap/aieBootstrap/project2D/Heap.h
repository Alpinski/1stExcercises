#pragma once
#include "DynamicArray.h"

class Heap
{
public:
	Heap();
	~Heap();

	int Peek();
	void Pop();

	//Clear all values from the heap
	void Clear();

	//Push/Remove values from the heap
	void Push(int value);
	void Remove(int value);

	//Get information about the heap itself
	int GetSize();
	int GetMaxSize();

	//Set the minimum amount of space needed for this heap
	void SetMaxSize(int minSize);

	//Checks if heap is empty
	bool IsEmpty();

	int GetParentIndex(int childIndex);



private:
	DynamicArray<int> m_pValueArray;
};

