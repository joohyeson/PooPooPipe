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
class sound;

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
		spacePress = nullptr;
		
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;
		
		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;

		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background;
	Object* movePuzzle, * movePuzzle2, * movePuzzle3, * startPuzzle, * endPuzzle, *spacePress;
	Object* levelImage, * numberImage;

	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12;

	Object* blackPuzzle1, * blackPuzzle2, * blackPuzzle3;

	Object* playUI, *quitUI, *optionUI, *restartUI;

	Object* button;
	Object* clear;
	MovePooPoo mPooPoo;
	Object* Levelsel, *Levelsel_pressed;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Vector3<float> getOrigin1_1 = { 0, 0, 0 };
	Vector3<float> getOrigin1_2 = { 0, 0, 0 };

	Vector3<float> getOrigin2_1 = { 0, 0, 0 };
	Vector3<float> getOrigin2_2 = { 0, 0, 0 };

	Vector3<float> getOrigin3_1 = { 0, 0, 0 };
	Vector3<float> getOrigin3_2 = { 0, 0, 0 };

	Vector3<float> buttonClick_1 = { 0, 0, 0 };

	LimitRotate rotTime;
	Input mInput;
	bool rot[3] = { false };
	bool movable[3] = { false };
	bool move[3] = { false };

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
	GLuint texureSpace3;
	GLint LevelPage;
	GLint LevelPage_pressed;

	GLint texturePlayUI3;
	GLint textureQuitUI3;
	GLint textureOptionUI3;
	GLint textureRestartUI3;
	GLuint numberTexture;
	GLuint levelTexture;
	
	bool blCheck1 = false;
	bool blCheck1_2 = false;

	bool blCheck2 = false;
	bool blCheck2_2 = false;

	bool conecTcheck1 = false;
	bool conecTcheck2 = false;
	bool conecTcheck3 = false;

	LevelSelect current;
};