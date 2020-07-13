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
		goToMain_pressed = nullptr;
		key = 0;
		fullScreen = nullptr;
		fullScreenFalse = nullptr;
		fullScreenTrue = nullptr;
		quitButton = nullptr;
		quitButton_pressed = nullptr;

		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;
		soundBar = nullptr;
		goToMainP = nullptr;
		mInput = nullptr
	}

	void Init() override;
	void Update() override;
	void Close() override;
	void getInput(Input* m, Sound* ms);
	
	GameLevels GetCurrLevel() override
	{
		return GameLevels::OPTION;
	}

private:
	Object* background, * option, * music, * arrowRight, * arrowLeft, * bar0;
<<<<<<< HEAD
	Object* goToMain, *goToMain_pressed, * fullScreen, * fullScreenFalse, * fullScreenTrue;
	Object* quitButton, * quitButton_pressed, * backtomain, * backtomain_pressed;
	
=======
	Object* goToMain, * fullScreen, * fullScreenFalse, * fullScreenTrue, *goToMainP;
	Object* quitButton, * quitButton_pressed;
>>>>>>> 572c59e3e49f12653c5d1f1bb36aa5227497f8f1
	
	int key;
	
	Mesh mMesh;
	Shader mShader;
	
	bool fullcheck = false;
	bool quitC = false;
	
	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;
	Object* soundBar;

	bool quitCheck = false;
	bool realQuit = false;

	Vector2<float> cursor;
	GameLevels goback;
	
	Input* mInput;
	//Sound* soundm;
	int prevLev = 0;
};