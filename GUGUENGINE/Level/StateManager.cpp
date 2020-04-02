/*
 *hakyung.kim
 *uijin.lee
 *11.14.2019
 *digipen.hagyeong@gmail.com
 *StateManager.cpp
 *to manage stage
 *we can change level
 */
#include "StateManager.h"
#include "DigipenLogo.h"
#include "Option.h"
#include "FmodLogo.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "MainMenu.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"
#include "Level7.h"
#include "Level8.h"
#include "LevelSelect.h"
#include "MovingCheck.h"


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
	current = MOVINGCHECK;
	
	levels.push_back(new DigipenLogo());
	levels.push_back(new FmodLogo());
	levels.push_back(new MainMenu());
	levels.push_back(new LevelOption());
	levels.push_back(new Level1());
	levels.push_back(new Level2());
	levels.push_back(new Level3());
	levels.push_back(new Level4());
	levels.push_back(new Level5());
	levels.push_back(new Level6());
	levels.push_back(new Level7());
	levels.push_back(new Level8());
	levels.push_back(new LevelSelect());

	levels.push_back(new MovingCheck());


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