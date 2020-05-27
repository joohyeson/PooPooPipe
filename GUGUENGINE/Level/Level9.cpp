
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level9.h"
#include "../GUGUENGINE/Sound.h"

Sound se9;
Sound playSE9;

void Level9::Init()
{
	STATE_MANAGER->setCurrentLV(0);

	autoRot = true;

	chekNext9 = 0;

	conecTcheck9_1 = false;
	conecTcheck9_2 = false;
	conecTcheck9_3 = false;

	degree9 = 0;
	degree9_2 = DegreeToRadian(60.f);
	degree9_3 = DegreeToRadian(-60.f);
	degree9_4 = DegreeToRadian(60.f);
	degree9_5 = 0;
	degree9_6 = DegreeToRadian(-180.f);
	degree9_7 = DegreeToRadian(120.f);
	degree9_rot = DegreeToRadian(-120.f);
	
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(1920, 1920.f);
	textureBackground9 = TEXTURE->CreateTexture("assets\\background.png", 0);	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine9 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack9 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve9 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree9 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV9 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart9 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd9 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine9_2 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve9_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV9_2 = TEXTURE->CreateTexture("assets\\image4_11.png", 0);
	texureIdCurve9_3 = TEXTURE->CreateTexture("assets\\55.png", 0);

	texureIdbutton9 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear9 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace9 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);

	se9.Init();
	se9.LoadSE("assets\\coin.mp3");

	playSE9.Init();
	playSE9.LoadSE("assets\\flushing.wav");
	mShader2.BuildTextureShader();


	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 713.5f, 300.f });
	playUI->mesh->SetMeshType(rectangle);
	playUI->mesh->InitializeTextureMesh(173.f, 200.f);
	texturePlayUI9 = TEXTURE->CreateTexture("assets\\playUI.png", 0);

	pooCharacter = OBJECT_FACTORY->CreateEmptyObject();
	pooCharacter->AddComponent(new Mesh());
	pooCharacter->Init();
	pooCharacter->mesh->setTransform({ -700.f, -700.f });
	pooCharacter->mesh->SetMeshType(rectangle);
	pooCharacter->mesh->InitializeTextureMesh(80.f, 80.f);

	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->SetMeshType(rectangle);
	quitUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureQuitUI9 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 713.5f, 0.f });
	optionUI->mesh->SetMeshType(rectangle);
	optionUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureOptionUI9 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->SetMeshType(rectangle);
	restartUI->mesh->InitializeTextureMesh(173.f, 200.f);
	textureRestartUI9 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);
	levelImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 800.0f, 450.f - 20.f });
	numberImage = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 830, 450.f - 20.f });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 280.f + 50.f }, 120.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 280.f + 50.f });
	puzzle1->pipe->SetDirection(false, false, false, false, true, true);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f - 465.f, 280.f + 50.f });
	puzzle2->pipe->SetDirection(false, false, false, true, false, true);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 120.f);
	//puzzle3->pipe->SetDirection(false, true, false, true, false, false);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, 160.f + 22.f }, -120.f);
	puzzle4->pipe->SetDirection(false, true, false, true, false, true);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f }, -60.f);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);
	puzzle6->pipe->SetDirection(true, false, false, true, false, false);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 40.f - 5.f }, 60.f);
	//puzzle7->pipe->SetDirection(false, false, true, true, false, false);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f }, 180.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, -80.f - 32.f });
	puzzle9->pipe->SetDirection(false, false, false, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, -80.f - 32.f }, -240.f);
	puzzle10->pipe->SetDirection(true, false, true, true, false, false);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 60.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, 120.f);
	puzzle12->pipe->SetDirection(false, true, false, true, false, false);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 280.f + 50.f });
	puzzle13->pipe->SetDirection(false, true, true, false, false, false);

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 276.f - 376.f, 160.f + 22.f }, -60);
	//puzzle14->pipe->SetDirection(false, false, false, true, true, false);

	Levelsel = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 713.5f, -300.f }, 180.f);
	Levelsel_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 1800.f, -300.f }, 180.f);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 40.f - 5.f });
	puzzle15->pipe->SetDirection(true, false, false, true, false, false);

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, -80.f - 32.f }, -180.f);
	puzzle16->pipe->SetDirection(false, true, true, false, false, false);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, -200.f - 62.f }, -60.f);
	puzzle17->pipe->SetDirection(true, false, false, false, false, true);

	puzzle18 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, 160.f + 22.f }, -60.f);
	puzzle18->pipe->SetDirection(true, false, false, true, false, true);

	puzzle19 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, 160.f + 22.f }, 60.f);
	puzzle19->pipe->SetDirection(true, false, true, false, false, false);

	puzzle20 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, -80.0f - 32.f });
	puzzle20->pipe->SetDirection(false, false, false, true, false, true);
	levelTexture = TEXTURE->CreateTexture("assets\\level.png", 0);
	numberTexture = TEXTURE->CreateTexture("assets\\06.png", 0);
	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.0f, -340.f });

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);
	levelImage->mesh->InitializeTextureMesh(100.f, 100.f);
	numberImage->mesh->InitializeTextureMesh(100.f, 100.f);

	LevelPage = TEXTURE->CreateTexture("assets\\levelButton.png", 0);
	LevelPage_pressed = TEXTURE->CreateTexture("assets\\levelButton_2.png", 0);

	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::S_, puzzle13->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, puzzle4->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle15->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle16->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SE_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle17->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::NW_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SE_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle20->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	mInput.InitCallback(APPLICATION->getMyWindow());

}

