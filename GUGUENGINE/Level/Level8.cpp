
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level8.h"
#include "../GUGUENGINE/Sound.h"

//Sound se8;
//Sound playSE8;

void Level8::Init()
{
	STATE_MANAGER->setCurrentLV(0);
	skip = false;
	failS[0] = false;
	failS[1] = false;
	soundCheck = false;
	soundCheck2 = false;
	Nos[0] = false;
	Nos[1] = false;
	Cur[0] = false;
	Cur[1] = false;
	Cur[2] = false;
	checking = false;
	
	QuitAskBack = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	textureIdQuitAskBack = TEXTURE->CreateTexture("assets\\bar1.png", 0);
	QuitAskBack->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

	QuitAsk = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	textureIdQuitAsk = TEXTURE->CreateTexture("assets\\quitcheck.png", 0);
	QuitAsk->mesh->InitializeTextureMesh(700.f, 700.f);

	Yes = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	textureIdYes = TEXTURE->CreateTexture("assets\\yes.png", 0);
	Yes->mesh->InitializeTextureMesh(130.f, 110.f);

	mInput.setInput(KEY::LEFT);

	No = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	textureIdNo = TEXTURE->CreateTexture("assets\\no.png", 0);
	No->mesh->InitializeTextureMesh(130.f, 110.f);

	Yes_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	textureIdYes_p = TEXTURE->CreateTexture("assets\\yes_p.png", 0);
	Yes_p->mesh->InitializeTextureMesh(130.f, 110.f);

	No_p = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	textureIdNo_p = TEXTURE->CreateTexture("assets\\no_p.png", 0);
	No_p->mesh->InitializeTextureMesh(130.f, 110.f);

	quitCheck = false;
	realQuit = false;

	rotTime.setRotate(30);
	rotrot2 = true;
	std::cout << rotTime.getLimitTime() << std::endl;
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
	degree8_2 = 0;
	degree8_3 = 0;
	degree8_4 = 0;
	degree8_5 = 0;
	degree8_6 = 0;
	degree8_7 = 0;

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	textureBackground8 = TEXTURE->CreateTexture("assets\\background1.png", 0);
	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI8 = TEXTURE->CreateTexture("assets\\playUI.png", 0);

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
	textureQuitUI8 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);

	quitUI_p = OBJECT_FACTORY->CreateEmptyObject();
	quitUI_p->AddComponent(new Mesh());
	quitUI_p->Init();

	quitUI_p->mesh->setTransform({ 1800.f, 150.f });
	quitUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureQuitUI3p = TEXTURE->CreateTexture("assets\\quitUI_2.png", 0);


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 713.5f, 0.f });
	optionUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI8 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);

	optionUI_p = OBJECT_FACTORY->CreateEmptyObject();
	optionUI_p->AddComponent(new Mesh());
	optionUI_p->Init();
	optionUI_p->mesh->setTransform({ 1713.5f, 0.f });
	optionUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI3p = TEXTURE->CreateTexture("assets\\optionUI_2.png", 0);

	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureRestartUI8 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);

	restartUI_p = OBJECT_FACTORY->CreateEmptyObject();
	restartUI_p->AddComponent(new Mesh());
	restartUI_p->Init();
	restartUI_p->mesh->setTransform({ 1800.f, -150.f });
	restartUI_p->mesh->InitializeTextureMesh(173.f, 200.f);
	textureRestartUI3p = TEXTURE->CreateTexture("assets\\restartUI_2.png", 0);

	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	fail->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	textureFail = TEXTURE->CreateTexture("assets\\failScreen.png", 0);

	texureIdLine8 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack8 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve8 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree8 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV8 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart8 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd8 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine8_2 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve8_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV8_2 = TEXTURE->CreateTexture("assets\\image4_11.png", 0);
	LevelPage = TEXTURE->CreateTexture("assets\\levelButton.png", 0);
	LevelPage_pressed = TEXTURE->CreateTexture("assets\\levelButton_2.png", 0);


	texureIdbutton8 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear8 = TEXTURE->CreateTexture("assets\\clear.png", 0);

	levelTexture = TEXTURE->CreateTexture("assets\\level.png", 0);
	numberTexture = TEXTURE->CreateTexture("assets\\04.png", 0);
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

	//se8.Init();
	//se8.LoadSE("assets\\coin.mp3");

	//playSE8.Init();
	//playSE8.LoadSE("assets\\flushing.wav");

	mShader2.BuildTextureShader();

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 280.f + 50.f }, 120.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 280.f + 50.f });
	puzzle1->pipe->SetDirection(false, false, false, true, false, true);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f - 465.f, 280.f + 50.f });
	puzzle2->pipe->SetDirection(false, false, false, false, true, true);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -268.f - 519.f, 160.f + 22.f }, 120.f);
	puzzle3->pipe->SetDirection(false, true, false, true, false, false);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, 160.f + 22.f });
	puzzle4->pipe->SetDirection(false, false, false, true, false, true);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f });

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 40.f - 5.f });
	puzzle6->pipe->SetDirection(true, false, false, true, false, false);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f });
	puzzle7->pipe->SetDirection(false, false, false, false, true, true);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f }, 120.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, -80.f - 32.f });
	puzzle9->pipe->SetDirection(false, false, false, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, -80.f - 32.f }, -60.f);
	puzzle10->pipe->SetDirection(true, false, false, false, true, false);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 180.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, 180.f);
	puzzle12->pipe->SetDirection(false, true, true, false, false, false);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 280.f + 50.f });
	puzzle13->pipe->SetDirection(false, false, false, false, true, true);

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, 160.f + 22.f }, -60);
	puzzle14->pipe->SetDirection(false, false, false, true, true, false);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 40.f - 5.f });
	puzzle15->pipe->SetDirection(true, false, false, true, false, false);

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, -80.f - 32.f }, -60.f);
	puzzle16->pipe->SetDirection(true, false, false, false, true, false);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, -200.f - 62.f });
	puzzle17->pipe->SetDirection(false, false, false, true, false, true);

	puzzle18 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, 160.f + 22.f });
	puzzle18->pipe->SetDirection(false, false, false, false, true, true);

	puzzle19 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, 160.f + 22.f }, 60.f);
	puzzle19->pipe->SetDirection(false, false, true, false, false, true);

	puzzle20 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, -80.0f - 32.f });
	puzzle20->pipe->SetDirection(false, false, false, true, false, true);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850, 450.f - 20.f });

	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);

	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);

	mPooPoo.Init();
	mPooPoo2.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::S_, puzzle13->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, puzzle4->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle15->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, puzzle16->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SW_, puzzle17->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::N_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::S_, DirAngle::NW_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SE_, DirAngle::S_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle20->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	mPooPoo2.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::SW_, DirAngle::S_, puzzle13->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::N_, DirAngle::SW_, puzzle4->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::NE_, DirAngle::SW_, puzzle19->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::NE_, DirAngle::N_, puzzle18->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::S_, DirAngle::SW_, puzzle2->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle1->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::N_, DirAngle::SE_, puzzle3->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle6->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::NW_, DirAngle::S_, puzzle20->mesh->GetTransform());
	mPooPoo2.AddAngle(DirAngle::N_, DirAngle::SE_, endPuzzle->mesh->GetTransform());


	mInput.InitCallback(APPLICATION->getMyWindow());

	firstTime = glfwGetTime();

}

