#pragma once
#include "Application.h"
#include "Input.h"

class Application {
public:
	Application()=default;
	~Application() {};
	bool IsGameRunning() const { return isGameRunning; }
	bool ValidCheck(void);
	void Update(void);

private:
	bool isGameRunning = false;
	Input m_input;
	SDL_Window* window=nullptr;
	SDL_Renderer* renderer=nullptr;
	SDL_GLContext glContext = nullptr;
	int sizeX = 300;
	int sizeY = 400;

	int mouse_X;
	int mouse_Y;

};