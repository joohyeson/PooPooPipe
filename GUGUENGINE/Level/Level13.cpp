
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level13.h"
#include "../GUGUENGINE/Sound.h"


void Level13::Init()
{
	STATE_MANAGER->setCurrentLV(0);

	chekNext8 = 0;
	firstTime = glfwGetTime();
	failS[0] = false;
	failS[1] = false;
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
	degree8_8 = static_cast<float>(DegreeToRadian(-120.f));

	mini = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 330.f, 150.f });
	texturemini = TEXTURE->CreateTexture("assets\\mini.png", 0);
	mini->mesh->InitializeTextureMesh(500.f, 500.f);


	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	textureBackground8 = TEXTURE->CreateTexture("assets\\background2.png", 0);	
	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI8 = TEXTURE->CreateTexture("assets\\playUI.png", 0);

	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	win = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.0f, -2000.0f });
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);
	win->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));

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

	LevelPage = TEXTURE->CreateTexture("assets\\levelButton.png", 0);
	LevelPage_pressed = TEXTURE->CreateTexture("assets\\levelButton_2.png", 0);


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
	texureIdEnd8 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine8_2 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve8_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV8_2 = TEXTURE->CreateTexture("assets\\image4_11.png", 0);

	textureIdCurveAuto = TEXTURE->CreateTexture("assets\\image_auto1.png", 0);
	textureIdVAuto = TEXTURE->CreateTexture("assets\\image_auto2.png", 0);
	textureIdLineAuto = TEXTURE->CreateTexture("assets\\image_auto3.png", 0);

	texureIdbutton8 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear8 = TEXTURE->CreateTexture("assets\\clear.png", 0);


	levelTexture = TEXTURE->CreateTexture("assets\\level.png", 0);
	numberTexture = TEXTURE->CreateTexture("assets\\01.png", 0);
	numberTexture2 = TEXTURE->CreateTexture("assets\\00.png", 0);

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


	mShader2.BuildTextureShader();

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 120.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 208.f - 393.f, -200.f - 62.f }, -360.f);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 280.f + 50.f });

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 280.f + 50.f }, -120.f);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle,  { 208.f - 393.f, 280.f + 50.f },-60.f);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, 160.f + 22.f });
	puzzle4->pipe->SetDirection(false, false, false, true, false, true);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f },60.f);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f });
	puzzle7->pipe->SetDirection(false, false, false, false, true, true);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f }, 120.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 448.f, -80.f - 32.f });

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, -80.f - 32.f });
	puzzle10->pipe->SetDirection(false, false, false, true, false, true);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, -120.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, -200.f - 62.f }, -120.f);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, 280.f + 50.f }, -180.f);

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, 160.f + 22.f }, -120.f);
	puzzle14->pipe->SetDirection(true, true, false, false, false, false);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 40.f - 5.f }, 60.f);
	puzzle15->pipe->SetDirection(false, false, true, false, false, true);

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 276.f - 376.f, -80.f - 32.f },-60.f);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);

	puzzle18 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, 160.f + 22.f });
	puzzle18->pipe->SetDirection(true, false, false, true, false, false);

	puzzle19 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, 160.f + 22.f },240.f);
	puzzle19->pipe->SetDirection(false, true, false, false, false, true);

	puzzle20 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 482.f, -80.0f - 32.f });

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 350.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });

	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850, 450.f - 20.f });
	numberImage2 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 880, 450.f - 20.f });

	button->mesh->InitializeTextureMesh(300.f, 300.f);
	clear->mesh->InitializeTextureMesh(380.f, 150.f);

	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage2->mesh->InitializeTextureMesh(100.f, 100.f);


	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(MESHTYPE::rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle18->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle19->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::N_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::S_, DirAngle::NE_, puzzle4->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::S_, puzzle14->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::S_, puzzle15->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, endPuzzle->mesh->GetTransform());

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level13::Update()
{
	STATE_MANAGER->setCurrentLV(10);
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

	if (puzzle18->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle18->mesh)) //18 7
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[0] = true;
		}
		if (rot[0] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle18->pipe->Update();
				puzzle7->pipe->Update();

				degree8 += static_cast<float>(DegreeToRadian(60.f));
				puzzle18->mesh->setRotation(degree8);
				puzzle7->mesh->setRotation(degree8);

				this->sound->Play("assets\\coin.mp3", 1);

				rot[0] = false;
			}
		}
	}

	if (puzzle7->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle7->mesh)) // 18 7
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[1] = true;
		}
		if (rot[1] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle7->pipe->Update();
				puzzle18->pipe->Update();

				degree8 += static_cast<float>(DegreeToRadian(60.f));

				puzzle7->mesh->setRotation(degree8);
				puzzle18->mesh->setRotation(degree8);

				this->sound->Play("assets\\coin.mp3", 1);

				rot[1] = false;
			}
		}
	}


	if (puzzle19->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle19->mesh)) //19 10
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[2] = true;
		}
		if (rot[2] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle19->pipe->Update();
				puzzle10->pipe->Update();

				degree8_2 += static_cast<float>(DegreeToRadian(60.f));
				puzzle19->mesh->setRotation(degree8_2 + static_cast<float>(DegreeToRadian(240.f)));
				puzzle10->mesh->setRotation(degree8_2);

				this->sound->Play("assets\\coin.mp3", 1);
				rot[2] = false;
			}
		}
	}


	if (puzzle10->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle10->mesh)) //19 10 
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[3] = true;
		}
		if (rot[3] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle19->pipe->Update();
				puzzle10->pipe->Update();

				degree8_2 += static_cast<float>(DegreeToRadian(60.f));

				puzzle19->mesh->setRotation(degree8_2 + static_cast<float>(DegreeToRadian(240.f)));
				puzzle10->mesh->setRotation(degree8_2);

				this->sound->Play("assets\\coin.mp3", 1);
				rot[3] = false;
			}
		}
	}

	if (puzzle4->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle4->mesh)) // 4 15
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[4] = true;
		}
		if (rot[4] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle4->pipe->Update();
				puzzle15->pipe->Update();

				degree8_3 += static_cast<float>(DegreeToRadian(60.f));

				puzzle4->mesh->setRotation(degree8_3);
				puzzle15->mesh->setRotation(degree8_3 + static_cast<float>(DegreeToRadian(60.f)));

				this->sound->Play("assets\\coin.mp3", 1);
				rot[4] = false;
			}
		}
	}

	if (puzzle15->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle15->mesh)) // 4 15
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[6] = true;
		}
		if (rot[6] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle15->pipe->Update();
				puzzle4->pipe->Update();

				degree8_3 += static_cast<float>(DegreeToRadian(60.f));

				puzzle4->mesh->setRotation(degree8_3);
				puzzle15->mesh->setRotation(degree8_3 + static_cast<float>(DegreeToRadian(60.f)));

				this->sound->Play("assets\\coin.mp3", 1);

				rot[6] = false;
			}
		}
	}

	if (puzzle1->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle1->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[7] = true;
		}
		if (rot[7] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle1->pipe->Update();


				degree8_4 += static_cast<float>(DegreeToRadian(60.f));
				puzzle1->mesh->setRotation(degree8_4);

				this->sound->Play("assets\\coin.mp3", 1);

				rot[7] = false;
			}
		}
	}

	if (puzzle20->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle20->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[9] = true;
		}
		if (rot[9] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle20->pipe->Update();

				degree8_6 += static_cast<float>(DegreeToRadian(60.f));
				puzzle20->mesh->setRotation(degree8_6);

				this->sound->Play("assets\\coin.mp3", 1);

				rot[9] = false;
			}
		}
	}

	if (puzzle9->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle9->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[10] = true;
		}
		if (rot[10] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle9->pipe->Update();

				degree8_7 += static_cast<float>(DegreeToRadian(60.f));
				puzzle9->mesh->setRotation(degree8_7);

				this->sound->Play("assets\\coin.mp3", 1);

				rot[10] = false;
			}
		}
	}

	if (puzzle14->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle14->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[5] = true;
		}
		if (rot[5] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle14->pipe->Update();

				degree8_8 += static_cast<float>(DegreeToRadian(60.f));
				puzzle14->mesh->setRotation(degree8_8);

				this->sound->Play("assets\\coin.mp3", 1);

				rot[5] = false;
			}
		}
	}

	if (puzzle18->pipe->GetDirValue(W) == 1 && (puzzle18->pipe->GetDirValue(E) == 1 && puzzle19->pipe->GetDirValue(W) == 1))
	{
		//std::cout << "18 & 19" << std::endl;
		conecTcheck8_1 = true;
	}
	else
	{
		conecTcheck8_1 = false;
	}

	if ((puzzle18->pipe->GetDirValue(E) == 1 && puzzle19->pipe->GetDirValue(W) == 1)  && (puzzle19->pipe->GetDirValue(SE) == 1 && puzzle7->pipe->GetDirValue(NW) == 1))
	{
		//std::cout << "18&&19  19&&7" << std::endl;

		conecTcheck8_2 = true;
	}
	else
	{
		conecTcheck8_2 = false;
	}

	if ((puzzle4->pipe->GetDirValue(SW) == 1 && puzzle7->pipe->GetDirValue(NE) == 1) && (puzzle19->pipe->GetDirValue(SE) == 1 && puzzle7->pipe->GetDirValue(NW) == 1))
	{
		//std::cout << "4&&7 19&&7" << std::endl;

		conecTcheck8_3 = true;
	}
	else
	{
		conecTcheck8_3 = false;
	}

	if ((puzzle4->pipe->GetDirValue(E) == 1 && puzzle14->pipe->GetDirValue(W) == 1) && (puzzle14->pipe->GetDirValue(SW) == 1 && puzzle15->pipe->GetDirValue(NE) == 1))
	{
		//std::cout << "15&&14 14&&4" << std::endl;

		conecTcheck8_4 = true;

	}
	else
	{
		conecTcheck8_4 = false;
	}


	if ((puzzle14->pipe->GetDirValue(SW) == 1 && puzzle15->pipe->GetDirValue(NE) == 1) && (puzzle15->pipe->GetDirValue(SW) == 1 && puzzle10->pipe->GetDirValue(NE) == 1))
	{
		//std::cout << "14&&15  15&&10" << std::endl;

		conecTcheck8_5 = true;

	}
	else
	{
		conecTcheck8_5 = false;
	}


	if ((puzzle15->pipe->GetDirValue(SW) == 1 && puzzle10->pipe->GetDirValue(NE) == 1) && (puzzle10->pipe->GetDirValue(SE) == 1))
	{
		//std::cout << "15&&10 10" << std::endl;

		conecTcheck8_6 = true;

	}
	else
	{
		conecTcheck8_6 = false;
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
			if (conecTcheck8_1 && conecTcheck8_2 && conecTcheck8_3 && conecTcheck8_4 && conecTcheck8_5 && conecTcheck8_6)
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
				if (failS[1] == false)
				{
					last = 0;
					this->sound->Play("assets\\fart.mp3", 1);
					failS[1] = true;
					first = glfwGetTime();
				}
			}
		}
	}
	if (failS[1] == true)
	{
		last = glfwGetTime();
		if (last - first > 1.5f)
		{
			fail->mesh->setTransform({ 0,0 });;
			poopooCheck = false;
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

	}

	if (skip == true)
	{
		if (lastTime - firstTime > 2)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
		}
	}

	if (fail->collision->Point2BoxCollision({ cursor8.x,cursor8.y }, fail->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			fail->mesh->setTransform({ -2000.f,-2000.f });
			STATE_MANAGER->ReloadState();
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
			INPUT->setInput(KEY::LEFT);
			glfwTerminate();
			ENGINE->Quit();
		}
	}
	else
	{
		UI[3] = false;
		quitUI_p->mesh->setTransform({ 1000.f, 1000.f });
	}


	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground8);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), textureIdCurveAuto);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), textureIdVAuto);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), textureIdCurveAuto);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), textureIdLineAuto);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);

	puzzle18->mesh->Update(mShader2.GetShaderHandler(), textureIdLineAuto);
	puzzle19->mesh->Update(mShader2.GetShaderHandler(), textureIdCurveAuto);
	puzzle20->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);

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
	numberImage2->mesh->Update(mShader2.GetShaderHandler(), numberTexture2);

	pooCharacter->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton8);

	win->mesh->Update(mShader2.GetShaderHandler(), textureWin);

	restartUI_p->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI3p);
	playUI_p->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI3p);
	quitUI_p->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI3p);
	optionUI_p->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI3p);
	mini->mesh->Update(mShader2.GetShaderHandler(), texturemini);

	fail->mesh->Update(mShader2.GetShaderHandler(), textureFail);

	if (mPooPoo.IsFinish() == false)
	{
		pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
	}

	if (mInput.IsPressed(KEY::A))
	{
		INPUT->setInput(KEY::A);
		STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
	}

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level13::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
