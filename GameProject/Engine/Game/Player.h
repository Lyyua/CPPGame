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
	void Render(); //渲染
	void Update();//每一帧检测
	void Flap(); //抖动
	Vector3* GetPos();
	Rigdbody& GetRigdbody();
	void Reset(); //重置
	~Player();

private:
	Vector3 * pos;
	Sprite mSprite;
	Rigdbody rd;
	void HandleInput(); //输入处理
	float flapForce;
	float maxRot;
};
#endif // !PLAYER
