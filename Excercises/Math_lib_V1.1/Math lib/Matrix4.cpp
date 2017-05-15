#include "Matrix4.h"
#include <math.h>

Matrix4::Matrix4()
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

Matrix4::Matrix4(float xx, float xy, float xz, float xw, float yy, float yx, float yz, float yw, float zz, float zx, float zy, float zw, float ww, float wx, float wy, float wz)
{
	m[0][0] = xx;
	m[0][1] = xy;
	m[0][2] = xz;
	m[0][3] = xw;
	m[1][0] = yy;
	m[1][1] = yx;
	m[1][2] = yz;
	m[1][3] = yw;
	m[2][0] = zz;
	m[2][1] = zx;
	m[2][2] = zy;
	m[2][3] = zw;
	m[3][0] = ww;
	m[3][1] = wx;
	m[3][2] = wy;
	m[3][3] = wz;
}

Matrix4::~Matrix4()
{
}

Vector4 Matrix4::operator*(const Vector4& rhs)
{
	Vector4 result;
	result.x = m[0][0] * rhs.x + m[0][1] * rhs.x + m[0][2] * rhs.x + m[0][3] * rhs.x;
	result.y = m[1][0] * rhs.y + m[1][1] * rhs.y + m[1][2] * rhs.y + m[1][3] * rhs.y;
	result.z = m[2][0] * rhs.z + m[2][1] * rhs.z + m[2][2] * rhs.z + m[2][3] * rhs.z;
	result.z = m[3][0] * rhs.w + m[3][1] * rhs.w + m[3][2] * rhs.w + m[3][3] * rhs.w;

	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs)
{
	Matrix4 result;
	result.m[0][0] = m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0] + m[0][2] * rhs.m[2][0] + m[0][3] * rhs.m[3][0];
	result.m[0][1] = m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1] + m[0][2] * rhs.m[2][1] + m[0][3] * rhs.m[3][1];
	result.m[0][2] = m[0][0] * rhs.m[0][2] + m[0][1] * rhs.m[1][2] + m[0][2] * rhs.m[2][2] + m[0][3] * rhs.m[3][2];
	result.m[0][2] = m[0][0] * rhs.m[0][3] + m[0][1] * rhs.m[1][3] + m[0][2] * rhs.m[2][3] + m[0][3] * rhs.m[3][3];

	result.m[1][0] = m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0] + m[1][2] * rhs.m[2][0] + m[1][3] * rhs.m[3][0];
	result.m[1][1] = m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1] + m[1][2] * rhs.m[2][1] + m[1][3] * rhs.m[3][1];
	result.m[1][2] = m[1][0] * rhs.m[0][2] + m[1][1] * rhs.m[1][2] + m[1][2] * rhs.m[2][2] + m[1][3] * rhs.m[3][2];
	result.m[1][2] = m[1][0] * rhs.m[0][3] + m[1][1] * rhs.m[1][3] + m[1][2] * rhs.m[2][3] + m[1][3] * rhs.m[3][3];

	result.m[2][0] = m[2][0] * rhs.m[0][0] + m[2][1] * rhs.m[1][0] + m[2][2] * rhs.m[2][0] + m[2][3] * rhs.m[3][0];
	result.m[2][1] = m[2][0] * rhs.m[0][1] + m[2][1] * rhs.m[1][1] + m[2][2] * rhs.m[2][1] + m[2][3] * rhs.m[3][1];
	result.m[2][2] = m[2][0] * rhs.m[0][2] + m[2][1] * rhs.m[1][2] + m[2][2] * rhs.m[2][2] + m[2][3] * rhs.m[3][2];
	result.m[2][3] = m[2][0] * rhs.m[0][3] + m[2][1] * rhs.m[1][3] + m[2][2] * rhs.m[2][3] + m[2][3] * rhs.m[3][3];

	result.m[3][0] = m[3][0] * rhs.m[0][0] + m[3][1] * rhs.m[1][0] + m[3][2] * rhs.m[2][0] + m[3][3] * rhs.m[3][0];
	result.m[3][1] = m[3][0] * rhs.m[0][1] + m[3][1] * rhs.m[1][1] + m[3][2] * rhs.m[2][1] + m[3][3] * rhs.m[3][1];
	result.m[3][2] = m[3][0] * rhs.m[0][2] + m[3][1] * rhs.m[1][2] + m[3][2] * rhs.m[2][2] + m[3][3] * rhs.m[3][2];
	result.m[3][3] = m[3][0] * rhs.m[0][3] + m[3][1] * rhs.m[1][3] + m[3][2] * rhs.m[2][3] + m[3][3] * rhs.m[3][3];

	return result;
}

Matrix4 Matrix4::setRotationX(const float a)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = cosf(a);
	m[1][2] = -sinf(a);
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = sinf(a);
	m[2][2] = cosf(a);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

Matrix4 Matrix4::setRotationY(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = 0;
	m[0][2] = sinf(a);
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = -sin(a);
	m[2][1] = 0;
	m[2][2] = cosf(a);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

Matrix4 Matrix4::setRotationZ(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = -sinf(a);
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = sinf(a);
	m[1][1] = cosf(a);
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

Vector4& Matrix4::operator[](const int rhs)
{
	return*(Vector4*)m[rhs];
}

Matrix4::operator float*()
{
	return &m[0][0];
}