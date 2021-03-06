//---------------------------------------------------------------------
// Tuple.cpp
//---------------------------------------------------------------------
#include "tuple.h"

Tuple Tuple::Point(float x, float y, float z)
{
	return Tuple(x, y, z, 1.0f);
}

Tuple Tuple::Vector(float x, float y, float z)
{
	return Tuple(x, y, z, 0.0f);
}

bool Tuple::IsPoint() const
{
	return this->w == 1;
}

bool Tuple::IsVector() const
{
	return this->w == 0;
}

bool Tuple::operator==(const Tuple& v2) const
{
	float epsilon = 0.0001f;
	return fabs(x - v2.x) < epsilon &&
		fabs(y - v2.y) < epsilon &&
		fabs(z - v2.z) < epsilon;
}

void Tuple::operator=(float f)
{
	x = f;
	y = f;
	z = f;
}

void Tuple::operator=(const Tuple& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
//------------------------------------------------------------------------
// Vector addition/subtraction/multiplication/division with another Vector
//------------------------------------------------------------------------

#define APPLY_OPERATOR_VECTOR(v, op) { x op v.x, y op v.y, z op v.z, w op v.w }
Tuple Tuple::operator+(const Tuple& v) const { return APPLY_OPERATOR_VECTOR(v, +); }
Tuple Tuple::operator-(const Tuple& v) const { return APPLY_OPERATOR_VECTOR(v, -); }
Tuple Tuple::operator*(const Tuple& v) const { return APPLY_OPERATOR_VECTOR(v, *); }
Tuple Tuple::operator/(const Tuple& v) const { return APPLY_OPERATOR_VECTOR(v, / ); }
#undef APPLY_OPERATOR_VECTOR

//------------------------------------------------------------------------
// Vector addition/subtraction/multiplication/division with a scalar.
//------------------------------------------------------------------------

#define APPLY_OPERATOR_SCALAR(s, op) { x op s, y op s, z op s, w op s }
Tuple Tuple::operator+(float s) const { return APPLY_OPERATOR_SCALAR(s, +); }
Tuple Tuple::operator-(float s) const { return APPLY_OPERATOR_SCALAR(s, -); }
Tuple Tuple::operator*(float s) const { return APPLY_OPERATOR_SCALAR(s, *); }
Tuple Tuple::operator/(float s) const
{
	float recip;
	if (s < 0.000001f)  s = 1.0f;
	recip = 1.0f / s;
	return APPLY_OPERATOR_SCALAR(recip, *);
}
#undef APPLY_OPERATOR_SCALAR

Tuple Tuple::operator-() const
{
	return Tuple(-x, -y, -z, w);
}

//------------------------------------------------------------------------
// Vector addition/subtraction/multiplication/division with another Vector
//------------------------------------------------------------------------
#define APPLY_OPERATOR_INIT(v, op) { x op v.x; y op v.y; z op v.z; w op v.w; }
void Tuple::operator+=(const Tuple& v) { APPLY_OPERATOR_INIT(v, +=) }
void Tuple::operator-=(const Tuple& v) { APPLY_OPERATOR_INIT(v, -=) }
void Tuple::operator*=(const Tuple& v) { APPLY_OPERATOR_INIT(v, *=) }
void Tuple::operator/=(const Tuple& v) { APPLY_OPERATOR_INIT(v, /=) }
#undef APPLY_OPERATOR_INIT

//------------------------------------------------------------------------
// Magnitude(), Dot(), Cross(), and Normalize() Functions
//------------------------------------------------------------------------
float Tuple::Magnitude() const
{
	return sqrtf((x * x) + (y * y) + (z * z));
}

//v(x1, y1, z1) dot w(x2, y2, z2) = x1*x2 + y1*y2 + z1*z2
float Tuple::Dot(const Tuple& other) const
{
	return(this->x * other.x + this->y * other.y + this->z * other.z);
}

Tuple Tuple::Cross(const Tuple& other) const
{
	Tuple v = Tuple();
	v.x = ((this->y * other.z) - (this->z * other.y));
	v.y = ((this->z * other.x) - (this->x * other.z));
	v.z = ((this->x * other.y) - (this->y * other.x));
	v.w = this->w;
	return v;
}

Tuple Tuple::Normalize() const
{
	float m = Magnitude();
	if (m < 0.0000001f)
	{
		m = 1.0f;
	}
	float invertedMagnitude = 1 / m;
	return Tuple(
		x * invertedMagnitude,
		y * invertedMagnitude,
		z * invertedMagnitude,
		w);
}

Tuple Tuple::Reflect(const Tuple& normal) const
{
	return (*this) - normal * 2 * this->Dot(normal);
}

std::ostream& operator<<(std::ostream& os, Tuple const& v)
{
	os << "(" << v.X() << ", " << v.Y() << ", " << v.Z() << ", " << v.W() << ")";
	return os;
}