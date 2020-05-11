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

		Level3 = nullptr;
		Level3_pressed = nullptr;

		Level4 = nullptr;
		Level4_pressed = nullptr;

		Level5 = nullptr;
		Level5_pressed = nullptr;

		Level6 = nullptr;
		Level6_pressed = nullptr;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	int getLevNum = 0;
	bool changeLev = false;
	Object* backgroundLv;
	Shader mShader, mShader2;
	Object* Level1;
	Object* Level1_pressed;

	Object* Level2;
	Object* Level2_pressed;

	Object* Level3;
	Object* Level3_pressed;

	Object* Level4;
	Object* Level4_pressed;

	Object* Level5;
	Object* Level5_pressed;

	Object* Level6;
	Object* Level6_pressed;

	Input levelInput;
};