 #pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(Vector3, Vector3, Vector3);

	Matrix3 operator*(Matrix3);
	Vector3 operator*(Vector3);
	Vector3& operator[] (int other);

	Matrix3(float, float, float, 
		float, float, float,
		float, float, float);

	operator float*();

	void RotateX(float);
	void RotateY(float);
	void RotateZ(float);

private:

	float Matrix[3][3];
	float identityMatrixData[3][3];
};