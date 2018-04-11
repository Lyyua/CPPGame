#ifndef GAMEMANAGER
#define GAMEMANAGER

#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"

#include "Engine\Game\Player.h"
#include "Pipe.h"
#include "Engine\IO\Keyboard.h"
class GameManager
{

public:
	enum class State {
		START,
		PLAYING,
		GAMEOVER,
	};

public:
	GameManager();
	void Start();

	~GameManager();

private:
	Engine* mEngine;
	Player* mPlayer;

	Sprite startSprite;
	Sprite endSprite;
	State mState;
};

#endif