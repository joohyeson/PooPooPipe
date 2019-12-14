#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Engine.h
 *Engine to run game
 */
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