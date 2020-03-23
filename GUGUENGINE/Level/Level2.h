#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Level2.h
 *this is level2 header
 */
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/glfwInput.h"

class sound;

class Level2 : public LevelManager
{
public:
	Level2()
	{
		background = 0;
		movePuzzle = nullptr;
		blackPuzzle = nullptr;
		puzzleUp = nullptr;
		puzzleDown = nullptr;
		spacePress = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background;
	Object* movePuzzle, * blackPuzzle, * puzzleUp, * puzzleDown, *spacePress;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };
	Input input;
};