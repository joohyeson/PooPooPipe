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
#include "Engine.h"
#include"Application.h"
#include <iostream>
#include "ObjectManager.h"
#include "../Level/StateManager.h"
#include "glfwInput.h"

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
	for (auto GUGU : Systems)
	{
		GUGU->Init();
	}
}

void Engine::GameLoop()
{
	while (GAMERUN)
	{
		for (auto GUGU : Systems)
		{
			GUGU->Update();
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
