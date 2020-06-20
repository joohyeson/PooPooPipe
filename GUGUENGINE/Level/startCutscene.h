#pragma once
#include "../GUGUENGINE/LevelManager.h"
#include "../GUGUENGINE/Object.h"
#include "../GUGUENGINE/Mathematics/Vector3.hpp"
#include "../GUGUENGINE/Shader.h"

class startCut : public LevelManager
{
public:
	startCut()
	{
		startCut1 = nullptr;
		startCut2 = nullptr;
		startCut3 = nullptr;
	}

	void Init() override;
	void Update() override;
	void Close() override;

private:
	Object* startCut1;
	GLuint texturestartCut1;
	Object* startCut2;
	GLuint texturestartCut2;
	Object* startCut3;
	GLuint texturestartCut3;
	Shader mShader;
	
	float dt = 0.f;
};
