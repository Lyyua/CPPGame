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
	void MoveTo(Vector3 pos); //����Ŀ���
	void MoveBy(Vector3 deltaPos);//��λ�仯��
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void SpeedTo(float x);//�ٶȸ�ֵ
	void SpeedBy(float x);//�ٶȱ仯��

	Vector3* GetSize();
	Vector3* GetPos();
	float* GetRot();
	void RotateTo(float _rot);//�Ƕȸ�ֵ
	void RotateBy(float deltaRot); //�Ƕȱ仯��
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


