#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int l = 0; l < 3; l++)
		{
			Matrix[i][l] = 0.0;
			identityMatrixData[i][l] = 0.0;
		}
	}
}

Matrix3::Matrix3(Vector3 Xvec, Vector3 Yvec, Vector3 Zvec)
{
	for (int i = 0; i < 3; i++)
	{
		Matrix[i][0] = Xvec[i];
		identityMatrixData[i][0] = Xvec[i];
	}

	for (int i = 0; i < 3; i++)
	{
		Matrix[i][1] = Yvec[i];
		identityMatrixData[i][0] = Yvec[i];
	}
	
	for (int i = 0; i < 3; i++)
	{
		Matrix[i][2] = Zvec[i];
		identityMatrixData[i][0] = Zvec[i];
	}
}

Matrix3 Matrix3::operator*(Matrix3 other)
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

Vector3 Matrix3::operator*(Vector3 vector)
{
	Vector3 outcome;

	for (int c = 0; c < 3; c++)
	{
		outcome[c] =
			Matrix[0][c] * vector[c] +
			Matrix[1][c] * vector[c] +
			Matrix[2][c] * vector[c];
	}
	return outcome;
}

Vector3 & Matrix3::operator[](int)
{
	// TODO: insert return statement here
	Vector3 vector3 =
	Vector3(Matrix[0][0],
		    Matrix[1][0],
		    Matrix[2][0]);

	return vector3;
}

Matrix3::Matrix3(float A, float B, float C, float D, float E, float F, float G, float H, float I)
{
	Matrix[0][0] = A;
	Matrix[1][0] = B;
	Matrix[2][0] = C;

	Matrix[0][1] = D;
	Matrix[1][1] = E;
	Matrix[2][1] = F;

	Matrix[0][2] = G;
	Matrix[1][2] = H;
	Matrix[2][2] = I;
}

Matrix3::operator float*()
{
	return Matrix[0];
}

void Matrix3::RotateX(float Radi)
{
	Matrix3 xRotationMatrix = Matrix3(
		cos(Radi), sin(Radi), 0.0f
		, -sin(Radi), cos(Radi), 0.0f, 
		0.0f, 0.0f, 1.0f);

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			Matrix[c][r] =
				identityMatrixData[0][r] * xRotationMatrix.Matrix[c][0] +
				identityMatrixData[1][r] * xRotationMatrix.Matrix[c][1] +
				identityMatrixData[2][r] * xRotationMatrix.Matrix[c][2];
		}
	}
}

void Matrix3::RotateY(float Radi)
{
	Matrix3 yRotationMatrix = Matrix3(cos(Radi), 0.0, -sin(Radi), 0.0, 1.0, 0.0, sin(0), 0.0, cos(Radi));

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			Matrix[c][r] =
				identityMatrixData[0][r] * yRotationMatrix.Matrix[c][0] +
				identityMatrixData[1][r] * yRotationMatrix.Matrix[c][1] +
				identityMatrixData[2][r] * yRotationMatrix.Matrix[c][2];
		}
	}
}

void Matrix3::RotateZ(float Radi)
{
	Matrix3 zRotationMatrix = Matrix3(1.0, 0.0, 0.0, 0.0, cos(Radi), sin(Radi), 0.0, -sin(Radi), cos(Radi));

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			Matrix[c][r] =
				identityMatrixData[0][r] * zRotationMatrix.Matrix[c][0] +
				identityMatrixData[1][r] * zRotationMatrix.Matrix[c][1] +
				identityMatrixData[2][r] * zRotationMatrix.Matrix[c][2];
		}
	}
}
