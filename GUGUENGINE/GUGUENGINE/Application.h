#pragma once
#include "Application.h"
//#include "Input.h"
#include  "Shader.h"
//#include "include/GLFW/glfw3.h"
#include "System.h"

class Application : public System
{
public:
	Application();
	~Application();
	
	bool IsGameRunning() const { return isGameRunning; }
	void ValidCheck();
	
	void Init() override;
	void Update() override;

	
private:
	bool isGameRunning = false;
	int sizeX = 300;
	int sizeY = 400;
	int height = 600;
	int width = 800;
	int mouse_X;
	int mouse_Y;
	Shader mShader;
	GLFWwindow* Mywindow;

};
