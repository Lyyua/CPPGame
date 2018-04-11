#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

Mouse::Mouse()
{

}

void Mouse::MousePosCallBack(GLFWwindow* window, double xpos, double ypos)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	x = xpos;
	y = height - ypos;
}

void Mouse::MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods)
{
	cout << "button: " << button << endl;
	if (button < 0)
	{
		return;
	}

	if (action != GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

	if (action == GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = false;;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;

}

double Mouse::GetMouseX()
{
	return x;
}

double Mouse::GetMouseY()
{
	return y;
}

bool Mouse::ButtonDown(int button)
{
	bool x = buttonsDown[button];
	buttonsDown[button] = false;
	return x;
}

bool Mouse::ButtonUp(int button)
{
	bool x = buttonsUp[button];
	buttonsUp[button] = false;
	return x;
}

bool Mouse::Button(int button)
{
	return buttons[button];
}

Mouse::~Mouse()
{

}
