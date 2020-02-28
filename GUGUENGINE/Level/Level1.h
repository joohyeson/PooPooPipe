#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Level1.h
 *this is level1 header
 */
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE/Sound.h"

class Sound;

class Level1 : public LevelManager
{
public:
	Level1()
	{
		background = nullptr;
		movePuzzle = nullptr;
		blackPuzzle = nullptr;
		puzzleLeft = nullptr;
		puzzleRight = nullptr;
		spacePress = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background;
	Object* movePuzzle, * blackPuzzle, * puzzleLeft, * puzzleRight;
	Object* spacePress;

	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };

};