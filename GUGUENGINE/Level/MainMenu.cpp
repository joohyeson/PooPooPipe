/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *MainMenu.cpp
 *this is mainmenu
 */
#include "MainMenu.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"

int check0 = 0;
int moveCheck0 = 0;
int moveCheck0_2 = 0;
int moveCheck0_3 = 0;

float volume = 0.3f;

extern bool mainMenu;

void MainMenu::Init()
{
	mainMenu = false;
	
	isPlaying = false;
	
	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();
	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	for(int i = 0;  i < 4; i++)
	{
		UI[i] = false;
	}
	
	startButton = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton = OBJECT_FACTORY->CreateEmptyObject();
	optionButton = OBJECT_FACTORY->CreateEmptyObject();
	creditsButton = OBJECT_FACTORY->CreateEmptyObject();

	startButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	optionButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	creditsButton_pressed = OBJECT_FACTORY->CreateEmptyObject();

	test = OBJECT_FACTORY->CreateEmptyObject();
	test2 = OBJECT_FACTORY->CreateEmptyObject();

	mShader.BuildTextureShader();
	startButton->AddComponent(new Mesh());
	startButton->AddComponent(new CollisionCheck());
	startButton->Init();
	startButton_pressed->AddComponent(new Mesh());
	startButton_pressed->AddComponent(new CollisionCheck());
	startButton_pressed->Init();

	startButton->mesh->setTransform({ 0.f,-20.f });
	startButton->mesh->SetMeshType(MESHTYPE::rectangle);
	startButton->mesh->InitializeTextureMesh(280.f, 70.f);
	startButton_pressed->mesh->setTransform({ 1000.f,-20.f });
	startButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	startButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	tutorialButton->AddComponent(new Mesh());
	tutorialButton->Init();
	tutorialButton_pressed->AddComponent(new Mesh());
	tutorialButton_pressed->Init();

	tutorialButton->mesh->setTransform({ 0.0f,-100.f });
	tutorialButton->mesh->SetMeshType(MESHTYPE::rectangle);
	tutorialButton->mesh->InitializeTextureMesh(350.f, 70.f);
	tutorialButton_pressed->mesh->setTransform({ 1000.0f,-100.f });
	tutorialButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	tutorialButton_pressed->mesh->InitializeTextureMesh(350.f, 70.f);

	optionButton->AddComponent(new Mesh());
	optionButton->Init();
	optionButton_pressed->AddComponent(new Mesh());
	optionButton_pressed->Init();
	optionButton->mesh->setTransform({ 0.0f,-180.f });
	optionButton->mesh->SetMeshType(MESHTYPE::rectangle);
	optionButton->mesh->InitializeTextureMesh(280.f, 70.f);
	optionButton_pressed->mesh->setTransform({ 0.0f,-180.f });
	optionButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	optionButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	checking = false;

	creditsButton->AddComponent(new Mesh());
	creditsButton->Init();
	creditsButton_pressed->AddComponent(new Mesh());
	creditsButton_pressed->Init();
	creditsButton->mesh->setTransform({ 0.0f,-260.f });
	creditsButton->mesh->SetMeshType(MESHTYPE::rectangle);
	creditsButton->mesh->InitializeTextureMesh(350.f, 70.f);
	creditsButton_pressed->mesh->setTransform({ 0.0f,-260.f });
	creditsButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	creditsButton_pressed->mesh->InitializeTextureMesh(350.f, 70.f);

	menuInput.InitCallback(APPLICATION->getMyWindow());
	
	//this->sound->Play("assets\\BGM_airplane.mp3", -1);
}

void MainMenu::Update()
{
	this->sound->Update();
	cursor0 = menuInput.Cursor;

	if(menuInput.IsPressed(KEY::LEFT))
	{
		if(checking == false)
		{
			this->sound->Play("assets\\click.wav", 1);
			checking = true;
		}
	}
	else
	{
		if(checking == true)
		{
			checking = false;
		}
	}
	
	if (menuInput.IsPressed(KEY::ESCAPE))
	{
		INPUT->setInput(KEY::ESCAPE);
		STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
	}

	if (menuInput.IsKeyDown(KEY::F) == true)
	{
		std::cout << "F Key" << std::endl;
		menuInput.setInput(KEY::F);

		APPLICATION->SetFullScreen();
	}

	if (menuInput.IsPressed(KEY::UP))
	{
		std::cout << "Up Key" << std::endl;

		if (volume < 1.0f)
		{
			volume += 0.1f;
			this->sound->SetVolume(volume);
			//bgm.SetVolume(volume);
			menuInput.setInput(KEY::UP);
			std::cout << volume << std::endl;
		}
	}
	if (menuInput.IsPressed(KEY::DOWN))
	{
		std::cout << "Down Key" << std::endl;

		if (volume > 0.0f)
		{
			volume -= 0.1f;
			this->sound->SetVolume(volume);
			menuInput.setInput(KEY::DOWN);
			//bgm.SetVolume(volume);

			std::cout << volume << std::endl;
		}
	}

	if (menuInput.IsPressed(KEY::A) == true)
	{
		INPUT->setInput(KEY::A);
		STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST3);
	}
	
	if (isPlaying == false)
	{
		this->sound->Play("assets\\BGM_airplane.mp3", -1);
		isPlaying = true;
	}

	if (startButton->collision->Point2BoxCollision(cursor0, startButton->mesh))
	{
		if(UI[0] == false)
		{
			UI[0] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

		startButton_pressed->mesh->setTransform(startButton->mesh->GetTransform());

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST3);
		}
	}
	else
	{
		UI[0] = false;
		startButton_pressed->mesh->setTransform({1000.f, 1000.f});
	}


	if (tutorialButton->collision->Point2BoxCollision(cursor0, tutorialButton->mesh))
	{
		if (UI[1] == false)
		{
			UI[1] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		tutorialButton_pressed->mesh->setTransform(tutorialButton->mesh->GetTransform());
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST1);
		}
	}
	else
	{
		UI[1] = false;
		tutorialButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (optionButton->collision->Point2BoxCollision(cursor0, optionButton->mesh))
	{
		if (UI[2] == false)
		{
			UI[2] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		optionButton_pressed->mesh->setTransform(optionButton->mesh->GetTransform());

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			mainMenu = true;
			INPUT->setInput(KEY::LEFT);
			if(this->sound->IsMute_() == false)
			{
				this->sound->ToggleMute();
			}
			STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
		}
	}
	else
	{
		UI[2] = false;
		optionButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (creditsButton->collision->Point2BoxCollision(cursor0, creditsButton->mesh))
	{
		if (UI[3] == false)
		{
			UI[3] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		creditsButton_pressed->mesh->setTransform(creditsButton->mesh->GetTransform());
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			STATE_MANAGER->ChangeLevel(GameLevels::CREDITS);
		}
	}
	else
	{
		UI[3] = false;
		creditsButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}


	background->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::title));
	startButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::start));
	tutorialButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::tutorial));
	optionButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionL));
	creditsButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit));

	startButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::startP));
	tutorialButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::tutorialP));
	optionButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::optionLP));
	creditsButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::creatP));

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.f, 0.f, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void MainMenu::Close()
{
	mShader.Delete();
	mMesh.Delete();
	OBJECT_FACTORY->DestroyAllObjects();
}
