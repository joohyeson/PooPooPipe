#pragma once
#include "Application.h"
//#include "Input.h"
#include <include/GLFW/glfw3.h>

class Application {
public:
	Application() = default;
	~Application() {}
	bool IsGameRunning() const { return isGameRunning; }
	bool ValidCheck();
	void Update();
	void End();
	//void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	//void errorCallback(int errorCode, const char* errorDescription);
	//void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	//void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	//void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

private:
	bool isGameRunning = true;
	const int width = 800;
	const int height = 600;
	GLFWwindow* window;

};
