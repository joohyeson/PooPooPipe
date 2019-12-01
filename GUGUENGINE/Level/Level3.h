#pragma once
#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Shader.h"

class Level3 : public LevelManager
{
public:
	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* puzzle1, * puzzle2, * puzzle3, * puzzle4, * puzzle5, * puzzle6, * puzzle7, * puzzle8, * puzzle9, * puzzle10;
	int key;
	Mesh mMesh;
	Shader mShader, mShader2, mShader3, mShader4, mShader5, mShader6, mShader7, mShader8, mShader9, mShader10;
	Vector3<float> getOrigin = { 0, 0, 0 };
	Vector3<float> getOrigin2 = { 0, 0, 0 };
	Vector3<float> getOrigin3 = { 0, 0, 0 };

};
