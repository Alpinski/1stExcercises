#include <iostream>
#include "PlayerO.h"
#include "Board.h"
using namespace std;



PlayerO::PlayerO()
{
}


PlayerO::~PlayerO()
{
}

char PlayerO::PlayerOMark(char square[3][3])
{
	int print = 0;
	bool input = true;

	while (input == true)
	{
		cin >> print;
		cin.clear();
		cin.ignore(10000000, '\n');
		input = false;
		//-----------------------------------------------------------------
		// Check if the move was valid and replace with the specific mark.
		//-----------------------------------------------------------------
		if (print == 1 && square[0][0] == '1')
		{
			square[0][0] = 'O';
		}
		else if (print == 2 && square[0][1] == '2')
		{
			square[0][1] = 'O';
		}
		else if (print == 3 && square[0][2] == '3')
		{
			square[0][2] = 'O';
		}
		else if (print == 4 && square[1][0] == '4')
		{
			square[1][0] = 'O';
		}
		else if (print == 5 && square[1][1] == '5')
		{
			square[1][1] = 'O';
		}
		else if (print == 6 && square[1][2] == '6')
		{
			square[1][2] = 'O';
		}
		else if (print == 7 && square[2][0] == '7')
		{
			square[2][0] = 'O';
		}
		else if (print == 8 && square[2][1] == '8')
		{
			square[2][1] = 'O';
		}
		else if (print == 9 && square[2][2] == '9')
		{
			square[2][2] = 'O';
		}
		else
		{
			cout << "Invalid Turn" << endl;
			input = true;
		}
		
	}
	return 'O';
}