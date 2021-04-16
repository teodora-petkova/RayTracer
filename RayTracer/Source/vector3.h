//---------------------------------------------------------------------
// Vector3.h Header
//---------------------------------------------------------------------
#ifndef VECTOR3_H
#define VECTOR3_H

#pragma once

#include <math.h>
#define MAX(a,b) a < b ? b : a

class __declspec(dllexport) Vector3
{
public:
	Vector3();
	Vector3(float f);
	Vector3(float x, float y, float z);
	Vector3(const Vector3& v);
	void operator=(float f);
	void operator=(Vector3 v);
	Vector3 operator+(Vector3 v);
	Vector3 operator-(Vector3 v);
	Vector3 operator*(Vector3 v);
	Vector3 operator/(Vector3 v);
	Vector3 operator+(float f);
	Vector3 operator-(float f);
	Vector3 operator-();
	Vector3 operator*(float f);
	Vector3 operator/(float f);
	void operator+=(Vector3 v);
	void operator-=(Vector3 v);
	void operator*=(Vector3 v);
	void operator/=(Vector3 v);
	Vector3 operator+=(float f);
	Vector3 operator-=(float f);
	Vector3 operator*=(float f);
	Vector3 operator/=(float f);
	bool operator==(const Vector3& v2) const;
	float magnitude();
	friend float dot(Vector3 v1, Vector3 v2);
	void normalize();
	friend Vector3 cross(Vector3 v1, Vector3 v2);

	float x, y, z;
};
#endif
