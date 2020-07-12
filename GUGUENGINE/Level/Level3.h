#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *12.13.2019
 *digipen.hagyeong@gmail.com
 *Level3.h
 *this is level3 header
 */
#include "LevelSelect.h"
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/limitedRotate.h"
#include "../GUGUENGINE/MovePooPoo.h"
#include  "../GUGUENGINE/glfwInput.h"
#include <time.h>


 //class sound;

class Level3 : public LevelManager
{
public:
	Level3()
	{
		background = nullptr;
		movePuzzle = nullptr;
		movePuzzle2 = nullptr;
		movePuzzle3 = nullptr;

		startPuzzle = nullptr;
		endPuzzle = nullptr;
		puzzle1 = nullptr;
		puzzle2 = nullptr;
		puzzle3 = nullptr;
		puzzle4 = nullptr;
		puzzle5 = nullptr;
		puzzle6 = nullptr;
		puzzle7 = nullptr;

		puzzle8 = nullptr;
		puzzle9 = nullptr;
		puzzle10 = nullptr;
		puzzle11 = nullptr;
		puzzle12 = nullptr;

		blackPuzzle1 = nullptr;
		blackPuzzle2 = nullptr;
		blackPuzzle3 = nullptr;

		Levelsel = nullptr;
		Levelsel_pressed = nullptr;

		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;

		playUI_p = nullptr;
		quitUI_p = nullptr;
		optionUI_p = nullptr;
		restartUI_p = nullptr;

		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;

		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
		pooCharacter = nullptr;
		fail = nullptr;
		win = nullptr;

		key = 0;

	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST3;
	}
	//void Wait(long waitTime);

	Vector2<float> Pos1;
	Vector2<float> Pos2;
	Vector2<float> Pos3;

	float d1 = 0;
	float d2 = 0;
	float d3 = 0;

	float con1;
	float con2;
	float con3;

	bool di1[6] = { false, false, false, true, false, true };
	bool di2[6] = { true, false, false, true, false, false };
	bool di3[6] = { false, false, false, true, false, true };


private:

	double first;
	double last;
	bool failS = false;
	bool skip = false;

	bool Nos[2] = { false };
	bool Cur[3] = { false };
	
	Object* background;
	Object* movePuzzle, * movePuzzle2, * movePuzzle3, * startPuzzle, * endPuzzle;
	Object* levelImage, * numberImage;

	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12;

	Object* blackPuzzle1, * blackPuzzle2, * blackPuzzle3;

	Object* playUI, * quitUI, * optionUI, * restartUI;
	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;

	Object* pooCharacter;
	Object* button;
	Object* clear;
	Object* fail;
	Object* win;

	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;

	GLuint textureIdQuitAskBack;
	GLuint textureIdQuitAsk;
	GLuint textureIdYes;
	GLuint textureIdNo;
	GLuint textureIdYes_p;
	GLuint textureIdNo_p;

	bool quitCheck = false;
	bool realQuit = false;
	bool checking = false;
	bool SUI[5] = { false };
	
	MovePooPoo mPooPoo;
	Object* Levelsel, * Levelsel_pressed;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	LimitRotate rotTime;
	Input mInput;
	bool rot[3] = { false };
	bool movable[3] = { false };
	bool move[3] = { false };
	bool UI[5] = { false };
	bool poopooCheck = false;

	Vector2<float> cursor3;

	int coorcheck = 0;

	int movable1 = 0;
	int movable2 = 0;
	int movable3 = 0;
	int connectMove = 0;

	float degree2 = 0;
	float degree2_2 = 0;
	float degree2_3 = 0;

	double lastTime = 0;
	double firstTime = 0;
	int chekNext = 0;

	GLuint textureBackground3;

	GLuint texureIdLine3;
	GLuint texureIdCurve3;
	GLuint texureIdBlack3;

	GLuint texureIdStart3;
	GLuint texureIdEnd3;

	GLuint texureIdLine3_1;
	GLuint texureIdCurve3_2;

	GLuint texureIdbutton3;
	GLuint texureIdclear3;

	GLint LevelPage;
	GLint LevelPage_pressed;

	GLint texturePlayUI3;
	GLint textureQuitUI3;
	GLint textureOptionUI3;
	GLint textureRestartUI3;

	GLint texturePlayUI3p;
	GLint textureQuitUI3p;
	GLint textureOptionUI3p;
	GLint textureRestartUI3p;

	GLuint numberTexture;
	GLuint levelTexture;
	GLint textureFail;
	GLint textureWin;

	bool blCheck1 = false;
	bool blCheck1_2 = false;

	bool blCheck2 = false;
	bool blCheck2_2 = false;

	bool conecTcheck1 = false;
	bool conecTcheck2 = false;
	bool conecTcheck3 = false;

	LevelSelect current;
};


