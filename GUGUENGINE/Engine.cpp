#include<SDL.h>
#include <glew.h>
#include <vector>
#include "Engine.h"
#include <glm/glm.hpp>
#include"Application.h"
#include <iostream>
#include "test/StateManager.h"
#include "ObjectFactory.h"

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
	std::cout << "Initialize Engine" << std::endl;
	//Order is important
	AddSystem(new Application());
	AddSystem(new ObjectFactory());
	//AddSystem(new Graphics());
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

}

void Engine::Quit()
{
	GAMERUN = false;
}

void Engine::AddSystem(System* system)
{
	Systems.push_back(system);
}
