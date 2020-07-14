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
	
	for (int i = 0; i < 5; i++)
	{
		UI[i] = false;
	}

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

	option->mesh->setTransform({ 0.0f,400.f });
	option->mesh->SetMeshType(MESHTYPE::rectangle);
	option->mesh->InitializeTextureMesh(400.f, 100.f);

	goToMain = OBJECT_FACTORY->CreateEmptyObject();
	goToMain->AddComponent(new Mesh());
	goToMain->AddComponent(new CollisionCheck());
	goToMain->Init();
	goToMain->mesh->setTransform({ 0.f,-90.f });
	goToMain->mesh->SetMeshType(MESHTYPE::rectangle);
	goToMain->mesh->InitializeTextureMesh(350.f, 70.f);

	goToMain_pressed = OBJECT_FACTORY->CreateEmptyObject();
	goToMain_pressed->AddComponent(new Mesh());
	goToMain_pressed->Init();
	goToMain_pressed->mesh->setTransform({ 3500.0f,-100.f });
	goToMain_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	goToMain_pressed->mesh->InitializeTextureMesh(350.f, 70.f);

	backtomain = OBJECT_FACTORY->CreateEmptyObject();
	backtomain->AddComponent(new Mesh());
	backtomain->AddComponent(new CollisionCheck());
	backtomain->Init();
	backtomain->mesh->setTransform({ 0.f,-180.f });
	backtomain->mesh->SetMeshType(MESHTYPE::rectangle);
	backtomain->mesh->InitializeTextureMesh(560.f, 70.f);

	backtomain_pressed = OBJECT_FACTORY->CreateEmptyObject();
	backtomain_pressed->AddComponent(new Mesh());
	backtomain_pressed->Init();
	backtomain_pressed->mesh->setTransform({ 3500.0f,-100.f });
	backtomain_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	backtomain_pressed->mesh->InitializeTextureMesh(560.f, 70.f);



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
	fullScreen->mesh->setTransform({ -230.f,130.f });
	fullScreen->mesh->SetMeshType(MESHTYPE::rectangle);
	fullScreen->mesh->InitializeTextureMesh(480.f, 80.f);

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

	quitButton->mesh->setTransform({ 0.0f,0.f });
	quitButton->mesh->SetMeshType(MESHTYPE::rectangle);
	quitButton->mesh->InitializeTextureMesh(280.f, 70.f);
	quitButton_pressed->mesh->setTransform({ 3500.0f,-100.f });
	quitButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	quitButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	creditsButton = OBJECT_FACTORY->CreateEmptyObject();
	creditsButton->AddComponent(new Mesh());
	creditsButton->AddComponent(new CollisionCheck());
	creditsButton->Init();
	creditsButton->mesh->setTransform({ 0.f,-270.f });
	creditsButton->mesh->SetMeshType(MESHTYPE::rectangle);
	creditsButton->mesh->InitializeTextureMesh(350.f, 70.f);

	creditsButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	creditsButton_pressed->AddComponent(new Mesh());
	creditsButton_pressed->Init();
	creditsButton_pressed->mesh->setTransform({ 3500.0f,-100.f });
	creditsButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	creditsButton_pressed->mesh->InitializeTextureMesh(350.f, 70.f);

	tutorialButton = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton->AddComponent(new Mesh());
	tutorialButton->AddComponent(new CollisionCheck());
	tutorialButton->Init();
	tutorialButton->mesh->setTransform({ 0.f,-360.f });
	tutorialButton->mesh->SetMeshType(MESHTYPE::rectangle);
	tutorialButton->mesh->InitializeTextureMesh(350.f, 70.f);

	tutorialButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton_pressed->AddComponent(new Mesh());
	tutorialButton_pressed->Init();
	tutorialButton_pressed->mesh->setTransform({ 3500.0f,-100.f });
	tutorialButton_pressed->mesh->SetMeshType(MESHTYPE::rectangle);
	tutorialButton_pressed->mesh->InitializeTextureMesh(350.f, 70.f);

	controls = OBJECT_FACTORY->CreateEmptyObject();
	controls->AddComponent(new Mesh());
	controls->AddComponent(new CollisionCheck());
	controls->Init();
	controls->mesh->setTransform({ 5000.f,100.f });
	controls->mesh->SetMeshType(MESHTYPE::rectangle);
	controls->mesh->InitializeTextureMesh(1920.f, 1080.f);


	credit1 = OBJECT_FACTORY->CreateEmptyObject();
	credit1->AddComponent(new Mesh());
	credit1->AddComponent(new CollisionCheck());
	credit1->Init();
	credit1->mesh->setTransform({ 5000.f,100.f });
	credit1->mesh->SetMeshType(MESHTYPE::rectangle);
	credit1->mesh->InitializeTextureMesh(1920.f, 1080.f);

	credit2 = OBJECT_FACTORY->CreateEmptyObject();
	credit2->AddComponent(new Mesh());
	credit2->AddComponent(new CollisionCheck());
	credit2->Init();
	credit2->mesh->setTransform({ 5000.f,100.f });
	credit2->mesh->SetMeshType(MESHTYPE::rectangle);
	credit2->mesh->InitializeTextureMesh(1920.f, 1080.f);

	credit3 = OBJECT_FACTORY->CreateEmptyObject();
	credit3->AddComponent(new Mesh());
	credit3->AddComponent(new CollisionCheck());
	credit3->Init();
	credit3->mesh->setTransform({ 5000.f,100.f });
	credit3->mesh->SetMeshType(MESHTYPE::rectangle);
	credit3->mesh->InitializeTextureMesh(1920.f, 1080.f);

	next = OBJECT_FACTORY->CreateEmptyObject();
	next->AddComponent(new Mesh());
	next->AddComponent(new CollisionCheck());
	next->Init();
	next->mesh->setTransform({ 5000.f,100.f });
	next->mesh->SetMeshType(MESHTYPE::rectangle);
	next->mesh->InitializeTextureMesh(350.f, 288.f);


	mShader.BuildTextureShader();
	mInput = new Input();
	
	mInput->InitCallback(APPLICATION->getMyWindow());
	SUI = false;
}

