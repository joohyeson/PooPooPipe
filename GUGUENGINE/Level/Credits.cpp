/*
 *eunjin.hong
 *01.28.2020
 *eunjin.hong@gmail.com
 *Credits.cpp
 *This is Credits
 */
#include "Credits.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

void LevelCredits::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();
	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	goToMain = OBJECT_FACTORY->CreateEmptyObject();
	goToMain->AddComponent(new Mesh());
	goToMain->AddComponent(new CollisionCheck());
	goToMain->Init();

	goToMain->mesh->setTransform({ -700.0f,350.f });
	goToMain->mesh->SetMeshType(MESHTYPE::rectangle);
	goToMain->mesh->InitializeTextureMesh(80.f, 80.f);

	mShader.BuildTextureShader();

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void LevelCredits::Update()
{
	cursor = mInput.Cursor;

	if (goToMain->collision->Point2BoxCollision(cursor, goToMain->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			std::cout << "to main" << std::endl;
			STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
		}
	}

	background->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit1));
	goToMain->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::restartUI));

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClearColor(0.f, 0.f, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void LevelCredits::Close()
{
	//mShader.Delete();
	//mMesh.Delete();
	mShader.Delete();

	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}