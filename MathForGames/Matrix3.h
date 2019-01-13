#pragma once
#include "Vectors3.h"

class matrix3
{
public:
	matrix3();
	matrix3(Vector3, Vector3, Vector3);

	void set(matrix3);
	matrix3 operator*(const matrix3)const;
	Vector3 operator*(const Vector3)const;

	void rotateX(float);
	void rotateY(float);
	void rotateZ(float);

private:

	float matrix[3][3];

	Vector3 xcol;
	Vector3 ycol;
	Vector3 zcol;
	Vector3 xrow;
	Vector3 yrow;
	Vector3 zrow;
};