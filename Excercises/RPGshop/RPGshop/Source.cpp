#include <iostream>

using namespace std;


struct potions
{
	int potion;
	int price;
	int quantity;
	int gold;


};

potions theVendor();

void main()
{
	potions goldElixir[10];

	


	system("pause");
}

potions theVendor()
{
	potions goldElixir;

	int HealthPotion;

	int ManaPotion;


	goldElixir.gold = 1000000;
	cout << "Gold: " << goldElixir.gold << endl;

	
	
	
	cout << goldElixir.potions << endl;



	return goldElixir;
}