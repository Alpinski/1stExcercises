#pragma once

#include "Vector2.h"
#include "Renderer2D.h"
#include <cmath>
using namespace aie;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 768

static bool CircleSquareCollision(const Vector2& v2CircleCentre, float fRadius, const Vector2& v2SquareTopLeft, const Vector2& v2SquareBottomRight)
{
	float fSquareWidth = v2SquareBottomRight.x - v2SquareTopLeft.x;
	float fSquareHeight = v2SquareBottomRight.y - v2SquareTopLeft.y;
	float fSquareCentreX = v2SquareTopLeft.x + fSquareWidth * 0.5f;
	float fSquareCentreY = v2SquareTopLeft.y + fSquareHeight * 0.5f;

	float fDistanceX = abs(v2CircleCentre.x - fSquareCentreX);
	float fDistanceY = abs(v2CircleCentre.y - fSquareCentreY);

	if (fDistanceX > (fSquareWidth * 0.5f + fRadius))
		return false;

	if (fDistanceY > (fSquareHeight * 0.5f + fRadius))
		return false;

	if (fDistanceX <= (fSquareWidth * 0.5f))
		return true;

	if (fDistanceY <= (fSquareHeight * 0.5f))
		return true;

	float fCornerDistance_sq = powf((fDistanceX - fSquareWidth * 0.5f), 2) + powf((fDistanceY - fSquareHeight * 0.5f), 2);

	return (fCornerDistance_sq <= powf(fRadius, 2));
}

static void DrawSquare(Renderer2D* m_2dRenderer, Vector2& v2TopLeft, Vector2& v2BottomRight)
{
	m_2dRenderer->drawLine(v2TopLeft.x, v2TopLeft.y, v2BottomRight.x, v2TopLeft.y);
	m_2dRenderer->drawLine(v2TopLeft.x, v2BottomRight.y, v2BottomRight.x, v2BottomRight.y);
	m_2dRenderer->drawLine(v2TopLeft.x, v2TopLeft.y, v2TopLeft.x, v2BottomRight.y);
	m_2dRenderer->drawLine(v2BottomRight.x, v2TopLeft.y, v2BottomRight.x, v2BottomRight.y);
}

