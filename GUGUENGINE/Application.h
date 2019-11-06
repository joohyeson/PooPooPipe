#pragma once

#include "Input.h"
#include "System.h"

class Application : public System
{
public:
	Application();
	~Application();

	void Init() override;
	void Update() override;
	
	bool IsGameRunning() const { return isGameRunning; }
	bool ValidCheck(void);
	
	void gameLoop();

private:
	bool isGameRunning = false;
	Input m_input;
	SDL_Window* window=nullptr;
	SDL_Renderer* renderer=nullptr;
	SDL_GLContext glContext = nullptr;
	
	int sizeX = 300;
	int sizeY = 400;
	int height = 600;
	int width = 800;
	int mouse_X;
	int mouse_Y;

};

