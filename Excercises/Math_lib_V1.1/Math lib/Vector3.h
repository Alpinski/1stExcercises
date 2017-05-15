#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float newX, float newY, float newZ);
	~Vector3();

	Vector3 operator+(const Vector3& rhs);

	//Vector3 Add(const Vector3 & rhs);

	Vector3 operator-(const Vector3 & rhs);

	Vector3 operator*(const float rhs);

	Vector3 posOperator();

	Vector3 operator-();

	//Vector3 Multiply(float scalar);

	Vector3 operator/(const float rhs);

	Vector3 operator+=(const Vector3 & rhs);

	float & operator[](const int rhs);

	operator float*();

	float Magnitude();

	void Normalise();

	Vector3 Normalised(Vector3 data);

	float Dot(Vector3 rhs);

	Vector3 Cross(Vector3 rhs);

	float x;
	float y;
	float z;
};

 