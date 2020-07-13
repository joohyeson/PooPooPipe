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

extern bool  getOpt = false;
extern bool mainMenu = false;

void LevelOption::Init()
{
	prevLev = 0;
	background = OBJECT_FACTORY->CreateEmptyObject();
	background->AddComponent(new Mesh());
	background->Init();

	quitC = false;
	
	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(1920, 1080);

	option = OBJECT_FACTORY->CreateEmptyObject();
	option->AddComponent(new Mesh());
	option->Init();

	QuitAskBack = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	QuitAskBack->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	QuitAsk = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	QuitAsk->mesh->InitializeTextureMesh(700.f, 700.f);

	Yes = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	Yes->mesh->InitializeTextureMesh(130.f, 110.f);

	No = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	No->mesh->InitializeTextureMesh(130.f, 110.f);

	Yes_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	Yes_p->mesh->InitializeTextureMesh(130.f, 110.f);

	No_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	No_p->mesh->InitializeTextureMesh(130.f, 110.f);

	quitCheck = false;
	realQuit = false;

	option->mesh->setTransform({ 0.0f,350.f });
	option->mesh->SetMeshType(MESHTYPE::rectangle);
	option->mesh->InitializeTextureMesh(400.f, 100.f);

	goToMain = OBJECT_FACTORY->CreateEmptyObject();
	goToMain->AddComponent(new Mesh());
	goToMain->AddComponent(new CollisionCheck());
	goToMain->Init();

	goToMain->mesh->setTransform({ -700.0f,350.f });
	goToMain->mesh->SetMeshType(MESHTYPE::rectangle);
	goToMain->mesh->InitializeTextureMesh(80.f, 80.f);


	music = OBJECT_FACTORY->CreateEmptyObject();
	music->AddComponent(new Mesh());
	music->Init();

	music->mesh->setTransform({ -300.f,240.f });
	music->mesh->SetMeshType(MESHTYPE::rectangle);
	music->mesh->InitializeTextureMesh(240.f, 80.f);


	arrowRight = OBJECT_FACTORY->CreateEmptyObject();
	arrowRight->AddComponent(new Mesh());
	arrowRight->Init();
	arrowRight->mesh->setTransform({ 350.f,240.f });
	arrowRight->mesh->SetMeshType(MESHTYPE::rectangle);
	arrowRight->mesh->InitializeTextureMesh(80.f, 80.f);

	arrowLeft = OBJECT_FACTORY->CreateEmptyObject();
	arrowLeft->AddComponent(new Mesh());
	arrowLeft->Init();
	arrowLeft->mesh->setTransform({ -160.f,240.f });
	arrowLeft->mesh->SetMeshType(MESHTYPE::rectangle);
	arrowLeft->mesh->InitializeTextureMesh(80.f, 80.f);

	bar0 = OBJECT_FACTORY->CreateEmptyObject();
	bar0->AddComponent(new Mesh());
	bar0->Init();
	bar0->mesh->setTransform({ 95.f, 240.f });
	bar0->mesh->SetMeshType(MESHTYPE::rectangle);
	bar0->mesh->InitializeTextureMesh(400.f, 80.f);

	soundBar = OBJECT_FACTORY->CreateEmptyObject();
	soundBar->AddComponent(new Mesh());
	soundBar->Init();
	soundBar->mesh->setTransform({ 15.f, 240.f });
	soundBar->mesh->SetMeshType(MESHTYPE::rectangle);
	soundBar->mesh->InitializeTextureMesh(150.f, 30.f);

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

	fullcheck = false;
	
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

	mShader.BuildTextureShader();
	mInput = new Input();
	
	mInput->InitCallback(APPLICATION->getMyWindow());

	
	//SOUND->StopSound("BGM");
}

