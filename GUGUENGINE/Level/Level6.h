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
		
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;
		
		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
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
	Object* Levelsel, * Levelsel_pressed;

	Object* playUI, * quitUI, * optionUI, * restartUI;
	Object* levelImage, * numberImage;
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
	bool poopooCheck = false;
	GLuint numberTexture;
	GLuint levelTexture;
	Vector2<float> cursor6;

	int coorcheck6 = 0;
	int connectMove6 = 0;

	float degree6 = DegreeToRadian(60.f);
	float degree6_2 = DegreeToRadian(-60.f);
	float degree6_3 = DegreeToRadian(120.f);
	float degree6_4 = DegreeToRadian(180.f);
	float degree6_5 = DegreeToRadian(-180.f);
	float degree6_6 = DegreeToRadian(-120.f);

	bool rotrot = true;

	int chekNext6 = 0;

	GLuint textureBackground6;

	GLuint texureIdLine6;
	GLuint texureIdCurve6;
	GLuint texureIdThree6;
	GLuint texureIdV6;
	GLuint texureIdBlack6;
	GLint LevelPage;
	GLint LevelPage_pressed;
	GLuint texureIdStart6;
	GLuint texureIdEnd6;

	GLuint texureIdLine6_1;
	GLuint texureIdCurve6_2;
	GLuint texureIdV6_2;


	GLuint texureIdbutton6;
	GLuint texureIdclear6;
	GLuint texureSpace6;

	GLint texturePlayUI6;
	GLint textureQuitUI6;
	GLint textureOptionUI6;
	GLint textureRestartUI6;

	bool conecTcheck6_1 = false;
	bool conecTcheck6_2 = false;
	bool conecTcheck6_3 = false;
	bool conecTcheck6_4 = false;
	bool conecTcheck6_5 = false;
};
