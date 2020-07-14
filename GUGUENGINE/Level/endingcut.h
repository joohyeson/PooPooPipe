#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"
class sound;
class endingCut : public LevelManager
{
public:
	endingCut()
	{
		endCut1 = nullptr;
		endCut2 = nullptr;

		textureendCut1 = 0;
		textureendCut2 = 0;

		next = nullptr;
		skip = nullptr;
		texturestartNext = 0;
		texturestartSkip = 0;

	}

	void Init() override;
	void Update() override;
	void Close() override;
	
	GameLevels GetCurrLevel() override
	{
		return GameLevels:: ENDINGCUTS;
	}
private:
	Input mInput;
	Object* endCut1;
	GLuint textureendCut1;
	Object* endCut2;
	GLuint textureendCut2;
	Shader mShader;
	Object* next;
	Object* skip;
	GLuint texturestartNext;
	GLuint texturestartSkip;
	Vector2<float> cursor__;

	bool input[2] = { false, false };
	bool cut[2] = { false, false };
	bool sound_[3] = { false };
};