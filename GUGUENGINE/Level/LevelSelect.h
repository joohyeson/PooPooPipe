#pragma once
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"
class sound;

class LevelSelect : public LevelManager
{
public:
	LevelSelect()
	{
		backgroundLv = nullptr;

		Level1 = nullptr;
		Level1_pressed = nullptr;
		
		Level2 = nullptr;
		Level2_pressed = nullptr;
		Level2_lock = nullptr;
		
		Level3 = nullptr;
		Level3_pressed = nullptr;
		Level3_lock = nullptr;

		Level4 = nullptr;
		Level4_pressed = nullptr;
		Level4_lock = nullptr;

		Level5 = nullptr;
		Level5_pressed = nullptr;
		Level5_lock = nullptr;

		Level6 = nullptr;
		Level6_pressed = nullptr;
		Level6_lock = nullptr;

		Level7 = nullptr;
		Level7_pressed = nullptr;
		Level7_lock = nullptr;

		Level8 = nullptr;
		Level8_pressed = nullptr;
		Level8_lock = nullptr;

		Level9 = nullptr;
		Level9_pressed = nullptr;
		Level9_lock = nullptr;

		Level10 = nullptr;
		Level10_pressed = nullptr;
		Level10_lock = nullptr;

		Level11 = nullptr;
		Level11_pressed = nullptr;
		Level11_lock = nullptr;
		
		currentLevel = 0;

		textureBackgroundLv = 0;

		texureIdLv1 = 0;
		texureIdLv1_pressed = 0;

		texureIdLv2 = 0;
		texureIdLv2_pressed = 0;
		texureId_lock = 0;

		texureIdLv3 = 0;
		texureIdLv3_pressed = 0;


		texureIdLv4 = 0;
		texureIdLv4_pressed = 0;


		texureIdLv5 = 0;
		texureIdLv5_pressed = 0;


		texureIdLv6 = 0;
		texureIdLv6_pressed = 0;

		texureIdLv7 = 0;
		texureIdLv7_pressed = 0;

		texureIdLv8 = 0;
		texureIdLv8_pressed = 0;

		texureIdLv9 = 0;
		texureIdLv9_pressed = 0;

		texureIdLv10 = 0;
		texureIdLv10_pressed = 0;

		texureIdLv11 = 0;
		texureIdLv11_pressed = 0;
	}
	int currentLevel;
	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::LV_SELECT;
	}
private:
	int getLevNum = 0;

	Object* backgroundLv;
	Shader mShader, mShader2;
	Object* Level1;
	Object* Level1_pressed;

	Object* Level2;
	Object* Level2_pressed;
	Object* Level2_lock;

	Object* Level3;
	Object* Level3_pressed;
	Object* Level3_lock;

	Object* Level4;
	Object* Level4_pressed;
	Object* Level4_lock;

	Object* Level5;
	Object* Level5_pressed;
	Object* Level5_lock;

	Object* Level6;
	Object* Level6_pressed;
	Object* Level6_lock;

	Object* Level7;
	Object* Level7_pressed;
	Object* Level7_lock;
	
	Object* Level8;
	Object* Level8_pressed;
	Object* Level8_lock;

	Object* Level9;
	Object* Level9_pressed;
	Object* Level9_lock;

	Object* Level10;
	Object* Level10_pressed;
	Object* Level10_lock;

	Object* Level11;
	Object* Level11_pressed;
	Object* Level11_lock;
	
	Input levelInput;

	GLuint textureBackgroundLv;

	GLuint texureIdLv1;
	GLuint texureIdLv1_pressed;

	GLuint texureIdLv2;
	GLuint texureIdLv2_pressed;
	GLuint texureId_lock;

	GLuint texureIdLv3;
	GLuint texureIdLv3_pressed;


	GLuint texureIdLv4;
	GLuint texureIdLv4_pressed;


	GLuint texureIdLv5;
	GLuint texureIdLv5_pressed;


	GLuint texureIdLv6;
	GLuint texureIdLv6_pressed;

	GLuint texureIdLv7;
	GLuint texureIdLv7_pressed;

	GLuint texureIdLv8;
	GLuint texureIdLv8_pressed;

	GLuint texureIdLv9;
	GLuint texureIdLv9_pressed;

	GLuint texureIdLv10;
	GLuint texureIdLv10_pressed;

	GLuint texureIdLv11;
	GLuint texureIdLv11_pressed;
};
