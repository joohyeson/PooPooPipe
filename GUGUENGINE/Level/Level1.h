#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/Sound.h"

class Sound;

class Level1 : public LevelManager
{
public:
	Level1()
	{
		movePuzzle = nullptr;
		blackPuzzle = nullptr;
		puzzleLeft = nullptr;
		puzzleRight = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* movePuzzle, * blackPuzzle, * puzzleLeft, * puzzleRight;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Sound bgm;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };

};