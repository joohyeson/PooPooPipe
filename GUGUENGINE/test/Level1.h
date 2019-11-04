#pragma once

#include "../LevelSystem.h"
#include "../Object.h"

class Level1 : public LevelSystem
{
public:
	Level1() {};
	void Init() override;
	void Update() override;
	void Close() override;
	~Level1() {};
};
