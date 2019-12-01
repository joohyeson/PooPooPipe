#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"

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
	Vector3<float> getOrigin = { 0.f, 0.f, 0.f };
	Vector3<float> getOrigin2 = { 0.f, 0.f, 0.f };
};
