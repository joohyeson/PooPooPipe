#pragma once

class System
{
public:
	System();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual ~System(){}
};