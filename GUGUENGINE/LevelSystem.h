#pragma once

class LevelSystem
{
public:
	LevelSystem();
	virtual ~LevelSystem(){}
	
	virtual void Init();
	virtual void Update();
	virtual void Close();
};