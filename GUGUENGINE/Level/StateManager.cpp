#include "StateManager.h"
#include "Level1.h"
#include "Level2.h"


StateManager* STATE_MANAGER = nullptr;

StateManager::StateManager()
{
	STATE_MANAGER = this;
}

StateManager::~StateManager()
{
}

void StateManager::Init()
{
	current = LV_TEST1;
	levels.push_back(new Level1());
	levels.push_back(new Level2());
	levels.at(current)->Init();
}

void StateManager::Update()
{
	levels.at(current)->Update();
}

void StateManager::ChangeLevel(GameLevels changeLV)
{
	current = changeLV;
	levels.at(current)->Init();
}