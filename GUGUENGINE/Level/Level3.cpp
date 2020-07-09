/*
 *hakyung.kim
 *12.13.2019
 *digipen.hagyeong@gmail.com
 *Level3.cpp
 *if you want to check pipe connect, you can remove "//"pipe connect
 *this is level3
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level3.h"

#include "../GUGUENGINE/Sound.h"


void Level3::Init()
{
	STATE_MANAGER->setCurrentLV(0);

	QuitAskBack = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdQuitAskBack = TEXTURE->CreateTexture("assets\\bar1.png", 0);
	QuitAskBack->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	QuitAsk = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdQuitAsk = TEXTURE->CreateTexture("assets\\quitcheck.png", 0);
	QuitAsk->mesh->InitializeTextureMesh(700.f, 700.f);

	Yes = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdYes = TEXTURE->CreateTexture("assets\\yes.png", 0);
	Yes->mesh->InitializeTextureMesh(130.f, 110.f);
	
	mInput.setInput(KEY::LEFT);
	
	No = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdNo = TEXTURE->CreateTexture("assets\\no_p.png", 0);
	No->mesh->InitializeTextureMesh(130.f, 110.f);

	Yes_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdYes_p = TEXTURE->CreateTexture("assets\\yes_p.png", 0);
	Yes_p->mesh->InitializeTextureMesh(130.f, 110.f);

	No_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -1000.f, -1000.f });
	textureIdNo_p = TEXTURE->CreateTexture("assets\\no.png", 0);
	No_p->mesh->InitializeTextureMesh(130.f, 110.f);

	quitCheck = false;
	realQuit = false;
	
	chekNext = 0;
	skip = false;
	failS = false;
	firstTime = glfwGetTime();
	conecTcheck1 = false;
	conecTcheck2 = false;
	conecTcheck3 = false;

	degree2 = 0;
	degree2_2 = 0;
	degree2_3 = 0;

	blCheck1 = false;
	blCheck1_2 = false;

	blCheck2 = false;
	blCheck2_2 = false;

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	textureBackground3 = TEXTURE->CreateTexture("assets\\background1.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f }, 0,
		false, false, false, true, false, true);
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });

	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI3 = TEXTURE->CreateTexture("assets\\playUI.png", 0);
	
	playUI_p = OBJECT_FACTORY->CreateEmptyObject();
	playUI_p->AddComponent(new Mesh());
	playUI_p->Init();

	playUI_p->mesh->setTransform({ 1713.5f, 300.f });
	playUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI3p = TEXTURE->CreateTexture("assets\\playUI_2.png", 0);
	
	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureQuitUI3 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);
	
	quitUI_p = OBJECT_FACTORY->CreateEmptyObject();
	quitUI_p->AddComponent(new Mesh());
	quitUI_p->Init();

	quitUI_p->mesh->setTransform({	1800.f, 150.f });
	quitUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureQuitUI3p = TEXTURE->CreateTexture("assets\\quitUI_2.png", 0);
	
	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 713.5f, 0.f });
	optionUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI3 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);
	
	optionUI_p = OBJECT_FACTORY->CreateEmptyObject();
	optionUI_p->AddComponent(new Mesh());
	optionUI_p->Init();
	optionUI_p->mesh->setTransform({ 1713.5f, 0.f });
	optionUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI3p = TEXTURE->CreateTexture("assets\\optionUI_2.png", 0);
	
	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureRestartUI3 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);

	restartUI_p = OBJECT_FACTORY->CreateEmptyObject();
	restartUI_p->AddComponent(new Mesh());
	restartUI_p->Init();
	restartUI_p->mesh->setTransform({ 1800.f, -150.f });
	restartUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureRestartUI3p = TEXTURE->CreateTexture("assets\\restartUI_2.png", 0);
	
	mPooPoo.Init();
	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 280.f + 50.f }, 60.f);
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 280.f + 50.f });
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 180.f);
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 482.f, 160.f + 22.f });
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 448.f, 160.f + 22.f }, 120.f);
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f }, 240.f);
	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 482.f, -80.0f - 32.f });
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 448.f, -80.f - 32.f }, 60.f);
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 415.f, -80.f - 32.f }, 60.f);
	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 60.f);
	puzzle12 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, -200.f - 62.f });

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 140.f - 415.f, 160.f + 22.f });
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -64.f - 465.f, 40.f - 5.f });
	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -268.f - 519.f, -80.f - 32.f });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 280.f + 50.f }, -240.f);
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f });

	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);
	
	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });

	levelImage= OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage= OBJECT_FACTORY->CreateObject(Type::shape_rec, { 830, 450.f - 20.f });

	texureIdLine3 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack3 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve3 = TEXTURE->CreateTexture("assets\\image2.png", 0);

	texureIdStart3 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd3 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine3_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve3_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	LevelPage = TEXTURE->CreateTexture("assets\\levelButton.png", 0);
	LevelPage_pressed = TEXTURE->CreateTexture("assets\\levelButton_2.png", 0);

	texureIdbutton3 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear3 = TEXTURE->CreateTexture("assets\\clear.png", 0);

	levelTexture= TEXTURE->CreateTexture("assets\\level.png", 0);
	numberTexture= TEXTURE->CreateTexture("assets\\01.png", 0);
	textureFail = TEXTURE->CreateTexture("assets\\failScreen.png", 0);
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);


	//se3.Init();
	//se3.LoadSE("assets\\coin.mp3");

	//playSE3.Init();
	//playSE3.LoadSE("assets\\flushing.wav");

	mShader2.BuildTextureShader();
	mShader.BuildTextureShader();
	
	movePuzzle2->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle3->pipe->SetDirection(false, false, false, true, false, true);
	endPuzzle->pipe->SetDirection(true, false, false, false, false, false);
	puzzle2->pipe->SetDirection(false, false, false, true, false, true);
	puzzle6->pipe->SetDirection(false, false, true, false, true, false);
	puzzle7->pipe->SetDirection(false, true, false, false, false, true);

	
	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);
	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);
	fail->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SW_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SW_, blackPuzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle6->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, endPuzzle->mesh->GetTransform());

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level3::Update()
{
	lastTime = glfwGetTime();

	STATE_MANAGER->setCurrentLV(1);

	cursor3 = mInput.Cursor;

	if (mInput.IsPressed(KEY::F) == true)
	{
		APPLICATION->SetFullScreen();
		mInput.setInput(KEY::F);
	}

	if (Levelsel->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, Levelsel->mesh) == true)
	{
		if(UI[4] == false)
		{
			UI[4] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		Levelsel_pressed->mesh->setTransform(Levelsel->mesh->GetTransform());
		
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
				//INPUT->setInput(KEY::LEFT);
				chekNext = 0;

				conecTcheck1 = false;
				conecTcheck2 = false;
				conecTcheck3 = false;

				degree2 = 0;
				degree2_2 = 0;
				degree2_3 = 0;

				blCheck1 = false;
				blCheck1_2 = false;

				blCheck2 = false;
				blCheck2_2 = false;

				std::cout << "check" << std::endl;
				STATE_MANAGER->ChangeLevel(GameLevels::LV_SELECT);
			}
	}
	else
	{
		UI[4] = false;
		Levelsel_pressed->mesh->setTransform({ 1800.f, -300.f });
	}

	if (movePuzzle->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[1] && !movable[2])
		{
			movePuzzle->mesh->setTransform({ cursor3.x, cursor3.y });
			movable[0] = true;
		}

		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[0] = true;
		}
		if (rot[0] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				movePuzzle->pipe->Update();
				degree2 += static_cast<float>(DegreeToRadian(60.f));
				movePuzzle->mesh->setRotation(degree2);

				this->sound->Play("assets\\coin.mp3", 1);
				//se3.Play("assets\\coin.mp3", 1);
				//se3.SetVolume(0.5f);
				//se3.SetLoopCount(1);
				rot[0] = false;
			}
		}
	}
	else
	{
		movable[0] = false;
	}

	if (blCheck1)
	{
		if ((movePuzzle->pipe->GetDirValue(NW) == 1 && puzzle2->pipe->GetDirValue(SE) == 1) && (movePuzzle->pipe->GetDirValue(SW) == 1 && puzzle7->pipe->GetDirValue(NE) == 1))
		{
			//std::cout << "pipe connect\n";
			conecTcheck1 = true;
		}
		else
		{
			conecTcheck1 = false;
			//std::cout << "Not connect\n";
		}
	}
	if (blCheck1_2)
	{
		if ((movePuzzle->pipe->GetDirValue(NE) == 1 && puzzle6->pipe->GetDirValue(SW) == 1) && (movePuzzle->pipe->GetDirValue(SE) == 1 && endPuzzle->pipe->GetDirValue(NW) == 1))
		{
			conecTcheck1 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck1 = false;
			//std::cout << "Not connect\n";
		}
	}

	if (movePuzzle2->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle2->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[2])
		{
			movePuzzle2->mesh->setTransform({ cursor3.x, cursor3.y });
			movable[1] = true;
		}
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[1] = true;
		}
		if (rot[1] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				movePuzzle2->pipe->Update();

				degree2_2 += static_cast<float>(DegreeToRadian(60.f));
				movePuzzle2->mesh->setRotation(degree2_2);

				this->sound->Play("assets\\coin.mp3", 1);

				//se3.Play(1);
				//se3.SetVolume(0.5f);
				//se3.SetLoopCount(1);
				rot[1] = false;
			}
		}

	}
	else
	{
		movable[1] = false;
	}

	if ((movePuzzle2->pipe->GetDirValue(E) == puzzle7->pipe->GetDirValue(W)) && (movePuzzle2->pipe->GetDirValue(W) == puzzle6->pipe->GetDirValue(E)))
	{
		conecTcheck2 = true;
		//std::cout << "pipe connect\n";
	}
	else
	{
		conecTcheck2 = false;
		//std::cout << "Not connect\n";
	}

	if (movePuzzle3->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle3->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1])
		{
			movePuzzle3->mesh->setTransform({ cursor3.x, cursor3.y });
			movable[2] = true;
		}
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[2] = true;
		}
		if (rot[2] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				movePuzzle3->pipe->Update();
				degree2_3 += static_cast<float>(DegreeToRadian(60.f));
				movePuzzle3->mesh->setRotation(degree2_3);

				this->sound->Play("assets\\coin.mp3", 1);
				//se3.Play(1);
				//se3.SetVolume(0.5f);
				//se3.SetLoopCount(1);
				rot[2] = false;
			}
		}
	}
	else
	{
		movable[2] = false;
	}

	if (blCheck2)
	{
		if ((movePuzzle3->pipe->GetDirValue(NW) == puzzle2->pipe->GetDirValue(SE)) && (movePuzzle3->pipe->GetDirValue(SW) == puzzle7->pipe->GetDirValue(NE)))
		{
			//std::cout << "pipe connect\n";
			conecTcheck3 = true;
		}
		else
		{
			conecTcheck3 = false;
			//std::cout << "Not connect\n";
		}
	}
	if (blCheck2_2)
	{
		if ((movePuzzle3->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle3->pipe->GetDirValue(SE) == endPuzzle->pipe->GetDirValue(NW)))
		{
			conecTcheck3 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck3 = false;
			//std::cout << "Not connect\n";
		}
	}
	if (movable[0] == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh)))
			{
				if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
					movable[0] = false;
					blCheck1 = true;
					blCheck1_2 = false;
				}
				else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					movable[0] = false;
					blCheck1_2 = false;
					blCheck1 = false;
				}
				else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					movable[0] = false;
					blCheck1_2 = true;
					blCheck1 = false;
				}
			}
		}
		else
		{
			conecTcheck1 = false;
		}
	}
	if (movable[1] == true)
	{
		if ((movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh)))
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle2->mesh))
				{
					movePuzzle2->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
					movable[1] = false;
				}
				if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh))
				{
					movePuzzle2->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					movable[1] = false;
				}
				if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh))
				{
					movePuzzle2->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					movable[1] = false;
				}
			}
		}
		else
		{
			conecTcheck2 = false;
		}
	}
	if (movable[2] == true)
	{
		if ((movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh)))
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
					movable[2] = false;
					blCheck2 = true;
					blCheck2_2 = false;
				}
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					movable[2] = false;

					blCheck2 = false;
					blCheck2_2 = false;
				}
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					movable[2] = false;
					blCheck2 = false;
					blCheck2_2 = true;
				}
			}
		}
		else
		{
			conecTcheck3 = false;
		}
	}

	if (playUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, playUI->mesh))
	{
		if(UI[0] == false)
		{
			UI[0] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		playUI_p->mesh->setTransform(playUI->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			INPUT->setInput(KEY::LEFT);
			poopooCheck = true;
		}
	}
	else
	{
		UI[0] = false;
		playUI_p->mesh->setTransform({1000.f, 1000.f});
		connectMove = 0;
	}

	if(poopooCheck == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			INPUT->setInput(KEY::LEFT);

			if (conecTcheck1 && conecTcheck2 && conecTcheck3)
			{
				std::cout << "if 3" << std::endl;
				clear->mesh->setTransform({ 350.f, -240.f });
				chekNext = 1;
				std::cout << "clear" << std::endl;
				connectMove = 0;
				mPooPoo.SetIsSuccess(true);

				this->sound->Play("assets\\flushing.wav", 1);

				//playSE3.Play(1);
				//playSE3.SetVolume(0.5f);
				//playSE3.SetLoopCount(1);
				poopooCheck = false;
			}
			else 
			{
				if(failS == false)
				{
					this->sound->Play("assets\\fart.mp3", 1);
					failS = true;
					first = glfwGetTime();
				}
				last = glfwGetTime();
				if(last - first > 1.5f)
				{
					fail->mesh->setTransform({ 0,0 });
					failS = false;
					poopooCheck = false;
				}
			}
		}

	}
	
	if (fail->collision->Point2BoxCollision({ cursor3.x,cursor3.y }, fail->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);

			fail->mesh->setTransform({ -2000.f,-2000.f });
			STATE_MANAGER->ReloadState();
		}
	}

	if (restartUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, restartUI->mesh))
	{
		if (UI[1] == false)
		{
			UI[1] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		restartUI_p->mesh->setTransform(restartUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			INPUT->setInput(KEY::LEFT);

			STATE_MANAGER->ReloadState();
		}
	}
	else
	{
		UI[1] = false;
		restartUI_p->mesh->setTransform({ 1700.f, 1000.f });
	}

	if (optionUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, optionUI->mesh))
	{
		if (UI[2] == false)
		{
			UI[2] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		optionUI_p->mesh->setTransform(optionUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			INPUT->setInput(KEY::LEFT);

			STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
		}
	}
	else
	{
		UI[2] = false;
		optionUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (quitUI->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, quitUI->mesh))
	{
		if (UI[3] == false)
		{
			UI[3] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		quitUI_p->mesh->setTransform(quitUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			INPUT->setInput(KEY::LEFT);
			if (quitCheck == false)
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
		UI[3] = false;
		quitUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (Yes->collision->Point2BoxCollision(cursor3, Yes->mesh))
	{
		Yes_p->mesh->setTransform(Yes->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			realQuit = true;
		}
	}
	else
	{
		Yes_p->mesh->setTransform({ -1000.f, -1000.f });
	}

	if (No->collision->Point2BoxCollision(cursor3, No->mesh))
	{
		No_p->mesh->setTransform(No->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			quitCheck = false;
			realQuit = false;
			//STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST3);
			QuitAsk->mesh->setTransform({ -1000.f, -1000.f });
			QuitAskBack->mesh->setTransform({ -1000.f, -1000.f });
			Yes->mesh->setTransform({ -1000.f, -1000.f });
			No->mesh->setTransform({ -1000.f, -1000.f });
		}
	}
	else
	{
		No_p->mesh->setTransform({ -1000.f, -1000.f });
	}
	
	if (mPooPoo.IsFinish() == false)
	{
		pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
	}

	if (quitCheck == true && realQuit == true)
	{
		glfwTerminate();
		ENGINE->Quit();
	}
	
	Vector2<float> pooCoor = pooCharacter->mesh->GetTransform();
	Vector2<float> endCoor = endPuzzle->mesh->GetTransform();

	if(pooCoor.x == endCoor.x && pooCoor.y == endCoor.y)
	{
		if(skip == false)
		{
			this->sound->Play("assets\\yeah.wav", 1);
		}
		skip = true;
		win->mesh->setTransform({ 0,0 });
		
		chekNext = 0;

		conecTcheck1 = false;
		conecTcheck2 = false;
		conecTcheck3 = false;

		degree2 = 0;
		degree2_2 = 0;
		degree2_3 = 0;

		blCheck1 = false;
		blCheck1_2 = false;

		blCheck2 = false;
		blCheck2_2 = false;
	}

	if(skip == true)
	{
		if (lastTime - firstTime > 2)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST4);
		}
	}

	/*se3.Update();
	playSE3.Update();*/

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground3);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart3);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd3);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3_2);
	movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3_1);
	movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3_2);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton3);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear3);
	Levelsel->mesh->Update(mShader2.GetShaderHandler(), LevelPage);
	Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), LevelPage_pressed);
	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI3);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI3);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI3);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI3);
	restartUI_p->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI3p);
	playUI_p->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI3p);
	quitUI_p->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI3p);
	optionUI_p->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI3p);
	levelImage->mesh->Update(mShader2.GetShaderHandler(), levelTexture);
	numberImage->mesh->Update(mShader2.GetShaderHandler(), numberTexture);

	pooCharacter->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton3);

	win->mesh->Update(mShader.GetShaderHandler(), textureWin);
	fail->mesh->Update(mShader2.GetShaderHandler(), textureFail);
	
	QuitAskBack->mesh->Update(mShader.GetShaderHandler(), textureIdQuitAskBack);
	QuitAsk->mesh->Update(mShader.GetShaderHandler(), textureIdQuitAsk);
	Yes->mesh->Update(mShader.GetShaderHandler(), textureIdYes);
	No->mesh->Update(mShader.GetShaderHandler(), textureIdNo);
	Yes_p->mesh->Update(mShader.GetShaderHandler(), textureIdYes_p);
	No_p->mesh->Update(mShader.GetShaderHandler(), textureIdNo_p);
	if ( mInput.IsPressed(KEY::A) == true)
	{
		INPUT->setInput(KEY::A);
		STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST4);
	}

	if (mInput.IsPressed(KEY::ESCAPE) == true) {
		INPUT->setInput(KEY::ESCAPE);
		STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
	}

	
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level3::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	//ENGINE->Quit();

	/*se3.Free();
	playSE3.Free();*/

	OBJECT_FACTORY->DestroyAllObjects();
}


