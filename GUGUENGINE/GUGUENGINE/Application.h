#pragma once
/*
 *juhye.son
 *9.17.2019
 *juhye.son990902@gmail.com
 *Application.h
 *this is applicaiotn header
 */
#include "Application.h"
#include  "Shader.h"
#include "../GLFW/glfw3.h"
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

	

	void setMyWindow(GLFWwindow& m);
	GLFWwindow* getMyWindow();


	int height = 800;
	int width = 800;
private:
	bool isGameRunning = false;
	int sizeX = 300;
	int sizeY = 400;
	
	int mouse_X;
	int mouse_Y;
	Shader mShader;
	GLFWwindow* Mywindow;

};
extern Application* APPLICATION;
