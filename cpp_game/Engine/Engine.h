#pragma once // Windows Onle. Following code is cross platform:
//#ifndef AWO_ENGINE
//#define AWO_ENGINE

#include "GLFW\glfw3.h" // OpenGL
#include <iostream>
#include <string>
#pragma comment(lib, "opengl32.lib") // TODO: not platform indeepndant - could probably be resolved by adding library manually

class Engine
{
public:
	const static int SCREEN_WIDTH;
	const static int SCREEN_HEIGHT;

	Engine();
	~Engine();

	bool Initialize(std::string _windowTitle);

	void Update();
	void Render();

private:
	const static int Z_NEAR;
	const static int Z_FAR;
	static GLFWwindow* window;
};

// For cross platform - instead of #pragma once
//#endif // !AWO_ENGINE