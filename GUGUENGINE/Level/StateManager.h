#pragma once
#include<vector>
#include "../GUGUENGINE/System.h"
#include "../GUGUENGINE/LevelManager.h"

//define enum for level
enum GameLevels
{	
	MAINMENU, 
	LV_TEST1,
	LV_TEST2,
	LV_TEST3,
	LV_TEST4
};

class StateManager : public System
{
public:
	StateManager();
	~StateManager();
	void Init() override;
	void Update() override;

	//change level
	void ChangeLevel(GameLevels changeLV);

	//Store the current level.
	GameLevels current;
	//Store the levels.
	std::vector<LevelManager*> levels;
};
extern StateManager* STATE_MANAGER;
