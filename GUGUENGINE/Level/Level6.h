#pragma once
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE//CollisionCheck.h"
#include "../GUGUENGINE/glfwInput.h"
#include "../GUGUENGINE/limitedRotate.h"
#include "../GUGUENGINE/MovePooPoo.h"

class sound;

class Level6 : public LevelManager
{
public:
	Level6()
	{
		background = nullptr;

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

		puzzle13 = nullptr;
		puzzle14 = nullptr;
		puzzle15 = nullptr;
		puzzle16 = nullptr;
		puzzle17 = nullptr;

		blackPuzzle1 = nullptr;
		blackPuzzle2 = nullptr;
		blackPuzzle3 = nullptr;
		spacePress = nullptr;

		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;

		button = nullptr;
		clear = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background;
	Object* startPuzzle, * endPuzzle, * spacePress;

	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12, * puzzle13, * puzzle14, * puzzle15, * puzzle16, * puzzle17;

	Object* blackPuzzle1, * blackPuzzle2, * blackPuzzle3;

	Object* playUI, * quitUI, * optionUI, * restartUI;

	Object* button;
	Object* clear;
	MovePooPoo mPooPoo;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Vector3<float> getOrigin1 = { 0, 0, 0 };

	Vector3<float> getOrigin2 = { 0, 0, 0 };

	Vector3<float> getOrigin3 = { 0, 0, 0 };

	Vector3<float> getOrigin4 = { 0, 0, 0 };

	Vector3<float> getOrigin5 = { 0, 0, 0 };

	Vector3<float> getOrigin6 = { 0, 0, 0 };


	Vector3<float> buttonClick_1 = { 0, 0, 0 };

	LimitRotate rotTime;
	Input mInput;
	bool rot[6] = { false };
	bool movable[3] = { false };
	bool move[3] = { false };
};
