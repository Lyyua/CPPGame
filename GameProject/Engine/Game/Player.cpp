#include "Player.h"

Player::Player()
{

}

Player::Player(Sprite _sprite)
{
	mSprite = _sprite;
	pos = mSprite.GetPos();
	mSprite.SetScale(Vector3(0.1, 0.1, 0.1));
	Rect* pRect = new Rect(mSprite.GetPos(), mSprite.GetSize(), Vector3(0, 0, 0));
	rd.Initialize(-9.8, mSprite.GetPos(), mSprite.GetSize(), pRect, false);
	flapForce = 750;
	maxRot = 30;
}

void Player::Render()
{
	mSprite.Render();
	rd.Render();
}

void Player::Update()
{
	HandleInput();
	rd.Update();
}

void Player::HandleInput()
{
	if (Keyboard::KeyDown(GLFW_KEY_SPACE))
	{
		Flap();
	}
	float newRot = (rd.GetVel().y / flapForce)*maxRot; //向上运动时，角度向上
	mSprite.RotateTo(newRot);
	rd.GetBoundRect()->RotateLocalTo(newRot);
}

void Player::Flap()
{
	rd.AddForce(Vector3(0, flapForce, 0));
	mSprite.RotateTo(maxRot);
	rd.RotateLocalTo(maxRot);
}

Rigdbody& Player::GetRigdbody()
{
	return rd;
}

Vector3* Player::GetPos()
{
	return pos;
}

void Player::Reset()
{
	mSprite.MoveTo(Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mSprite.RotateTo(0);
	rd.RotateLocalTo(0);
	rd.SetVel(Vector3(0, 0, 0));
}

Player::~Player()
{

}