void LevelOption::Update()
{
	this->sound->Update();
	cursor = mInput->Cursor;
	
	if (goToMain->collision->Point2BoxCollision(cursor, goToMain->mesh) && quitCheck == false)
	{
		if (UI[0] == false)
		{
			UI[0] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

		goToMain_pressed->mesh->setTransform({ -700.0f,350.f });

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
				STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);				
			}

		}
	}
	else
	{
		UI[0] = false;
		goToMain_pressed->mesh->setTransform({ -2000.0f,-2000.f });
	}

	if (fullScreenFalse->collision->Point2BoxCollision(cursor, fullScreenFalse->mesh) && quitCheck == false)
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
	
	if (arrowRight->collision->Point2BoxCollision(cursor, arrowRight->mesh) && quitCheck == false)
	{
		if (mInput->IsPressed(KEY::LEFT))
		{

			std::cout << "Up Key" << std::endl;
			float volume = this->sound->GetVolume();

			if (volume < 1.0f)
			{
				if(SUI == false)
				{
					this->sound->Play("assets\\control.wav", 1);
					SUI = true;
				}
				volume += 0.1f;
				this->sound->SetVolume(volume);
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
			INPUT->setInput(KEY::LEFT);

		}
		else
		{
			SUI = false;
		}
	}

	if (arrowLeft->collision->Point2BoxCollision(cursor, arrowLeft->mesh) && quitCheck == false)
	{
		if (mInput->IsPressed(KEY::LEFT))
		{
			std::cout << "Down Key" << std::endl;
			float volume = this->sound->GetVolume();

			if (volume > 0.0f)
			{
				if (SUI == false)
				{
					this->sound->Play("assets\\control.wav", 1);
					SUI = true;
				}
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
			INPUT->setInput(KEY::LEFT);
		}
		else
		{
			SUI = false;
		}
	}

	if (quitButton->collision->Point2BoxCollision(cursor, quitButton->mesh))
	{
		if (UI[1] == false)
		{
			UI[1] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

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
		UI[1] = false;
		quitC = false;
		quitButton_pressed->mesh->setTransform({ 2000.f, 2000.f });
	}

	if (goToMain->collision->Point2BoxCollision(cursor, goToMain->mesh) && quitCheck == false)
	{
		goToMain_pressed->mesh->setTransform(goToMain->mesh->GetTransform());

		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
		}
	}
	else
	{
		goToMain_pressed->mesh->setTransform({ 2000.f, 2000.f });
	}


	if (backtomain->collision->Point2BoxCollision(cursor, backtomain->mesh) && quitCheck == false)
	{
		if (UI[2] == false)
		{
			UI[2] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

		backtomain_pressed->mesh->setTransform(backtomain->mesh->GetTransform());

		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
			
			if (this->sound->IsMute_() == true)
			{
				this->sound->ToggleMute();
			}

			if (mainMenu == true)
			{
				mainMenu = false;
				STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
			}

		}
	}
	else
	{
		UI[2] = false;
		backtomain_pressed->mesh->setTransform({ 2000.f, 2000.f });
	}

	int creditnum = 0;

	if (creditsButton->collision->Point2BoxCollision(cursor, creditsButton->mesh) && quitCheck == false)
	{

		if (UI[3] == false)
		{
			UI[3] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

		creditsButton_pressed->mesh->setTransform(creditsButton->mesh->GetTransform());

		if (mInput->IsPressed(KEY::LEFT))
		{
			if (this->sound->IsMute_() == true)
			{
				this->sound->ToggleMute();
			}

			INPUT->setInput(KEY::LEFT);
			credit1->mesh->setTransform({ 0.f,0.f });
			next->mesh->setTransform({ 700.f,400.f });
		}

	}
	else
	{
		UI[3] = false;
		creditsButton_pressed->mesh->setTransform({ 2000.f, 2000.f });
	}

	if (next->collision->Point2BoxCollision(cursor, next->mesh) == true)
	{
		if (mInput->IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);

			if (creditnum == 0)
			{
				credit1->mesh->setTransform({ 5000.f,0.f });
				credit2->mesh->setTransform({ 0.f,0.f });
				next->mesh->setTransform({ 700.f,400.f });
				creditnum = 1;
			}
			if (creditnum == 1)
			{
				credit2->mesh->setTransform({ 5000.f,0.f });
				credit3->mesh->setTransform({ 0.f,0.f });
				next->mesh->setTransform({ 700.f,400.f });
				creditnum = 2;
			}
		}
	}

	if (tutorialButton->collision->Point2BoxCollision(cursor, tutorialButton->mesh) && quitCheck == false)
	{
		if (UI[4] == false)
		{
			UI[4] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}

		tutorialButton_pressed->mesh->setTransform(tutorialButton->mesh->GetTransform());

		if (mInput->IsPressed(KEY::LEFT))
		{
			if (this->sound->IsMute_() == true)
			{
				this->sound->ToggleMute();
			}

			INPUT->setInput(KEY::LEFT);
			controls->mesh->setTransform({ 0.f,0.f });
		}
	}
	else
	{
		UI[4] = false;
		tutorialButton_pressed->mesh->setTransform({ 2000.f, 2000.f });
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

	goToMain->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::resume));
	goToMain_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::resume2));


	arrowRight->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::volumeR));
	arrowLeft->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::volumeL));

	bar0->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::bar0));
	soundBar->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::BAR1));

	fullScreen->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::fullScrenL));

	fullScreenFalse->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::fullCheck));
	fullScreenTrue->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::fullCheck2));

	quitButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitL));
	quitButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::quitLp));

	backtomain->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::backtomain));
	backtomain_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::backtomain2));

	creditsButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit));
	creditsButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::creatP));

	tutorialButton->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::tutorial));
	tutorialButton_pressed->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::tutorialP));

	controls->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::controls));

	credit1->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit1));
	credit2->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit2));
	credit3->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::credit3));

	next->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::nextd));

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

