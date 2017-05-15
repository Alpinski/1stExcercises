#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float xx, float xy, float xz, float xw, float yy, float yx, float yz, float yw, float zz, float zx, float zy, float zw, float ww, float wx, float wy, float wz);
	~Matrix4();

	Vector4 operator*(const Vector4 & rhs);

	Matrix4 operator*(const Matrix4 & rhs);

	Matrix4 setRotationX(const float a);

	Matrix4 setRotationY(const float a);

	Matrix4 setRotationZ(const float a);

	Vector4 & operator[](const int rhs);

	operator float*();

	float m[4][4];
};

