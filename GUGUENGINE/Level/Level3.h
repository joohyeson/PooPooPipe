#pragma once
#pragma once

#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"

class Level3 : public LevelManager
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
	glm::vec3 getOrigin = { 0, 0, 0 };
	glm::vec3 getOrigin2 = { 0, 0, 0 };
};