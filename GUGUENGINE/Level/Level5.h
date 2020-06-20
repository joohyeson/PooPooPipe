#pragma once
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/FitPuzzleComponent.h"
#include "../GUGUENGINE/HexCoordinates.h"
#include "../GUGUENGINE//CollisionCheck.h"
#include "../GUGUENGINE/glfwInput.h"
#include "../GUGUENGINE/MovePooPoo.h"

class sound;

class Level5 : public LevelManager
{
public:
	Level5()
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
		puzzle11 = nullptr;
		puzzle12 = nullptr;

		blackPuzzle1 = nullptr;
		blackPuzzle2 = nullptr;
		blackPuzzle3 = nullptr;
		spacePress = nullptr;
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;
		
		playUI = nullptr;
		quitUI = nullptr;
		optionUI = nullptr;
		restartUI = nullptr;

		playUI_p = nullptr;
		quitUI_p = nullptr;
		optionUI_p = nullptr;
		restartUI_p = nullptr;
		win = nullptr;

		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
		pooCharacter = nullptr;
		fail = nullptr;
		mini = nullptr;
		
		key = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* background;
	Object* movePuzzle, * movePuzzle2, * movePuzzle3, * startPuzzle, * endPuzzle, * spacePress;
	Object* levelImage, * numberImage;

	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12;

	Object* blackPuzzle1, * blackPuzzle2, * blackPuzzle3;
	Object* pooCharacter;
	Object* playUI, * quitUI, * optionUI, * restartUI, *fail;
	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;
	Object* win;
	GLint textureWin;

	Object* Levelsel, * Levelsel_pressed;
	Object* mini;
	GLuint texturemini;

	Object* button;
	Object* clear;

	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	MovePooPoo mPooPoo;
	Input mInput;
	bool rot[3] = { false };
	bool movable[3] = { false };
	bool move[3] = { false };
	bool poopooCheck = false;
	
	bool skip = false;
	float transition = 0.0f;
	
	Vector2<float> cursor5;

	int coorcheck5 = 0;
	int connectMove5 = 0;

	float degree5 = 0;
	float degree5_2 = 0;
	float degree5_3 = 0;

	int chekNext5 = 0;

	bool movePuzzleCheck5 = true;

	GLuint textureBackground5;

	GLuint texureIdLine5;
	GLuint texureIdCurve5;
	GLuint texureIdThree5;

	GLuint textureIdMove5;

	GLuint texureIdV5;
	GLuint texureIdBlack5;

	GLuint texureIdStart5;
	GLuint texureIdEnd5;

	GLuint texureIdLine5_1;
	GLuint texureIdCurve5_2;

	GLuint texureIdbutton5;
	GLuint texureIdclear5;
	GLuint texureSpace5;

	GLint texturePlayUI5;
	GLint textureQuitUI5;
	GLint textureOptionUI5;
	GLint textureRestartUI5;

	GLint texturePlayUI3p;
	GLint textureQuitUI3p;
	GLint textureOptionUI3p;
	GLint textureRestartUI3p;
	
	GLuint numberTexture;
	GLuint levelTexture;
	GLint LevelPage;
	GLint LevelPage_pressed;
	GLint textureFail;

	bool blCheck5 = false;
	bool blCheck5_2 = false;
	bool blCheck5_3 = false;

	bool blCheck6 = false;
	bool blCheck6_2 = false;
	bool blCheck6_3 = false;

	bool blCheck7 = false;
	bool blCheck7_2 = false;
	bool blCheck7_3 = false;

	bool conecTcheck5_1 = false;
	bool conecTcheck5_2 = false;
	bool conecTcheck5_3 = false;
	bool UI[5] = { false };

};