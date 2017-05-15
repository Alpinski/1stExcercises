#pragma once
class Vector4
{
public:
	Vector4();
	Vector4(float newX, float newY, float newZ, float newW);
	~Vector4();

	Vector4 operator+(const Vector4 & rhs);

	Vector4 operator-(const Vector4 & rhs);

	Vector4 operator*(float rhs);

	Vector4 posOperator();

	Vector4 operator-();

	Vector4 operator/(const float rhs);

	Vector4 operator+=(const Vector4 & rhs);

	float & operator[](const int rhs);

	operator float*();

	float Magnitude();

	void Normalise();

	float Dot(Vector4 rhs);

	Vector4 Cross(Vector4 rhs);

	float x;
	float y;
	float z;
	float w;
};

