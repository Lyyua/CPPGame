#ifndef  RIGDBODY
#define RIGDBODY
#include "Engine\Math\Vector3.h"
#include "Engine\Math\Rect.h"
class Rigdbody
{
public:
	Rigdbody();

	void Initialize(float _gravrity, Vector3* _pos, Vector3* _size, Rect* _boundingRect, bool _isStatic);
	void Render();
	void Update();
	void AddForce(Vector3 force);
	void SetVel(Vector3 _vel);
	Vector3 GetVel();
	void RotateLocalTo(float _rot);
	static bool IsColliding(const Rigdbody& a, const Rigdbody& b);
	Rect* GetBoundRect();
	Vector3* GetPos();
	~Rigdbody();

private:
	Vector3 * pos;
	Vector3* size;
	Rect* boundingRect = nullptr;

	Vector3 velocity;
	float gravrity;
	bool isStatic;

};
#endif // ! RIGDBODY
