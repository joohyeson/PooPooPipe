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


class FmodLogo : public LevelManager
{
public:
	FmodLogo()
	{
		fmodLogo = nullptr;
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
	Shader mShader;
	double	 lastTime;
	double firstTime;
};