void Level9::Update()
{
	STATE_MANAGER->setCurrentLV(6);

	cursor9 = mInput.Cursor;

	se9.Update();
	playSE9.Update();

	if (Levelsel->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, Levelsel->mesh) == true)
	{
		Levelsel_pressed->mesh->setTransform(Levelsel->mesh->GetTransform());
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			chekNext9 = 0;

			conecTcheck9_1 = false;
			conecTcheck9_2 = false;
			conecTcheck9_3 = false;

			degree9 = 0;
			degree9_2 = DegreeToRadian(60.f);
			degree9_3 = DegreeToRadian(-60.f);
			degree9_4 = DegreeToRadian(60.f);
			degree9_5 = 0;
			degree9_6 = DegreeToRadian(-180.f);
			degree9_7 = DegreeToRadian(120.f);
			degree9_rot = DegreeToRadian(-120.f);

			std::cout << "check" << std::endl;
			mPooPoo.Clear();
			Close();
			STATE_MANAGER->ChangeLevel(LV_SELECT);
		}
	}
	else
	{
		Levelsel_pressed->mesh->setTransform({ 1800.f, -300.f });
	}
	if (puzzle1->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle1->mesh))
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

				degree9 += static_cast<float>(DegreeToRadian(60.f));
				puzzle1->mesh->setRotation(degree9);


				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);
				rot[0] = false;
			}
		}
	}


	if (puzzle19->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle19->mesh))
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

				degree9_2 += static_cast<float>(DegreeToRadian(60.f));
				puzzle19->mesh->setRotation(degree9_2);

				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);
				rot[1] = false;
			}
		}
	}


	if (puzzle14->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle14->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[2] = true;
		}
		if (rot[2] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle14->pipe->Update();

				degree9_3 += static_cast<float>(DegreeToRadian(60.f));
				puzzle14->mesh->setRotation(degree9_3);

				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);
				rot[2] = false;
			}
		}
	}

	if (puzzle6->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle6->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[3] = true;
		}
		if (rot[3] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle6->pipe->Update();

				degree9_4 += static_cast<float>(DegreeToRadian(60.f));
				puzzle6->mesh->setRotation(degree9_4);

				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);
				rot[3] = false;

			}

		}
	}

	if (puzzle20->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle20->mesh))
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

				degree9_5 += static_cast<float>(DegreeToRadian(60.f));
				puzzle20->mesh->setRotation(degree9_5);

				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);
				rot[4] = false;
			}
		}
	}

	if (puzzle16->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle16->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[5] = true;
		}
		if (rot[5] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle16->pipe->Update();

				degree9_6 += static_cast<float>(DegreeToRadian(60.f));
				puzzle16->mesh->setRotation(degree9_6);


				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);
				rot[5] = false;
			}
		}
	}

	if (puzzle12->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle12->mesh))
	{
		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot[6] = true;
		}
		if (rot[6] == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				puzzle12->pipe->Update();

				degree9_7 += static_cast<float>(DegreeToRadian(60.f));
				puzzle12->mesh->setRotation(degree9_7);

				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);
				rot[6] = false;
			}

		}
	}

	if ((puzzle15->pipe->GetDirValue(SE) == puzzle16->pipe->GetDirValue(NW)))
	{
		conecTcheck9_1 = true;
	}
	else
	{
		conecTcheck9_1 = false;
	}

	if ((puzzle12->pipe->GetDirValue(E) == puzzle17->pipe->GetDirValue(W)) && (puzzle12->pipe->GetDirValue(NW) == puzzle9->pipe->GetDirValue(SE)))
	{

		conecTcheck9_2 = true;
	}
	else
	{
		conecTcheck9_2 = false;
	}

	if ((puzzle20->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (puzzle20->pipe->GetDirValue(SW) == endPuzzle->pipe->GetDirValue(NE)))
	{

		conecTcheck9_3 = true;
	}
	else
	{
		conecTcheck9_3 = false;
	}

	if (playUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, playUI->mesh))
	{
		

		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			poopooCheck = true;
		}
	}
	else
	{
		connectMove9 = 0;
	}
	if(poopooCheck == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			if (autoRot)
			{
				puzzle4->pipe->Update();

				degree9_rot += static_cast<float>(DegreeToRadian(-120.f));
				puzzle4->mesh->setRotation(degree9_rot);

				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);

				autoRot = false;

				if (!conecTcheck9_1 || !conecTcheck9_2 || !conecTcheck9_3)
				{
					std::cout << "fail" << std::endl;
					STATE_MANAGER->ReloadState();
				}
			}

			if (conecTcheck9_1 && conecTcheck9_2 && conecTcheck9_3)
			{
				std::cout << "if 3" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext9 = 1;
				std::cout << "clear" << std::endl;
				mPooPoo.SetIsSuccess(true);
				connectMove9 = 0;

				playSE9.Play(1);
				playSE9.SetVolume(0.5f);
				playSE9.SetLoopCount(1);

			}
		}
		
	}
	if (restartUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, restartUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST9);

		}
	}

	if (optionUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, optionUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			STATE_MANAGER->ChangeLevel(OPTION);
		}
	}


	if (quitUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, quitUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			glfwTerminate();
		}
	}


	se9.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground9);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdV9_2);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_3);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9_2);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdV9_2);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);

	puzzle18->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle19->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);
	puzzle20->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart9);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd9);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton9);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear9);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace9);
	pooCharacter->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton9);
	Levelsel->mesh->Update(mShader2.GetShaderHandler(), LevelPage);
	Levelsel_pressed->mesh->Update(mShader2.GetShaderHandler(), LevelPage_pressed);
	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI9);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI9);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI9);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI9);
	if (mPooPoo.IsFinish() == false)
	{
		pooCharacter->mesh->setTransform(mPooPoo.MoveInPuzzle(pooCharacter->mesh->GetTransform()));
	}

	levelImage->mesh->Update(mShader2.GetShaderHandler(), levelTexture);
	numberImage->mesh->Update(mShader2.GetShaderHandler(), numberTexture);


	if ((mInput.IsPressed(KEY::SPACE) == true && chekNext9 == 1) || mInput.IsPressed(KEY::A) == true)
	{
		chekNext9 = 0;
		
		conecTcheck9_1 = false;
		conecTcheck9_2 = false;
		conecTcheck9_3 = false;
		
		degree9 = 0;
		degree9_2 = DegreeToRadian(60.f);
		degree9_3 = DegreeToRadian(-60.f);
		degree9_4 = DegreeToRadian(60.f);
		degree9_5 = 0;
		degree9_6 = DegreeToRadian(-180.f);
		degree9_7 = DegreeToRadian(120.f);
		degree9_rot = DegreeToRadian(-120.f);

		STATE_MANAGER->ChangeLevel(LV_TEST10);

	}
	if (mInput.IsPressed(KEY::ESCAPE) == true) {
		glfwTerminate();
	}
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void Level9::Close()
{
	mShader.Delete();
	mMesh.Delete();
	mPooPoo.Clear();

	OBJECT_FACTORY->DestroyAllObjects();
}
