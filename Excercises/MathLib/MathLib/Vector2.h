#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float newX, float newY);
	~Vector2();

	Vector2 Vector2:: operator+(const Vector2& rhs);

	float x;
	float y;
};