void Level8::Update()
{
	STATE_MANAGER->setCurrentLV(4);

	/*se8.Update();
	playSE8.Update();*/

	if (mInput.IsPressed(KEY::F) == true)
	{
		APPLICATION->SetFullScreen();
		mInput.setInput(KEY::F);
	}

	cursor8 = mInput.Cursor;
	if (mInput.IsPressed(KEY::LEFT))
	{
		if (checking == false)
		{
			this->sound->Play("assets\\click.wav", 1);
			checking = true;
		}
	}
	else
	{
		if (checking == true)
		{
			checking = false;
		}
	}
	if (Levelsel->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, Levelsel->mesh) == true)
	{
		if (Nos[0] == false && Nos[1] == false)
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
				degree8_2 = 0;
				degree8_3 = 0;
				degree8_4 = 0;
				degree8_5 = 0;
				degree8_6 = 0;
				degree8_7 = 0;

				std::cout << "check" << std::endl;
				STATE_MANAGER->ChangeLevel(GameLevels::LV_SELECT);
			}
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

		if (failS[1] == false)
		{
			last = 0;
			this->sound->Play("assets\\fart.mp3", 1);
			failS[1] = true;
			first = glfwGetTime();
		}
		last = glfwGetTime();
		if (last - first > 1.5f)
		{
			Nos[0] = true;
			fail->mesh->setTransform({ 0,0 });;
			poopooCheck = false;
		}

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

					//se8.Play("assets\\coin.mp3", 1);

					rot[0] = false;
				}
			}
		}

		if (puzzle18->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle18->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[1] = true;
			}
			if (rot[1] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle18->pipe->Update();

					degree8_2 += static_cast<float>(DegreeToRadian(60.f));
					puzzle18->mesh->setRotation(degree8_2);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					//se8.Play(1);
					//se8.SetVolume(0.5f);
					//se8.SetLoopCount(1);
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

					degree8_3 += static_cast<float>(DegreeToRadian(60.f));
					puzzle4->mesh->setRotation(degree8_3);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					//se8.Play(1);
					//se8.SetVolume(0.5f);
					//se8.SetLoopCount(1);
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

					//se8.Play(1);
					//se8.SetVolume(0.5f);
					//se8.SetLoopCount(1);
					rot[3] = false;
				}
			}
		}

		if (puzzle20->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle20->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[4] = true;
			}
			if (rot[4] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle20->pipe->Update();

					degree8_5 += static_cast<float>(DegreeToRadian(60.f));
					puzzle20->mesh->setRotation(degree8_5);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					//se8.Play(1);
					//se8.SetVolume(0.5f);
					//se8.SetLoopCount(1);
					rot[4] = false;
				}
			}
		}


		if (puzzle9->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle9->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[5] = true;
			}
			if (rot[5] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle9->pipe->Update();

					degree8_6 += static_cast<float>(DegreeToRadian(60.f));
					puzzle9->mesh->setRotation(degree8_6);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);

					//se8.Play(1);
					//se8.SetVolume(0.5f);
					//se8.SetLoopCount(1);
					rot[5] = false;
				}
			}
		}

		if (puzzle17->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle17->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[6] = true;
			}
			if (rot[6] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle17->pipe->Update();

					degree8_7 += static_cast<float>(DegreeToRadian(60.f));
					puzzle17->mesh->setRotation(degree8_7);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);
					//se8.Play(1);
					//se8.SetVolume(0.5f);
					//se8.SetLoopCount(1);

					rot[6] = false;
				}
			}
		}


		if ((puzzle1->pipe->GetDirValue(E) == 1 && puzzle2->pipe->GetDirValue(W) == 1) && (puzzle1->pipe->GetDirValue(SW) == 1 && puzzle3->pipe->GetDirValue(NE) == 1))
		{
			conecTcheck8_1 = true;
		}
		else
		{
			conecTcheck8_1 = false;
		}

		if ((puzzle18->pipe->GetDirValue(NE) == 1 && puzzle2->pipe->GetDirValue(SW) == 1) && (puzzle18->pipe->GetDirValue(E) == 1 && puzzle19->pipe->GetDirValue(W) == 1))
		{

			conecTcheck8_2 = true;
		}
		else
		{
			conecTcheck8_2 = false;
		}

		if ((puzzle7->pipe->GetDirValue(SW) == 1 && puzzle9->pipe->GetDirValue(NE) == 1) && (puzzle7->pipe->GetDirValue(SE) == 1 && puzzle10->pipe->GetDirValue(NW) == 1))
		{

			conecTcheck8_3 = true;
		}
		else
		{
			conecTcheck8_3 = false;
		}

		if ((puzzle9->pipe->GetDirValue(NE) == 1 && puzzle7->pipe->GetDirValue(SW) == 1) && (puzzle9->pipe->GetDirValue(W) == 1 && puzzle20->pipe->GetDirValue(E) == 1))
		{
			conecTcheck8_4 = true;

		}
		else
		{
			conecTcheck8_4 = false;
		}

		if ((puzzle17->pipe->GetDirValue(NE) == 1 && puzzle16->pipe->GetDirValue(SW) == 1) && (puzzle17->pipe->GetDirValue(W) == 1 && puzzle12->pipe->GetDirValue(E) == 1))
		{
			conecTcheck8_9 = true;

		}
		else
		{
			conecTcheck8_9 = false;
		}


		if ((puzzle4->pipe->GetDirValue(NE) == 1 && puzzle13->pipe->GetDirValue(SW) == 1) && (puzzle4->pipe->GetDirValue(SE) == 1 && puzzle15->pipe->GetDirValue(NW) == 1))
		{
			conecTcheck8_5 = true;
		}
		else
		{
			conecTcheck8_5 = false;
		}

		if ((puzzle4->pipe->GetDirValue(NE) == 1 && puzzle13->pipe->GetDirValue(SW) == 1) && (puzzle4->pipe->GetDirValue(W) == 1 && puzzle19->pipe->GetDirValue(E) == 1))
		{
			conecTcheck8_6 = true;

		}
		else
		{
			conecTcheck8_6 = false;
		}

		if ((puzzle20->pipe->GetDirValue(NW) == 1 && puzzle6->pipe->GetDirValue(SE) == 1) && (puzzle20->pipe->GetDirValue(SW) == 1 && endPuzzle->pipe->GetDirValue(NE) == 1))
		{
			conecTcheck8_7 = true;

		}
		else
		{
			conecTcheck8_7 = false;
		}

		if ((puzzle20->pipe->GetDirValue(E) == 1 && puzzle9->pipe->GetDirValue(W) == 1) && (puzzle20->pipe->GetDirValue(SW) == 1 && endPuzzle->pipe->GetDirValue(NE) == 1))
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
		if (Nos[0] == false && Nos[1] == false)
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

			if (conecTcheck8_1 && conecTcheck8_2 && conecTcheck8_6 && conecTcheck8_7)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 350.f, -240.f });
				chekNext8 = 1;
				mPooPoo2.SetIsSuccess(true);

				std::cout << "clear" << std::endl;
				connectMove8 = 0;

				if (soundCheck == false)
				{
					this->sound->Play("assets\\flushing.wav", 1);

				}
				soundCheck = true;

			}
			else if (conecTcheck8_3 && conecTcheck8_4 && conecTcheck8_5 && conecTcheck8_8 && conecTcheck8_9)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 350.f, -240.f });
				chekNext8 = 1;
				mPooPoo.SetIsSuccess(true);

				std::cout << "clear" << std::endl;
				connectMove8 = 0;

				if (soundCheck2 == false)
				{
					this->sound->Play("assets\\flushing.wav", 1);

				}
				soundCheck2 = true;

				poopooCheck = false;

			}
			else {
				if (failS[0] == false)
				{
					last = 0;
					this->sound->Play("assets\\fart.mp3", 1);
					failS[0] = true;
					first = glfwGetTime();
				}
				last = glfwGetTime();
				if (last - first > 1.5f)
				{
					Nos[0] = true;
					fail->mesh->setTransform({ 0,0 });
					poopooCheck = false;
				}
			}
		}
	}

	if (fail->collision->Point2BoxCollision({ cursor8.x,cursor8.y }, fail->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			failS[1] = false;
			failS[0] = false;
			Nos[0] = false;
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
		degree8_2 = 0;
		degree8_3 = 0;
		degree8_4 = 0;
		degree8_5 = 0;
		degree8_6 = 0;
		degree8_7 = 0;

		rotTime.setRotate(30);
	}
	lastTime = glfwGetTime();

	if (skip == true)
	{
		if (lastTime - firstTime > 2)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST5);
		}
	}
	if (restartUI->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, restartUI->mesh))
	{
		if (Nos[0] == false && Nos[1] == false)
		{
			if (UI[1] == false)
			{
				UI[1] = true;
				this->sound->Play("assets\\UI.wav", 1);
			}
			restartUI_p->mesh->setTransform(restartUI->mesh->GetTransform());

			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				INPUT->setInput(KEY::LEFT);

				STATE_MANAGER->ReloadState();

			}
		}
	}
	else
	{
		UI[1] = false;
		restartUI_p->mesh->setTransform({ 1700.f, 1000.f });
	}
	if (optionUI->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, optionUI->mesh))
	{
		if (Nos[0] == false && Nos[1] == false)
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
	}
	else
	{
		UI[2] = false;
		optionUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (quitUI->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, quitUI->mesh))
	{
		if (Nos[0] == false && Nos[1] == false)
		{
			if (UI[3] == false)
			{
				UI[3] = true;
				this->sound->Play("assets\\UI.wav", 1);
			}
			quitUI_p->mesh->setTransform(quitUI->mesh->GetTransform());

			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				INPUT->setInput(KEY::LEFT);
				if (quitCheck == false)
				{
					//SOUND->Pause();
					Nos[1] = true;
					quitCheck = true;
					QuitAskBack->mesh->setTransform({ 0.f, 0.f });
					QuitAsk->mesh->setTransform({ 0.f, 0.f });
					Yes->mesh->setTransform({ -100.f, -50.f });
					No->mesh->setTransform({ 100.f, -50.f });
				}
			}
		}
	}
	else
	{
		UI[3] = false;
		quitUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}
	if (Yes->collision->Point2BoxCollision(cursor8, Yes->mesh))
	{
		if (SUI[0] == false)
		{
			SUI[0] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		Yes_p->mesh->setTransform(Yes->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			realQuit = true;
		}
	}
	else
	{
		SUI[0] = false;

		Yes_p->mesh->setTransform({ -1000.f, -1000.f });
	}

	if (No->collision->Point2BoxCollision(cursor8, No->mesh))
	{
		if (SUI[1] == false)
		{
			SUI[1] = true;
			this->sound->Play("assets\\UI.wav", 1);
		}
		No_p->mesh->setTransform(No->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT))
		{
			INPUT->setInput(KEY::LEFT);
			quitCheck = false;
			realQuit = false;
			Nos[1] = false;

			QuitAsk->mesh->setTransform({ -2000.f, -2000.f });
			QuitAskBack->mesh->setTransform({ -2000.f, -2000.f });
			Yes->mesh->setTransform({ -2000.f, -2000.f });
			No->mesh->setTransform({ -2000.f, -2000.f });
		}
	}
	else
	{
		SUI[1] = false;

		No_p->mesh->setTransform({ -1000.f, -1000.f });
	}

	if (quitCheck == true && realQuit == true)
	{
		glfwTerminate();
		ENGINE->Quit();
	}

	//se8.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground8);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);

	puzzle18->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);
	puzzle19->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle20->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart8);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd8);
	Levelsel->mesh->Update(mShader2.GetShaderHandler(), LevelPage);
	Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), LevelPage_pressed);
	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton8);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear8);

	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI8);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI8);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI8);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI8);


	restartUI_p->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI3p);
	playUI_p->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI3p);
	quitUI_p->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI3p);
	optionUI_p->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI3p);

	levelImage->mesh->Update(mShader2.GetShaderHandler(), levelTexture);
	numberImage->mesh->Update(mShader2.GetShaderHandler(), numberTexture);
	leftCount->mesh->Update(mShader2.GetShaderHandler(), textureLeft);

	pooCharacter->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton8);


	if (mPooPoo.IsFinish() == false && mPooPoo2.IsFinish() == false)
	{
		if (mPooPoo.GetIsSuccess() == true)
		{
			pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
		}
		else if (mPooPoo2.GetIsSuccess() == true)
		{
			pooCharacter->mesh->setTransform(mPooPoo2.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
		}
	}
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


	if (mInput.IsPressed(KEY::A))
	{
		INPUT->setInput(KEY::A);

		STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST5);
	}
	QuitAskBack->mesh->Update(mShader2.GetShaderHandler(), textureIdQuitAskBack);
	QuitAsk->mesh->Update(mShader2.GetShaderHandler(), textureIdQuitAsk);
	Yes->mesh->Update(mShader2.GetShaderHandler(), textureIdYes);
	No->mesh->Update(mShader2.GetShaderHandler(), textureIdNo);
	Yes_p->mesh->Update(mShader2.GetShaderHandler(), textureIdYes_p);
	No_p->mesh->Update(mShader2.GetShaderHandler(), textureIdNo_p);


	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.f, 0.f, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level8::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	mPooPoo2.Clear();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
