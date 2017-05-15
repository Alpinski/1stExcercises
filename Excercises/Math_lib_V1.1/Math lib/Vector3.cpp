#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}


Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;

	return result;
}

//Vector3 Vector3::Add(const Vector3& rhs)
//{
//	return Translate(rhs);
//	
//}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;

	return result;
}

Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	return result;
}

Vector3 operator*(float lhs, const Vector3 rhs)
{
	Vector3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	return result;
}

float Vector3::Dot(Vector3 rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z;
	return result;
}

Vector3 Vector3::Cross(Vector3 rhs)
{
	Vector3 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	return result;
}

float Vector3::Magnitude()
{
	float result;
	result = sqrtf((x*x) + (y*y) + (z*z));
	return result;
}

void Vector3::Normalise()
{
	float length = Magnitude();
	if (length != 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
}

Vector3 Vector3::Normalised(Vector3 data)
{
	Vector3 result;
	float Mag = data.Magnitude();
	if (!Mag == 0)
	{
		result.x = x / Mag;
		result.y = y / Mag;
		result.z = z / Mag;
	}
	return result;
}

Vector3 Vector3::posOperator()
{
	Vector3 result;
	result.x = +x;
	result.y = +y;
	result.z = +z;

	return result;
}

Vector3 Vector3::operator-()
{
	Vector3 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;

	return result;
}


//Vector3 Vector3::Multiply(float scalar)
//{
//	return Scale(scalar);
//
//}

Vector3 Vector3::operator/(const float rhs)
{
	Vector3 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;

	return result;
}

Vector3 Vector3::operator+= (const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

float& Vector3::operator[](const int rhs)
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
	else
	{
		return x;
	}
}

Vector3::operator float*()
{
	return &x;
}