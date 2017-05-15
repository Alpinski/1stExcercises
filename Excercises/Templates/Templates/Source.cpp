#include<iostream>

using namespace std;

void main()
{

}


template<typename T, typename F>
T min(T a F b)
{
	if(a < b)
	{
		return a;
	}
	else if (b < a)
	{
		return b;
	}
	else
	{
		cout << "They are the same!" << endl;
		return 0;
	}
}

template<typename T, typename F>
T max(T a F b)
{
	if (a > b)
	{
		return a;
	}
	else if (b > a)
	{
		return b;
	}
	else
	{
		cout << "They are the same!" << endl;
		return 0;
	}
}

template<typename T, typename F, typename M>
T Clamp(T a F b M c)
{
	int min;
	int max;
	if (a > b)
	{
		return a;
	}
	else if (b > a)
	{
		return b;
	}
	else
	{
		cout << "They are the same!" << endl;
		return 0;
	}
}