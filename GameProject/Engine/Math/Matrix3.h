#ifndef MAT3
#define MAT3
#include <stdio.h>
class Matrix3
{
public:
	Matrix3();
	Matrix3& operator=(const Matrix3& m3);
	float*& operator[](const int& a);
	float& operator()(const int& a, const int& b);
	~Matrix3();

private:
	float** m3_array;

};
#endif // !MAT3
