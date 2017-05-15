#include "Vector4.h"
#include <math.h>


Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float newX, float newY, float newZ, float newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

Vector4::~Vector4()
{
}

Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;

	return result;
}

Vector4 Vector4::operator-(const Vector4& rhs)
{
	Vector4 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w + rhs.w;

	return result;
}

Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w + rhs;

	return result;
}

Vector4 operator*(float lhs, const Vector4 rhs)
{
	Vector4 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}

float Vector4::Dot(Vector4 rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	return result;
}

Vector4 Vector4::Cross(Vector4 rhs)
{
	Vector4 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;
	return result;
}

float Vector4::Magnitude()
{
	float result;
	result = sqrtf((x*x) + (y*y) + (z*z) + (w*w));
	return result;
}

void Vector4::Normalise()
{
	float length = Magnitude();
	if (length != 0)
	{
		x /= length;
		y /= length;
		z /= length;
		w /= length;
	}
}

Vector4 Vector4::posOperator()
{
	Vector4 result;
	result.x = +x;
	result.y = +y;
	result.z = +z;
	result.z = +w;

	return result;
}

Vector4 Vector4::operator-()
{
	Vector4 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	result.z = -w;

	return result;
}

Vector4 Vector4::operator/(const float rhs)
{
	Vector4 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;
	result.w = w / rhs;
	return result;
}

Vector4 Vector4::operator+= (const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}

float& Vector4::operator[](const int rhs)
{
	if (rhs == 0)
	{
		return x;
	}
	else if (rhs == 1)
	{
		return y;
	}
	else if (rhs == 2)
	{
		return z;
	}
	else if (rhs == 3)
	{
		return w;
	}
	else
	{
		return x;
	}
}

Vector4::operator float*()
{
	return &x;
}