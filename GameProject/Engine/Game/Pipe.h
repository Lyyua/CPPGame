#ifndef  PIPE
#define PIPE
#include "Engine\Math\Vector3.h"
#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\Physics\Rigdbody.h"
class Pipe
{
public:
	Pipe();
	Pipe(float _x);
	static Sprite* pipeSprite;
	static void Initialize(); //加载障碍物图片
	void MoveBack();	//往回走
	bool CheckIfOut();
	void RandHeight();
	void RandHeight(float _x);
	void Render();
	Rigdbody& GetTopRD();
	Rigdbody& GetBotRd();

private:
	Sprite topSprite;
	Sprite botSprite;
	Rigdbody topRd;
	Rigdbody botRd;
	
	Vector3* pos;
	Vector3* scale;

	float speed;
	float top;
	float toptop;
	float bot;
	float botbot;
};
#endif // ! PIPE
