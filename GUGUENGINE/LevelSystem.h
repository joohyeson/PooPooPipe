#pragma once

class LevelSystem
{
public:
	LevelSystem();
	virtual ~LevelSystem(){}
	
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
};