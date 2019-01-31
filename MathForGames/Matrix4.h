#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(Vector4, Vector4, Vector4, Vector4);

	Matrix4 operator* (Matrix4);
	Vector4 operator* (Vector4);

	Vector4& operator[] (int);

	void RotateX(float);
	void RotateY(float);
	void RotateZ(float);

	operator float*();

	Matrix4(float, float, float,
		float, float, float,
		float, float, float, 
		float, float, float, 
		float, float, float, float);

private:
	float Matrix[4][4];
	float identityMatrixData[4][4];
};