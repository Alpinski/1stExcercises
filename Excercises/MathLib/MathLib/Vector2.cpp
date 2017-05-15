#include "Vector2.h"



Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float newX, float newY)
{
	x = newX;
	y = newY;

}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator + (const Vector2& rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}