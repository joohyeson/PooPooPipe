#pragma once
#include "Application.h"
//#include "Input.h"
#include  "Shader.h"
//#include "include/GLFW/glfw3.h"
#include "System.h"
#include "Input.h"
class Application : public System
{
public:
	Application();
	~Application();
	
	bool IsGameRunning() const { return isGameRunning; }
	void ValidCheck();
	
	void Init() override;
	void Update() override;

	void PollKeyboardEvent(SDL_Event& currentEvent);
	void PollMouseEvent(SDL_Event& currentEvent);

	void setMyWindow(GLFWwindow& m);
	GLFWwindow* getMyWindow();
	SDL_Event& GetEvent() { return SDLevent; }

	int height = 600;
	int width = 600;
private:
	SDL_Event SDLevent;
	bool isGameRunning = false;
	int sizeX = 300;
	int sizeY = 400;
	
	int mouse_X;
	int mouse_Y;
	Shader mShader;
	GLFWwindow* Mywindow;

};
extern Application* APPLICATION;
