#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	Matrix2();
	Matrix2(float xx, float xy, float yy, float yx);
	~Matrix2();

	Vector2 operator*(const Vector2& rhs);

	Matrix2 operator*(const Matrix2& rhs);

	Matrix2 setRotation(const float a);

	Vector2& operator[](const int rhs);

	operator float*();

	float m[2][2];
};

