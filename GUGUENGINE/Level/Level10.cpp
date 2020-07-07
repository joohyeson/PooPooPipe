
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level10.h"
#include "../GUGUENGINE/Sound.h"


void Level10::Init()
{
	STATE_MANAGER->setCurrentLV(0);
	skip = false;
	firstTime = glfwGetTime();


	rotTime.setRotate(30);
	rotrot2 = true;
	chekNext8 = 0;

	conecTcheck8_1 = false;
	conecTcheck8_2 = false;
	conecTcheck8_3 = false;
	conecTcheck8_4 = false;
	conecTcheck8_5 = false;
	conecTcheck8_6 = false;
	conecTcheck8_7 = false;
	conecTcheck8_8 = false;
	conecTcheck8_9 = false;

	degree8 = 0;
	degree8_2 = DegreeToRadian(60.f);
	degree8_3 = DegreeToRadian(180.f);
	degree8_4 = 0;
	degree8_5 = 0;
	degree8_6 = 0;;
	degree8_7 = DegreeToRadian(-240.f);
	degree8_8 = 0;
	degree8_9 = DegreeToRadian(180.f);
	mini = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 330.f, 150.f });
	texturemini = TEXTURE->CreateTexture("assets\\mini.png", 0);
	mini->mesh->InitializeTextureMesh(500.f, 500.f);

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	textureBackground8 = TEXTURE->CreateTexture("assets\\background2.png", 0);	

	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI8 = TEXTURE->CreateTexture("assets\\playUI.png", 0);

	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureQuitUI8 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 713.5f, 0.f });
	optionUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI8 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->InitializeTextureMesh(173.f, 200.f);
	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	fail->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	textureFail = TEXTURE->CreateTexture("assets\\failScreen.png", 0);
	textureRestartUI8 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);


	texureIdLine8 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack8 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve8 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree8 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV8 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart8 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd8 = TEXTURE->CreateTexture("assets\\imageStart2.png", 0);

	texureIdLine8_2 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve8_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV8_2 = TEXTURE->CreateTexture("assets\\image4_11.png", 0);

	textureIdAuto1 = TEXTURE->CreateTexture("assets\\image_auto1.png", 0);
	textureIdAuto2 = TEXTURE->CreateTexture("assets\\image_auto2.png", 0);

	LevelPage = TEXTURE->CreateTexture("assets\\levelButton.png", 0);
	LevelPage_pressed = TEXTURE->CreateTexture("assets\\levelButton_2.png", 0);
	texureIdbutton8 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear8 = TEXTURE->CreateTexture("assets\\clear.png", 0);

	levelTexture = TEXTURE->CreateTexture("assets\\level.png", 0);
	numberTexture = TEXTURE->CreateTexture("assets\\07.png", 0);
	textureLeft = TEXTURE->CreateTexture("assets\\left_turn.png", 0);

	textureLeftNumber0 = TEXTURE->CreateTexture("assets\\00.png", 0);
	textureLeftNumber1 = TEXTURE->CreateTexture("assets\\01.png", 0);
	textureLeftNumber2 = TEXTURE->CreateTexture("assets\\02.png", 0);
	textureLeftNumber3 = TEXTURE->CreateTexture("assets\\03.png", 0);
	textureLeftNumber4 = TEXTURE->CreateTexture("assets\\04.png", 0);
	textureLeftNumber5 = TEXTURE->CreateTexture("assets\\05.png", 0);
	textureLeftNumber6 = TEXTURE->CreateTexture("assets\\06.png", 0);
	textureLeftNumber7 = TEXTURE->CreateTexture("assets\\07.png", 0);
	textureLeftNumber8 = TEXTURE->CreateTexture("assets\\8.png", 0);
	textureLeftNumber9 = TEXTURE->CreateTexture("assets\\9.png", 0);

	textureLeftNumberTen0 = TEXTURE->CreateTexture("assets\\00.png", 0);
	textureLeftNumberTen1 = TEXTURE->CreateTexture("assets\\01.png", 0);
	textureLeftNumberTen2 = TEXTURE->CreateTexture("assets\\02.png", 0);
	textureLeftNumberTen3 = TEXTURE->CreateTexture("assets\\03.png", 0);
	textureLeftNumberTen4 = TEXTURE->CreateTexture("assets\\04.png", 0);
	textureLeftNumberTen5 = TEXTURE->CreateTexture("assets\\05.png", 0);

	leftCount = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 250, 450.f - 20.f });
	leftCount->mesh->InitializeTextureMesh(250.f, 80.f);

	leftnumber = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 430, 450.f - 20.f });
	leftnumber->mesh->InitializeTextureMesh(80.f, 100.f);

	leftnumberTen = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 400, 450.f - 20.f });
	leftnumberTen->mesh->InitializeTextureMesh(80.f, 100.f);


	mShader2.BuildTextureShader();

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 280.f + 50.f }, 120.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, -200.f - 62.f }, -120.f);
	endPuzzle->pipe->SetDirection(true, false, false, true, false, false);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle,  { 72.f - 430.f, 280.f + 50.f });
	puzzle1->pipe->SetDirection(true, false, false, true, false, false);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 280.f + 50.f }, 60.f);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, -60.f);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, 160.f + 22.f },180.f);
	puzzle4->pipe->SetDirection(true, false, true, false, false, false);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f - 465.f, 40.f - 5.f });
	puzzle5->pipe->SetDirection(true, false, false, true, false, false);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 40.f - 5.f });
	puzzle6->pipe->SetDirection(false, false, false, false, true, true);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f });
	puzzle7->pipe->SetDirection(false, false, false, false, true, true);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f }, 180.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 448.f, -80.f - 32.f });

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, -80.f - 32.f }, -240.f);
	puzzle10->pipe->SetDirection(false, false, true, true, false, false);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 240.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, 180.f);
	puzzle12->pipe->SetDirection(true, false, true, false, false, false);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 208.f - 393.f, 280.f + 50.f });

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 276.f - 376.f, 160.f + 22.f }, -120);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 208.f - 393.f, 40.f - 5.f });

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, -80.f - 32.f }, 180.f);
	puzzle16->pipe->SetDirection(false, true, true, false, false, false);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f });
	puzzle17->pipe->SetDirection(false, false, false, false, true, true);

	puzzle18 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 482.f, 160.f + 22.f });

	puzzle19 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, 160.f + 22.f }, 60.f);
	puzzle19->pipe->SetDirection(false, false, false, true, true, false);

	puzzle20 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, -80.0f - 32.f }, -60.f);
	puzzle20->pipe->SetDirection(false, false, false, true, false, true);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850, 450.f - 20.f });

	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);

	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);

	playUI_p = OBJECT_FACTORY->CreateEmptyObject();
	playUI_p->AddComponent(new Mesh());
	playUI_p->Init();
	playUI_p->mesh->setTransform({ 1713.5f, 300.f });
	playUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI3p = TEXTURE->CreateTexture("assets\\playUI_2.png", 0);


	quitUI_p = OBJECT_FACTORY->CreateEmptyObject();
	quitUI_p->AddComponent(new Mesh());
	quitUI_p->Init();

	quitUI_p->mesh->setTransform({ 1800.f, 150.f });
	quitUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureQuitUI3p = TEXTURE->CreateTexture("assets\\quitUI_2.png", 0);


	optionUI_p = OBJECT_FACTORY->CreateEmptyObject();
	optionUI_p->AddComponent(new Mesh());
	optionUI_p->Init();
	optionUI_p->mesh->setTransform({ 1713.5f, 0.f });
	optionUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI3p = TEXTURE->CreateTexture("assets\\optionUI_2.png", 0);


	restartUI_p = OBJECT_FACTORY->CreateEmptyObject();
	restartUI_p->AddComponent(new Mesh());
	restartUI_p->Init();
	restartUI_p->mesh->setTransform({ 1800.f, -150.f });
	restartUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureRestartUI3p = TEXTURE->CreateTexture("assets\\restartUI_2.png", 0);


	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);


	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::S_, puzzle13->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SW_, puzzle4->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SE_, puzzle19->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SW_, puzzle5->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SE_, puzzle6->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, puzzle20->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::NE_, puzzle17->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle11->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::N_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::S_, DirAngle::SE_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level10::Update()
{
	STATE_MANAGER->setCurrentLV(7);
	lastTime = glfwGetTime();

	if (mInput.IsPressed(KEY::F) == true)
	{
		APPLICATION->SetFullScreen();
		mInput.setInput(KEY::F);
	}
	cursor8 = mInput.Cursor;

	if (Levelsel->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, Levelsel->mesh) == true)
	{
		if (UI[4] == false)
		{
			UI[4] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		Levelsel_pressed->mesh->setTransform(Levelsel->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			std::cout << "check" << std::endl;
			STATE_MANAGER->ChangeLevel(GameLevels::LV_SELECT);
		}
	}
	else
	{
		UI[4] = false;
		Levelsel_pressed->mesh->setTransform({ 1800.f, -300.f });
	}

	if (rotTime.getLimitTime() == 0)
	{
		rotrot2 = false;
		fail->mesh->setTransform({ 0,0 });
		STATE_MANAGER->ReloadState();

		std::cout << "rotation limit!!!" << std::endl;
	}
	if (rotrot2)
	{
		if (puzzle1->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle1->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[0] = true;
			}
			if (rot[0] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle1->pipe->Update();

					degree8 += static_cast<float>(DegreeToRadian(60.f));
					puzzle1->mesh->setRotation(degree8);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);
					
					rot[0] = false;
				}
			}
		}

		if (puzzle19->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle19->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[1] = true;
			}
			if (rot[1] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle19->pipe->Update();

					degree8_2 += static_cast<float>(DegreeToRadian(60.f));
					puzzle19->mesh->setRotation(degree8_2);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);
					
					rot[1] = false;
				}
			}
		}


		if (puzzle4->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle4->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[2] = true;
			}
			if (rot[2] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle4->pipe->Update();
					puzzle16->pipe->Update();

					degree8_3 += static_cast<float>(DegreeToRadian(60.f));
					puzzle4->mesh->setRotation(degree8_3);
					puzzle16->mesh->setRotation(degree8_3);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);
					
					rot[2] = false;
				}
			}
		}


		if (puzzle7->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle7->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[3] = true;
			}
			if (rot[3] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle7->pipe->Update();

					degree8_4 += static_cast<float>(DegreeToRadian(60.f));
					puzzle7->mesh->setRotation(degree8_4);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);
					
					rot[3] = false;
				}
			}
		}

		if (puzzle6->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle6->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[4] = true;
			}
			if (rot[4] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle6->pipe->Update();

					degree8_5 += static_cast<float>(DegreeToRadian(60.f));
					puzzle6->mesh->setRotation(degree8_5);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					rot[4] = false;
				}
			}
		}


		if (puzzle5->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle5->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[5] = true;
			}
			if (rot[5] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle5->pipe->Update();

					degree8_6 += static_cast<float>(DegreeToRadian(60.f));
					puzzle5->mesh->setRotation(degree8_6);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					rot[5] = false;
				}
			}
		}

		if (puzzle10->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle10->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[6] = true;
			}
			if (rot[6] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle10->pipe->Update();

					degree8_7 += static_cast<float>(DegreeToRadian(60.f));
					puzzle10->mesh->setRotation(degree8_7);

					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);


					rot[6] = false;
				}
			}
		}

		if (puzzle16->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle16->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[7] = true;
			}
			if (rot[7] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle16->pipe->Update();
					puzzle4->pipe->Update();

					degree8_3 += static_cast<float>(DegreeToRadian(60.f));
					puzzle16->mesh->setRotation(degree8_3);
					puzzle4->mesh->setRotation(degree8_3);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);


					rot[7] = false;
				}
			}
		}

		if (puzzle17->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle17->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[8] = true;
			}
			if (rot[8] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle17->pipe->Update();

					degree8_8 += static_cast<float>(DegreeToRadian(60.f));
					puzzle17->mesh->setRotation(degree8_8);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					rot[8] = false;
				}
			}
		}

		if (puzzle12->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle12->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[9] = true;
			}
			if (rot[9] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle12->pipe->Update();

					degree8_9 += static_cast<float>(DegreeToRadian(60.f));
					puzzle12->mesh->setRotation(degree8_9);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					rot[9] = false;
				}
			}
		}

		if (puzzle1->pipe->GetDirValue(E) && puzzle1->pipe->GetDirValue(W))
		{
			conecTcheck8_1 = true;
		}
		else
		{
			conecTcheck8_1 = false;
		}

		if (puzzle4->pipe->GetDirValue(NE)&& (puzzle4->pipe->GetDirValue(W) == puzzle19->pipe->GetDirValue(E)))
		{

			conecTcheck8_2 = true;
		}
		else
		{
			conecTcheck8_2 = false;
		}

		if ((puzzle19->pipe->GetDirValue(E) == puzzle4->pipe->GetDirValue(W)) && (puzzle19->pipe->GetDirValue(SE) == puzzle7->pipe->GetDirValue(NW)))
		{

			conecTcheck8_3 = true;
		}
		else
		{
			conecTcheck8_3 = false;
		}

		if ((puzzle7->pipe->GetDirValue(NW) == puzzle19->pipe->GetDirValue(SE)) && (puzzle7->pipe->GetDirValue(W) == puzzle5->pipe->GetDirValue(E)))
		{
			conecTcheck8_4 = true;

		}
		else
		{
			conecTcheck8_4 = false;
		}

		if ((puzzle5->pipe->GetDirValue(E) == puzzle7->pipe->GetDirValue(W)) && (puzzle5->pipe->GetDirValue(W) == puzzle6->pipe->GetDirValue(E)))
		{
			conecTcheck8_9 = true;

		}
		else
		{
			conecTcheck8_9 = false;
		}


		if ((puzzle5->pipe->GetDirValue(W) == puzzle6->pipe->GetDirValue(E)) && puzzle6->pipe->GetDirValue(SE))
		{
			conecTcheck8_5 = true;
		}
		else
		{
			conecTcheck8_5 = false;
		}

		if (puzzle17->pipe->GetDirValue(NE) && puzzle17->pipe->GetDirValue(E))
		{
			conecTcheck8_6 = true;

		}
		else
		{
			conecTcheck8_6 = false;
		}

		if (puzzle12->pipe->GetDirValue(W) && (puzzle12->pipe->GetDirValue(NE) == puzzle10->pipe->GetDirValue(SW)))
		{
			conecTcheck8_7 = true;

		}
		else
		{
			conecTcheck8_7 = false;
		}

		if ((puzzle12->pipe->GetDirValue(NE) == puzzle10->pipe->GetDirValue(SW)) && (puzzle10->pipe->GetDirValue(SE) == endPuzzle->pipe->GetDirValue(NW)))
		{
			conecTcheck8_8 = true;

		}
		else
		{
			conecTcheck8_8 = false;
		}
	}
	if (playUI->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, playUI->mesh))
	{
		if (UI[0] == false)
		{
			UI[0] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		playUI_p->mesh->setTransform(playUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			poopooCheck = true;

		}
	}
	else
	{
		UI[0] = false;
		playUI_p->mesh->setTransform({ 1000.f, 1000.f });
		connectMove8 = 0;
	}
	if (poopooCheck == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{

			if (conecTcheck8_1 && conecTcheck8_2 && conecTcheck8_3 && conecTcheck8_4 && conecTcheck8_5 && conecTcheck8_6 && conecTcheck8_7 && conecTcheck8_8 && conecTcheck8_9)
			{
				clear->mesh->setTransform({ 350.f, -240.f });
				chekNext8 = 1;
				mPooPoo.SetIsSuccess(true);

				std::cout << "clear" << std::endl;
				connectMove8 = 0;

				this->sound->Play("assets\\flushing.wav", 1);

				
				poopooCheck = false;
			}
			else {
				fail->mesh->setTransform({ 0,0 });
				poopooCheck = false;
			}
		}
	}

	if (fail->collision->Point2BoxCollision({ cursor8.x,cursor8.y }, fail->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			fail->mesh->setTransform({ -2000.f,-2000.f });
			if (lastTime - firstTime > 3)
			{
				STATE_MANAGER->ReloadState();
			}
		}
	}

	if (restartUI->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, restartUI->mesh))
	{
		if (UI[1] == false)
		{
			UI[1] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		restartUI_p->mesh->setTransform(restartUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			STATE_MANAGER->ReloadState();
			INPUT->setInput(KEY::LEFT);
		}
	}
	else
	{
		UI[1] = false;
		restartUI_p->mesh->setTransform({ 1700.f, 1000.f });
	}

	if (optionUI->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, optionUI->mesh))
	{
		if (UI[2] == false)
		{
			UI[2] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		optionUI_p->mesh->setTransform(optionUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
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


	if (quitUI->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, quitUI->mesh))
	{
		if (UI[3] == false)
		{
			UI[3] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		quitUI_p->mesh->setTransform(quitUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			glfwTerminate();
		}
	}
	else
	{
		UI[3] = false;
		quitUI_p->mesh->setTransform({ 1000.f, 1000.f });
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
	}
	
	if(skip == true)
	{
		if(lastTime - firstTime > 2)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST11);
		}
	}
	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground8);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8_2);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), textureIdAuto1);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8_2);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), textureIdAuto2);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);

	puzzle18->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle19->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);
	puzzle20->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart8);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd8);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton8);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear8);
	Levelsel->mesh->Update(mShader2.GetShaderHandler(), LevelPage);
	Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), LevelPage_pressed);
	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI8);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI8);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI8);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI8);

	levelImage->mesh->Update(mShader2.GetShaderHandler(), levelTexture);
	numberImage->mesh->Update(mShader2.GetShaderHandler(), numberTexture);
	leftCount->mesh->Update(mShader2.GetShaderHandler(), textureLeft);


	restartUI_p->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI3p);
	playUI_p->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI3p);
	quitUI_p->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI3p);
	optionUI_p->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI3p);

	mini->mesh->Update(mShader2.GetShaderHandler(), texturemini);

	pooCharacter->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton8);

	

	switch (rotTime.getLimitTime() / 10)
	{
	case 0:
		leftnumberTen->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumberTen0);
		break;
	case 1:
		leftnumberTen->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumberTen1);
		break;
	case 2:
		leftnumberTen->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumberTen2);
		break;
	case 3:
		leftnumberTen->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumberTen3);
		break;
	case 4:
		leftnumberTen->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumberTen4);
		break;
	case 5:
		leftnumberTen->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumberTen5);
		break;
	}

	switch (rotTime.getLimitTime() % 10)
	{
	case 0:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber0);
		break;
	case 1:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber1);
		break;
	case 2:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber2);
		break;
	case 3:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber3);
		break;
	case 4:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber4);
		break;
	case 5:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber5);
		break;
	case 6:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber6);
		break;
	case 7:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber7);
		break;
	case 8:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber8);
		break;
	case 9:
		leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber9);
		break;
	}

	win->mesh->Update(mShader2.GetShaderHandler(), textureWin);
	fail->mesh->Update(mShader2.GetShaderHandler(), textureFail);

	if (mPooPoo.IsFinish() == false)
	{
		pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
	}

	if (mInput.IsPressed(KEY::A))
	{
		INPUT->setInput(KEY::A);
		STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST11);
	}

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level10::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
