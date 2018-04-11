#include "Engine.h"
#include "Engine\IO\Mouse.h"
#include "Engine\IO\Keyboard.h"
int Engine::SCREEN_WIDTH = 1024 * 0.8;
int Engine::SCREEN_HEIGHT = 768 * 0.8;
float Engine::dt = 0;
GLFWwindow* Engine::window = NULL;

Engine::Engine()
{
	cout << "construct" << endl;
}


Engine::~Engine()
{
}
bool Engine::Initialize(const char* windowTitle)
{
	if (!glfwInit())
	{
		cout << "error when glfwinit" << endl;
		return false;
	}
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);

	if (window == NULL)
	{
		cout << "error creating window" << endl;
		return false;
	}

	//OpenGL SetUp
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	//点击事件注册
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallBack);
	//鼠标事件注册
	glfwSetCursorPosCallback(window, Mouse::MousePosCallBack);
	//按键事件注册
	glfwSetKeyCallback(window, Keyboard::KeyCallBack);

	glfwSwapInterval(1);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	lastTime = (float)glfwGetTime();

	//GL SetUp
	//ViewPort
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

float timeCount = 0;
float fpsTime = 0;

void Engine::Update()
{
	float now = (float)glfwGetTime();
	dt = now - lastTime;
	fpsTime += dt;
	if (fpsTime < 1)
	{
		timeCount++;
	}
	else
	{
		cout << timeCount << endl;
		timeCount = 0;
		fpsTime = 0;
	}

	lastTime = now;
	glfwPollEvents();
}

void Engine::BeginRender()
{
	glClearColor(0, 1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Engine::EndRender()
{
	glfwSwapBuffers(window);
}

float Engine::GetDT()
{
	return dt;
}