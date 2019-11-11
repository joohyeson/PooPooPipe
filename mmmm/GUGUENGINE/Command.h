#pragma once
#include "CommandType.h"

class Command
{
public:
	Command(ComponentType type);
	virtual ~Command() {};
	virtual void Execute() = 0;
private:
	ComponentType mType;
};

