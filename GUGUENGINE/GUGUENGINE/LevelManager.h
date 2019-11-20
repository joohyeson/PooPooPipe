#pragma once
class LevelManager
{
public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
	virtual ~LevelManager()	{}
};
