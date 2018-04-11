#ifndef VECTOR3
#define VECTOR3
#include <sstream>
#include "Matrix3.h"

using namespace std;
class Vector3
{
public:
	static const Vector3 ZERO;
	static const Vector3 ONE;
	Vector3();
	Vector3(float _x, float _y, float _z);
	Vector3(const Vector3& other);  //�������죬����������ܸı�

	Vector3& operator=(const Vector3& other); //��ֵ����
	Vector3 operator+(const Vector3& other); //�������
	Vector3 operator-(const Vector3& other); //�������
	Vector3 operator*(const Vector3& other); //�������
	Vector3 operator*(const float p);
	//friend float operator*(const float p, const Vector3& other);
	Vector3 operator*(Matrix3& m3);
	static float Dot(const Vector3& a, const Vector3& b);
	static Vector3 Projection(const Vector3& a, const Vector3& b);
	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	string toString();
	~Vector3();


	float x;
	float y;
	float z;

};
#endif