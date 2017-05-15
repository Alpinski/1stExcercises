#include<iostream>
#include "SSword.h"
#include "KKnight.h"
#include "V3.h"

using namespace std;

void printMenu()
{
	cout << "What would you like to do? (Enter number 1-6)" << endl;
	cout << "1: Rename Knight" << endl;
	cout << "2: Change Knight's level" << endl;
	cout << "3: Damage Knight" << endl;
	cout << "4: Change Knight's position" << endl;
	cout << "5: Change Sword's Name" << endl;
	cout << "6: Change Sword's Damage" << endl;
}

void main()
{
	Knight hero;
	hero.createKnight();

	//game loop
	bool gameRunning = true;
	while (gameRunning)
	{
		system("cls");
		
		hero.printKnight();
		printMenu();

		int input;
		cin >> input;
		cin.clear ();		
		cin.ignore(9999999, '\n');

		switch (input)
		{
		case 1:
			cout << "Enter a new name for the knight" << endl;
			char name[32];
			cin >> name;
			hero.setName(name);
			break;
		case 2:
			cout << "Enter level" << endl;
			int level;
			cin >> level;
			hero.setLevel(level);
			break; 
		case 3:
			cout << "How much damage" << endl;
			cin >> input;
			int damage;
			cin >> damage;
			hero.doDmagae(damage);
			break;
		case 4:
			float x;
			float y;
			cout << "Enter x postition" << endl;
			cin >> x;
			cout << "Enter y position" << endl;
			cin >> y;
			hero.setPosition(x, y);
			break;
		case 5:
			cout << "Enter sword's name" << endl;
			char swordName[32];
			cin >> swordName;
			hero.setSwordName(swordName);
			break;
		case 6:
			cout << "Change Sword's damage" << endl;
			int swordDamage;
			cin >> swordDamage;
			hero.setSwordDamage(swordDamage);
			break;
		default:
			cout << "Not a valid option, please try again" << endl;
			system("pause");
			break;
		}
		system("pause");
	}
	system("pause");
}