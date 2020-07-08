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
#include "../GUGUENGINE/glfwInput.h"
class Sound;

class MainMenu : public LevelManager
{
public:
	MainMenu()
	{
		background = nullptr;
		startButton = nullptr;
		tutorialButton = nullptr;
		startButton_pressed = nullptr;
		tutorialButton_pressed = nullptr;
		optionButton = nullptr;
		optionButton_pressed = nullptr;
		test = nullptr;
		test2 = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	
private:
	Object* background;
	Object* startButton;
	Object* tutorialButton;
	Object* optionButton;
	Object* startButton_pressed;
	Object* tutorialButton_pressed;
	Object* optionButton_pressed;
	Object* test;
	Object* test2;

	bool UI[3] = { false };
	
	GLuint textureId00;	//game title
	GLuint textureId01; //game start
	GLuint textureId02; //title
	GLuint textureId03; //tutorial
	GLuint textureId05;//test
	GLuint textureId04;	//option button
	GLuint textureId06;//man
	GLuint startPress;
	GLuint tutorialPress;
	GLuint optionPress;

	int key;
	//MovePooPoo getDirectionPooPoo;

	Mesh mMesh;
	Shader mShader;
	Shader testNDCShader;//it will be deleted when NDC function is completed

	Input menuInput;
	Vector2<float> cursor0;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };
	Vector3<float> getOrigin3 = { 0, 0, 0 };

};
