#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.12.2019
 *digipen.hagyeong@gmail.com
 *LevelManager.cpp
 *for manage level
 */

#include "../GUGUENGINE/Sound.h"

class LevelManager
{
public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
	virtual ~LevelManager()	{}

	Sound* sound;

};
