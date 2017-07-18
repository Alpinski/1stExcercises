#pragma once
#include <iostream>
#include <cmath>


class Vector2
{
public:
	//--------------------------------------------------------------------------------------
	//Constructor
	//--------------------------------------------------------------------------------------
	Vector2();
	//--------------------------------------------------------------------------------------
	//Constructor
	//--------------------------------------------------------------------------------------
	Vector2(float newX , float newY);
	//--------------------------------------------------------------------------------------
	//Deconstructor
	//--------------------------------------------------------------------------------------
	~Vector2();
	//--------------------------------------------------------------------------------------
	// Adds two vector2s together
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 operator+(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// Subtracts two vector2s together
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 operator-(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// times two vector4s together
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 operator*(const float rhs);
	//--------------------------------------------------------------------------------------
	// takes two equal-length sequences of numbers and returns a single number.
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	float Dot(Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number is greater than the other number
	//
	// Param:
	//		input: takes a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	bool operator> (const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number is less than the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	bool operator< (const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number is equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	bool operator==(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number does not equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	bool operator!=(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number greater than or equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	bool operator<=(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	// returns true or false depending on if the number less than or equal to the other number
	//
	// Param:
	//		takes in a vector2
	// Return:
	//		returns true or false
	//--------------------------------------------------------------------------------------
	bool operator>=(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//How large an object is
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	float Magnitude();
	//--------------------------------------------------------------------------------------
	//square of a magnitude
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	float sqrMagnitude();
	//--------------------------------------------------------------------------------------
	//multiply by a factor that makes an integral equal to a desired value
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	void Normalise();
	//--------------------------------------------------------------------------------------
	//normalise the magnitude
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 Normalised(Vector2& data);
	//--------------------------------------------------------------------------------------
	//calculates the distance between two vector4s
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the dist
	//--------------------------------------------------------------------------------------
	float Distance(Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//Divides two vectors
	//
	// Param:
	//		Takes in a float
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 operator/(const float rhs);
	//--------------------------------------------------------------------------------------
	//positive number
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 posOperator();
	//--------------------------------------------------------------------------------------
	//negative number
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 operator-();
	//--------------------------------------------------------------------------------------
	//short for x = x + y
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 operator+=(const Vector2& rhs);
	float & operator[](const int rhs);
	operator float*();
	//--------------------------------------------------------------------------------------
	//calculates the minimum of the vector2
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 min(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//calculates the maximum of the vector2
	//
	// Param:
	//		Takes in a Vector2
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 max(const Vector2& rhs);
	//--------------------------------------------------------------------------------------
	//moves the point to the nearest available value.
	//
	// Param:
	//		Takes in two Vector2s
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 clamp(Vector2& min, Vector2 & max);
	//--------------------------------------------------------------------------------------
	//interpolation between two values
	//
	// Param:
	//		Takes in two Vector2s and a float
	// Return:
	//		none
	//--------------------------------------------------------------------------------------
	Vector2 lerp(Vector2 a, Vector2 b, float t);
	//--------------------------------------------------------------------------------------
	//compound linear interpolations
	//
	// Param:
	//		Takes in three Vector2s and a float
	// Return:
	//		none
	//--------------------------------------------------------------------------------------
	Vector2 quadraticBezier(Vector2 a, Vector2 b, Vector2 c, float t);
	//--------------------------------------------------------------------------------------
	//compound linear interpolations with tangents
	//
	// Param:
	//		Takes in four Vector2s and a float
	// Return:
	//		none
	//--------------------------------------------------------------------------------------
	Vector2 hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);
	//--------------------------------------------------------------------------------------
	//Swizzles the elements of the vector, assigning differing values depending on the variables in the function name
	//
	// Param:
	//		none
	// Return:
	//		returns the result
	//--------------------------------------------------------------------------------------
	Vector2 xx();
	Vector2 xy();
	Vector2 yx();
	Vector2 yy();
	
	float x;
	float y;
};
//--------------------------------------------------------------------------------------
// times a float and a vector2 together
//
// Param:
//		takes in a vector2
// Return:
//		returns the result
//--------------------------------------------------------------------------------------
Vector2 operator*(float lhs, const Vector2 rhs);
