#include "Keyboard.h"


bool Keyboard::keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysUp[GLFW_KEY_LAST] = { 0 };

Keyboard::Keyboard()
{
}

void Keyboard::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key < 0)
	{
		return;
	}

	if (action != GLFW_RELEASE && keys[key] == false)
	{
		keysDown[key] = true;
		keysUp[key] = false;
		keys[key] = true;
	}

	if (action == GLFW_RELEASE && keys[key] == true)
	{
		keysDown[key] = false;
		keysUp[key] = true;
		keys[key] = false;
	}
}

bool Keyboard::KeyDown(int button)
{
	bool x = keysDown[button];
	keysDown[button] = false;
	return x;
}

bool Keyboard::KeyUp(int button)
{
	bool x = keysUp[button];
	keysUp[button] = false;
	return x;
}

bool Keyboard::Key(int button)
{
	return keys[button];
}

Keyboard::~Keyboard()
{
}
