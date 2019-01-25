#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int l = 0; l < 3; l++)
		{
			Matrix[i][l] = 0.0;
		}
	}
}

Matrix3::Matrix3(Vector3 Xvec, Vector3 Yvec, Vector3 Zvec)
{
	for (int i = 0; i < 3; i++)
	{
		Matrix[i][0] = Xvec[i];
	}

	for (int i = 0; i < 3; i++)
	{
		Matrix[i][1] = Yvec[i];
	}
	
	for (int i = 0; i < 3; i++)
	{
		Matrix[i][2] = Zvec[i];
	}
}

Matrix3 Matrix3::operator*(const Matrix3 other) const
{
	Matrix3 outcome;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			outcome.Matrix[c][r] =
				Matrix[0][r] * other.Matrix[c][0] +
				Matrix[1][r] * other.Matrix[c][1] +
				Matrix[2][r] * other.Matrix[c][2];

		}
	}

	return outcome;
}

Vector3 Matrix3::operator*(const Vector3 vector) const
{
	Vector3 outcome;


		
	return outcome;
}

Vector3 & Matrix3::operator[](int other)
{
	// TODO: insert return statement here
	Vector3 vec3 = Vector3(Matrix[0][0],
		Matrix[1][0],
		Matrix[2][0]);

	return vec3;
}

void Matrix3::RotateZ(float Radians)
{

	auto RotationXcol = Vector3(cos(Radians), sin(Radians), 0.0);
	auto RotationYcol = Vector3(-sin(Radians), cos(Radians), 0);
	auto RotationZcol = Vector3(0.0, 0.0, 1.0);

	Matrix3 zRotationMatrix = Matrix3(RotationXcol,
		RotationYcol,
		RotationYcol);

	*this = (*this * zRotationMatrix);
}
