#include <iostream>
#include <limits>

using namespace std;

void main()
{
	bool GameRunning = true;

	int playerScore = 0;
	int AIscore = 0;

	while (GameRunning)
	{
		int AIdiceRoll = (rand() % 6) + 1;
		cout << "Going to roll a dice!" << endl;
		cout << "Beat my dice roll!" << endl;
		cout << "AI Roll:-------> " << AIdiceRoll << " <-------" << endl;
		
		int playerDiceRoll = (rand() % 6) + 1;
		bool DiceRoll  = false;		
		char R;
		cout << "Press R To Roll!" << endl;
		cout << ">";
		if (cin >> R)
		{

			DiceRoll = true;

		}
		cout << "Player Roll:-------> " << playerDiceRoll << " <-------" << endl;
		
		if (playerDiceRoll > AIdiceRoll)
		{
			++playerScore;
			cout << "YOU WIN!" << endl;
		}
		else if (playerDiceRoll == AIdiceRoll)
		{
			cout << "DRAW!" << endl;
		}
		else
		{
			++AIscore;
			cout << "YOU LOSE!" << endl;
		}
		
		cout << "AI: " << AIscore << endl;
		cout << "YOU: " << playerScore << endl;



		system("pause");
	}
}