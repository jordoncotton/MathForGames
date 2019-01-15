#pragma once
#include "Vectors3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(Vector3, Vector3, Vector3);

	void set(Matrix3);
	Matrix3 operator*(const Matrix3)const;
	Vector3 operator*(const Vector3)const;
	Vector3& operator[] (int);

	void rotateX(float);
	void rotateY(float);
	void rotateZ(float);

private:

	float Matrix[3][3];

	Vector3 xcol;
	Vector3 ycol;
	Vector3 zcol;
	Vector3 xrow;
	Vector3 yrow;
	Vector3 zrow;
};