#ifndef RECT
#define RECT
#include "Vector3.h"
#include "Engine\Engine.h"
#include "Matrix3.h"

#define PI  3.1415926535

class Rect
{
public:
	Rect();
	Rect(Vector3* _size);
	Rect(Vector3* _pos, Vector3* _size, Vector3 _color);
	~Rect();
	void MoveTo(Vector3 to);
	void MoveBy(Vector3 by);
	void RotateLocalTo(float _rot);
	void SetSize(Vector3 _size);
	void UpdateLocalVertex();
	void Render();

	Vector3 topLeftVertex;
	Vector3 topRightVertex;
	Vector3 bottomLeftVertex;
	Vector3 bottomRightVertex;
private:

	void UpdateVertices(); //¸üÐÂ¶¥µã

	Vector3* pos;
	Vector3* size;
	Vector3 color;
	float rot;
	Vector3 local_topLeftVertex;
	Vector3 local_topRightVertex;
	Vector3 local_bottomLeftVertex;
	Vector3 local_bottomRightVertex;
};
#endif

