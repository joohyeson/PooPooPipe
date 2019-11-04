#pragma once
#include "../LevelSystem.h"
#include "../Object.h"

class Level2 : public LevelSystem
{
public:
	Level2() {};
	void Init() override;
	void Update() override;
	void Close() override;
	~Level2() {};
};