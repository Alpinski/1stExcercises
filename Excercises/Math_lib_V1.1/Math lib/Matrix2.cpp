#include "Matrix2.h"
#include <math.h>

Matrix2::Matrix2()
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
}

Matrix2::Matrix2(float xx, float xy, float yy, float yx)
{
	m[0][0] = xx;
	m[0][1] = xy;
	m[1][0] = yx;
	m[1][1] = yy;
}

Matrix2::~Matrix2()
{
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
	Vector2 result;
	result.x = m[0][0] * rhs.x + m[0][1] * rhs.x;
	result.y = m[1][0] * rhs.y + m[1][1] * rhs.y;

	return result;
}

Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	Matrix2 result;
	result.m[0][0] = m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0];
	result.m[0][1] = m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1];

	result.m[1][0] = m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0];
	result.m[1][1] = m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1];

	return result;
}

Matrix2 Matrix2::setRotation(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = sinf(a);
	m[1][0] = -sinf(a);
	m[1][1] = cosf(a);
}

Vector2& Matrix2::operator[](const int rhs)
{
	return*(Vector2*)m[rhs];
}

Matrix2::operator float*()
{
	return &m[0][0];
}
