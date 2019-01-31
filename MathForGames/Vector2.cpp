#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
{
	xPos, yPos = 0.0f;
}

Vector2::~Vector2()
{ 

}

Vector2::Vector2(float x, float y)
{
	xPos = x;
	yPos = y;
}

float Vector2::GetX()
{
	return xPos;
}

float Vector2::GetY()
{
	return yPos;
}

Vector2 Vector2::operator+(Vector2 & rhs)
{
	return Vector2(xPos + rhs.xPos, yPos + rhs.yPos);
}

Vector2 Vector2::operator-(Vector2 & rhs)
{
	return Vector2(xPos - rhs.xPos, yPos - rhs.yPos);
}

Vector2 Vector2::operator*(float rhs)
{
	return Vector2(xPos * rhs, yPos * rhs);
}

bool Vector2::operator==(Vector2 & rhs)
{
	if (xPos == rhs.xPos && yPos == rhs.yPos)
	{
		return true;
	}
	return false;
}

bool Vector2::operator!=(Vector2 & rhs)
{
	if (xPos != rhs.xPos && yPos != rhs.yPos)
	{
		return true;
	}
	return false;
}

float Vector2::Magnitude()
{
	return sqrtf(pow(xPos, 2) + pow(yPos, 2));
}

float Vector2::Distance(Vector2 other)
{
	Vector2 a = *this - other;
	return a.Magnitude();
}

float Vector2::DotProduct(Vector2 other)
{
	return ((xPos + other.xPos) + (yPos + other.yPos));
}

float Vector2::operator[](int index)
{
	switch (index)
	{
	case 0:
		return xPos;
	case 1:
		return yPos;
	default:
		return 0.0;
	}
	return 0.0f;
}

Vector2::operator float*()
{
	float temp[2] = { xPos, yPos };

	return &temp[0];
}

Vector2 Vector2::Normalize()
{
	return Vector2((xPos / Magnitude()), (yPos / Magnitude()));
}
