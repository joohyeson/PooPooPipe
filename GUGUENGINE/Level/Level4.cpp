/*
 *hakyung.kim
 *uijin.lee
 *12.13.2019
 *digipen.hagyeong@gmail.com
 *if you want to check pipe connect, you can remove "//"pipe connect
 *this is level 4
 *Level4.cpp
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level4.h"
#include "../GUGUENGINE/Sound.h"

Sound se4;
Sound playSE4;

void Level4::Init()
{
	chekNext4 = 0;

	conecTcheck4_1 = false;
	conecTcheck4_2 = false;
	conecTcheck4_3 = false;

	degree4 = 0;
	degree4_2 = 0;
	degree4_3 = 0;

	blCheck3 = false;
	blCheck3_2 = false;

	blCheck4 = false;
	blCheck4_2 = false;

	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground4 = TEXTURE->CreateTexture("assets\\background1.png", 0);


	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 800.f, 300.f });
	playUI->mesh->SetMeshType(rectangle);
	playUI->mesh->InitializeTextureMesh(150.f, 150.f);
	texturePlayUI4 = TEXTURE->CreateTexture("assets\\playUI.png", 0);


	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->SetMeshType(rectangle);
	quitUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureQuitUI4 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 800.f, 0.f });
	optionUI->mesh->SetMeshType(rectangle);
	optionUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureOptionUI4 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->SetMeshType(rectangle);
	restartUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureRestartUI4 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);


	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f }, 60.f);
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -526.795, 330 });
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -353.59, 330 });
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -613.397, 180 });
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -266.987, 180 });
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -526.795, 30 }, 60.f);
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -353.59, 30 }, 300.f);
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -180.385, 30 }, 240.f);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -266.987, -120 }, 60.f);
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -93.782,-120 }, 60.f);
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -353.59,-270 }, 180.f);

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -440.192, 180 });
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -440.192, -120 });
	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -180.385, -270 });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -700, 330 }, 120.f);
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -7.18, -270 }, 60.f);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });

	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -80.0f, -450 });

	texureIdLine4 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack4 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve4 = TEXTURE->CreateTexture("assets\\image2.png", 0);

	texureIdStart4 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd4 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine4_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve4_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	texureIdbutton4 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear4 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace4 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	se4.Init();
	se4.LoadSE("assets\\coin.mp3");

	playSE4.Init();
	playSE4.LoadSE("assets\\flushing.wav");

	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle3->pipe->SetDirection(true, false, false, true, false, false);
	endPuzzle->pipe->SetDirection(false, false, false, false, false, true);
	puzzle1->pipe->SetDirection(false, false, false, true, false, true);
	puzzle6->pipe->SetDirection(true, false, false, false, true, false);
	puzzle10->pipe->SetDirection(true, false, true, false, false, false);


	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, puzzle6->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, blackPuzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level4::Update()
{
	cursor4 = mInput.Cursor;

	se4.Update();
	playSE4.Update();

	if (movePuzzle->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[1] && !movable[2])
		{
			movePuzzle->mesh->setTransform({ cursor4.x, cursor4.y });
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

				degree4 += static_cast<float>(DegreeToRadian(60.f));
				movePuzzle->mesh->setRotation(degree4);

				se4.Play(1);
				se4.SetVolume(0.5f);
				se4.SetLoopCount(1);
				rot[0] = false;

			}
		}
	}
	else
	{
		movable[0] = false;
	}

	if (blCheck3)
	{
		if ((movePuzzle->pipe->GetDirValue(NW) == puzzle1->pipe->GetDirValue(SE)) && (movePuzzle->pipe->GetDirValue(SE) == puzzle6->pipe->GetDirValue(NW)))
		{
			conecTcheck4_1 = true;
		}
		else
		{
			conecTcheck4_1 = false;
		}
	}

	if (blCheck3_2)
	{
		if ((movePuzzle->pipe->GetDirValue(W) == puzzle10->pipe->GetDirValue(E)) && (movePuzzle->pipe->GetDirValue(E) == endPuzzle->pipe->GetDirValue(W)))
		{
			conecTcheck4_1 = true;
		}
		else if ((movePuzzle->pipe->GetDirValue(E) == puzzle10->pipe->GetDirValue(W)) && (movePuzzle->pipe->GetDirValue(W) == endPuzzle->pipe->GetDirValue(E)))
		{
			conecTcheck4_1 = true;
		}
		else
		{
			conecTcheck4_1 = false;
		}
	}

	if (movePuzzle2->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle2->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[2])
		{
			movePuzzle2->mesh->setTransform({ cursor4.x, cursor4.y });
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
				degree4_2 += static_cast<float>(DegreeToRadian(60.f));
				movePuzzle2->mesh->setRotation(degree4_2);

				se4.Play(1);
				se4.SetVolume(0.5f);
				se4.SetLoopCount(1);
				rot[1] = false;
			}
		}
	}
	else
	{
		movable[1] = false;
	}

	if ((movePuzzle2->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle10->pipe->GetDirValue(NW)))
	{
		conecTcheck4_2 = true;
	}
	else
	{
		conecTcheck4_2 = false;
	}

	if (movePuzzle3->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle3->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1])
		{
			movePuzzle3->mesh->setTransform({ cursor4.x, cursor4.y });
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
				degree4_3 += static_cast<float>(DegreeToRadian(60.f));

				movePuzzle3->mesh->setRotation(degree4_3);

				se4.Play(1);
				se4.SetVolume(0.5f);
				se4.SetLoopCount(1);
				rot[2] = false;

			}
		}
	}
	else
	{
		movable[2] = false;
	}

	if (blCheck4)
	{
		if ((movePuzzle3->pipe->GetDirValue(NW) == puzzle1->pipe->GetDirValue(SE)) && (movePuzzle3->pipe->GetDirValue(SE) == puzzle6->pipe->GetDirValue(NW)))
		{
			std::cout << "pipe connect\n";
			conecTcheck4_3 = true;
		}
		else
		{
			conecTcheck4_3 = false;
		}
	}
	if (blCheck4_2)
	{
		if ((movePuzzle3->pipe->GetDirValue(W) == puzzle10->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(E) == endPuzzle->pipe->GetDirValue(W)))
		{
			conecTcheck4_3 = true;
		}
		else
		{
			conecTcheck4_3 = false;
		}
	}

	if (movable[0] == true)
	{
		if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh)))
		{
			if (mInput.IsPressed(KEY::LEFT) == false)
			{
				if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
					blCheck3 = true;
					blCheck3_2 = false;
				}

				if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					blCheck3 = false;
					blCheck3_2 = false;
				}

				if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					blCheck3 = false;
					blCheck3_2 = true;
				}
			}
		}
		else
		{
			conecTcheck4_1 = false;
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
				}
				if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh))
				{
					movePuzzle2->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
				}
				if (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh))
				{
					movePuzzle2->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
				}
			}
		}
		else
		{
			conecTcheck4_2 = false;
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
					blCheck4 = true;
					blCheck4_2 = false;
				}
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					blCheck4 = false;
					blCheck4_2 = false;
				}
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					blCheck4 = false;
					blCheck4_2 = true;
				}
			}
		}
		else
		{
			conecTcheck4_3 = false;
		}
	}

	if (playUI->collision->Point2BoxCollision({ cursor4.x,cursor4.y }, playUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			poopooCheck = true;
			
		}
	}
	else
	{
		connectMove4 = 0;
	}
	if(poopooCheck == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == false)
		{
			if (conecTcheck4_1 && conecTcheck4_2 && conecTcheck4_3)
			{
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext4 = 1;
				std::cout << "clear" << std::endl;
				mPooPoo.SetIsSuccess(true);

				playSE4.Play(1);
				playSE4.SetVolume(0.5f);
				playSE4.SetLoopCount(1);
				poopooCheck = false;
			}
		}
	}
	if (restartUI->collision->Point2BoxCollision({ cursor4.x,cursor4.y }, restartUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			STATE_MANAGER->ChangeLevel(LV_TEST4);
		}
	}


	if (optionUI->collision->Point2BoxCollision({ cursor4.x,cursor4.y }, optionUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			STATE_MANAGER->ChangeLevel(OPTION);
		}
	}

	if (quitUI->collision->Point2BoxCollision({ cursor4.x,cursor4.y }, quitUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			glfwTerminate();
		}
	}

	se4.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground4);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack4);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack4);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack4);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart4);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd4);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4_1);
	movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4_2);
	movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4_1);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton4);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear4);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace4);

	if (mPooPoo.IsFinish() == false)
	{
		mPooPoo.MoveInPuzzle(mShader2.GetShaderHandler());
	}
	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI4);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI4);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI4);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI4);


	if ((mInput.IsPressed(KEY::SPACE) == true && chekNext4 == 1) || (mInput.IsPressed(KEY::A) == true))
	{
		STATE_MANAGER->ChangeLevel(LV_TEST6);
		chekNext4 = 0;

		conecTcheck4_1 = false;
		conecTcheck4_2 = false;
		conecTcheck4_3 = false;

		degree4 = 0;
		degree4_2 = 0;
		degree4_3 = 0;

		blCheck3 = false;
		blCheck3_2 = false;

		blCheck4 = false;
		blCheck4_2 = false;
	}

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level4::Close()
{
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
