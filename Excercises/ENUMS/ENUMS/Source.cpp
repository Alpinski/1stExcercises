#include<iostream>

using namespace std;

enum monsterType
{
	EMONSTERTYPE_ORC,
	EMONSTERTYPE_ALIEN,
	EMONSTERTYPE_DEMON,
	EMONSTERTYPE_COUNT
};

struct Monster
{
	monsterType type;
};

void main()
{
	monsterType monsters[EMONSTERTYPE_COUNT];

	for (int i = 0; i < 3; ++i)
	{
		monsters[i] = (monsterType)i;
	}

	system("pause");
}