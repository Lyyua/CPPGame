#include "GameManager.h"
#include "PipeManager.h"

GameManager::GameManager()
{
	mEngine = new Engine();
	mEngine->Initialize("game");//初始化GL运行环境
	Sprite mSprite = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mPlayer = new Player(mSprite);

	startSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	startSprite.SetScale(Vector3(0.5, 0.5, 0.5));
	endSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	endSprite.SetScale(Vector3(0.1, 0.1, 0.1));
	mState = State::START;
}

void GameManager::Start()
{
	PipeManager pManager;
	pManager.Initialize();
	while (true)
	{
		if (Keyboard::KeyDown(GLFW_KEY_ESCAPE))
		{
			break;
		}
		mEngine->Update();

		switch (mState)
		{
		case GameManager::State::START:
			mEngine->BeginRender();//清空缓存，开始渲染
			startSprite.Render();
			mEngine->EndRender();//更换缓存
			if (Keyboard::KeyDown(GLFW_KEY_SPACE))
			{
				mState = State::PLAYING;
				mPlayer->Reset();
				pManager.ReSet();
			}
			break;
		case GameManager::State::PLAYING:
			mPlayer->Update();
			pManager.Update();

			mEngine->BeginRender();//清空缓存，开始渲染
			mPlayer->Render();
			pManager.Render();
			mEngine->EndRender();//更换缓存
			if (pManager.CheckColision(mPlayer))
			{
				mState = State::GAMEOVER;
			}
			if (mPlayer->GetPos()->y <0 || mPlayer->GetPos()->y>Engine::SCREEN_HEIGHT)
			{
				mState = State::GAMEOVER;
			}

			break;
		case GameManager::State::GAMEOVER:
			mEngine->BeginRender();//清空缓存，开始渲染
			endSprite.Render();
			mEngine->EndRender();//更换缓存
			if (Keyboard::KeyDown(GLFW_KEY_SPACE))
			{
				//restart 
				mState = State::START;
			}
			break;
		default:
			break;
		}
	}
}

GameManager::~GameManager()
{
	delete mEngine;
	delete mPlayer;
}
