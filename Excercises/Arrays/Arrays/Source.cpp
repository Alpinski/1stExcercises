#include <iostream>

using namespace std;
int dimensions();
int grid();
int arrays();
int game();
void main()
{

	game();

	system("pause");
}

int arrays()
{
	int i;
	int data[10] = { 10,9,8,7,6,5,4,3,2 };
	for (i = 0; i < 10; ++i)
	{
		cin >> data[i];

	}

	int j;
	for (j = 10 - 1; j >= 0; --j);
	{
		cout << data[j] << endl;
	}
	

	return 0;
}

int grid()
{
	int nums[3][3]=
	{
		{1, 2, 3 },
		{4, 5, 6 },
		{7, 8, 9 }
	};

	for(int row = 0; row < 3; ++row) 
	{
		for (int col = 0; col < 3; ++col)
		{
			nums[row][col] = row * 3 + col;
			cout << nums[row][col];
		}
		cout << endl;
		
	}

	return 0;
}

int dimensions()
{
	int sum = 0;
	int sum1 = 0;
	int digits[5][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12},
		{13,14,15}
	};

	for (int row = 0; row < 5; ++row)
	{
		sum = 0;
		for (int col = 0; col < 3; ++col)
		{
			sum += digits[row][col];
			
			
		}
		cout << sum << endl;
	}
	cout << endl;

	for (int col = 0; col < 3; ++col)
	{
		sum = 0;
		for (int row = 0; row < 5; ++row)
		{
			sum += digits[row][col];
			
		}
		cout << sum << endl;
	}
	return 0;
}

int game()
{
	int HP = 100;
	
	int gArray[5] = { 100,100,100,100,100 };
	cout << "pick a player 0-4: ";
	for (int i = 0; i < 5; ++i)
	{
		cin >> gArray[5];
	}
	cout << gArray[5] << endl;

	int bandit = -40;

	if (cin >> gArray[5])
	{
	 
		cout << HP << endl;
	}


	return 0;
}