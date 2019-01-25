#pragma once
class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);

	float getX();
	float getY();
	float getZ();
	float getW();

	Vector4 operator + (Vector4& rhs);
	Vector4 operator - (Vector4& rhs);
	Vector4 operator * (float& rhs);

	bool operator == (Vector4& rhs);
	bool operator != (Vector4& rhs);

	float Magnitude();

	Vector4 Normalise();
	Vector4 Cross(Vector4 other);

	float Distance(Vector4 other);
	float Dot(Vector4 other);
	float& operator[] (int index);

	operator float* ();

private:
	float Xpos, Ypos, Zpos, Wpos;

};