#pragma once
/*
 *eunjin.hong
 *01.28.2020
 *eunjin.hong@gmail.com
 *Credits.h
 *This is Credits
 */
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/glfwInput.h"

class Sound;

class LevelCredits : public LevelManager
{
public:
	LevelCredits()
	{
		background = nullptr;
		goToMain = nullptr;
		textureBackgroundCredits = 0;
	}

	GameLevels GetCurrLevel() override
	{
		return GameLevels::CREDITS;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background, * goToMain;

	GLuint textureBackgroundCredits;
	GLuint textureGoToMain;
	Shader mShader;

	Input mInput;
	Vector2<float> cursor;
};