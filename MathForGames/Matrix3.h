#pragma once
#include "Vectors3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(Vector3, Vector3, Vector3);

	Matrix3 operator*(const Matrix3)const;
	Vector3 operator*(const Vector3)const;
	Vector3& operator[] (int);

	void RotateZ(float);

private:

	float Matrix[3][3];
};