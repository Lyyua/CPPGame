#ifndef KEYBOARD
#define KEYBOARD

#include "GLFW\glfw3.h"

class Keyboard
{
public:
	Keyboard();
	static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool KeyDown(int button);
	static bool KeyUp(int button);
	static bool Key(int button);

	~Keyboard();
private:

	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];
};

#endif
