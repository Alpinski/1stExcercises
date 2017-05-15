#include <iostream>
#include "WinLoseX.h"
#include <Windows.h>

using namespace std;
WORD GetConsoleTextAttribute(HANDLE hCon);

WinLoseX::WinLoseX()
{
}


WinLoseX::~WinLoseX()
{
}
//------------------------------------------------------
//Win Lose condition for PlayerX.
//------------------------------------------------------
bool WinLoseX::CheckWinX(char square[3][3])
{
		if (square[0][0] == square[0][1] && square[0][1] == square[0][2])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;
		}
		else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;

		}
		else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;
		}
		else if (square[0][0] == square[1][0] && square[1][0] == square[2][0])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;
		}
		else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;
		}
		else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;
		}
		else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;
		}
		else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "PlayerX is the Winner!" << endl;
			cout << "PlayerO SUX!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++ScoreX;
			return true;
		}
		else if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' && square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' && square[2][0] != '7' && square[2][1] != '8' && square[2][2] != '9')
		{
			cout << endl;
			cout << "Draw!" << endl;
			cout << "No WINNERS this time!" << endl;
			cout << "So you're both LOSERS!" << endl;
			cout << endl;
			return true;
		}
		else
		{
			return false;
		}
}