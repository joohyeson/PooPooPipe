#pragma once
/*
 *uijin.lee
 *4.13.2020
 *digipen.uijin.lee@gmail.com
 *this is team logo transition header
 */
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
	GameLevels GetCurrLevel() override
	{
		return GameLevels::GUGULOGO;
	}
private:
	Object* gugulogo;
	Shader mShader;
	double	 lastTime;
	double firstTime;
	bool check[2] = { false };
};
