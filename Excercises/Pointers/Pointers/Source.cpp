#include <iostream>

using namespace std;

void RevString(char* text);
int CountEven(int* nums, int nums_len);
int Maximum(double* myArray, int array_size);
void main()
{
	char text[] = {"Tektonik"}


	cout << answer << endl;


	system("pause");
}

void RevString(char* text)
{
	int length = strlen(text);
	char* start = text;
	char* end = start + (length - 1);

	while (start != end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}

int CountEven(int* nums, int nums_len)
{
	int length = nums_len;
	int Number = 0;

	for (int i = 0; i < nums_len; ++i)
	{
		if (nums[i] % 2 == 0)
		{
			++Number;
		}
	}
	return Number;
}

int Maximum(double* myArray, int array_size)
{
	double Max = 0;
	double* answer = nullptr;

	for (int i = 0; i < array_size; ++i)
	{
		if (myArray[i] > Max)
		{
			Max = myArray[i];
			answer = &myArray[i];
		}
	}
	return answer;
}

bool Contains(char* array, char search_value)
{
	char Tek;
}
