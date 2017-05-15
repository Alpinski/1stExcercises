#include <iostream>
#include "WinLose.h"
#include "PlayerO.h"
#include "PlayerX.h"
#include "Board.h"

using namespace std;

WinLose::WinLose()
{
}


WinLose::~WinLose()
{
}

void WinLose::CheckWin(char square[3][3])
{
	PlayerX Xmark;
	PlayerO Omark;

	while (Win == false)
	{
		if (square[1] == square[2] && square[2] == square[3])
		{
			Win = true;
			cout << "Player1" << endl;
			cout << "Winner!" << endl;
		}
		else if (square[4] == square[5] && square[5] == square[6])
		{
			Win = true;
			cout << "Player1" << endl;
			cout << "Winner!" << endl;
		}
		else if (square[7] == square[8] && square[8] == square[9])
		{
			Win = true;
			cout << "Player1" << endl;
			cout << "Winner!" << endl;
		}
		else if (square[1] == square[4] && square[4] == square[7])
		{
			Win = true;
			cout << "Player1" << endl;
			cout << "Winner!" << endl;
		}
		else if (square[2] == square[5] && square[5] == square[8])
		{
			Win = true;	
			cout << "Player1" << endl;
			cout << "Winner!" << endl;	
		}
		else if (square[3] == square[6] && square[6] == square[9])
		{
			Win = true;
			cout << "Player1" << endl;
			cout << "Winner!" << endl;
		}
		else if (square[1] == square[5] && square[5] == square[9])
		{
			Win = true;
			cout << "Player1" << endl;
			cout << "Winner!" << endl;
		}
		else if (square[3] == square[5] && square[5] == square[7])
		{
			Win = true;
			cout << "Player1" << endl;
			cout << "Winner!" << endl;
		}


		if (Win == false)
		{
			
		}
			if (square[1] == square[2] && square[2] == square[3])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
			else if (square[4] == square[5] && square[5] == square[6])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
			else if (square[7] == square[8] && square[8] == square[9])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
			else if (square[1] == square[4] && square[4] == square[7])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
			else if (square[2] == square[5] && square[5] == square[8])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
			else if (square[3] == square[6] && square[6] == square[9])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
			else if (square[1] == square[5] && square[5] == square[9])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
			else if (square[3] == square[5] && square[5] == square[7])
			{
				Win = true;
				cout << "Player2" << endl;
				cout << "Winner!" << endl;
			}
	}		
}



	
