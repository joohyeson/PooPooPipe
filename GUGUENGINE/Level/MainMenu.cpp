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



bool isPlaying = false;
//Sound bgm;


void MainMenu::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();
	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(1920, 1080.f);

	textureId02 = TEXTURE->CreateTexture("assets\\title.png", 0);

	startButton = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton = OBJECT_FACTORY->CreateEmptyObject();
	optionButton = OBJECT_FACTORY->CreateEmptyObject();

	startButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	optionButton_pressed = OBJECT_FACTORY->CreateEmptyObject();

	test = OBJECT_FACTORY->CreateEmptyObject();
	test2 = OBJECT_FACTORY->CreateEmptyObject();

	textureId00 = TEXTURE->CreateTexture("assets\\game_title.png", 0);
	textureId01 = TEXTURE->CreateTexture("assets\\start.png", 0);
	textureId03 = TEXTURE->CreateTexture("assets\\tutorial.png", 0);
	textureId04 = TEXTURE->CreateTexture("assets\\option.png", 0);
	textureId05 = TEXTURE->CreateTexture("assets\\testpoopoo.png", 0);
	textureId06 = TEXTURE->CreateTexture("assets\\man.png", 0);
	startPress = TEXTURE->CreateTexture("assets\\start2.png", 0);
	tutorialPress = TEXTURE->CreateTexture("assets\\tutorial2.png", 0);
	optionPress = TEXTURE->CreateTexture("assets\\option2.png", 0);

	mShader.BuildTextureShader();
	//testNDCShader.BuildTextureShaderNDC();
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
	tutorialButton->mesh->InitializeTextureMesh(280.f, 70.f);
	tutorialButton_pressed->mesh->setTransform({ 1000.0f,-100.f });
	tutorialButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	tutorialButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

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

	menuInput.InitCallback(APPLICATION->getMyWindow());

}

void MainMenu::Update()
{
	cursor0 = menuInput.Cursor;

	if (menuInput.IsPressed(KEY::ENTER))
	{
		//bgm.Stop();
		std::cout << "Stop music" << std::endl;
	}

	if (menuInput.IsPressed(KEY::ESCAPE))
	{
		glfwTerminate();
		ENGINE->Quit();
		//bgm.Free();
	}

	if (menuInput.IsPressed(KEY::UP))
	{
		std::cout << "Up Key" << std::endl;

		if (volume < 1.0f)
		{
			volume += 0.1f;
			//bgm.SetVolume(volume);

			std::cout << volume << std::endl;
		}
	}

	if (menuInput.IsPressed(KEY::DOWN))
	{
		std::cout << "Down Key" << std::endl;

		if (volume > 0.0f)
		{
			volume -= 0.1f;
			//bgm.SetVolume(volume);

			std::cout << volume << std::endl;
		}
	}

	if (menuInput.IsPressed(KEY::F))
	{
		std::cout << "F Key" << std::endl;

		APPLICATION->SetFullScreen();

	}

	if (isPlaying == false)
	{
		this->sound->Play("assets\\BGM_airplane.mp3", -1);
		isPlaying = true;
	}

	if (startButton->collision->Point2BoxCollision(cursor0, startButton->mesh))
	{

		startButton_pressed->mesh->setTransform(startButton->mesh->GetTransform());
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST3);
		}
	}
	else
	{
		startButton_pressed->mesh->setTransform({1000.f, 1000.f});
	}


	if (tutorialButton->collision->Point2BoxCollision(cursor0, tutorialButton->mesh))
	{
		tutorialButton_pressed->mesh->setTransform(tutorialButton->mesh->GetTransform());
		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST1);
		}
	}
	else
	{
		tutorialButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (optionButton->collision->Point2BoxCollision(cursor0, optionButton->mesh))
	{
		optionButton_pressed->mesh->setTransform(optionButton->mesh->GetTransform());

		if (menuInput.IsPressed(KEY::LEFT) == true)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
		}
	}
	else
	{
		optionButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
	}

	background->mesh->Update(mShader.GetShaderHandler(), textureId02);
	startButton->mesh->Update(mShader.GetShaderHandler(), textureId01);
	tutorialButton->mesh->Update(mShader.GetShaderHandler(), textureId03);
	optionButton->mesh->Update(mShader.GetShaderHandler(), textureId04);
	startButton_pressed->mesh->Update(mShader.GetShaderHandler(), startPress);
	tutorialButton_pressed->mesh->Update(mShader.GetShaderHandler(), tutorialPress);
	optionButton_pressed->mesh->Update(mShader.GetShaderHandler(), optionPress);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void MainMenu::Close()
{
	//bgm.Free();
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
