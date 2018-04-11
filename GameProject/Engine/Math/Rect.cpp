#include "Rect.h"

Rect::Rect()
{
	pos = &Vector3(0, 0, 0);
	size = &Vector3(0, 0, 0);
	color = Vector3(255, 0, 0);
	UpdateVertices();
	UpdateLocalVertex();
}

Rect::Rect(Vector3* _size) :Rect()
{
	size = _size;
	UpdateVertices();
	UpdateLocalVertex();
}

Rect::Rect(Vector3* _pos, Vector3* _size, Vector3 _color) :Rect(_size)
{
	pos = _pos;
	color = _color;
	UpdateVertices();
	UpdateLocalVertex();
}

void Rect::MoveTo(Vector3 target)
{
	*pos = target;
	UpdateVertices();
}

void Rect::MoveBy(Vector3 by)
{
	*pos = *pos + by;
	UpdateVertices();
}

void Rect::RotateLocalTo(float _rot)
{
	rot = _rot;
	Matrix3 mat3;
	float theta = _rot * PI / 180;
	mat3[0][0] = cosf(theta);
	mat3[0][1] = sinf(theta);
	mat3[0][2] = 0;

	mat3[1][0] = -sinf(theta);
	mat3[1][1] = cosf(theta);
	mat3[1][2] = 0;

	mat3[2][0] = 0;
	mat3[2][1] = 0;
	mat3[2][2] = 0;

	topRightVertex = local_topRightVertex * mat3;
	topLeftVertex = local_topLeftVertex * mat3;
	bottomLeftVertex = local_bottomLeftVertex * mat3;
	bottomRightVertex = local_bottomRightVertex * mat3;
}

void Rect::SetSize(Vector3 _size)
{
	*size = _size;
	UpdateVertices();
	UpdateLocalVertex();
}

void Rect::Render()
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	glColor4f(color.x, color.y, color.z, 1);
	glLineWidth(2.5);

	glBegin(GL_LINES);
	{
		glVertex2f(bottomLeftVertex.x, bottomLeftVertex.y);
		glVertex2f(bottomRightVertex.x, bottomRightVertex.y);

		glVertex2f(bottomRightVertex.x, bottomRightVertex.y);
		glVertex2f(topRightVertex.x, topRightVertex.y);

		glVertex2f(topRightVertex.x, topRightVertex.y);
		glVertex2f(topLeftVertex.x, topLeftVertex.y);

		glVertex2f(topLeftVertex.x, topLeftVertex.y);
		glVertex2f(bottomLeftVertex.x, bottomLeftVertex.y);

	}
	glEnd();
}

void Rect::UpdateVertices()
{
	topRightVertex = Vector3(size->x / 2, size->y / 2, 0);
	topLeftVertex = Vector3(-size->x / 2, size->y / 2, 0);
	bottomLeftVertex = Vector3(-size->x / 2, -size->y / 2, 0);
	bottomRightVertex = Vector3(size->x / 2, -size->y / 2, 0);
}

void Rect::UpdateLocalVertex()
{
	local_topRightVertex = Vector3(size->x / 2, size->y / 2, 0);
	local_topLeftVertex = Vector3(-size->x / 2, size->y / 2, 0);
	local_bottomLeftVertex = Vector3(-size->x / 2, -size->y / 2, 0);
	local_bottomRightVertex = Vector3(size->x / 2, -size->y / 2, 0);
}
Rect::~Rect()
{
}
