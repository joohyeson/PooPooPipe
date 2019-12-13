#include "StateManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "MainMenu.h"

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
	current = MAINMENU;
	levels.push_back(new MainMenu());
	levels.push_back(new Level1());
	levels.push_back(new Level2());
	levels.push_back(new Level3());

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