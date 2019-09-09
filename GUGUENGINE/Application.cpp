#pragma once
#include "SDL.h"
#include <iostream>
#include "Application.h"
#include "glew.h"

#pragma comment(lib, "SDL2.lib") 
#pragma comment(lib, "SDL2main.lib") 

bool Application::ValidCheck(void)
{
	SDL_Event event;

	// Initialize SDL
	// ==========================================================
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		// Something failed, print error and exit.
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	// Create and init the window
	// ==========================================================
	//window = SDL_CreateWindow("Server", posX, posY, sizeX, sizeY, 0);
	window = SDL_CreateWindow("GOOD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		sizeX, sizeY, SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}
	else {
			//Create context
			glContext = SDL_GL_CreateContext(window);
			SDL_GL_SetSwapInterval(true);
			if (glContext == NULL)
			{
				isGameRunning = false;
			}
	}

	isGameRunning = true;
	
	return true;
}
void Application::Update(void)
{
	////////////////change color//////////////////////////
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	/* Swap our back buffer to the front */
	SDL_GL_SwapWindow(window);
	/////////////////////////////////////////////////////////////
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isGameRunning = true;
			break;
		case SDL_KEYDOWN:
			/////////////////////////delete//////////////////////
			glClearColor(0.0, 1.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			/* Swap our back buffer to the front */
			SDL_GL_SwapWindow(window);
			/////////////////////////////////////////////////////////
			m_input.SetKeyPressed(event.key.keysym.scancode, SDL_KEYDOWN);
			break;
		case SDL_KEYUP:
			//glClearColor(255, 0, 0, 1);
			m_input.SetKeyPressed(event.key.keysym.scancode, SDL_KEYUP);
			break;
		//case SDL_WINDOWEVENT:
		//	break;
		case SDL_MOUSEBUTTONDOWN:
		//	//fall through to next case
		case SDL_MOUSEBUTTONUP:
			/////////////////////////delete//////////////////////
			glClearColor(0.0, 0.0, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			/* Swap our back buffer to the front */
			SDL_GL_SwapWindow(window);
			/////////////////////////////////////////////////////////
			m_input.SetMousePressed(event.button.button, SDL_MOUSEBUTTONUP);
		break;

		}
	}

}