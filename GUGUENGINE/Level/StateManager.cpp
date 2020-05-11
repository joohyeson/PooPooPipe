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
#include "Level9.h"
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
	current = MAINMENU;
	
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
	levels.push_back(new Level9());
	levels.push_back(new LevelSelect());

	levels.push_back(new MovingCheck());

	levels.at(current)->Init();
}

void StateManager::Update()
{
	switch (state) {
	case State::START:
		nextGameState = levels[0];
		state = State::LOAD;
		break;
	case State::LOAD:
		currGameState = nextGameState;
		currGameState->Init();
		state = State::RUNNING;
		break;
	case State::RUNNING:
		if (currGameState != nextGameState) {
			state = State::UNLOAD;
		}
		else {
			currGameState->Update();
		}
		break;
	case State::UNLOAD:
		currGameState->Close();
		if (nextGameState == nullptr) {
			state = State::SHUTDOWN;
			break;
		}
		state = State::LOAD;
		break;
	case State::SHUTDOWN:
		state = State::EXIT;
		break;
	case State::EXIT:
		break;
	}
}

void StateManager::Shutdown()
{
	state = State::UNLOAD;
	nextGameState = nullptr;
}

void StateManager::ReloadState()
{
	state = State::UNLOAD;
}

void StateManager::ChangeLevel(GameLevels changeLV)
{
	nextGameState = levels[changeLV];
}