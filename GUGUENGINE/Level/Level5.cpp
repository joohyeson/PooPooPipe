
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level5.h"
#include "../GUGUENGINE/Sound.h"
//
//Sound se5;
//Sound playSE5;

void Level5::Init()
{
	STATE_MANAGER->setCurrentLV(0);
	skip = false;
	transition = 0.f;

	chekNext5 = 0;

	conecTcheck5_1 = false;
	conecTcheck5_2 = false;
	conecTcheck5_3 = false;

	degree5 = 0;
	degree5_2 = 0;
	degree5_3 = 0;

	blCheck5 = false;
	blCheck5_2 = false;
	blCheck5_3 = false;

	blCheck6 = false;
	blCheck6_2 = false;
	blCheck6_3 = false;

	blCheck7 = false;
	blCheck7_2 = false;
	blCheck7_3 = false;

	movePuzzleCheck5 = true;

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground5 = TEXTURE->CreateTexture("assets\\background2.png", 0);

	mini = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 330.f, 200.f });
	texturemini = TEXTURE->CreateTexture("assets\\mini.png", 0);
	mini->mesh->InitializeTextureMesh(500.f, 500.f);

	
	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI5 = TEXTURE->CreateTexture("assets\\playUI.png", 0);

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
	textureQuitUI5 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);

	quitUI_p = OBJECT_FACTORY->CreateEmptyObject();
	quitUI_p->AddComponent(new Mesh());
	quitUI_p->Init();

	quitUI_p->mesh->setTransform({ 1800.f, 150.f });
	quitUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureQuitUI3p = TEXTURE->CreateTexture("assets\\quitUI_2.png", 0);
	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);
	win->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);

	
	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 713.5f, 0.f });
	optionUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI5 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);

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

	restartUI_p = OBJECT_FACTORY->CreateEmptyObject();
	restartUI_p->AddComponent(new Mesh());
	restartUI_p->Init();
	restartUI_p->mesh->setTransform({ 1800.f, -150.f });
	restartUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureRestartUI3p = TEXTURE->CreateTexture("assets\\restartUI_2.png", 0);

	textureRestartUI5 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);
	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	fail->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureFail = TEXTURE->CreateTexture("assets\\failScreen.png", 0);

	texureIdLine5 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack5 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve5 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree5 = TEXTURE->CreateTexture("assets\\image3.png", 0);

	LevelPage = TEXTURE->CreateTexture("assets\\levelButton.png", 0);
	LevelPage_pressed = TEXTURE->CreateTexture("assets\\levelButton_2.png", 0);

	textureIdMove5 = TEXTURE->CreateTexture("assets\\image5.png", 0);

	texureIdV5 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart5 = TEXTURE->CreateTexture("assets\\imageStart2.png", 0);
	texureIdEnd5 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine5_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve5_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	texureIdbutton5 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear5 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace5 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	
	/*se5.Init();
	se5.LoadSE("assets\\coin.mp3");*/

	/*
	playSE5.Init();
	playSE5.LoadSE("assets\\flushing.wav");
	*/

	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f - 250.f, 280.f });
	movePuzzle->pipe->SetDirection(false, false, false, true, false, true);

	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f - 250.f, 120.f });
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);

	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f - 250.f, 0.0f });
	movePuzzle3->pipe->SetDirection(false, false, false, true, false, true);

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 280.f + 50.f });
	startPuzzle->pipe->SetDirection(true, false, false, true, false, false);
	startPuzzle->mesh->setRotation(DegreeToRadian(-120.f));

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, -300);
	endPuzzle->pipe->SetDirection(false, false, false, true, false, true);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 280.f + 50.f }, 60.f);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 72.f - 430.f, 280.f + 50.f });

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 180.f);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 415.f, 160.f + 22.f });

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f }, 60.f);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f }, 0);//0
	puzzle7->pipe->SetDirection(true, false, true, false, false, true);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f });

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, -80.f - 32.f }, 180.f);
	puzzle9->pipe->SetDirection(false, false, true, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 415.f, -80.f - 32.f }, -60.f);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f });

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	puzzle12->pipe->SetDirection(false, true, true, false, false, false);

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -132.f - 482.f, 160.f + 22.f });

	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 4.0f - 448.f, 160.f + 22.f });

	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -132.f - 482.f, -80.0f - 32.f });

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	button->mesh->InitializeTextureMesh(300.f, 300.f);

	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	clear->mesh->InitializeTextureMesh(380.f, 150.f);

	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -20.0f, -340.f - 20.f });
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 830, 450.f - 20.f });
	levelTexture = TEXTURE->CreateTexture("assets\\level.png", 0);
	numberTexture = TEXTURE->CreateTexture("assets\\05.png", 0);
	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);
	
	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, blackPuzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::NE_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle11->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, endPuzzle->mesh->GetTransform());


	mInput.InitCallback(APPLICATION->getMyWindow());

}

