
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level5.h"
#include "../GUGUENGINE/Sound.h"

Sound se5;
Sound playSE5;

void Level5::Init()
{
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
	textureBackground5 = TEXTURE->CreateTexture("assets\\background.png", 0);


	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 800.f, 300.f });
	playUI->mesh->SetMeshType(rectangle);
	playUI->mesh->InitializeTextureMesh(150.f, 150.f);
	texturePlayUI5 = TEXTURE->CreateTexture("assets\\playUI.png", 0);


	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->SetMeshType(rectangle);
	quitUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureQuitUI5 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 800.f, 0.f });
	optionUI->mesh->SetMeshType(rectangle);
	optionUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureOptionUI5 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->SetMeshType(rectangle);
	restartUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureRestartUI5 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);


	texureIdLine5 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack5 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve5 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree5 = TEXTURE->CreateTexture("assets\\image3.png", 0);

	textureIdMove5 = TEXTURE->CreateTexture("assets\\image5.png", 0);

	texureIdV5 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart5 = TEXTURE->CreateTexture("assets\\imageStart2.png", 0);
	texureIdEnd5 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine5_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve5_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	texureIdbutton5 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear5 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace5 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	se5.Init();
	se5.LoadSE("assets\\coin.mp3");

	playSE5.Init();
	playSE5.LoadSE("assets\\flushing.wav");

	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f });
	movePuzzle->pipe->SetDirection(false, false, false, true, false, true);

	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);

	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });
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

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, 40.f - 5.f }, 240);
	puzzle7->pipe->SetDirection(false, true, true, false, true, false);

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

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -240.f });
	button->mesh->InitializeTextureMesh(80.f, 80.f);

	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	clear->mesh->InitializeTextureMesh(80.f, 80.f);

	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -20.0f, -340.f - 20.f });
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);


	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, blackPuzzle2->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle7->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, blackPuzzle3->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::NE_, puzzle11->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::NE_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, endPuzzle->mesh->GetTransform());


	mInput.InitCallback(APPLICATION->getMyWindow());

}

void Level5::Update()
{
	cursor5 = mInput.Cursor;

	se5.Update();
	playSE5.Update();

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


				se5.Play(1);
				se5.SetVolume(0.5f);
				se5.SetLoopCount(1);
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

				se5.Play(1);
				se5.SetVolume(0.5f);
				se5.SetLoopCount(1);
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

					se5.Play(1);
					se5.SetVolume(0.5f);
					se5.SetLoopCount(1);
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


	if (playUI->collision->Point2BoxCollision({ cursor5.x,cursor5.y }, playUI->mesh))
	{
		std::cout << "1: " << conecTcheck5_1 << "2: " << conecTcheck5_2 << "3: " << conecTcheck5_2 << std::endl;

		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			poopooCheck = true;

			

			
		}		
	}
	else
	{
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

				se5.Play(1);
				se5.SetVolume(0.5f);
				se5.SetLoopCount(1);

				movePuzzleCheck5 = false;

				if (!conecTcheck5_1 || !conecTcheck5_2 || !conecTcheck5_3)
				{
					std::cout << "fail" << std::endl;
					//STATE_MANAGER->ReloadState();
				}
			}
			
			if (conecTcheck5_1 && conecTcheck5_2 && conecTcheck5_3)
			{
				std::cout << "if 3" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext5 = 1;
				std::cout << "clear" << std::endl;
				mPooPoo.SetIsSuccess(true);
				connectMove5 = 0;

				playSE5.Play(1);
				playSE5.SetVolume(0.5f);
				playSE5.SetLoopCount(1);

				poopooCheck = false;
			}
		}
	}
	
	if (restartUI->collision->Point2BoxCollision({ cursor5.x,cursor5.y }, restartUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			STATE_MANAGER->ReloadState();
		}
	}



	if (optionUI->collision->Point2BoxCollision({ cursor5.x,cursor5.y }, optionUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			STATE_MANAGER->ChangeLevel(OPTION);
		}
	}


	if (quitUI->collision->Point2BoxCollision({ cursor5.x,cursor5.y }, quitUI->mesh))
	{
		if (mInput.IsPressed(KEY::LEFT) == true && !movable[0] && !movable[1] && !movable[2])
		{
			glfwTerminate();
		}
	}


	se5.Update();

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

	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI5);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI5);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI5);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI5);

	if (mPooPoo.IsFinish() == false)
	{
		mPooPoo.MoveInPuzzle(mShader2.GetShaderHandler());
	}
	if ((mInput.IsPressed(KEY::SPACE) == true && chekNext5 == 1) || mInput.IsPressed(KEY::A) == true)
	{
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
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
