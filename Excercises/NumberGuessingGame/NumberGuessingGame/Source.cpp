#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;
//--------------------------------------------------------------
//Prototypes of functions.
//--------------------------------------------------------------
void playeGuessing();
void aiGuessing();
WORD GetConsoleTextAttribute(HANDLE hCon);



void main()
{

	char input;
	bool GameRuns = true;
	while (GameRuns == true)
	{
	cout << "Do you want to play a game of numbers?" << endl;
	cout << "(Y) or (N)" << endl;

	//--------------------------------------------------------------
	//Allows the player to input Y or N.
	//--------------------------------------------------------------
	cin >> input;
	cin.clear();
	cin.ignore(90000000, '\n');

		if (input == 'Y' || input == 'y')
		{
			system("cls");
			cout << "which one would you like to be?" << endl;
			cout << "1:The one who guesses?" << endl;
			cout << "2:The one who keeps it guessing?" << endl;
			cin >> input;		
			//--------------------------------------------------------------
			//Launches the preffered game.
			//--------------------------------------------------------------
			if (input == '1')
			{
				system("cls");
				playeGuessing();
			}
			else if (input == '2')
			{
				system("cls");
				aiGuessing();
			}
			
		}
		else if (input == 'N' || input == 'n')
		{
			cout << "BYE" << endl;
			break;
		}
		else
		{
			cout << "Invalid Input!" << endl;
			continue;
		}
	}
}

void aiGuessing()
{
	//--------------------------------------------------------------
	//Makes rand work in conjuction with time.
	//--------------------------------------------------------------

	srand((int)time(0));

	//--------------------------------------------------------------
	// Game loop set to true.
	//--------------------------------------------------------------
	bool gameRunning = true;
	while (gameRunning)
	{	
		int guess = rand() % 100;
		int Lives = 5;
		int min = 1;
		int max = 100;
		int input;

		//--------------------------------------------------------------
		//Sets guessing to true
		//--------------------------------------------------------------
		bool guessing = true;
		while (guessing)
		{		
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Think a number" << endl;

			cout << "Is this your number? ------>  " << guess << endl;

			cout << "If not type (1) for HIGHER or (2) for LOWER!" << endl;

			cout << "If it is your NUMBER type (3)" << endl;

			SetConsoleTextAttribute(hConsole, saved_colors);

			//--------------------------------------------------------------
			//Switch statement for input "higher","lower","correct".
			//Also uses binary search in each statement.
			//--------------------------------------------------------------
			cin >> input;
			switch (input)
			{
			case 1:
				system("cls");
				min = guess;
				guess = (min + max) / 2;
				--Lives;
				break;
			case 2:
				system("cls");
				max = guess;
				guess = (min + max) / 2;
				--Lives;
				break;
			case 3:
				system("cls");
				cout << "You Lose!" << endl;
				guessing = false;
				gameRunning = false;
				break;
			default:
				system("cls");
				cout << "Invalid Input!" << endl;
				break;
			}
			//--------------------------------------------------------------
			//If your lives are equal to zero.
			//--------------------------------------------------------------
			if (Lives == 0)
			{
				system("cls");
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				const int saved_colors = GetConsoleTextAttribute(hConsole);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "You Win!" << endl;
				cout << "The Machines Have Lost!" << endl;
				SetConsoleTextAttribute(hConsole, saved_colors);
				gameRunning = false;
				break;
			}
		}
	}
}

void playeGuessing()
{
	srand((int)time(0));
	int Num = rand() % 100;
	int Guess = -1;
	int Lives = 0;

	//--------------------------------------------------------------
	//Game loop while guess doesn't equal Num it will keep looping.
	//--------------------------------------------------------------
	while (Guess != Num)
	{
		cout << "Take a Guess!" << endl;
	
		//-----------------------------------------------------------------
		//If guess is higher or lower than the Num it will add 1 to lives.
		//-----------------------------------------------------------------
		cout << "----->"; cin >> Guess; cout << "<-----";
		if (Guess < Num)
		{
			system("cls");
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);			
			cout << "Go HIGHER than HIGH!" << endl;	
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++Lives;
		}		
		else if (Guess > Num)
		{
			system("cls");
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);		
			cout << "Go LOWER than deep!" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			++Lives;		
		}
		//------------------------------------------------------------------------------------------
		//If your guess equals to the Number held by ai, prints out "you are correct" 100000 times.
		//------------------------------------------------------------------------------------------
		else
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const int saved_colors = GetConsoleTextAttribute(hConsole);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "You are correct!!!" << endl;
			for (int i = 0; i < 100000; ++i)
			{
				cout << "WINNER!!!" << endl;
			}
			SetConsoleTextAttribute(hConsole, saved_colors);
		}
		//--------------------------------------------------------------
		//If your lives are equal to 5 prints game over.
		//--------------------------------------------------------------
		if (Lives == 5)
		{
			cout << "GAME OVER!!!" << endl;
			break;
		}

	}
}

WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
