#include "Pipe.h"
#include "Engine\Math\Math.h"
Sprite* Pipe::pipeSprite = NULL;

Pipe::Pipe()
{
	if (!pipeSprite)
	{
		return;
	}
	topSprite = Sprite(*pipeSprite);
	topSprite.SetScale(Vector3(0.1, 0.1, 1));
	topSprite.MoveTo(Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT, 0));
	topSprite.RotateTo(180);

	botSprite = Sprite(*pipeSprite);
	botSprite.SetScale(Vector3(0.1, 0.1, 1));
	botSprite.MoveTo(Vector3(Engine::SCREEN_WIDTH / 2, 0, 0));
}

Pipe::Pipe(float _x)
{
	if (!pipeSprite)
	{
		return;
	}
	topSprite = Sprite(*pipeSprite);
	topSprite.SetScale(Vector3(0.1, 0.15, 1));

	top = Engine::SCREEN_HEIGHT - topSprite.GetSize()->x / 2; //图片的锚点是在中心的,恰好对齐上端
	toptop = Engine::SCREEN_HEIGHT + topSprite.GetSize()->x / 4; //图片一半没入上端

	topSprite.MoveTo(Vector3(_x + topSprite.GetSize()->x / 2, Math::RandFloat(top, toptop), 0));
	topSprite.RotateTo(180);
	Rect* topRect = new Rect(topSprite.GetPos(), topSprite.GetSize(), Vector3(255, 0, 0));
	topRd.Initialize(0, topSprite.GetPos(), topSprite.GetSize(), topRect, true);



	botSprite = Sprite(*pipeSprite);
	botSprite.SetScale(Vector3(0.1, 0.15, 1));

	bot = botSprite.GetSize()->x / 2;
	botbot = -botSprite.GetSize()->x / 2;

	botSprite.MoveTo(Vector3(_x + botSprite.GetSize()->x / 2, -botSprite.GetSize()->x / 2, 0));
	Rect* botRect = new Rect(botSprite.GetPos(), botSprite.GetSize(), Vector3(0, 0, 255));
	botRd.Initialize(0, botSprite.GetPos(), botSprite.GetSize(), botRect, true);
}

void Pipe::Initialize()
{
	pipeSprite = new Sprite("Assets/Art/pipe.png");
	pipeSprite->SpeedTo(100);
}

bool Pipe::CheckIfOut()
{
	if (topSprite.GetPos()->x <= -topSprite.GetSize()->x / 2)
	{
		return true;
	}
	return false;
}

//随机高度
void Pipe::RandHeight()
{
	topSprite.MoveTo(Vector3(topSprite.GetPos()->x + topSprite.GetSize()->x / 2, Math::RandFloat(top, toptop), 0));
	botSprite.MoveTo(Vector3(botSprite.GetPos()->x + botSprite.GetSize()->x / 2, Math::RandFloat(botbot, bot), 0));
	cout << botSprite.GetPos()->y << endl;
}

void Pipe::RandHeight(float _x)
{
	topSprite.MoveTo(Vector3(_x + topSprite.GetSize()->x / 2, Math::RandFloat(top, toptop), 0));
	botSprite.MoveTo(Vector3(_x + botSprite.GetSize()->x / 2, Math::RandFloat(botbot, bot), 0));
	cout << botSprite.GetPos()->y << endl;
}

void Pipe::Render()
{
	topSprite.Render();
	botSprite.Render();
	topRd.Render();
	botRd.Render();
}

void Pipe::MoveBack()
{
	topSprite.MoveLeft();
	botSprite.MoveLeft();
}

Rigdbody& Pipe::GetTopRD()
{
	return topRd;
}

Rigdbody& Pipe::GetBotRd()
{
	return botRd;
}
