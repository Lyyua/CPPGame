#include "Sprite.h"

Sprite::Sprite()
{
	texture = Texture();
	pos = Vector3::ZERO;
	scale = Vector3(1, 1, 1);
	rot = 0;
}

Sprite::Sprite(string path)
{
	texture = Texture(path);
	pos = Vector3::ZERO;
	scale = Vector3(1, 1, 1);
	rot = 0;
	size = Vector3(texture.GetWidth(), texture.GetHeight(), 0);
}

Sprite::Sprite(string path, Vector3 _pos)
{
	texture = Texture(path);
	pos = _pos;
	scale = Vector3(1, 1, 1);
	rot = 0;
	size = Vector3(texture.GetWidth(), texture.GetHeight(), 0);
}
float* Sprite::GetRot()
{
	return &rot;
}

void Sprite::SetScale(Vector3 s)
{
	scale = s;
	size = size * s;
}

void Sprite::MoveTo(Vector3 target)
{
	pos = target;
}

void Sprite::MoveBy(Vector3 deltaDir)
{

}

void Sprite::MoveLeft()
{
	pos.x -= speed * Engine::GetDT();
}

void Sprite::MoveRight()
{

}

void Sprite::MoveDown()
{

}

void Sprite::MoveUp()
{

}

void Sprite::RotateTo(float _rot)
{
	rot = _rot;
}

void Sprite::RotateBy(float _rot)
{
	rot += _rot;
}

void Sprite::SpeedTo(float v)
{
	speed = v;
}

void Sprite::SpeedBy(float deltaV)
{
	speed += deltaV;
}

void Sprite::Update()
{

}

Vector3* Sprite::GetSize()
{
	return &size;
}

Vector3* Sprite::GetPos()
{
	return &pos;
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	//Translate -> Rotate -> Scale
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, scale.z);

	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	{
		//把图形锚点设置在中心 逆时针顺序绑定！！！！
		glTexCoord2f(0, 0);	glVertex2f(-texture.GetWidth() / 2, -texture.GetHeight() / 2);
		glTexCoord2f(1, 0);	glVertex2f(texture.GetWidth() / 2, -texture.GetHeight() / 2);
		glTexCoord2f(1, 1);	glVertex2f(texture.GetWidth() / 2, texture.GetHeight() / 2);
		glTexCoord2f(0, 1);	glVertex2f(-texture.GetWidth() / 2, texture.GetHeight() / 2);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

Sprite::~Sprite()
{
}
