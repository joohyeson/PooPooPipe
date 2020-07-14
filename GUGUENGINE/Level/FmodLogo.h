#pragma once
/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *FmodLogo.h
 *this is FmodLogo
 */
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"
#include "../GUGUENGINE/glfwInput.h"


class FmodLogo : public LevelManager
{
public:
	FmodLogo()
	{
		fmodLogo = nullptr;
		textureFmod=0;
		lastTime = 0;
		firstTime = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;
	GameLevels GetCurrLevel() override
	{
		return GameLevels::FMODLOGO;
	}
private:
	Object* fmodLogo;
	GLuint textureFmod;
	Shader mShader;
	double	 lastTime;
	double firstTime;
	Input mInput;
};


