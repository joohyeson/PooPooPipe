#include "LevelSelect.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/glfwInput.h"

Vector2<float> cursorLv;
GLuint textureBackgroundLv;
GLuint texureIdLineLv;

Sound seLv;
void LevelSelect::Init()
{
	std::cout << "come in LevelSelect" << std::endl;
	backgroundLv = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	backgroundLv->mesh->InitializeTextureMesh(800.f, 800.f);
	textureBackgroundLv = TEXTURE->CreateTexture("assets\\background.png", 0);

	Level1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.0f, 120.f }, 60.f);
	texureIdLineLv = TEXTURE->CreateTexture("assets\\image0.png", 0);

	seLv.Init();
	seLv.LoadSE("assets\\coin.mp3");

	mShader2.BuildTextureShader();
	levelInput.InitCallback(APPLICATION->getMyWindow());
}

void LevelSelect::Update()
{
	levelInput.SetInput();
	cursorLv = levelInput.Cursor;

	if (levelInput.IsPressed(KEY::LEFT) == true)
	{
		if (Level1->collision->Point2BoxCollision({ cursorLv.x,cursorLv.y }, Level1->mesh) == true)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST4);
		}
	}
	backgroundLv->mesh->Update(mShader2.GetShaderHandler(), textureBackgroundLv);
	Level1->mesh->Update(mShader2.GetShaderHandler(), texureIdLineLv);
	glfwSwapBuffers(APPLICATION->getMyWindow());

	

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void LevelSelect::Close()
{
}
