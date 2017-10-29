#include "Engine.h"

const int Engine::SCREEN_WIDTH = 1024;
const int Engine::SCREEN_HEIGHT = 768;

const int Engine::Z_NEAR = -10;
const int Engine::Z_FAR = 10;

GLFWwindow* Engine::window = NULL;

Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::Initialize(std::string _windowTitle) {
	// Initialize OpenGL
	if (!glfwInit()) {
		std::cout << "[Error] Could not initialize GLFW." << std::endl;
		return false;
	}

	// Create an OpenGL Window
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, _windowTitle.c_str(), NULL, NULL);
	if (window == NULL) {
		std::cout << "[ERROR] Could not create window." << std::endl;
		return false;
	}

	// OpenGL Setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);
	
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	// GL Setup
	//   Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION); // GL_PROJECTION are fine for 2d. Otherones can be used - look up the GL wiki
	glLoadIdentity(); // Loads an "identity matrix"
	glOrtho(0, width, 0, height, Z_NEAR, Z_FAR); // zNear and zFar is basically the depth. For 2D -10 to 10 will be sufficient.
	glDepthRange(Z_NEAR, Z_FAR);

	glMatrixMode(GL_MODELVIEW); // Change Matrix mode (not GL_PROJECTION anymore)

	//   Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // TODO: Check documentation on how this works

	return true;
}

void Engine::Update() {
	glfwPollEvents(); // Allow OpenGL to handle all events stacking up in the queue... i.e. moving the screen around
}

void Engine::Render() {
	glClearColor(0.2, .7, 0, 1); // Clear background with a blueish color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Anything drawn before glfwSwapBuffers(window) will be rendered

	glfwSwapBuffers(window);

	// Anything drawn here will not be renderd
}