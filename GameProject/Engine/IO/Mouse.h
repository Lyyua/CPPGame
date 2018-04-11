#ifndef  MOUSE
#define MOUSE

#include "GLFW\glfw3.h"
#include <iostream>
using namespace std;
class Mouse
{
public:
	Mouse();

	static void MousePosCallBack(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);

	static double GetMouseX();
	static double GetMouseY();

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool Button(int button);
	~Mouse();

private:
	static double x;
	static double y;

	static bool buttons[]; //IO输入对应的按键
	static bool buttonsDown[];
	static bool buttonsUp[];

};
#endif // ! MOUSE
