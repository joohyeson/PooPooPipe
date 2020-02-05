#pragma once
/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *DigipenLogo.h
 *this is digipen logo
 */
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"


class DigipenLogo : public LevelManager
{
public:
	DigipenLogo()
	{
		digipenLogo = nullptr;

	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* digipenLogo;
	Shader mShader;

};


