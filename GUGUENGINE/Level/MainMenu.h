#pragma once
/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *MainMenu.h
 *this is mainmenu
 */
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/Sound.h"
#include "..//GUGUENGINE/MovePooPoo.h"
class Sound;

class MainMenu : public LevelManager
{
public:
	MainMenu()
	{
		background = nullptr;
		startButton = nullptr;
		tutorialButton = nullptr;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	
private:
	Object* background;
	Object* startButton;
	Object* tutorialButton;
	Object* optionButton;
	Object* test;
	Object* test2;

	MovePooPoo getDirectionPooPoo;

	Mesh mMesh;
	Shader mShader;
	Shader testNDCShader;//it will be deleted when NDC function is completed

	
	int key;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };
	Vector3<float> getOrigin3 = { 0, 0, 0 };

};
