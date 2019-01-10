#pragma once
#include "Vectors3.h"

class matrix3
{
public:
	matrix3();
	void set(matrix3);
	matrix3 operator*(const matrix3)const;

private:
	Vector3 xcol;
	Vector3 ycol;
	Vector3 zcol;

	Vector3 xrow;
	Vector3 yrow;
	Vector3 zrow;
};