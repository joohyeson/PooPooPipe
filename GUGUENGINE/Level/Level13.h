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

class Level13 : public LevelManager
{
public:
	Level13()
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
		numberImage2 = nullptr;
		pooCharacter = nullptr;

		fail = nullptr;
		mini = nullptr;

		playUI_p = nullptr;
		quitUI_p = nullptr;
		optionUI_p = nullptr;
		restartUI_p = nullptr;
		win = nullptr;

		key = 0;
		QuitAskBack = nullptr;
		QuitAsk = nullptr;
		Yes = nullptr;
		No = nullptr;

		Yes_p = nullptr;
		No_p = nullptr;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_TEST13;
	}
private:
	Object* background;
	Object* startPuzzle, * endPuzzle;
	Object* pooCharacter;
	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12, * puzzle13, * puzzle14, * puzzle15, * puzzle16, * puzzle17;
	Object* Levelsel, * Levelsel_pressed;
	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;
	GLint texturePlayUI3p;
	GLint textureQuitUI3p;
	GLint textureOptionUI3p;
	GLint textureRestartUI3p;
	bool Nos[2] = { false };
	Object* QuitAskBack;
	Object* QuitAsk;
	Object* Yes;
	Object* No;
	Object* Yes_p;
	Object* No_p;

	GLuint textureIdQuitAskBack;
	GLuint textureIdQuitAsk;
	GLuint textureIdYes;
	GLuint textureIdNo;
	GLuint textureIdYes_p;
	GLuint textureIdNo_p;

	bool quitCheck = false;
	bool realQuit = false;

	Object* puzzle18, * puzzle19, * puzzle20;

	Object* playUI, * quitUI, * optionUI, * restartUI, * fail;

	Object* win;
	GLint textureWin;
	Object* mini;
	GLuint texturemini;

	double lastTime = 0;
	double firstTime = 0;
	bool skip = false;
	double first;
	double last;
	bool failS[2] = { false };
	bool UI[5] = { false };

	Object* button;
	Object* clear;

	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	Object* levelImage, * numberImage, * numberImage2;
	MovePooPoo mPooPoo;
	MovePooPoo mPooPoo2;
	Vector3<float> buttonClick_1 = { 0, 0, 0 };

	Vector2<float> cursor8;
	Input mInput;

	bool rot[11] = { false };
	bool poopooCheck = false;

	int coorcheck8 = 0;

	int connectMove8 = 0;

	float degree8 = 0;
	float degree8_2 = 0;
	float degree8_3 = 0;
	float degree8_4 = 0;
	float degree8_5 = 0;
	float degree8_6 = 0;
	float degree8_7 = 0;
	float degree8_8 = static_cast<float>(DegreeToRadian(-120.f));

	int chekNext8 = 0;

	int move8_1 = 0;
	int move8_2 = 0;
	int move8_3 = 0;

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
	GLint LevelPage;
	GLint LevelPage_pressed;
	GLuint texureIdbutton8;
	GLuint texureIdclear8;

	GLint texturePlayUI8;
	GLint textureQuitUI8;
	GLint textureOptionUI8;
	GLint textureRestartUI8;

	GLuint textureIdVAuto;
	GLuint textureIdCurveAuto;
	GLuint textureIdLineAuto;

	GLuint numberTexture;
	GLuint numberTexture2;
	GLuint levelTexture;
	GLint textureFail;

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
