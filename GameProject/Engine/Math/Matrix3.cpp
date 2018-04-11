#include "Matrix3.h"

Matrix3::Matrix3()
{
	m3_array = new float*[3];
	for (int i = 0; i < 3; i++)
	{
		m3_array[i] = new float[3];
	}
}

Matrix3 & Matrix3::operator=(const Matrix3& m3)
{
	if (m3_array == m3.m3_array)
	{
		return *this;
	}
	if (m3_array != NULL)
	{
		delete[]m3_array;
	}
	m3_array = m3.m3_array;
	return *this;
}

float*& Matrix3::operator[](const int& a)
{
	return m3_array[a];
}

float& Matrix3::operator()(const int& a, const int& b)
{
	return m3_array[a][b];
}

Matrix3::~Matrix3()
{
	delete[] m3_array;

}