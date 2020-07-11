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
#include "../GUGUENGINE/glfwInput.h"

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
		mouse = nullptr;
		key = 0;
		levelCheck = 0;
		spaceCheck = 0;
		win = nullptr;
		texureIdLine1 = 0;
		texureIdCurve1 = 0;
		texureIdBlack1 = 0;
		textureBackground1 = 0;
		textureSpace1 = 0;
		textureMouse = 0;
		textureWin = 0;
	}
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST1;
	}
	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background;
	Object* movePuzzle, * blackPuzzle, * puzzleLeft, * puzzleRight, *mouse;

	Object* spacePress;
	Input mInput;
	bool movable = false;
	Vector2<float> cursor;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };

	GLuint texureIdLine1;
	GLuint texureIdCurve1;
	GLuint texureIdBlack1;
	GLuint textureBackground1;
	GLuint textureSpace1;
	GLuint textureMouse;
	Object* win;
	GLuint textureWin;

	bool levelCheck;
	bool spaceCheck;
	double lastTime = 0;
	double firstTime = 0;

};