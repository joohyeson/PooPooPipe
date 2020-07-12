/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Engine.cpp
 */
#include<SDL.h>
#include <glew.h>
#include <vector>
#include <iostream>

#include "Engine.h"
#include"Application.h"
#include "ObjectManager.h"
#include "glfwInput.h"
#include "Sound.h"
#include "../Level/StateManager.h"


Engine* ENGINE = nullptr;

Engine::Engine()
{
	GAMERUN = true;
	ENGINE = this;
}

Engine::~Engine()
{
	ENGINE = nullptr;
}

void Engine::Init()
{
	AddSystem(new Application());
	AddSystem(new ObjectFactory());
	AddSystem(new StateManager());

	lastTick = std::chrono::system_clock::now();
	fpsCalcTime = lastTick;

	for (auto GUGU : Systems)
	{
		GUGU->Init();
	}
}

void Engine::GameLoop()
{
	int width, height;
	
	while (GAMERUN)
	{
		std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
		double dt = std::chrono::duration<double>(now - lastTick).count();
		glfwGetWindowSize(APPLICATION->getMyWindow(), &width, &height);

		if (dt >= 1 / Engine::Target_FPS)
		{
			lastTick = now;

			if (++frameCount >= Engine::FPS_IntervalFrameCount)
			{
				double actualTime = std::chrono::duration<double>((now - fpsCalcTime)).count();
				std::cout << "FPS:  " << frameCount / actualTime << std::endl;
				frameCount = 0;
				fpsCalcTime = now;
			}

			if (width != 0 && height != 0)
			{
				if (SOUND->IsPaused() == false)
				{
					SOUND->Resume();
				}
				for (auto GUGU : Systems)
				{
					GUGU->Update();
				}
				checkWindow = true;
			}
			else
			{
				APPLICATION->Update();
				SOUND->Pause();
				if (checkWindow)
				{
					std::cout << "window is minimized" << std::endl;
					checkWindow = false;
				}
			}
		}
		
	}
	INPUT->Update();
}

void Engine::Quit()
{
	GAMERUN = false;
}

void Engine::AddSystem(System* system)
{
	Systems.push_back(system);
}
