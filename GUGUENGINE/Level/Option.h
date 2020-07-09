#pragma once
/*
 *eunjin.hong
 *01.28.2020
 *eunjin.hong@gmail.com
 *Option.h
 *This is Option
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

class LevelOption : public LevelManager
{
public:
	LevelOption()
	{
		background = nullptr;
		option = nullptr;
		music = nullptr;
		arrowRight = nullptr;
		arrowLeft = nullptr;
		bar0 = nullptr;
		goToMain = nullptr;
		key = 0;
		fullScreen = nullptr;
		fullScreenFalse = nullptr;
		fullScreenTrue = nullptr;
		quitButton = nullptr;
		quitButton_pressed = nullptr;

		textureBackgroundOption = 0;
		textureOption = 0;
		textureMusic = 0;

		textureArrowLeft = 0;
		textureArrowRight = 0;

		textureBar0 = 0;

		textureGoToMain = 0;
		textureQuit = 0;
		textureQuitPressed = 0;
		textureFullScreen = 0;
		textureCheckTrue = 0;
		textureCheckFalse;

		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;
		soundBar = nullptr;
		textureSoundBar = 0;
		soundBarSize = { 400.f, 70.f };
		soundBarPosition = { 95.f, 240.f };
	}

	void Init() override;
	void Update() override;
	void Close() override;

	GameLevels GetCurrLevel() override
	{
		return GameLevels::OPTION;
	}
private:
	Object* background, * option, * music, * arrowRight, * arrowLeft, * bar0;
	Object* goToMain, * fullScreen, * fullScreenFalse, * fullScreenTrue;
	Object* quitButton, * quitButton_pressed;
	int key;
	Mesh mMesh;
	Shader mShader;

	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;
	Object* soundBar;

	GLuint textureIdQuitAskBack;
	GLuint textureIdQuitAsk;
	GLuint textureIdYes;
	GLuint textureIdNo;
	GLuint textureIdYes_p;
	GLuint textureIdNo_p;

	bool quitCheck = false;
	bool realQuit = false;

	GLuint textureBackgroundOption;
	GLuint textureOption;
	GLuint textureMusic;

	GLuint textureArrowLeft;
	GLuint textureArrowRight;

	GLuint textureBar0;

	GLuint textureGoToMain;
	GLuint textureQuit, textureQuitPressed;
	GLuint textureFullScreen, textureCheckTrue, textureCheckFalse, textureSoundBar;

	Vector2<float> cursor;

	Input mInput;

	Vector2<float> soundBarSize;
	Vector2<float> soundBarPosition;
};