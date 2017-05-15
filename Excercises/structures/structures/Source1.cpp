#include <iostream>

using namespace std;


struct Shop
{
	int gold;
	int price;
	int quantity;

};

Shop theVendor();

void main()
{
	theVendor();

	system("pause");
}

Shop theVendor()
{
	Shop goldElixir;
	

	goldElixir.gold = 1000000;

	cout << goldElixir.gold << endl;


	return goldElixir;
}