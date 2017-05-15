#include <iostream>

using namespace std;

int drag(int a, int b);

void main()
{
	int myFloat = 2.42f;
	int myVar = 10;
	int& myRef = myVar;
	int& myRef2 = myFloat;

	
	myVar = 115;

	cout << myVar << endl;
	cout << myRef << endl;
	cout << myRef2 << endl;

	myRef = 2;


	int nums = drag(10, 20);

	cout << nums << endl;

	system("pause");
}

int drag(int& a, int& b)
{
	  int result = a + b;
	

	return result; 
}