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

class Sound;

class LevelOption : public LevelManager
{
public:
	LevelOption()
	{
		background = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background, *option, *music, *arrowRight, *arrowLeft;
	int key;
	Mesh mMesh;
	Shader mShader;

};