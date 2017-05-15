#include <iostream>
#include "WinLoseO.h"
#include <Windows.h>

using namespace std;

WORD GetConsoleTextAttribute(HANDLE hCon);

WinLoseO::WinLoseO()
{
}


WinLoseO::~WinLoseO()
{
}

//------------------------------------------------------
//Win Lose condition for PlayerO.
//------------------------------------------------------
bool WinLoseO::CheckWinO(char square [3][3])
{
	if (square[0][0] == square[0][1] && square[0][1] == square[0][2])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
		return true;
	}
	else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
		return true;
	}
	else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
		return true;
	}
	else if (square[0][0] == square[1][0] && square[1][0] == square[2][0])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
		return true;
	}
	else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
		return true;
	}
	else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
		return true;
	}
	else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
		return true;
	}
	else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const int saved_colors = GetConsoleTextAttribute(hConsole);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "PlayerO is the WINNER!" << endl;
		cout << "PlayerX SUX!" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		++ScoreO;
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