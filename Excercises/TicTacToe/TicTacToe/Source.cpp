#include <iostream>
#include "Board.h"
#include "PlayerX.h"
#include "PlayerO.h"
#include "WinLoseX.h"
#include "WinLoseO.h"
#include "Board.h"

using namespace std;

void main()
{
	WinLoseX WLX;
	WinLoseO WLO;
	Board GB;
	PlayerX XT;
	PlayerO OT;

	char input;

	bool gameRunning = true;
	//------------------------------------------
	// Game Loop that calls the functions.
	//------------------------------------------
	while (gameRunning)
	{
		GB.Reset();
		cout << "Do you want to play TicTacToe?" << endl;
		cout << "(Y) or (N)" << endl;
		cin >> input;
		if (input == 'Y' || input == 'y')
		{
			while (input == 'Y' || input == 'y')
			{
				GB.PlayField(WLX.ScoreX, WLO.ScoreO);
				XT.PlayerXMark(GB.square);
				GB.PlayField(WLX.ScoreX, WLO.ScoreO);
				
				if (WLX.CheckWinX(GB.square) == true)
					break;
	
				OT.PlayerOMark(GB.square);
				GB.PlayField(WLX.ScoreX, WLO.ScoreO);

				if (WLO.CheckWinO(GB.square) == true)
					break;
			}
		}
		else if (input == 'N' || input == 'n')
		{
			cout << "fail" << endl;
		}

	}
	system("Pause");
}
