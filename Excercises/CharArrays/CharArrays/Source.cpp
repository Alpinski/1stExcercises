#include <iostream>

using namespace std;

int chatbot();
int login();

void main()
{
	login();

	system("pause");
}


int chatbot()
{
	cout << "What is your name?" << endl;

	char name[14];
	cin >> name;
	cin.clear();
	cin.ignore(999999, '\n');

	cout << "what is your last name?" << endl;

	char surname[32];
	cin >> surname;
	cin.clear();
	cin.ignore(999999, '\n');

	char fullname[128];
	strcpy_s(fullname, name);
	strcat_s(fullname, " ");
	strcat_s(fullname, surname);

	cout << fullname << endl;

	return 0;
}

int login()
{

	bool testPass(char[]);

	cout << "Enter Username:";
	char uName [14];
	cin >> uName;
	cin.clear();
	cin.ignore(999999, '\n');

	cout << "Password: ";
	char Pass[32];
	cin >> Pass;
	cin.clear();
	cin.ignore(999999, '\n');
	

	for (int i = 0; i < 1; ++i)
	{
		if (strlen(Pass) > 8 == true && testPass == true)
		{
			cout << "Password is valid! " << endl;
		}
		else
		{
			cout << "Password is invalid! " << endl;
		}
	}
	bool testPass(char Pass[32]);// a beautiful hack (:
	{
		// flags
		bool aUpper = false,
			aLower = false,
			aDigit = false;
		for (int i = 0; Pass[i]; ++i)
			if (isupper(Pass[i]))
				aUpper = true;
			else if (islower(Pass[i]))
				aLower = true;
			else if (isdigit(Pass[i]))
				aDigit = true;
		if (aUpper && aLower && aDigit)
			return true;
		else
			return false;
	}

	return 0;
}