#pragma once
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

class Level9 : public LevelManager
{
public:
	Level9()
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
		spacePress = nullptr;
		Levelsel = nullptr;
		Levelsel_pressed = nullptr;
		button = nullptr;
		clear = nullptr;
		levelImage = nullptr;
		numberImage = nullptr;
		pooCharacter = nullptr;
		fail = nullptr;
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

private:
	Object* background;
	Object* startPuzzle, * endPuzzle, * spacePress;
	bool UI[5] = { false };

	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7;
	Object* puzzle8, * puzzle9, * puzzle10, * puzzle11, * puzzle12, * puzzle13, * puzzle14, * puzzle15, * puzzle16, * puzzle17;
	Object* levelImage, * numberImage;
	Object* puzzle18, * puzzle19, * puzzle20;
	Object* Levelsel, * Levelsel_pressed;
	Object* win;
	Object* mini;
	GLuint texturemini;
	Object* playUI_p, * quitUI_p, * optionUI_p, * restartUI_p;
	GLint texturePlayUI3p;
	GLint textureQuitUI3p;
	GLint textureOptionUI3p;
	GLint textureRestartUI3p;

	GLint textureWin;


	Object* button;
	Object* clear;
	Object* playUI, * quitUI, * optionUI, * restartUI, * fail;
	GLuint numberTexture;
	GLuint levelTexture;
	
	MovePooPoo mPooPoo;
	Object* pooCharacter;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	Input mInput;

	bool rot[7] = { false };
	bool poopooCheck = false;

	Vector2<float> cursor9;
	bool skip = false;
	float transition = 0.0f;
	
	int coorcheck9 = 0;

	int connectMove9 = 0;

	bool autoRot = true;

	float degree9 = 0;
	float degree9_2 = DegreeToRadian(60.f);
	float degree9_3 = DegreeToRadian(-60.f);
	float degree9_4 = DegreeToRadian(60.f);
	float degree9_5 = 0;
	float degree9_6 = DegreeToRadian(-180.f);
	float degree9_7 = DegreeToRadian(120.f);
	float degree9_rot = DegreeToRadian(-120.f);

	int chekNext9 = 0;

	GLuint textureBackground9;

	GLuint texureIdLine9;
	GLuint texureIdCurve9;
	GLuint texureIdThree9;
	GLuint texureIdV9;
	GLuint texureIdBlack9;

	GLuint texureIdStart9;
	GLuint texureIdEnd9;

	GLuint texureIdLine9_2;
	GLuint texureIdCurve9_2;
	GLuint texureIdV9_2;

	GLuint texureIdCurve9_3;

	GLuint texureIdbutton9;
	GLuint texureIdclear9;
	GLuint texureSpace9;
	GLint LevelPage;
	GLint LevelPage_pressed;

	GLint texturePlayUI9;
	GLint textureQuitUI9;
	GLint textureOptionUI9;
	GLint textureRestartUI9;
	GLint textureFail;

	bool conecTcheck9_1 = false;
	bool conecTcheck9_2 = false;
	bool conecTcheck9_3 = false;

	bool SoundCheck = false;
};
