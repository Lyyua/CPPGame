#include "Vector3.h"
#include <math.h>

const Vector3 Vector3::ZERO = Vector3(0, 0, 0);
const Vector3 Vector3::ONE = Vector3(1, 1, 1);

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3 Vector3::operator+	(const Vector3& other)
{
	Vector3 ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	ret.z = z + other.z;
	return ret;
}

Vector3 Vector3::operator-	(const Vector3& other)
{
	Vector3 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;
	return ret;
}

Vector3 Vector3::operator*	(const Vector3& other)
{
	Vector3 ret;
	ret.x = x * other.x;
	ret.y = y * other.y;
	ret.z = z * other.z;
	return ret;
}

Vector3 Vector3::operator*	(const float p)
{
	Vector3 ret;
	ret.x = x * p;
	ret.y = y * p;
	ret.z = z * p;
	return ret;
}

Vector3 Vector3::operator*(Matrix3& m3)
{
	Vector3 ret;
	ret.x = x * m3[0][0] + y * m3[1][0] + z * m3[2][0];
	ret.y = x * m3[0][1] + y * m3[1][1] + z * m3[2][1];
	ret.z = x * m3[0][2] + y * m3[1][2] + z * m3[2][2];
	return ret;
}

bool Vector3::operator== (const Vector3& other)
{
	return (x == other.x && y == other.y&& z == other.z);
}

bool Vector3::operator!= (const Vector3& other)
{
	return (!operator==(other));
}

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
///n*(v¡¤n)/|n|^2
Vector3 Vector3::Projection(const Vector3& a, const Vector3& b)
{
	return Vector3(
		(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2) + (float)pow(b.z, 2)))*b.x,
		(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2) + (float)pow(b.z, 2)))*b.y,
		(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2) + (float)pow(b.z, 2)))*b.z);
}

string Vector3::toString()
{
	stringstream ss;
	ss << "(" << x << "," << y << "," << z << ")";
	return ss.str();
}

Vector3::~Vector3()
{
}
