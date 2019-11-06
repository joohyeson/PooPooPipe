#include"StateManager.h"
#include "../Engine.h"

int main()
{
	//make new Engine
	Engine* ENGINE = new Engine();

	//Initialize Engine
	ENGINE->Init();

	//GameLoop
	ENGINE->GameLoop();

	//If the gameloop ends, delete Engine
	delete ENGINE;

	return 0;
}

