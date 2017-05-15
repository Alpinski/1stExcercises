#include <iostream>

using namespace std;

void Begin();
void NestedWhile();
void randomAss();
void main()
{


	randomAss();

	system("Pause");
}

//void Begin()
//{
//	int Num;
//	int Num2;
//	int Num3;
//	int Num4;
//
//	cout << "enter the first number" << endl;
//
//	cin >> Num;
//
//	cout << "enter the second number" << endl;
//
//	cin >> Num2;
//
//	Num3 = Num + Num2;
//	Num4 = Num3 / 2;
//
//	cout << Num4 << endl;
//}

//void NestedWhile()
//{
//	int counter1 = 1;
//	int Num = 1;
//
//	while (counter1 < 5)
//	{
//		while (Num < counter1)
//		{
//			cout << Num << endl;
//			++Num;
//		}
//		++counter1;
//	}
//
//}

void randomAss()
{
	int current;
	int sum;
	int i = 1;
	bool superIncreasing = true;

	cin >> current;

	sum = current;

	while (i < 7)
	{
		++i;
		cin >> current;

		if (current <= sum)
		{
			superIncreasing = false;
		}
		else
		{
			sum = sum + current;
		}
		cin.clear();
		cin.ignore(1000000, '\n');
	}

	if (superIncreasing == true)
	{
		cout << "Input forms a super increasing sequence" << endl;
	}
	else
	{
		cout << "Input is not super increasing" << endl;
	}

}