#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Sound.h"

class Sound;

class Level1 : public LevelManager
{
public:
	
	Level1()
	{
		puzzle1 = nullptr;
		key=0;
	}
	void Init() override;
	void Update() override;
	void Close() override;
	
private:
	Object* puzzle1, *puzzle2;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	Sound bgm;

};