#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
}

Vector3::~Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
}

float Vector3::GetX()
{
	return xPos;
}

float Vector3::GetY()
{
	return yPos;
}

float Vector3::GetZ()
{
	return zPos;
}

Vector3 Vector3::operator+(Vector3 & rhs)
{
	return Vector3(xPos + rhs.xPos, yPos + rhs.yPos, zPos + rhs.zPos);
}

Vector3 Vector3::operator-(Vector3 & rhs)
{
	return Vector3(xPos - rhs.xPos, yPos - rhs.yPos, zPos - rhs.zPos);
}

Vector3 Vector3::operator*(float  rhs)
{
	return Vector3(xPos * rhs, yPos * rhs, zPos * rhs);
}

float & Vector3::operator[](int other)
{
	// TODO: insert return statement here
	float zero = 0.0;

	switch (other)
	{
		case 0:
		return xPos;
		case 1:
		return yPos;
		case 2:
		return zPos;
		default:
		return zero;
	}
}

Vector3::operator float*()
{
	float temp[3] = { xPos, yPos, zPos };

	return &temp[0];
}

Vector3 Vector3::CrossProduct(Vector3 rhs)
{
	float x = ((yPos * zPos) - (zPos * yPos));
	float y = ((zPos * xPos) - (xPos * zPos));
	float z = ((xPos * yPos) - (yPos * xPos));

	return Vector3(x, y, z);
}

bool Vector3::operator==(Vector3 & rhs)
{
	if (xPos == rhs.xPos && yPos == rhs.yPos && zPos == rhs.zPos)
	{
		return true;
	}
	return false;
}

bool Vector3::operator!=(Vector3 & rhs)
{
	if (xPos != rhs.xPos && yPos != rhs.yPos && zPos != rhs.zPos)
	{
		return true;
	}
	return false;
}

float Vector3::magnitude()
{
	return sqrtf(pow(xPos, 2) + pow(yPos, 2) + pow(zPos, 2));
}

float Vector3::Distance(Vector3 other)
{
	Vector3 a = *this - other;
	return a.magnitude();
}

float Vector3::DotProduct(Vector3 other)
{
	return ((xPos * other.xPos) + (yPos * other.yPos) + (zPos * other.zPos));
}

Vector3 Vector3::Normalize()
{
	return Vector3((xPos / magnitude()), (yPos / magnitude()), (zPos / magnitude()));
}