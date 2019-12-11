#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"

class Sound;

class Level1 : public LevelManager
{
public:

	Level1()
	{
		puzzle1 = nullptr;
		puzzle2 = nullptr;
		puzzle3 = nullptr;
		puzzle4 = nullptr;
		key=0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	
private:
	Object* puzzle1, *puzzle2, *puzzle3, *puzzle4;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Sound bgm;


	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };

};