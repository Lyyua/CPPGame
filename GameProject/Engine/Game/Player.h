#ifndef PLAYER
#define PLAYER

#include "Engine\Graphics\Sprite.h"
#include "Engine\Engine.h"
#include "Engine\Physics\Rigdbody.h"
#include "Engine\IO\Keyboard.h"
class Player
{
public:
	Player();
	Player(Sprite _sprite);
	void Render(); //��Ⱦ
	void Update();//ÿһ֡���
	void Flap(); //����
	Vector3* GetPos();
	Rigdbody& GetRigdbody();
	void Reset(); //����
	~Player();

private:
	Vector3 * pos;
	Sprite mSprite;
	Rigdbody rd;
	void HandleInput(); //���봦��
	float flapForce;
	float maxRot;
};
#endif // !PLAYER
