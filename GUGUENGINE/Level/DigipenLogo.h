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
#include "../GUGUENGINE/glfwInput.h"


class DigipenLogo : public LevelManager
{
public:
	DigipenLogo()
	{
		digipenLogo = nullptr;
		textureDigipenLogo = 0;
		lastTime = 0;
		firstTime = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* digipenLogo;
	Shader mShader;
	GLuint textureDigipenLogo;
	double lastTime;
	double firstTime;
	Vector2<float> cursor0;
	Input mInput;
};


