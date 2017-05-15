#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float xx, float xy, float xz, float yy, float yx, float yz, float zz, float zx, float zy);
	~Matrix3();

	Vector3 operator*(const Vector3 & rhs);

	Matrix3 operator*(const Matrix3 & rhs);

	Matrix3 setRotationX(const float a);

	Matrix3 setRotationY(const float a);

	Matrix3 setRotationZ(const float z);

	Vector3 & operator[](const int rhs);

	operator float*();

	float m[3][3];
};

