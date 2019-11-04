#pragma once

#include "../LevelSystem.h"
#include "../System.h"

enum GameLevel
{
	LV_TEST1,
	LV_TEST2
};

//This class manage the state. 
class StateManager : public System
{
public:
	StateManager();
	~StateManager();
	void Init() override;
	void Update() override;

	void ChangeLevel(GameLevel changeLV);

	GameLevel current;

};
extern StateManager* STATEMANAGER;