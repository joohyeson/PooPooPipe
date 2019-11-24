#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"

class Level2 : public LevelManager
{
public:
	Level2(){}
	void Init() override;
	void Update() override;
	void Close() override;
};