#include <iostream>
#include "Board.h"
#include <Windows.h>

using namespace std;

WORD GetConsoleTextAttribute(HANDLE hCon);

Board::Board()
{	
}


Board::~Board()
{
}

//---------------------------------------------
//Draws the Board.
//---------------------------------------------
void Board::PlayField(int ScoreX, int ScoreO)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "		         Tic Tac Toe      " << endl;

	cout << "		Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "			   |     |     " << endl;
	cout << " 			" << square[0][0] << "  |  " << square[0][1] << "  |  " << square[0][2] << endl;

	cout << "		      _____|_____|_____" << endl;
	cout << "			   |     |     " << endl;

	cout << " 		        " << square[1][0] << "  |  " << square[1][1] << "  |  " << square[1][2] << endl;

	cout << "		      _____|_____|_____" << endl;
	cout << "			   |     |     " << endl;

	cout << " 			" << square[2][0] << "  |  " << square[2][1] << "  |  " << square[2][2] << endl;

	cout << "			   |     |     " << endl << endl;

	cout << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "PlayerX: " << ScoreX << "				";
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Player0: " << ScoreO << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);


}
//---------------------------------------------
//The reset function for the board.
//---------------------------------------------
void Board::Reset()
{
	for (int i = 0; i < 9; ++i)
	{
		int a = i / 3;
		int b = i % 3;

		square[a][b] = '0' + i + 1;
	}
}

WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
