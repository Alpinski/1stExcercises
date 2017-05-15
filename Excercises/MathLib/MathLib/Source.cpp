#include <iostream>
#include "Vector2.h"

using namespace std;



int main()
{
	Vector2 pos(3.0f, 5.0f);
	Vector2 offset(2.0f, 6.0f);
	
	Vector2 result = pos + offset;

	system("pause");
	return 0;
}