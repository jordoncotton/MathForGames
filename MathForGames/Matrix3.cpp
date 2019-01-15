#include "Matrix3.h"

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

void Matrix3::set(Matrix3)
{
	
}

Matrix3 Matrix3::operator*(const Matrix3 rotate) const
{
	Matrix3 outcome;

	for (int v = 0; v < 3; v++)
	{
		for (int a = 0; a < 3; a++)
		{
			outcome.Matrix[v][a] =
				Matrix[0][v] * rotate.Matrix[a][0] +
				Matrix[1][v] * rotate.Matrix[a][1] +
				Matrix[2][v] * rotate.Matrix[a][2];

		}
	}
	return outcome;
}

Vector3 Matrix3::operator*(const Vector3 vector) const
{
	Vector3 outcome;

	for (int c = 0; c < 3; c++)
	{
		outcome[c] = Matrix[0][c] * vector[c] +
			Matrix[1][c] * vector[c] +
			Matrix[2][c] * vector[c];
	}
	return outcome;
}

Vector3 & Matrix3::operator[](int)
{
	// TODO: insert return statement here
	Vector3 vec3 = Vector3(Matrix[0][0],
		Matrix[1][0],
		Matrix[2][0]);

	return vec3;
}

void Matrix3::rotateX(float radians)
{
	auto rotateX = Vector3(cos(radians), sin(radians), 0.0);
}   

void Matrix3::rotateY(float radians)
{
	auto rotateY = Vector3(-sin(radians), cos(radians), 0);
}

void Matrix3::rotateZ(float)
{
	auto rotateZ = Vector3(0.0, 0.0, 1.0);
}
