#include <iostream>

using namespace std;

class Player
{
public:
	Player(); //e
	Player(const char * name); //d
	Player(int a_max_ammo, int a_max_health); //a
	Player(float x, float y); //b
	Player(Player& a_player); //c

	float X, Y;
	int ammo;
	int max_ammo;
	int health;
	int max_health;
	char name[64];
};
void main()
{
	Player p1(100, 100);  //a
	Player p2(25.f, 16.f); //b
	Player p3(p1); //c
	Player p4("Jerry"); //d
	Player p5(); //e
}