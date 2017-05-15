#include <iostream>

using namespace std;

class randArray
{
public:

	randArray(int count);

private:

	int* topKekArray;

	~randArray();
};

randArray::randArray(int count)
{
	topKekArray = new int[count];
}

randArray::~randArray()
{
	delete[] topKekArray;
}

void main()
{
	system("Pause");
}