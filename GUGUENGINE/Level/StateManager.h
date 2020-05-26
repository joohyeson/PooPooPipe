#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *11.14.2019
 *digipen.hagyeong@gmail.com
 *StateManager.h
 *this is header for statemanage.cpp
 */
#include<vector>
#include "../GUGUENGINE/System.h"
#include "../GUGUENGINE/LevelManager.h"

//define enum for level
enum GameLevels
{
	DIGIPENLOGO,
	FMODLOGO,
	MAINMENU,
	OPTION,
	LV_TEST1,
	LV_TEST2,
	LV_TEST3,
	LV_TEST4,
	LV_TEST5,
	LV_TEST6,
	LV_TEST7,
	LV_TEST8,
	LV_TEST9,
	LV_TEST10,
	LV_SELECT,
	MOVINGCHECK
};

class StateManager : public System
{
public:
	StateManager();
	~StateManager();
	void Init() override;
	void Update() override;
	void Shutdown();
	void ReloadState();
	//change level
	void ChangeLevel(GameLevels changeLV);
	void setCurrentLV(int i);
	int GetCurrentLV();
private:
	enum class State {
		START,
		LOAD,
		RUNNING,
		UNLOAD,
		SHUTDOWN,
		EXIT,
	};
	//Store the current level.
	GameLevels current;
	//Store the levels.
	std::vector<LevelManager*> levels;
	State state;
	LevelManager* currGameState;
	LevelManager* nextGameState;
	int currentLV;
};
extern StateManager* STATE_MANAGER;
