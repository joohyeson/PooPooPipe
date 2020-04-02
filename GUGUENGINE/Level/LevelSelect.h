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
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* backgroundLv;
	Shader mShader, mShader2;
	Object* Level1;
	Input levelInput;
};