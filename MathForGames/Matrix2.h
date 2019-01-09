#pragma once
#include "Vectors2.h"

class Matrix2
{
public:
	Vector2 xcol;
	Vector2 ycol;

	Matrix2(Vector2 x, Vector2 y);
	Matrix2 times(Matrix2 other);
};