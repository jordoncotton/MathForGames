#include "Matrix3.h"

matrix3::matrix3()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int l = 0; l <= 2; l++)
		{
			num[i][l] = 0.0;
		}
	}
}

void matrix3::set(matrix3)
{

}

matrix3 matrix3::operator*(const matrix3) const
{
	return matrix3();
}
