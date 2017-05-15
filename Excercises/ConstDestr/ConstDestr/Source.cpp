#include <iostream>

using namespace std;

struct Bullet
{
	float x, y;
};

class Player
{
public:
	//Constructor
	Player();

	Player(int max_ammo)
	{
		bullets = new Bullet[max_ammo];
		ammo = 0;
		health = 0;
		max_health = 100;
	}
	//Destructor
	~Player(); // implement this

	int health;
	int max_health;
	int ammo;
	int max_ammo;
	Bullet* bullets;
};

Player::Player()
{

}

Player::~Player()
{
	
}