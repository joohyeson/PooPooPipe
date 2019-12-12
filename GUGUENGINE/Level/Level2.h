#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"

class sound;

class Level2 : public LevelManager
{
public:
	Level2()
	{
		movePuzzle = nullptr;
		blackPuzzle = nullptr;
		puzzleUp = nullptr;
		puzzleDown = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* movePuzzle, * blackPuzzle, * puzzleUp, * puzzleDown;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };

};