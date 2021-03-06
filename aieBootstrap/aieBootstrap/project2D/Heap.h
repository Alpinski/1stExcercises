#pragma once
#include "DynamicArray.h"
#include "AstarNode.h"
#include <cmath>

class Heap
{
public:
	//--------------------------------------------------
	//default constructor and destructor
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	Heap(){}
	~Heap(){}
	//--------------------------------------------------
	//Peeks at what is at the top of heap
	//
	//Parameters:
	//
	//Returns: m_pValueArray[nTop]->m_nFScore
	//
	//--------------------------------------------------
	int Peek()
	{
		int nTop = m_pValueArray.Size() - 1;
		return m_pValueArray[nTop]->m_nFScore;
	}
	//--------------------------------------------------
	//pops an element off the heap
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	void Pop()
	{
		m_pValueArray.popBack();
	}
	//--------------------------------------------------
	//Clear all values from the heap
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------
	void Clear()
	{
		m_pValueArray.Clear();
	}
	//--------------------------------------------------
	//Push/Remove values from the heap
	//
	//Parameters:
	//
	//Returns:
	//
	//--------------------------------------------------	
	void Push(AstarNode* value)
	{
		// Add data to end of array
		m_pValueArray.pushBack(value);

		// Loop through and swap parent if data is smaller
		int current = m_pValueArray.Size() - 1;
		while (true)
		{
			if (current == 0)
				break;

			int parent = GetParentIndex(current);

			if (m_pValueArray[current]->m_nFScore < m_pValueArray[parent]->m_nFScore)
			{
				AstarNode* swap = m_pValueArray[current];
				m_pValueArray[current] = m_pValueArray[parent];
				m_pValueArray[parent] = swap;

				current = parent;
			}
			else
				break;
		}
	
	}

	AstarNode* Remove()
	{
		AstarNode* result = m_pValueArray[0];

		int last = m_pValueArray.Size() - 1;
		m_pValueArray[0] = m_pValueArray[last];

		int current = 0;

		while (true)
		{
			int child0 = GetChildIndex(current, 1);
			if (child0 > last)
			{
				break;
			}
			int child1 = GetChildIndex(current, 2);
			int smallerChild = child0;
			if (child1 <= last && m_pValueArray[child1]->m_nFScore < m_pValueArray[smallerChild]->m_nFScore)
			{
				smallerChild = child1;
			}

			if (m_pValueArray[smallerChild]->m_nFScore < m_pValueArray[current]->m_nFScore)
			{
				AstarNode* swap = m_pValueArray[current];
				m_pValueArray[current] = m_pValueArray[smallerChild];
				m_pValueArray[smallerChild] = swap;

				current = smallerChild;
			}
			else
			{
				break;
			}

		}
		m_pValueArray.popBack();
		return result;
	}
	//--------------------------------------------------
	//gets how big the heap is
	//
	//Parameters:
	//
	//Returns:m_pValueArray.Size();
	//
	//--------------------------------------------------
	int GetSize()
	{
		return m_pValueArray.Size();
	}
	//--------------------------------------------------
	//gets how big the heap can get
	//
	//Parameters:
	//
	//Returns:m_pValueArray.Capacity();
	//
	//--------------------------------------------------
	int GetMaxSize()
	{
		return m_pValueArray.Capacity();

	}

	//--------------------------------------------------
	//checks if the heap is empty
	//
	//Parameters:
	//
	//Returns:(m_pValueArray.Size() == 0);
	//
	//--------------------------------------------------
	bool IsEmpty()
	{
		return(m_pValueArray.Size() == 0);
	}
	//--------------------------------------------------
	//Gets the index of parent
	//
	//Parameters:
	//
	//Returns:(childIndex - 1) / 2;
	//
	//--------------------------------------------------
	int GetParentIndex(int childIndex)
	{
		return (childIndex - 1) / 2;
	}
	//--------------------------------------------------
	//Gets the index of child
	//
	//Parameters:
	//
	//Returns:(2 * parentIndex) + whichChild;
	//
	//--------------------------------------------------
	int GetChildIndex(int parentIndex, int whichChild)
	{
		return (2 * parentIndex) + whichChild;
	}
	//--------------------------------------------------
	//Looks at what is in the array
	//
	//Parameters: takes in an AstarNode
	//
	//Returns: i or -1
	//
	//--------------------------------------------------
	int Contains(AstarNode* pValueArray)
	{
		for (int i = 0; i < m_pValueArray.Size(); ++i)
		{
			if (m_pValueArray[i] == pValueArray)
			{
				return i;
			}
		}
		return -1;
	}
	//--------------------------------------------------
	//Sorts heap
	//
	//Parameters: takes in an int
	//
	//Returns:
	//
	//--------------------------------------------------
	void HeapSort(int index)
	{
		if (index == 0)
		{
			return;
		}
			

		int nNodeIndex = index;
		int nParent = GetParentIndex(index);

		//Check if node has a lower F value than parent, if so then swap.
		while (nParent >= 0 && m_pValueArray[nNodeIndex]->m_nFScore < m_pValueArray[nParent]->m_nFScore)
		{
			//Swap
			AstarNode* temp = m_pValueArray[nParent];
			m_pValueArray[nParent] = m_pValueArray[nNodeIndex];
			m_pValueArray[nNodeIndex] = temp;

			nNodeIndex = nParent;
			nParent = GetParentIndex(nNodeIndex);
		}
	}

private:
	DynamicArray<AstarNode*> m_pValueArray;
};

