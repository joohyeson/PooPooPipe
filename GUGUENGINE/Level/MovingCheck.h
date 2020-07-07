#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *12.13.2019
 *digipen.hagyeong@gmail.com
 *this is level4 header
 *Level4.h
 */
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "..//GUGUENGINE/MovePooPoo.h"
#include "..//GUGUENGINE/GenerateMap.h"
class sound;

class MovingCheck : public LevelManager
{
public:
	MovingCheck()
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

		blackPuzzle1 = nullptr;
		blackPuzzle2 = nullptr;
		//blackPuzzle3 = nullptr;
		spacePress = nullptr;

		textureBackground4 = 0;
		texureIdLine4 = 0;
		texureIdCurve4 = 0;
		texureIdBlack4 = 0;

		texureIdStart4 = 0;
		texureIdEnd4 = 0;

		texureIdLine4_1 = 0;
		texureIdCurve4_2 = 0;

		texureIdbutton4 = 0;
		texureIdclear4 = 0;
		texureSpace4 = 0;

		button = nullptr;
		clear = nullptr;
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
private:
	Object* background;
	Object* movePuzzle, * movePuzzle2, * movePuzzle3, * startPuzzle, * endPuzzle, * spacePress;

	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5;
	Object* puzzle6, * puzzle7, * puzzle8, * puzzle9, * puzzle10;

	Object* blackPuzzle1, * blackPuzzle2;/** blackPuzzle3*/

	Object* button;
	Object* clear;
	//MovePooPoo myPooPoo;
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

	GLuint textureBackground4;

	GLuint texureIdLine4;
	GLuint texureIdCurve4;
	GLuint texureIdBlack4;

	GLuint texureIdStart4;
	GLuint texureIdEnd4;

	GLuint texureIdLine4_1;
	GLuint texureIdCurve4_2;

	GLuint texureIdbutton4;
	GLuint texureIdclear4;
	GLuint texureSpace4;

	MovePooPoo mPooPoo;
	GenerateMap myMap;

};