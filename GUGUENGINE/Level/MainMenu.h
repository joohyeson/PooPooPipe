#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/Sound.h"

class Sound;

class MainMenu : public LevelManager
{
public:
	MainMenu()
	{
		gameLogo = nullptr;
		startButton = nullptr;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	
private:
	Object* gameLogo;
	Object* startButton;
	Mesh mMesh;
	Shader mShader;

	
	int key;

	Vector3<float> getOrigin = { 0, 0, 0 };
};