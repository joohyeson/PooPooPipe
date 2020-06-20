
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level6.h"
#include "../GUGUENGINE/Sound.h"

//Sound se6;
//Sound playSE6;

void Level6::Init()
{
	STATE_MANAGER->setCurrentLV(0);
	skip = false;
	transition = 0.f;

	chekNext6 = 0;

	conecTcheck6_1 = false;
	conecTcheck6_2 = false;
	conecTcheck6_3 = false;
	conecTcheck6_4 = false;
	conecTcheck6_5 = false;

	degree6 = DegreeToRadian(60.f);
	degree6_2 = DegreeToRadian(-60.f);
	degree6_3 = DegreeToRadian(120.f);
	degree6_4 = DegreeToRadian(180.f);
	degree6_5 = DegreeToRadian(-180.f);
	degree6_6 = DegreeToRadian(-120.f);
	
	rotTime.setRotate(30);
	rotrot = true;
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground6 = TEXTURE->CreateTexture("assets\\background1.png", 0);	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);
	win->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	
	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI6 = TEXTURE->CreateTexture("assets\\playUI.png", 0);

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
	textureQuitUI6 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);

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
	textureOptionUI6 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);

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

	fail = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f, -2000.f });
	fail->mesh->InitializeTextureMesh(APPLICATION->width - 100.f, APPLICATION->height - 100.f);
	textureFail = TEXTURE->CreateTexture("assets\\failScreen.png", 0);

	textureRestartUI6 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);

	texureIdLine6 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack6 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve6 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree6 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV6 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart6 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd6 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine6_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve6_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV6_2 = TEXTURE->CreateTexture("assets\\image4_11.png", 0);

	texureIdbutton6 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear6 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace6 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
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

	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);


	//se6.Init();
	//se6.LoadSE("assets\\coin.mp3");

	//playSE6.Init();
	//playSE6.LoadSE("assets\\flushing.wav");


	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 830, 450.f - 20.f });

	leftCount = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 250, 450.f - 20.f });
	leftCount->mesh->InitializeTextureMesh(250.f, 80.f);

	leftnumber = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 430, 450.f - 20.f });
	leftnumber->mesh->InitializeTextureMesh(80.f, 100.f);

	leftnumberTen = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 400, 450.f - 20.f });
	leftnumberTen->mesh->InitializeTextureMesh(80.f, 100.f);

	mShader2.BuildTextureShader();

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f - 465.f, 280.f + 50.f }, -240.f);
	startPuzzle->pipe->SetDirection(true, false, false, true, false, false);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);
	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 280.f + 50.f }, -60.f);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 280.f + 50.f }, 60.f);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -268.f - 519.f, 160.f + 22.f }, 180.f);
	puzzle3->pipe->SetDirection(false, false, false, true, false, true);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, 160.f + 22.f }, 60.f);
	puzzle4->pipe->SetDirection(false, false, true, false, true, false);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f }, -60.f);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 40.f - 5.f }, -120.f);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f }, 120.f);
	puzzle7->pipe->SetDirection(false, false, true, true, false, false);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f }, 120.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, -80.f - 32.f });
	puzzle9->pipe->SetDirection(false, false, false, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 415.f, -80.f  -32.f }, 60.f);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 180.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, -120.f);
	puzzle12->pipe->SetDirection(false, true, false, false, false, true);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 280.f + 50.f });
	puzzle13->pipe->SetDirection(false, false, false, true, false, true);

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, 160.f + 22.f }, 60.f);
	puzzle14->pipe->SetDirection(false, false, false, true, true, false);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 40.f - 5.f });
	puzzle15->pipe->SetDirection(false, false, false, true, false, true);

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, -80.f - 32.f }, -180.f);
	puzzle16->pipe->SetDirection(true, false, true, false, false, false);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, -200.f - 62.f }, -120.f);
	puzzle17->pipe->SetDirection(false, true, false, false, false, true);

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, 160.f + 22.f }, -60.f);
	blackPuzzle1->pipe->SetDirection(true, false, false, false, false, true);
	blackPuzzle1->mesh->InitializeTextureMesh();

	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 448.f, 160.f + 22.f });

	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, -80.0f - 32.f },180.f);
	blackPuzzle3->pipe->SetDirection(true, false, true, false, false, false);

	LevelPage = TEXTURE->CreateTexture("assets\\levelButton.png", 0);
	LevelPage_pressed = TEXTURE->CreateTexture("assets\\levelButton_2.png", 0);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -20.0f, -340.f - 20.f });
	levelTexture = TEXTURE->CreateTexture("assets\\level.png", 0);
	numberTexture = TEXTURE->CreateTexture("assets\\03.png", 0);
	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);
	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);

	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle13->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle14->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle4->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::NE_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle15->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, puzzle16->mesh->GetTransform());

	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SW_, puzzle17->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::NW_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SE_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level6::Update()
{
	cursor6 = mInput.Cursor;
	STATE_MANAGER->setCurrentLV(3);

	if (rotTime.getLimitTime() == 0)
	{
		rotrot = false;
		fail->mesh->setTransform({ 0,0 });
		std::cout << "rotation limit!!!" << std::endl;

	}



	/*se6.Update();
	playSE6.Update();*/

	if (Levelsel->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, Levelsel->mesh) == true)
	{
		Levelsel_pressed->mesh->setTransform(Levelsel->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT) == true )
		{
			INPUT->setInput(KEY::LEFT);

			chekNext6 = 0;

			conecTcheck6_1 = false;
			conecTcheck6_2 = false;
			conecTcheck6_3 = false;
			conecTcheck6_4 = false;
			conecTcheck6_5 = false;

			degree6 = DegreeToRadian(60.f);
			degree6_2 = DegreeToRadian(-60.f);
			degree6_3 = DegreeToRadian(120.f);
			degree6_4 = DegreeToRadian(180.f);
			degree6_5 = DegreeToRadian(-180.f);
			degree6_6 = DegreeToRadian(-120.f);

			rotTime.setRotate(100);

			std::cout << "check" << std::endl;

			STATE_MANAGER->ChangeLevel(LV_SELECT);
		}
	}
	else
	{
		Levelsel_pressed->mesh->setTransform({ 1800.f, -300.f });
	}
	if (rotrot)
	{
		if (puzzle14->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle14->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[0] = true;
			}
			if (rot[0] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle14->pipe->Update();

					degree6 += static_cast<float>(DegreeToRadian(60.f));
					std::cout << "1" << std::endl;
					puzzle14->mesh->setRotation(degree6);
					rotTime.Update();
					//rightCheck6 = 0;
					
					this->sound->Play("assets\\coin.mp3", 1);
					//se6.Play(1);
					//se6.SetVolume(0.5f);
					//se6.SetLoopCount(1);

					rot[0] = false;
				}
			}
		}

		if (blackPuzzle1->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, blackPuzzle1->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[1] = true;
			}
			if (rot[1] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					blackPuzzle1->pipe->Update();
					degree6_2 += static_cast<float>(DegreeToRadian(60.f));
					std::cout << "2" << std::endl;
					blackPuzzle1->mesh->setRotation(degree6_2);
					//rightCheck6_2 = 0;
					rotTime.Update();
					
					this->sound->Play("assets\\coin.mp3", 1);

					//se6.Play(1);
					//se6.SetVolume(0.5f);
					//se6.SetLoopCount(1);

					rot[1] = false;
				}
			}
		}


		if (puzzle7->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle7->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[2] = true;
			}
			if (rot[2] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle7->pipe->Update();
					degree6_3 += static_cast<float>(DegreeToRadian(60.f));
					puzzle7->mesh->setRotation(degree6_3);
					rotTime.Update();

					this->sound->Play("assets\\coin.mp3", 1);
					
					//se6.Play(1);
					//se6.SetVolume(0.5f);
					//se6.SetLoopCount(1);

					rot[2] = false;
				}
			}
		}

		if (blackPuzzle3->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, blackPuzzle3->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[3] = true;
			}
			if (rot[3] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					blackPuzzle3->pipe->Update();
					degree6_4 += static_cast<float>(DegreeToRadian(60.f));
					blackPuzzle3->mesh->setRotation(degree6_4);
					std::cout << "4" << std::endl;
					rotTime.Update();
					
					this->sound->Play("assets\\coin.mp3", 1);

					//se6.Play(1);
					//se6.SetVolume(0.5f);
					//se6.SetLoopCount(1);
					rot[3] = false;
				}
			}
		}

		if (puzzle16->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle16->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[4] = true;
			}
			if (rot[4] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle16->pipe->Update();
					degree6_5 += static_cast<float>(DegreeToRadian(60.f));
					puzzle16->mesh->setRotation(degree6_5);
					rotTime.Update();
					std::cout << "5" << std::endl;
					
					this->sound->Play("assets\\coin.mp3", 1);

					//se6.Play(1);
					//se6.SetVolume(0.5f);
					//se6.SetLoopCount(1);

					rot[4] = false;
				}
			}
		}

		if (puzzle12->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle12->mesh))
		{
			if (mInput.IsPressed(KEY::RIGHT) == true)
			{
				rot[5] = true;
			}
			if (rot[5] == true)
			{
				if (mInput.IsPressed(KEY::RIGHT) == false)
				{
					puzzle12->pipe->Update();
					degree6_6 += static_cast<float>(DegreeToRadian(60.f));
					puzzle12->mesh->setRotation(degree6_6);

					rotTime.Update();
					std::cout << "6" << std::endl;
					
					this->sound->Play("assets\\coin.mp3", 1);
					
					//se6.Play(1);
					//se6.SetVolume(0.5f);
					//se6.SetLoopCount(1);


					rot[5] = false;
				}
			}
		}

		if (button->collision->Point2BoxCollision({ cursor6.x,cursor6.y }, button->mesh))
		{
			if (mInput.IsPressed(KEY::LEFT) == true)
			{
				if (conecTcheck6_1 && conecTcheck6_2 && conecTcheck6_3)
				{
					std::cout << "if 5" << std::endl;
					clear->mesh->setTransform({ 350.f, -240.f });
					chekNext6 = 1;
					std::cout << "clear" << std::endl;
					mPooPoo.SetIsSuccess(true);
					connectMove6 = 0;

					this->sound->Play("assets\\flushing.wav", 1);

					//playSE6.Play(1);
					//playSE6.SetVolume(0.5f);
					//playSE6.SetLoopCount(1);
				}

			}
		}
		else
		{
			connectMove6 = 0;
		}

		if ((puzzle14->pipe->GetDirValue(NW) == puzzle13->pipe->GetDirValue(SE)) && (puzzle14->pipe->GetDirValue(W) == puzzle4->pipe->GetDirValue(E)))
		{
			conecTcheck6_1 = true;
		}
		else
		{
			conecTcheck6_1 = false;
		}

		if ((puzzle7->pipe->GetDirValue(NE) == puzzle4->pipe->GetDirValue(SW)) && (puzzle7->pipe->GetDirValue(E) == puzzle15->pipe->GetDirValue(W)))
		{
			conecTcheck6_2 = true;
		}
		else
		{
			conecTcheck6_2 = false;
		}

		if ((puzzle16->pipe->GetDirValue(NW) == puzzle15->pipe->GetDirValue(SE)) && (puzzle16->pipe->GetDirValue(SW) == puzzle17->pipe->GetDirValue(NE)))
		{
			conecTcheck6_3 = true;
		}
		else
		{
			conecTcheck6_3 = false;
		}

		if ((puzzle12->pipe->GetDirValue(E) == puzzle17->pipe->GetDirValue(W)) && (puzzle12->pipe->GetDirValue(NW) == puzzle9->pipe->GetDirValue(SE)))
		{
			conecTcheck6_4 = true;

		}
		else
		{
			conecTcheck6_4 = false;
		}

		if ((blackPuzzle3->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (blackPuzzle3->pipe->GetDirValue(SW) == endPuzzle->pipe->GetDirValue(NE)))
		{
			conecTcheck6_5 = true;

		}
		else
		{
			conecTcheck6_5 = false;
		}
	}

	if (conecTcheck6_1)
	{
		std::cout << "1" << std::endl;
	}
	else if (conecTcheck6_2)
	{
		std::cout << "2" << std::endl;

	}
	else if (conecTcheck6_3)
	{
		std::cout << "3" << std::endl;

	}
	else if (conecTcheck6_4)
	{
		std::cout << "4" << std::endl;

	}
	else if (conecTcheck6_5)
	{
		std::cout << "5" << std::endl;

	}
	if (playUI->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, playUI->mesh))
	{
		playUI_p->mesh->setTransform(playUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			poopooCheck = true;
		}
	}
	else
	{
		playUI_p->mesh->setTransform({ 1000.f, 1000.f });

		connectMove6 = 0;
	}
	
	if(poopooCheck == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			if (conecTcheck6_1 && conecTcheck6_2 && conecTcheck6_3 && conecTcheck6_4 && conecTcheck6_5)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext6 = 1;
				std::cout << "clear" << std::endl;
				mPooPoo.SetIsSuccess(true);
				connectMove6 = 0;
				poopooCheck = false;


				this->sound->Play("assets\\flushing.wav", 1);
			}
			else {
				fail->mesh->setTransform({ 0,0 });
				poopooCheck = false;
			}
		}
	}
	

	
	if (fail->collision->Point2BoxCollision({ cursor6.x,cursor6.y }, fail->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);

			fail->mesh->setTransform({ -2000.f,-2000.f });
			STATE_MANAGER->ReloadState();

		}
	}

	if (restartUI->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, restartUI->mesh))
	{
		restartUI_p->mesh->setTransform(restartUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);

			STATE_MANAGER->ReloadState();

		}
	}
	else
	{
		restartUI_p->mesh->setTransform({ 1700.f, 1000.f });
	}


	if (optionUI->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, optionUI->mesh))
	{
		optionUI_p->mesh->setTransform(optionUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);

			STATE_MANAGER->ChangeLevel(OPTION);
		}
	}
	else
	{
		optionUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}

	if (quitUI->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, quitUI->mesh))
	{
		quitUI_p->mesh->setTransform(quitUI->mesh->GetTransform());

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);

			glfwTerminate();
		}
	}
	else
	{
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

		chekNext6 = 0;

		conecTcheck6_1 = false;
		conecTcheck6_2 = false;
		conecTcheck6_3 = false;
		conecTcheck6_4 = false;
		conecTcheck6_5 = false;

		degree6 = DegreeToRadian(60.f);
		degree6_2 = DegreeToRadian(-60.f);
		degree6_3 = DegreeToRadian(120.f);
		degree6_4 = DegreeToRadian(180.f);
		degree6_5 = DegreeToRadian(-180.f);
		degree6_6 = DegreeToRadian(-120.f);

		rotTime.setRotate(100);
	}

	if(skip == true)
	{
		transition++;
		if(transition > 500.f)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST8);
		}
	}
	//se6.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground6);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdV6_2);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdV6_2);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6_2);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV6_2);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6_2);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdV6_2);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6_2);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart6);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd6);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton6);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear6);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace6);

	Levelsel->mesh->Update(mShader2.GetShaderHandler(), LevelPage);
	Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), LevelPage_pressed);
	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI6);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI6);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI6);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI6);
	

	restartUI_p->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI3p);
	playUI_p->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI3p);
	quitUI_p->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI3p);
	optionUI_p->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI3p);
	levelImage->mesh->Update(mShader2.GetShaderHandler(), levelTexture);
	numberImage->mesh->Update(mShader2.GetShaderHandler(), numberTexture);
	pooCharacter->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton6);
	leftCount->mesh->Update(mShader2.GetShaderHandler(), textureLeft);

	

	if (mPooPoo.IsFinish() == false)
	{
		pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
	}
	//leftnumberTen->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumberTen3);
	//leftnumber->mesh->Update(mShader2.GetShaderHandler(), textureLeftNumber0);

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

	if ((mInput.IsPressed(KEY::SPACE) == true && chekNext6 == 1) || mInput.IsPressed(KEY::A) == true)
	{
		INPUT->setInput(KEY::SPACE);
		INPUT->setInput(KEY::A);

		chekNext6 = 0;

		conecTcheck6_1 = false;
		conecTcheck6_2 = false;
		conecTcheck6_3 = false;
		conecTcheck6_4 = false;
		conecTcheck6_5 = false;

		degree6 = DegreeToRadian(60.f);
		degree6_2 = DegreeToRadian(-60.f);
		degree6_3 = DegreeToRadian(120.f);
		degree6_4 = DegreeToRadian(180.f);
		degree6_5 = DegreeToRadian(-180.f);
		degree6_6 = DegreeToRadian(-120.f);

		rotTime.setRotate(100);

		STATE_MANAGER->ChangeLevel(LV_TEST8);
	}
	if (mInput.IsPressed(KEY::ESCAPE) == true) {
		glfwTerminate();
	}
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level6::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
