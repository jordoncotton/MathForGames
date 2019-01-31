#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Matrix[i][j] = 0.0;
		}
	}
}

Matrix4::Matrix4(Vector4 Xvec, Vector4 Yvec, Vector4 Zvec, Vector4 Wvec)
{
	for (int i = 0; i < 4; i++)
	{
		Matrix[i][0] = Xvec[i];
	}
	for (int i = 0; i < 4; i++)
	{
		Matrix[i][1] = Yvec[i];
	}
	for (int i = 0; i < 4; i++)
	{
		Matrix[i][2] = Zvec[i];
	}
	for (int i = 0; i < 4; i++)
	{
		Matrix[i][3] = Wvec[i];
	}
}

Matrix4 Matrix4::operator*(Matrix4 something)
{
	Matrix4 outcome;

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			outcome.Matrix[c][r] =
				Matrix[0][r] * something.Matrix[c][0] +
				Matrix[1][r] * something.Matrix[c][1] +
				Matrix[2][r] * something.Matrix[c][2] +
				Matrix[3][r] * something.Matrix[c][3];

		}
	}

	return outcome;
	return Matrix4();
}

Vector4 Matrix4::operator*(Vector4 vector)
{
	Vector4 outcome;

	for (int r = 0; r < 4; r++)
	{
		outcome[r] = Matrix[0][r] * vector[r] +
			Matrix[1][r] * vector[r] +
			Matrix[2][r] * vector[r] +
			Matrix[3][r] * vector[r];
	}
	return outcome;
}

Vector4 & Matrix4::operator[](int)
{
	// TODO: insert return statement here
	Vector4 vec4 = Vector4(Matrix[0][0],
		Matrix[1][0],
		Matrix[2][0],
		Matrix[3][0]);

	return vec4;
}

void Matrix4::RotateX(float radi)
{
	auto rotationXcol = Vector4(1, 0.0, 0.0, 0.0);
	auto rotationYcol = Vector4(0.0, cos(radi), sin(radi), 0.0);
	auto rotationZcol = Vector4(0.0, -sin(radi), cos(radi), 0.0);
	auto rotationWcol = Vector4(0.0, 0.0, 0.0, 1.0);

	Matrix4 xRotationMatrix = Matrix4(rotationXcol,
		rotationYcol,
		rotationZcol,
		rotationWcol);

	*this = (*this * xRotationMatrix);
}

void Matrix4::RotateY(float radi)
{
	auto rotationXcol = Vector4(cos(radi), 0.0, -sin(radi), 0.0);
	auto rotationYcol = Vector4(0.0, 1.0, 0.0, 0.0);
	auto rotationZcol = Vector4(sin(radi), 0.0, cos(radi), 0.0);
	auto rotationWcol = Vector4(0.0, 0.0, 0.0, 1.0);

	Matrix4 y_rotation_matrix = Matrix4(rotationXcol,
		rotationYcol,
		rotationZcol,
		rotationWcol);

	*this = (*this * y_rotation_matrix);
}

void Matrix4::RotateZ(float radi)
{
	auto rotationXcol = Vector4(cos(radi), sin(radi), 0.0, 0.0);
	auto rotationYcol = Vector4(-sin(radi), cos(radi), 0.0, 0.0);
	auto rotationZcol = Vector4(0.0, 0.0, 1.0, 0.0);
	auto rotationWcol = Vector4(0.0, 0.0, 0.0, 1.0);

	Matrix4 zRotationMatrix = Matrix4(rotationXcol,
		rotationYcol,
		rotationZcol,
		rotationWcol);

	*this = (*this * zRotationMatrix);
}
