#pragma once
#include "DynamicArray.h"
#include "AstarNode.h"
#include <cmath>

class Heap
{
public:
	Heap(){}
	~Heap(){}

	int Peek()
	{
		int nTop = m_pValueArray.Size() - 1;
		return m_pValueArray[nTop]->m_nFScore;
	}
	void Pop()
	{
		m_pValueArray.popBack();
	}

	//Clear all values from the heap
	void Clear()
	{
		m_pValueArray.Clear();
	}

	//Push/Remove values from the heap
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

	//Get information about the heap itself
	int GetSize()
	{
		return m_pValueArray.Size();
	}

	int GetMaxSize()
	{
		return m_pValueArray.Capacity();

	}

	//Checks if heap is empty
	bool IsEmpty()
	{
		return(m_pValueArray.Size() == 0);
	}

	int GetParentIndex(int childIndex)
	{
		return (childIndex - 1) / 2;
	}

	int GetChildIndex(int parentIndex, int whichChild)
	{
		return (2 * parentIndex) + whichChild;
	}

	bool Contains(AstarNode* pValueArray)
	{
		for (int i = 0; i < m_pValueArray.Size(); ++i)
		{
			if (m_pValueArray[i] == pValueArray)
			{
				return true;
			}
		}
		return false;
	}

	//void HeapSort()
	//{
	//	int index = GetSize();
	//	int parent = floor((index - 1) / 2);
	//	while (m_pValueArray[index] > m_pValueArray[parent])
	//	{
	//		AstarNode* temp;
	//		temp = m_pValueArray[index];
	//		m_pValueArray[index] = m_pValueArray[parent];
	//		m_pValueArray[parent] = temp;
	//		index = parent;
	//		parent = floor((index - 1) / 2);
	//	}
	//}


private:
	DynamicArray<AstarNode*> m_pValueArray;
};