void LevelOption::Update()
{
	cursor = mInput->Cursor;
	
	if (goToMain->collision->Point2BoxCollision(cursor, goToMain->mesh))
	{
		if (mInput->IsPressed(KEY::LEFT))
		{
			getOpt = false;
			INPUT->setInput(KEY::LEFT);
			std::cout << "to main" << std::endl;

			if(this->sound->IsMute_() == true)
			{
				this->sound->ToggleMute();
			}
			
			if(mainMenu == true)
			{
				mainMenu = false;
				//this->sound->Resume();
				STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
				
			}

		}
	}

	if (fullScreenFalse->collision->Point2BoxCollision(cursor, fullScreenFalse->mesh))
	{
		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);

			if (APPLICATION->IsFullScreen() == true)
			{
				if(fullcheck == false)
				{
					fullcheck = true;
					fullScreenTrue->mesh->setTransform(Vector2<float>(-3500.f, 0));
				}
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

	if(fullcheck == true && APPLICATION->IsFullScreen() == false)
	{
		fullcheck = false;
	}
	
	if (arrowRight->collision->Point2BoxCollision(cursor, arrowRight->mesh))
	{
		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);

			std::cout << "Up Key" << std::endl;
			float volume = this->sound->GetVolume();

			if (volume < 1.0f)
			{
				volume += 0.1f;
				this->sound->SetVolume(volume);
				//사운드 넘겨주기
				mInput->setInput(KEY::UP);
				std::cout << volume << std::endl;
			}

			if (volume < 1.f)
			{
				soundBar->mesh->setTransform({ this->sound->soundBarPosition.x += 15.f, this->sound->soundBarPosition.y });
				soundBar->mesh->InitializeTextureMesh(this->sound->soundBarSize.x += 30.f, this->sound->soundBarSize.y);
			}
			else if (volume >= 1.f)
			{
				this->sound->soundBarSize = { 300.f, 30.f };
				this->sound->soundBarPosition = { 95.f, 240.f };

				soundBar->mesh->setTransform({ this->sound->soundBarPosition.x, this->sound->soundBarPosition.y });
				soundBar->mesh->InitializeTextureMesh(this->sound->soundBarSize.x, this->sound->soundBarSize.y);
			}
		}
	}

	if (arrowLeft->collision->Point2BoxCollision(cursor, arrowLeft->mesh))
	{
		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);

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
				mInput->setInput(KEY::DOWN);

				if (volume > 0)
				{
					soundBar->mesh->setTransform({ this->sound->soundBarPosition.x -= 15.f,this->sound->soundBarPosition.y });
					soundBar->mesh->InitializeTextureMesh(this->sound->soundBarSize.x -= 30.f, this->sound->soundBarSize.y);
				}

				std::cout << volume << std::endl;
			}
			else if (volume == 0)
			{
				this->sound->soundBarSize = { 0.f, 0.f };

				soundBar->mesh->InitializeTextureMesh(0, 0);
			}
		}
	}

	if (quitButton->collision->Point2BoxCollision(cursor, quitButton->mesh))
	{
		quitButton_pressed->mesh->setTransform(quitButton->mesh->GetTransform());

		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			if (quitCheck == false)
			{
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
		quitC = false;
		quitButton_pressed->mesh->setTransform({ 2000.f, 2000.f });
	}

	if (Yes->collision->Point2BoxCollision(cursor, Yes->mesh))
	{
		Yes_p->mesh->setTransform(Yes->mesh->GetTransform());
		if (mInput->IsPressed(KEY::LEFT))
		{
			mInput->setInput(KEY::LEFT);
			realQuit = true;
		}
	}
	else
	{
		Yes_p->mesh->setTransform({ -1000.f, -1000.f });
	}

	if (No->collision->Point2BoxCollision(cursor, No->mesh))
	{
		No_p->mesh->setTransform(No->mesh->GetTransform());
		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			realQuit = false; quitCheck = false;
			QuitAskBack->mesh->setTransform({ -2000.f, -2000.f });
			QuitAsk->mesh->setTransform({ -2000.f, -2000.f });
			Yes->mesh->setTransform({ -2000.f, -2000.f });
			No->mesh->setTransform({ -2000.f, -2000.f });
		}
	}
	else
	{
		No_p->mesh->setTransform({ -2000.f, -2000.f });
	}

	if (quitCheck == true && realQuit == true)
	{
		glfwTerminate();
		ENGINE->Quit();
	}

	background->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::background1));
	option->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionL));
	music->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::musicL));

	goToMain->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::restartUI));

	arrowRight->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::volumeR));
	arrowLeft->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::volumeL));

	bar0->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::bar0));
	soundBar->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::BAR1));

	fullScreen->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::fullScrenL));

	fullScreenFalse->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::fullCheck));
	fullScreenTrue->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::fullCheck2));

	quitButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitL));
	quitButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitLp));

	QuitAskBack->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::BAR1));
	QuitAsk->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::QUITCHECK));
	Yes->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES));
	No->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::no));
	Yes_p->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::YES_P));
	No_p->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::NO_P));

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.f, 0.f, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void LevelOption::Close()
{
	mShader.Delete();
	mMesh.Delete();

	OBJECT_FACTORY->DestroyAllObjects();
}

void LevelOption::getInput(Input* m, Sound* ms)
{
	mInput = m;
	this->sound = ms;
}

