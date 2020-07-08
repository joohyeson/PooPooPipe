#pragma once
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"

class sound;
class GUGULOGO : public LevelManager
{
public:
	GUGULOGO()
	{
		gugulogo = nullptr;
		lastTime = 0;
		firstTime = 0;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* gugulogo;
	Shader mShader;
	float	 lastTime;
	float firstTime;
	bool check = false;
};