void Level5::Update()
{
	STATE_MANAGER->setCurrentLV(5);

	cursor5 = mInput.Cursor;

	/*se5.Update();
	playSE5.Update();*/


	if (Levelsel->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, Levelsel->mesh) == true)
	{
		if (UI[4] == false)
		{
			UI[4] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		Levelsel_pressed->mesh->setTransform(Levelsel->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			INPUT->setInput(KEY::LEFT);
			chekNext5 = 0;

			conecTcheck5_1 = false;
			conecTcheck5_2 = false;
			conecTcheck5_3 = false;

			degree5 = 0;
			degree5_2 = 0;
			degree5_3 = 0;

			blCheck5 = false;
			blCheck5_2 = false;
			blCheck5_3 = false;

			blCheck6 = false;
			blCheck6_2 = false;
			blCheck6_3 = false;

			blCheck7 = false;
			blCheck7_2 = false;
			blCheck7_3 = false;

			std::cout << "check" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_SELECT);
		}
	}
	else
	{
		UI[4] = false;
		Levelsel_pressed->mesh->setTransform({ 1800.f, -300.f });
	}
	if (movePuzzle->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, movePuzzle->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[1] && !movable[2])
		{
			movePuzzle->mesh->setTransform({ cursor5.x, cursor5.y });
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

				degree5 += static_cast<float>(DegreeToRadian(60.f));
				movePuzzle->mesh->setRotation(degree5);

				this->sound->Play("assets\\coin.mp3", 1);

				//se5.Play(1);
				//se5.SetVolume(0.5f);
				//se5.SetLoopCount(1);
				rot[0] = false;
			}
		}
	}
	else
	{
		movable[0] = false;
	}

	if (blCheck5)
	{
		if (blCheck6_2)
		{
			if ((movePuzzle->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle->pipe->GetDirValue(E) == movePuzzle2->pipe->GetDirValue(W)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_1 = true;
			}
			else
			{
				conecTcheck5_1 = false;
				//std::cout << "Not connect\n";
			}
		}
		else if (blCheck7_2)
		{
			if ((movePuzzle->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle->pipe->GetDirValue(E) == movePuzzle3->pipe->GetDirValue(W)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_1 = true;
			}
			else
			{
				conecTcheck5_1 = false;
				//std::cout << "Not connect\n";
			}
		}
	}
	if (blCheck5_2)
	{
		if (blCheck6)
		{
			if ((movePuzzle->pipe->GetDirValue(W) == movePuzzle2->pipe->GetDirValue(E)) && (movePuzzle->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_1 = true;
			}
			else
			{
				conecTcheck5_1 = false;
				//std::cout << "Not connect\n";
			}
		}
		else if (blCheck7)
		{
			if ((movePuzzle->pipe->GetDirValue(W) == movePuzzle3->pipe->GetDirValue(E)) && (movePuzzle->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_1 = true;
			}
			else
			{
				conecTcheck5_1 = false;
				//std::cout << "Not connect\n";
			}
		}
	}
	if (blCheck5_3)
	{
		if ((movePuzzle->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (movePuzzle->pipe->GetDirValue(SW) == puzzle12->pipe->GetDirValue(NE)))
		{
			conecTcheck5_1 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck5_1 = false;
			//std::cout << "Not connect\n";
		}
	}

	if (movePuzzle2->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, movePuzzle2->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[2])
		{
			movePuzzle2->mesh->setTransform({ cursor5.x, cursor5.y });
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

				degree5_2 += static_cast<float>(DegreeToRadian(60.f));
				movePuzzle2->mesh->setRotation(degree5_2);

				this->sound->Play("assets\\coin.mp3", 1);
				//se5.Play(1);
				//se5.SetVolume(0.5f);
				//se5.SetLoopCount(1);
				rot[1] = false;
			}
		}
	}
	else
	{
		movable[1] = false;
	}

	if (blCheck6)
	{
		if (blCheck5_2)
		{
			if ((movePuzzle2->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(E) == movePuzzle->pipe->GetDirValue(W)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_2 = true;
			}
			else
			{
				conecTcheck5_2 = false;
				//std::cout << "Not connect\n";
			}
		}
		if (blCheck7_2)
		{
			if ((movePuzzle2->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(E) == movePuzzle3->pipe->GetDirValue(W)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_2 = true;
			}
			else
			{
				conecTcheck5_2 = false;
				//std::cout << "Not connect\n";
			}
		}
	}
	if (blCheck6_2)
	{
		if (blCheck5)
		{
			if ((movePuzzle2->pipe->GetDirValue(W) == movePuzzle->pipe->GetDirValue(E)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_2 = true;
			}
			else
			{
				conecTcheck5_2 = false;
				//std::cout << "Not connect\n";
			}
		}
		if (blCheck7)
		{
			if ((movePuzzle2->pipe->GetDirValue(W) == movePuzzle3->pipe->GetDirValue(E)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_2 = true;
			}
			else
			{
				conecTcheck5_2 = false;
				//std::cout << "Not connect\n";
			}
		}
	}
	
	if (blCheck6_3)
	{
		if ((movePuzzle2->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (movePuzzle2->pipe->GetDirValue(SW) == puzzle12->pipe->GetDirValue(NE)))
		{
			conecTcheck5_2 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck5_2 = false;
			//std::cout << "Not connect\n";
		}
	}

	if (movePuzzle3->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, movePuzzle3->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1])
		{
			movePuzzle3->mesh->setTransform({ cursor5.x, cursor5.y });
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
				{
					movePuzzle3->pipe->Update();
					degree5_3 += static_cast<float>(DegreeToRadian(60.f));
					movePuzzle3->mesh->setRotation(degree5_3);

					this->sound->Play("assets\\coin.mp3", 1);
					//se5.Play(1);
					//se5.SetVolume(0.5f);
					//se5.SetLoopCount(1);
					rot[2] = false;
				}
			}
		}
	}
	else
	{
		movable[2] = false;
	}
	if (blCheck7)
	{
		if (blCheck5_2)
		{
			if ((movePuzzle3->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle3->pipe->GetDirValue(E) == movePuzzle->pipe->GetDirValue(W)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_3 = true;
			}
			else
			{
				conecTcheck5_3 = false;
				//std::cout << "Not connect\n";
			}
		}
		else if (blCheck6_2)
		{
			if ((movePuzzle3->pipe->GetDirValue(NE) == startPuzzle->pipe->GetDirValue(SW)) && (movePuzzle3->pipe->GetDirValue(E) == movePuzzle2->pipe->GetDirValue(W)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_3 = true;
			}
			else
			{
				conecTcheck5_3 = false;
				//std::cout << "Not connect\n";
			}
		}
	}
	if (blCheck7_2)
	{
		if (blCheck5)
		{
			if ((movePuzzle3->pipe->GetDirValue(W) == movePuzzle->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_3 = true;
			}
			else
			{
				conecTcheck5_3 = false;
				//std::cout << "Not connect\n";
			}
		}
		else if (blCheck6)
		{
			if ((movePuzzle3->pipe->GetDirValue(W) == movePuzzle2->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
			{
				//std::cout << "pipe connect\n";
				conecTcheck5_3 = true;
			}
			else
			{
				conecTcheck5_3 = false;
				//std::cout << "Not connect\n";
			}
		}
	}
	if (blCheck7_3)
	{
		if ((movePuzzle3->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (movePuzzle3->pipe->GetDirValue(SW) == puzzle12->pipe->GetDirValue(NE)))
		{
			conecTcheck5_3 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck5_3 = false;
			//std::cout << "Not connect\n";
		}
	}

	//
	if (movable[0] == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh)))
			{
				{
					if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						movePuzzle->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
						movable[0] = false;
						blCheck5 = true;
						blCheck5_2 = false;
						blCheck5_3 = false;
					}
					else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						movePuzzle->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
						movable[0] = false;
						blCheck5 = false;
						blCheck5_2 = true;
						blCheck5_3 = false;
					}
					else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh))
					{
						movePuzzle->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
						movable[0] = false;
						blCheck5 = false;
						blCheck5_2 = false;
						blCheck5_3 = true;
					}
				}
			}
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
					blCheck6 = true;
					blCheck6_2 = false;
					blCheck6_3 = false;
				}
				else if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh))
				{
					movePuzzle2->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					movable[1] = false;
					blCheck6 = false;
					blCheck6_2 = true;
					blCheck6_3 = false;
				}
				else if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh))
				{
					movePuzzle2->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					movable[1] = false;
					blCheck6 = false;
					blCheck6_2 = false;
					blCheck6_3 = true;
				}
			}
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
					blCheck7 = true;
					blCheck7_2 = false;
					blCheck7_3 = false;
				}
				else if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					movable[2] = false;
					blCheck7 = false;
					blCheck7_2 = true;
					blCheck7_3 = false;
				}
				else if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					movable[2] = false;
					blCheck7 = false;
					blCheck7_2 = false;
					blCheck7_3 = true;
				}
			}
		}
	}


	if (playUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, playUI->mesh))
	{
		if (UI[0] == false)
		{
			UI[0] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		std::cout << "1: " << conecTcheck5_1 << "2: " << conecTcheck5_2 << "3: " << conecTcheck5_2 << std::endl;
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

		playUI_p->mesh->setTransform({ 1000.f, 1000.f });

		connectMove5 = 0;
	}
	
	if (poopooCheck == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{


			if (movePuzzleCheck5)
			{
				puzzle7->pipe->Update();
				puzzle7->mesh->setRotation(static_cast<float>(DegreeToRadian(300.f)));
				puzzle7->pipe->SetDirection(true, true, false, true, false, false);

				this->sound->Play("assets\\coin.mp3", 1);
				//se5.Play(1);
				//se5.SetVolume(0.5f);
				//se5.SetLoopCount(1);

				movePuzzleCheck5 = false;
			}
			
			if (conecTcheck5_1 && conecTcheck5_2 && conecTcheck5_3)
			{
				std::cout << "if 3" << std::endl;
				clear->mesh->setTransform({ 350.f, -240.f });
				chekNext5 = 1;
				std::cout << "clear" << std::endl;
				mPooPoo.SetIsSuccess(true);
				connectMove5 = 0;

				this->sound->Play("assets\\flushing.wav", 1);
				//playSE5.Play(1);
				//playSE5.SetVolume(0.5f);
				//playSE5.SetLoopCount(1);

				poopooCheck = false;
			}
			else {
				fail->mesh->setTransform({ 0,0 });
				poopooCheck = false;
			}
		}
	}
	
	if (fail->collision->Point2BoxCollision({ cursor5.x,cursor5.y }, fail->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			fail->mesh->setTransform({ -2000.f,-2000.f });
			STATE_MANAGER->ReloadState();

		}
	}
	
	Vector2<float> pooCoor = pooCharacter->mesh->GetTransform();
	Vector2<float> endCoor = endPuzzle->mesh->GetTransform();

	if (pooCoor.x == endCoor.x && pooCoor.y == endCoor.y)
	{
		if (skip == false)
		{
			this->sound->Play("assets\\yeah.wav", 1);
		}
		skip = true;
		win->mesh->setTransform({ 0,0 });
		chekNext5 = 0;

		conecTcheck5_1 = false;
		conecTcheck5_2 = false;
		conecTcheck5_3 = false;

		degree5 = 0;
		degree5_2 = 0;
		degree5_3 = 0;

		blCheck5 = false;
		blCheck5_2 = false;
		blCheck5_3 = false;

		blCheck6 = false;
		blCheck6_2 = false;
		blCheck6_3 = false;

		blCheck7 = false;
		blCheck7_2 = false;
		blCheck7_3 = false;
	}

	if(skip == true)
	{
		transition++;
		if(transition > 500.f)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST9);
		}
	}
	if (restartUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, restartUI->mesh))
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


	if (optionUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, optionUI->mesh))
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

			STATE_MANAGER->ChangeLevel(OPTION);
		}
	}
	else
	{
		UI[2] = false;

		optionUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (quitUI->collision->Point2HexagonCollision({ cursor5.x,cursor5.y }, quitUI->mesh))
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

			glfwTerminate();
		}
	}
	else
	{
		UI[3] = false;

		quitUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}

	//se5.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground5);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine5);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5);

	puzzle7->mesh->Update(mShader2.GetShaderHandler(), textureIdMove5);		//a block which it will move when the player presses 'start'

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine5);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdThree5);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdV5);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdThree5);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdV5);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack5);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack5);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack5);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart5);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd5);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5_2);
	movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5_2);
	movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve5_2);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton5);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear5);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace5);
	Levelsel->mesh->Update(mShader2.GetShaderHandler(), LevelPage);
	Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), LevelPage_pressed);
	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI5);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI5);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI5);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI5);
	restartUI_p->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI3p);
	playUI_p->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI3p);
	quitUI_p->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI3p);
	optionUI_p->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI3p);
	levelImage->mesh->Update(mShader2.GetShaderHandler(), levelTexture);
	numberImage->mesh->Update(mShader2.GetShaderHandler(), numberTexture);
	pooCharacter->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton5);
	mini->mesh->Update(mShader2.GetShaderHandler(), texturemini);

	fail->mesh->Update(mShader2.GetShaderHandler(), textureFail);
	win->mesh->Update(mShader2.GetShaderHandler(), textureWin);


	if (mPooPoo.IsFinish() == false)
	{
		pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
		
	}

	if ((mInput.IsPressed(KEY::SPACE) == true && chekNext5 == 1) || mInput.IsPressed(KEY::A) == true)
	{
		INPUT->setInput(KEY::A);
		INPUT->setInput(KEY::SPACE);
		chekNext5 = 0;

		conecTcheck5_1 = false;
		conecTcheck5_2 = false;
		conecTcheck5_3 = false;

		degree5 = 0;
		degree5_2 = 0;
		degree5_3 = 0;

		blCheck5 = false;
		blCheck5_2 = false;
		blCheck5_3 = false;

		blCheck6 = false;
		blCheck6_2 = false;
		blCheck6_3 = false;

		blCheck7 = false;
		blCheck7_2 = false;
		blCheck7_3 = false;

		STATE_MANAGER->ChangeLevel(LV_TEST9);
	}

	if (mInput.IsPressed(KEY::ESCAPE) == true) {
		glfwTerminate();
	}

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level5::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
