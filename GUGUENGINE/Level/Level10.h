#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE//CollisionCheck.h"
#include "../GUGUENGINE/limitedRotate.h"
#include  "../GUGUENGINE/glfwInput.h"
#include "../GUGUENGINE/MovePooPoo.h"

class sound;

class Level10 : public LevelManager
{
public:
	Level10()
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

		puzzle17 = nullptr;
		puzzle19 = nullptr;
		puzzle20 = nullptr;
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;
		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;

		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;

		leftCount = nullptr;
		leftnumberTen = nullptr;
		leftnumber = nullptr;
		fail = nullptr;
		pooCharacter = nullptr;
		win = nullptr;
		mini = nullptr;

		playUI_p = nullptr;
		quitUI_p = nullptr;
		optionUI_p = nullptr;
		restartUI_p = nullptr;

		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST10;
	}
private:
	Object* background;
	Object* startPuzzle, * endPuzzle;
	double first;
	double last;
	bool failS[2] = { false };
	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12, * puzzle13, * puzzle14, * puzzle15, * puzzle16, * puzzle17;
	Object* pooCharacter;
	Object* puzzle18, * puzzle19, * puzzle20;
	Object* Levelsel, * Levelsel_pressed;
	Object* mini;
	GLuint texturemini;
	Object* playUI, * quitUI, * optionUI, * restartUI, * fail;

	Object* button;
	Object* clear;
	Object* win;
	GLint textureWin;
	
	bool skip = false;
	double lastTime = 0;
	double firstTime = 0;
	
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;

	Object* levelImage, * numberImage, * leftCount, * leftnumberTen, * leftnumber;
	MovePooPoo mPooPoo;

	Vector3<float> buttonClick_1 = { 0, 0, 0 };
	LimitRotate rotTime;

	Vector2<float> cursor8;
	Input mInput;

	bool rot[10] = { false };
	bool UI[5] = { false };

	bool poopooCheck = false;

	bool rotrot2 = true;
	int coorcheck8 = 0;

	int connectMove8 = 0;

	float degree8 = 0;
	float degree8_2 = DegreeToRadian(60.f);
	float degree8_3 = DegreeToRadian(180.f);
	float degree8_4 = 0;
	float degree8_5 = 0;
	float degree8_6 = 0;
	float degree8_7 = DegreeToRadian(-240.f);
	float degree8_8 = 0;
	float degree8_9 = DegreeToRadian(180.f);

	int chekNext8 = 0;

	int move8_1 = 0;
	int move8_2 = 0;
	int move8_3 = 0;

	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;
	GLint texturePlayUI3p;
	GLint textureQuitUI3p;
	GLint textureOptionUI3p;
	GLint textureRestartUI3p;


	GLuint textureBackground8;

	GLuint texureIdLine8;
	GLuint texureIdCurve8;
	GLuint texureIdThree8;
	GLuint texureIdV8;
	GLuint texureIdBlack8;

	GLuint texureIdStart8;
	GLuint texureIdEnd8;

	GLuint texureIdLine8_2;
	GLuint texureIdCurve8_2;
	GLuint texureIdV8_2;

	GLuint textureIdAuto1;
	GLuint textureIdAuto2;

	GLuint texureIdbutton8;
	GLuint texureIdclear8;
	GLint LevelPage;
	GLint LevelPage_pressed;

	GLint texturePlayUI8;
	GLint textureQuitUI8;
	GLint textureOptionUI8;
	GLint textureRestartUI8;
	GLint textureFail;

	GLint textureLeft;
	GLint textureLeftNumberTen0;
	GLint textureLeftNumberTen1;
	GLint textureLeftNumberTen2;
	GLint textureLeftNumberTen3;
	GLint textureLeftNumberTen4;
	GLint textureLeftNumberTen5;

	GLint textureLeftNumber0;
	GLint textureLeftNumber1;
	GLint textureLeftNumber2;
	GLint textureLeftNumber3;
	GLint textureLeftNumber4;
	GLint textureLeftNumber5;
	GLint textureLeftNumber6;
	GLint textureLeftNumber7;
	GLint textureLeftNumber8;
	GLint textureLeftNumber9;

	GLuint numberTexture;
	GLuint levelTexture;

	bool conecTcheck8_1 = false;
	bool conecTcheck8_2 = false;
	bool conecTcheck8_3 = false;
	bool conecTcheck8_4 = false;
	bool conecTcheck8_5 = false;
	bool conecTcheck8_6 = false;
	bool conecTcheck8_7 = false;
	bool conecTcheck8_8 = false;
	bool conecTcheck8_9 = false;

};
