#include "Heap.h"
#include <cmath>

Heap::Heap()
{
}

Heap::~Heap()
{
}

int Heap::Peek()
{
	int nTop = m_pValueArray.Size() - 1;
	return m_pValueArray[nTop];
}

void Heap::Pop()
{
	m_pValueArray.popBack();
}

void Heap::Clear()
{
	m_pValueArray = 0;
}

void Heap::Push(int value)
{
	int index = GetSize();
	m_pValueArray.pushBack(value);
	int parent = floor((index - 1) / 2);
	while (m_pValueArray[index] > m_pValueArray[parent])
	{
		int temp;
		temp = m_pValueArray[index];
		m_pValueArray[index] = m_pValueArray[parent];
		m_pValueArray[parent] = temp;
		index = parent;
		parent = floor((index - 1) / 2);
	}
}

void Heap::Remove(int value)
{	
	int last = m_pValueArray.Size() - 1;
	m_pValueArray[0] = m_pValueArray[last];

	int current = 0;

	while (true)
	{
		int child0 = GetChildIndex(current, 0);
		if (child0 > last)
		{
			break;
		}
		int child1 = GetChildIndex(current, 1);
		int smallerChild = child0;
		if (child1 <= last && m_pValueArray[child1] < m_pValueArray[smallerChild])
		{
			smallerChild = child1;
		}

		if (m_pValueArray[smallerChild] < m_pValueArray[current])
		{
			int swap = m_pValueArray[current];
			m_pValueArray[current] = m_pValueArray[smallerChild];
			m_pValueArray[smallerChild] = swap;

			current = smallerChild;
		}
		else
		{
			break;
		}

	}
}

int Heap::GetSize()
{
	return m_pValueArray.Size();
}

int Heap::GetMaxSize()
{
	return m_pValueArray.Capacity();
}

void Heap::SetMaxSize(int minSize)
{
	m_pValueArray.Capacity() == minSize;
}

bool Heap::IsEmpty()
{
	return(m_pValueArray.Size() == 0);
}

int Heap::GetParentIndex(int childIndex)
{
	return (childIndex - 1) / 2;
}

int Heap::GetChildIndex(int parentIndex)
{
	return (2* parentIndex)
}
