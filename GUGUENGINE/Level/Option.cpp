/*
 *eunjin.hong
 *01.28.2020
 *eunjin.hong@gmail.com
 *Option.cpp
 *This is Option
 */
#include "Option.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

void LevelOption::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();
	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(1920, 1080);
	textureBackgroundOption = TEXTURE->CreateTexture("assets\\background.png", 0);

	option = OBJECT_FACTORY->CreateEmptyObject();
	option->AddComponent(new Mesh());
	option->Init();
	
	QuitAskBack = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdQuitAskBack = TEXTURE->CreateTexture("assets\\bar1.png", 0);
	QuitAskBack->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);

	QuitAsk = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdQuitAsk = TEXTURE->CreateTexture("assets\\quitcheck.png", 0);
	QuitAsk->mesh->InitializeTextureMesh(700.f, 700.f);

	Yes = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdYes = TEXTURE->CreateTexture("assets\\yes.png", 0);
	Yes->mesh->InitializeTextureMesh(130.f, 110.f);

	No = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdNo = TEXTURE->CreateTexture("assets\\no.png", 0);
	No->mesh->InitializeTextureMesh(130.f, 110.f);

	Yes_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdYes_p = TEXTURE->CreateTexture("assets\\yes.png", 0);
	Yes_p->mesh->InitializeTextureMesh(130.f, 110.f);

	No_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdNo_p = TEXTURE->CreateTexture("assets\\no.png", 0);
	No_p->mesh->InitializeTextureMesh(130.f, 110.f);
	
	quitCheck = false;
	realQuit = false;
	
	option->mesh->setTransform({ 0.0f,350.f });
	option->mesh->SetMeshType(MESHTYPE::rectangle);
	option->mesh->InitializeTextureMesh(400.f, 100.f);
	textureOption = TEXTURE->CreateTexture("assets\\option.png", 0);

	goToMain = OBJECT_FACTORY->CreateEmptyObject();
	goToMain->AddComponent(new Mesh());
	goToMain->AddComponent(new CollisionCheck());
	goToMain->Init();

	goToMain->mesh->setTransform({ -700.0f,350.f });
	goToMain->mesh->SetMeshType(MESHTYPE::rectangle);
	goToMain->mesh->InitializeTextureMesh(80.f, 80.f);

	textureGoToMain = TEXTURE->CreateTexture("assets\\restartUI.png", 0);
	
	music = OBJECT_FACTORY->CreateEmptyObject();
	music->AddComponent(new Mesh());
	music->Init();

	music->mesh->setTransform({ -300.f,240.f });
	music->mesh->SetMeshType(MESHTYPE::rectangle);
	music->mesh->InitializeTextureMesh(240.f, 80.f);
	textureMusic = TEXTURE->CreateTexture("assets\\music.png", 0);


	arrowRight = OBJECT_FACTORY->CreateEmptyObject();
	arrowRight->AddComponent(new Mesh());
	arrowRight->Init();
	arrowRight->mesh->setTransform({ 350.f,240.f });
	arrowRight->mesh->SetMeshType(MESHTYPE::rectangle);
	arrowRight->mesh->InitializeTextureMesh(80.f, 80.f);
	textureArrowRight = TEXTURE->CreateTexture("assets\\arrow_right.png", 0);

	arrowLeft= OBJECT_FACTORY->CreateEmptyObject();
	arrowLeft->AddComponent(new Mesh());
	arrowLeft->Init();
	arrowLeft->mesh->setTransform({ -160.f,240.f });
	arrowLeft->mesh->SetMeshType(MESHTYPE::rectangle);
	arrowLeft->mesh->InitializeTextureMesh(80.f, 80.f);
	textureArrowLeft = TEXTURE->CreateTexture("assets\\arrow_left.png", 0);

	bar0 = OBJECT_FACTORY->CreateEmptyObject();
	bar0->AddComponent(new Mesh());
	bar0->Init();
	bar0->mesh->setTransform({ 95.f, 240.f });
	bar0->mesh->SetMeshType(MESHTYPE::rectangle);
	bar0->mesh->InitializeTextureMesh(400.f, 80.f);
	textureBar0 = TEXTURE->CreateTexture("assets\\bar0.png", 0);

	fullScreen = OBJECT_FACTORY->CreateEmptyObject();
	fullScreen->AddComponent(new Mesh());
	fullScreen->Init();
	fullScreen->mesh->setTransform({ -260.f,130.f });
	fullScreen->mesh->SetMeshType(MESHTYPE::rectangle);
	fullScreen->mesh->InitializeTextureMesh(240.f, 80.f);

	fullScreenFalse = OBJECT_FACTORY->CreateEmptyObject();
	fullScreenFalse->AddComponent(new Mesh());
	fullScreenFalse->Init();
	fullScreenFalse->mesh->setTransform({ 350.f,130.f });
	fullScreenFalse->mesh->SetMeshType(MESHTYPE::rectangle);
	fullScreenFalse->mesh->InitializeTextureMesh(80.f, 80.f);

	fullScreenTrue = OBJECT_FACTORY->CreateEmptyObject();
	fullScreenTrue->AddComponent(new Mesh());
	fullScreenTrue->Init();
	fullScreenTrue->mesh->setTransform({ -3500.f,130.f });
	fullScreenTrue->mesh->SetMeshType(MESHTYPE::rectangle);
	fullScreenTrue->mesh->InitializeTextureMesh(80.f, 80.f);

	quitButton = OBJECT_FACTORY->CreateEmptyObject();
	quitButton_pressed = OBJECT_FACTORY->CreateEmptyObject();

	quitButton->AddComponent(new Mesh());
	quitButton->Init();
	quitButton_pressed->AddComponent(new Mesh());
	quitButton_pressed->Init();

	quitButton->mesh->setTransform({ 0.0f,20.f });
	quitButton->mesh->SetMeshType(MESHTYPE::rectangle);
	quitButton->mesh->InitializeTextureMesh(280.f, 70.f);
	quitButton_pressed->mesh->setTransform({ 3500.0f,-100.f });
	quitButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	quitButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	textureCheckTrue= TEXTURE->CreateTexture("assets\\checkO.png", 0);
	textureCheckFalse = TEXTURE->CreateTexture("assets\\checkX.png", 0);
	textureFullScreen = TEXTURE->CreateTexture("assets\\fullscreen.png", 0);
	
	textureQuit = TEXTURE->CreateTexture("assets\\quit.png", 0);
	textureQuitPressed = TEXTURE->CreateTexture("assets\\quit2.png", 0);

	mShader.BuildTextureShader();

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void LevelOption::Update()
{
	cursor = mInput.Cursor;

	if (goToMain->collision->Point2BoxCollision(cursor, goToMain->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT))
		{
			std::cout << "to main" << std::endl;
			STATE_MANAGER->ChangeLevel(nextLevel);
		}
	}

	if (fullScreenFalse->collision->Point2BoxCollision(cursor, fullScreenFalse->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT))
		{
			if (APPLICATION->IsFullScreen() == true)
			{
				fullScreenTrue->mesh->setTransform(Vector2<float>(-3500.f, 0));
			}
			else
			{
				fullScreenTrue->mesh->setTransform(fullScreenFalse->mesh->GetTransform());
			}
			
			APPLICATION->SetFullScreen();
		}
	}
	else
	{
		if (APPLICATION->IsFullScreen() == true)
		{
			fullScreenTrue->mesh->setTransform(fullScreenFalse->mesh->GetTransform());
		}
	}

	if (arrowRight->collision->Point2BoxCollision(cursor, arrowRight->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT))
		{
			std::cout << "Up Key" << std::endl;
			float volume = this->sound->GetVolume();
			if (volume < 1.0f)
			{
				volume += 0.1f;
				this->sound->SetVolume(volume);
				mInput.setInput(KEY::UP);
				std::cout << volume << std::endl;
			}
		}
	}

	if (arrowLeft->collision->Point2BoxCollision(cursor, arrowLeft->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT))
		{
			std::cout << "Down Key" << std::endl;
			float volume = this->sound->GetVolume();
			if (volume > 0.0f)
			{
				volume -= 0.1f;
				if (volume <= 0.f)
				{
					volume = 0.f;
				}
				this->sound->SetVolume(volume);
				mInput.setInput(KEY::DOWN);

				std::cout << volume << std::endl;
			}
		}
	}

	if (quitButton->collision->Point2BoxCollision(cursor, quitButton->mesh))
	{
		quitButton_pressed->mesh->setTransform(quitButton->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT))
		{
			mInput.setInput(KEY::LEFT);
			if(quitCheck == false)
			{
				//SOUND->Pause();
				quitCheck = true;
				QuitAskBack->mesh->setTransform({ 0.f, 0.f });
				QuitAsk->mesh->setTransform({ 0.f, 0.f });
				Yes->mesh->setTransform({ -100.f, -50.f });
				No->mesh->setTransform({ 100.f, -50.f });
			}
		}
	}
	else
	{
		quitButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (Yes->collision->Point2BoxCollision(cursor, Yes->mesh))
	{
		Yes_p->mesh->setTransform(Yes->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT))
		{
			mInput.setInput(KEY::LEFT);
			realQuit = true;
		}
	}
	else
	{
		Yes_p->mesh->setTransform({-1000.f, -1000.f});
	}
	
	if (No->collision->Point2BoxCollision(cursor, No->mesh))
	{
		No_p->mesh->setTransform(No->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT))
		{
			mInput.setInput(KEY::LEFT);
			realQuit = false;
			STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
		}
	}
	else
	{
		No_p->mesh->setTransform({ -1000.f, -1000.f });
	}
	
	if(quitCheck == true && realQuit == true)
	{
		glfwTerminate();
		ENGINE->Quit();
	}

	background->mesh->Update(mShader.GetShaderHandler(), textureBackgroundOption);
	option->mesh->Update(mShader.GetShaderHandler(), textureOption);
	music->mesh->Update(mShader.GetShaderHandler(), textureMusic);

	goToMain->mesh->Update(mShader.GetShaderHandler(), textureGoToMain);

	arrowRight->mesh->Update(mShader.GetShaderHandler(), textureArrowRight);
	arrowLeft->mesh->Update(mShader.GetShaderHandler(), textureArrowLeft);

	bar0->mesh->Update(mShader.GetShaderHandler(), textureBar0);

	fullScreen->mesh->Update(mShader.GetShaderHandler(), textureFullScreen);
	
	fullScreenFalse->mesh->Update(mShader.GetShaderHandler(), textureCheckFalse);
	fullScreenTrue->mesh->Update(mShader.GetShaderHandler(), textureCheckTrue);


	quitButton->mesh->Update(mShader.GetShaderHandler(), textureQuit);
	quitButton_pressed->mesh->Update(mShader.GetShaderHandler(), textureQuitPressed);

	QuitAskBack->mesh->Update(mShader.GetShaderHandler(), textureIdQuitAskBack);
	QuitAsk->mesh->Update(mShader.GetShaderHandler(), textureIdQuitAsk);
	Yes->mesh->Update(mShader.GetShaderHandler(), textureIdYes);
	No->mesh->Update(mShader.GetShaderHandler(), textureIdNo);
	Yes_p->mesh->Update(mShader.GetShaderHandler(), textureIdYes_p);
	No_p->mesh->Update(mShader.GetShaderHandler(), textureIdNo_p);
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwPollEvents();
}

void LevelOption::Close()
{
	mShader.Delete();
	mMesh.Delete();

	OBJECT_FACTORY->DestroyAllObjects();
}