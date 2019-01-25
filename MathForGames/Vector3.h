#pragma once

class Vector3
{
private:
	float xPos;
	float yPos;
	float zPos;

public:
	Vector3();
	~Vector3();
	Vector3(float x, float y, float z);

	float GetX();
	float GetY();
	float magnitude();
	float Distance(Vector3& other);
	float DotProduct(Vector3& other);

	Vector3 CrossProduct(Vector3& rhs);
	Vector3 Normalize();
	Vector3 operator+(Vector3 &rhs);
	Vector3 operator-(Vector3 &rhs);
	Vector3 operator*(float &rhs);
	float& operator[] (int other);

	bool operator==(Vector3 &rhs);
	bool operator!=(Vector3 &rhs);
};