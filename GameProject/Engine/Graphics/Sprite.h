#ifndef SPRITE
#define SPRITE

#include "Engine\Engine.h"
#include "Engine\Math\Vector3.h"
#include "Texture.h" 
#include <iostream>
#include <string>

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 pos);

	void Update();
	void Render();
	void MoveTo(Vector3 pos); //移至目标点
	void MoveBy(Vector3 deltaPos);//单位变化量
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void SpeedTo(float x);//速度赋值
	void SpeedBy(float x);//速度变化量

	Vector3* GetSize();
	Vector3* GetPos();
	float* GetRot();
	void RotateTo(float _rot);//角度赋值
	void RotateBy(float deltaRot); //角度变化量
	void SetScale(Vector3 s);
	~Sprite();
	
private:
	Texture texture;
	Vector3 pos;
	Vector3 scale;
	Vector3 size;

	float speed;
	float rot;

};

#endif // !SPRITE


