#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"

class Level2 : public LevelManager
{
public:
	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2;
	Mathematics::Vector3<float> getOrigin = { 0.f, 0.f, 0.f };
	Mathematics::Vector3<float> getOrigin2 = { 0.f, 0.f, 0.f };
};
