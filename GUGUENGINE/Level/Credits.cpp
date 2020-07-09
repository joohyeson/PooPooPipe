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
	textureBackgroundCredits = TEXTURE->CreateTexture("assets\\credits1.png", 0);

	mShader.BuildTextureShader();
}

void LevelCredits::Update()
{
	background->mesh->Update(mShader.GetShaderHandler(), textureBackgroundCredits);

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClearColor(0.4f, 0.3f, 0.3f, 1);
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