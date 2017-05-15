#include <iostream>

using namespace std;

struct Player
{
	char name[10];
	int health;
	int score;
};


Player newPlayer();


void main()
{
	Player threep[5];

	for (int i = 0; i < 5; ++i)
	{
		threep[i] = newPlayer();
	}
	for (int j = 0; j < 5; ++j)
	{
		cout << threep[j].name << " " << threep[j].health << " " << threep[j].score << endl;
	}

	if (cin >> threep[1].name)
	{
		cout << threep[1].name << " has got " << threep[1].score << "points" << endl;
	}
	else if (cin >> threep[2].name)
	{
		cout << threep[2].name << " has got " << threep[2].score << "points" << endl;
	}
	else if (cin >> threep[3].name)
	{
		cout << threep[3].name << " has got " << threep[3].score << "points" << endl;
	}
	else if (cin >> threep[4].name)
	{
		cout << threep[4].name << " has got " << threep[4].score << "points" << endl;
	}
	else if (cin >> threep[2].name)
	{
		cout << threep[5].name << " has got " << threep[5].score << "points" << endl;
	}
	else
	{
		cout << "INVALID INPUT!" << endl;
	}
	system("pause");
}

Player newPlayer()
{

	Player threep;

	cout << "Enter Name: ";
	cin >> threep.name;

	cout << "Enter Health: ";
	cin >> threep.health;

	cout << "Enter Score: ";
	cin >> threep.score;

	return threep;
}