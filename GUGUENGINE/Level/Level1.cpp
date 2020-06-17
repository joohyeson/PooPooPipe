/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Level1.cpp
 *this is level1
 */
#include "Level1.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

GLuint texureIdLine1;
GLuint texureIdCurve1;
GLuint texureIdBlack1;
GLuint textureBackground1;
GLuint textureSpace1;


//Sound se;

void Level1::Init()
{
	levelCheck = false;
	spaceCheck = false;
	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground1 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	puzzleLeft = OBJECT_FACTORY->CreateEmptyObject();
	puzzleRight = OBJECT_FACTORY->CreateEmptyObject();
	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine1 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack1 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve1 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	textureSpace1 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);

	//se.Init();
	//se.LoadMusic("assets\\coin.mp3");

	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 200.f,280.f });
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->mesh->InitializeTextureMesh();

	blackPuzzle->AddComponent(new Mesh());
	blackPuzzle->Init();
	blackPuzzle->mesh->setTransform({ 0.0f, 120.f });
	blackPuzzle->mesh->InitializeTextureMesh();

	puzzleLeft->AddComponent(new Mesh());
	puzzleLeft->Init();
	puzzleLeft->mesh->setTransform({ -136.f - 40.f, 120.f });
	puzzleLeft->mesh->setRotation(DegreeToRadian(60.f));
	puzzleLeft->mesh->InitializeTextureMesh();

	puzzleRight->AddComponent(new Mesh());
	puzzleRight->Init();
	puzzleRight->mesh->setTransform({ 136.f + 40.f, 120.f });
	puzzleRight->mesh->InitializeTextureMesh();

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -200.f });
	spacePress->mesh->SetMeshType(rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(560.f, 80.f);

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level1::Update()
{
	cursor = mInput.Cursor;

	//se.Update();

	if (movePuzzle->collision->Point2HexagonCollision(cursor, movePuzzle->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			movePuzzle->mesh->setTransform(cursor);
			movable = true;
		}
	}

	if (blackPuzzle->collision->Point2HexagonCollision({ movePuzzle->mesh->GetTransform().x , movePuzzle->mesh->GetTransform().y}, blackPuzzle->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			movable = true;
		}
	}

	if (movable == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh)))
			{
				{
					if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						movePuzzle->mesh->setTransform({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y });
						movable = false;
						levelCheck = true;
						spaceCheck = true;
					}
				}
			}
		}
	}

	if(spaceCheck == true)
	{
		if (mInput.IsPressed(KEY::SPACE) == true && levelCheck == true)
		{
			mInput.setInput(KEY::SPACE);
			STATE_MANAGER->ChangeLevel(LV_TEST2);
		}
	}


	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground1);
	blackPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack1);
	puzzleLeft->mesh->Update(mShader2.GetShaderHandler(), texureIdLine1);
	puzzleRight->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve1);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), textureSpace1);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdLine1);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level1::Close()
{
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}