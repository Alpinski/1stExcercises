#include <iostream>

using namespace std;

 float value(float a, float b);
 double value(float c, float d);
void main()
{
	value('c', 'd');
	system("pause");
}

float value(float a, float b)
{
	
	cout << "Enter Value 1: "; cin >> a;
	
	cout << "Enter Value 2: "; cin >> b;

	if (a > b)
	{
		cout << "The smaller number is: " << b << endl;
	}
	else if(b > a);
	{
		cout << "The smaller number is: " << a << endl;
	}

	return (a,b);
}

double value(double c, double d)
{

	cout << "Enter Value 1: "; cin >> c;

	cout << "Enter Value 2: "; cin >> d;

	if (c > d)
	{
		cout << "The smaller number is: " << d << endl;
	}
	else if (d > c);
	{
		cout << "The smaller number is: " << c << endl;
	}

	return (c,d);

}