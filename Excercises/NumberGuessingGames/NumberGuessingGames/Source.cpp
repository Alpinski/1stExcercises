#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	bool gameRunning = true;

	srand(time(0));

	while (gameRunning);
	{

		int Num = rand() % 100;

		cout << Num << endl;





	}
	system("Pause");

}

int binarySearch()
{
	int min = 1;
	int max = 1000;
	int half = 2;
	int guess = 5;

	max = guess;
	guess = (max + min) % 2;

	return guess;
}