#ifndef ENGINE
#define ENGINE

#include "GLFW/glfw3.h"
#pragma	comment(lib,"opengl32.lib")

#include <iostream>
using namespace std;

class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	~Engine();
	static float GetDT();
	bool Initialize(const char* windowTitle);
	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
	static float dt; //单位时间间隔
	float lastTime;
};

#endif


