#include "Rigdbody.h"
#include <limits>
Rigdbody::Rigdbody()
{
}

void Rigdbody::Initialize(float _gravrity, Vector3* _pos, Vector3* _size, Rect* _boundingRect, bool _isStatic)
{
	pos = _pos;
	size = _size;
	boundingRect = _boundingRect;
	isStatic = _isStatic;
	gravrity = _gravrity;
}

Vector3* Rigdbody::GetPos()
{
	return pos;
}

void Rigdbody::Update()
{
	if (isStatic)
	{
		return;
	}
	velocity.y += gravrity * Engine::GetDT() * 150; //150是根据放大倍数得来，1秒钟移动768像素单位，(1/2)(g*multi)t^2 g=9.8 multi = 150
	cout << velocity.y << endl;
	*pos = *pos + velocity * Engine::GetDT();
}

void Rigdbody::AddForce(Vector3 force)
{
	velocity = velocity + force;
}

void Rigdbody::SetVel(Vector3 _vel)
{
	velocity = _vel;
}

Vector3 Rigdbody::GetVel()
{
	return velocity;
}

void Rigdbody::Render()
{
	boundingRect->Render();
}

void Rigdbody::RotateLocalTo(float _rot)
{
	boundingRect->RotateLocalTo(_rot);
}

bool Rigdbody::IsColliding(const Rigdbody& a, const Rigdbody& b)
{
	//分离轴定理，根据点在各边的投影，计算是否都出现叠加区域，只要出现一个空隙，说明未碰撞，停止算法，返回未碰撞
	//因为是矩形，两条边是平行的，所以只需要一个图形取两条边即可。
	Vector3 points[8];

	points[0] = a.boundingRect->topRightVertex + *a.pos;  //atr
	points[1] = a.boundingRect->topLeftVertex + *a.pos;	//atl
	points[2] = a.boundingRect->bottomRightVertex + *a.pos; //abr
	points[3] = a.boundingRect->bottomLeftVertex + *a.pos;//abl

	points[4] = b.boundingRect->topRightVertex + *b.pos; //btr
	points[5] = b.boundingRect->topLeftVertex + *b.pos;//btl
	points[6] = b.boundingRect->bottomRightVertex + *b.pos;//bbr
	points[7] = b.boundingRect->bottomLeftVertex + *b.pos;//bbl

	Vector3 axes[4];
	axes[0] = points[0] - points[1];
	axes[1] = points[0] - points[2];
	axes[2] = points[7] - points[5];
	axes[3] = points[7] - points[6];

	for (int i = 0; i < 4; i++)
	{
		float aMin = numeric_limits<float>::max();
		float aMax = -numeric_limits<float>::max();
		for (int j = 0; j < 4; j++)
		{
			Vector3 proj = Vector3::Projection(points[j], axes[i]);
			float dot = Vector3::Dot(proj, axes[i]);
			aMin = dot < aMin ? dot : aMin;
			aMax = dot > aMax ? dot : aMax;
		}

		float bMin = numeric_limits<float>::max();
		float bMax = -numeric_limits<float>::max();
		for (int j = 4; j < 8; j++)
		{
			Vector3 proj = Vector3::Projection(points[j], axes[i]);
			float dot = Vector3::Dot(proj, axes[i]);
			bMin = dot < bMin ? dot : bMin;
			bMax = dot > bMax ? dot : bMax;
		}
		//cout << aMin << "\t" << aMax << "\t ......" << bMin << "\t" << bMax << endl;
		if (bMin <= aMax && aMin <= bMax)
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}

Rect* Rigdbody::GetBoundRect()
{
	return boundingRect;
}

Rigdbody::~Rigdbody()
{
	if (boundingRect == nullptr)
	{
		return;
	}
	delete boundingRect;
}