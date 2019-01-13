#include "Matrix3.h"

matrix3::matrix3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int l = 0; l < 3; l++)
		{
			matrix[i][l] = 0.0;
		}
	}
}

matrix3::matrix3(Vector3 Xvec, Vector3 Yvec, Vector3 Zvec)
{
	for (int i = 0; i < 3; i++)
	{
		matrix[i][0] = Xvec[i];
	}

	for (int i = 0; i < 3; i++)
	{
		matrix[i][1] = Yvec[i];
	}
	
	for (int i = 0; i < 3; i++)
	{
		matrix[i][2] = Zvec[i];
	}
}

void matrix3::set(matrix3)
{
	
}

matrix3 matrix3::operator*(const matrix3) const
{
	return matrix3();
}

Vector3 matrix3::operator*(const Vector3) const
{
	return Vector3();
}

void matrix3::rotateX(float)
{
}

void matrix3::rotateY(float)
{
}

void matrix3::rotateZ(float)
{
}
