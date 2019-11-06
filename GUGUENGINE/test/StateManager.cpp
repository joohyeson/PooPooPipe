#include "StateManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Level2.h"
#include "Level1.h"

StateManager* STATEMANAGER = nullptr;

StateManager::StateManager()
{
	STATEMANAGER = this;
}
StateManager::~StateManager(){}
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

void StateManager::ChangeLevel(GameLevel changeLV)
{
	current = changeLV;
	levels.at(current)->Init();
}
