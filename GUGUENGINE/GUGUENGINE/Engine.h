#pragma once
#include<vector>

class System;
class Engine
{
public:
	Engine();
	~Engine();

	void Init();

	void GameLoop();

	void Quit();

	void AddSystem(System* system);

private:
	std::vector<System*> Systems; 
	bool GAMERUN;  
};
extern Engine* ENGINE;