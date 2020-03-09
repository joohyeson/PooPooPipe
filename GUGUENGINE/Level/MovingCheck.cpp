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
#include "MovingCheck.h"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/GenerateMap.h"

int chekNextTest = 0;

bool conecTCheckTest_1 = false;
bool conecTCheckTest_2 = false;
bool conecTCheckTest_3 = false;

bool blCheckTest3 = false;
bool blCheckTest3_2 = false;

bool blCheckTest = false;
bool blCheckTest_2 = false;

float degreeTest = 0;
float degreeTest_2 = 0;
float degreeTest_3 = 0;

int CheckTest = 0;
Vector2<float> cursor5;

int movableTest_1 = 0;
int movableTest_2 = 0;
int movableTest_3 = 0;

int moveCheckTest = 0;
int moveCheckTest_2 = 0;
int moveCheckTest_3 = 0;
int connectMove4Test = 0;

int rightCheckTest = 0;
int rightCheckTest_2 = 0;
int rightCheckTest_3 = 0;



void level5keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNextTest == 1)
	{
		STATE_MANAGER->ChangeLevel(MAINMENU);
		chekNextTest = 0;

		conecTCheckTest_1 = false;
		conecTCheckTest_2 = false;
		conecTCheckTest_3 = false;

		degreeTest = 0;
		degreeTest_2 = 0;
		degreeTest_3 = 0;

		blCheckTest3 = false;
		blCheckTest3_2 = false;

		blCheckTest = false;
		blCheckTest_2 = false;
	}


	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		chekNextTest = 0;

		conecTCheckTest_1 = false;
		conecTCheckTest_2 = false;
		conecTCheckTest_3 = false;

		degreeTest = 0;
		degreeTest_2 = 0;
		degreeTest_3 = 0;

		blCheckTest3 = false;
		blCheckTest3_2 = false;

		blCheckTest = false;
		blCheckTest_2 = false;
		STATE_MANAGER->ChangeLevel(MAINMENU);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}
}

void level5cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor5 = { static_cast<float>(xpos) - APPLICATION->height / 2 ,  -(static_cast<float>(ypos) - APPLICATION->width / 2) };
}

void  level5mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheckTest += 1;
		moveCheckTest_2 += 1;
		moveCheckTest_3 += 1;
		connectMove4Test += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;

		if (movableTest_1 == 1)
		{
			movableTest_1 = 0;
		}
		if (movableTest_2 == 1)
		{
			movableTest_2 = 0;
		}
		if (movableTest_3 == 1)
		{
			movableTest_3 = 0;
		}

	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheckTest = 1;
		rightCheckTest_2 = 1;
		rightCheckTest_3 = 1;

		std::cout << "rightCheck2: " << rightCheckTest << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void MovingCheck::Init()
{
	GenerateMap myMap(4, 4);
	myMap.GetNextCenterCoor(80);
	//background = OBJECT_FACTORY->CreateEmptyObject();

	//background->AddComponent(new Mesh());
	//background->Init();

	//background->mesh->setTransform({ 0,0 });
	//background->mesh->SetMeshType(rectangle);
	//background->mesh->InitializeTextureMesh(800.f, 800.f);
	//textureBackground4 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	movePuzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	movePuzzle3 = OBJECT_FACTORY->CreateEmptyObject();

	puzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle3 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle4 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle5 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle6 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle7 = OBJECT_FACTORY->CreateEmptyObject();

	puzzle8 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle9 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle10 = OBJECT_FACTORY->CreateEmptyObject();

	blackPuzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle3 = OBJECT_FACTORY->CreateEmptyObject();

	startPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	endPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	button = OBJECT_FACTORY->CreateEmptyObject();
	clear = OBJECT_FACTORY->CreateEmptyObject();
	spacePress = OBJECT_FACTORY->CreateEmptyObject();


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


	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->AddComponent(new PuzzleComponent());
	movePuzzle->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 320.f, 280.f });
	movePuzzle->mesh->InitializeTextureMesh();

	movePuzzle2->AddComponent(new Mesh());
	movePuzzle2->AddComponent(new PuzzleComponent());
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle2->mesh->SetMeshType(hexagon);
	movePuzzle2->Init();
	movePuzzle2->mesh->setTransform({ 360.f, 120.f });
	movePuzzle2->mesh->InitializeTextureMesh();

	movePuzzle3->AddComponent(new Mesh());
	movePuzzle3->AddComponent(new PuzzleComponent());
	movePuzzle3->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle3->mesh->SetMeshType(hexagon);
	movePuzzle3->Init();
	movePuzzle3->mesh->setTransform({ 400.0f, 0.0f });
	movePuzzle3->mesh->InitializeTextureMesh();

	startPuzzle->AddComponent(new Mesh());
	startPuzzle->Init();
	startPuzzle->mesh->setRotation(DegreeToRadian(-240.f));
	startPuzzle->mesh->InitializeTextureMesh();
	myMap.SaveObject(startPuzzle);
	
	puzzle1->AddComponent(new Mesh());
	puzzle1->AddComponent(new PuzzleComponent());
	puzzle1->pipe->SetDirection(false, false, false, true, false, true);
	puzzle1->Init();
	puzzle1->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle1);

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	puzzle2->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle2);


	puzzle3->AddComponent(new Mesh());
	puzzle3->Init();
	puzzle3->mesh->setRotation(DegreeToRadian(180.f));
	puzzle3->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle3);


	puzzle4->AddComponent(new Mesh());
	puzzle4->Init();
	puzzle4->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle4);


	puzzle5->AddComponent(new Mesh());
	puzzle5->Init();
	puzzle5->mesh->setRotation(DegreeToRadian(60.f));
	puzzle5->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle5);


	blackPuzzle1->AddComponent(new Mesh());
	blackPuzzle1->Init();
	blackPuzzle1->mesh->InitializeTextureMesh();
	myMap.SaveObject(blackPuzzle1);

	puzzle6->AddComponent(new Mesh());
	puzzle6->AddComponent(new PuzzleComponent());
	puzzle6->Init();
	puzzle6->mesh->setRotation(DegreeToRadian(300.f));
	puzzle6->pipe->SetDirection(true, false, false, false, true, false);
	puzzle6->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle6);


	puzzle7->AddComponent(new Mesh());
	puzzle7->Init();
	puzzle7->mesh->setRotation(DegreeToRadian(240.f));
	puzzle7->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle7);


	puzzle8->AddComponent(new Mesh());
	puzzle8->Init();
	puzzle8->mesh->setRotation(DegreeToRadian(60.f));
	puzzle8->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle8);


	blackPuzzle2->AddComponent(new Mesh());
	blackPuzzle2->Init();
	blackPuzzle2->mesh->InitializeTextureMesh();
	myMap.SaveObject(blackPuzzle2);


	puzzle9->AddComponent(new Mesh());
	puzzle9->AddComponent(new CollisionCheck());
	puzzle9->Init();
	puzzle9->mesh->setTransform({ 0.4f * 400, -0.2f * 400 });
	puzzle9->mesh->setRotation(DegreeToRadian(60.f));
	puzzle9->mesh->InitializeTextureMesh();
	//myMap.SaveObject(puzzle9);


	puzzle10->AddComponent(new Mesh());
	puzzle10->AddComponent(new PuzzleComponent());
	puzzle10->Init();
	puzzle10->mesh->setRotation(DegreeToRadian(180.f));
	puzzle10->pipe->SetDirection(true, false, true, false, false, false);
	puzzle10->mesh->InitializeTextureMesh();
	myMap.SaveObject(puzzle10);


	blackPuzzle3->AddComponent(new Mesh());
	blackPuzzle3->Init();
	blackPuzzle3->mesh->InitializeTextureMesh();
	myMap.SaveObject(blackPuzzle3);

	endPuzzle->AddComponent(new Mesh());
	endPuzzle->AddComponent(new PuzzleComponent());
	endPuzzle->mesh->setRotation(DegreeToRadian(60.f));
	endPuzzle->pipe->SetDirection(false, false, false, false, false, true);
	endPuzzle->Init();
	endPuzzle->mesh->InitializeTextureMesh();
	myMap.SaveObject(endPuzzle);


	button->AddComponent(new Mesh());
	button->AddComponent(new CollisionCheck());
	button->mesh->setTransform({ -0.7f * 400, -0.6f * 400 });
	button->mesh->SetMeshType(rectangle);
	button->Init();
	button->mesh->InitializeTextureMesh(80.f, 80.f);

	clear->AddComponent(new Mesh());
	clear->mesh->setTransform({ -10.0f * 400, 10.0f * 400 });
	clear->mesh->SetMeshType(rectangle);
	clear->Init();
	clear->mesh->InitializeTextureMesh(80.f, 80.f);

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f * 400, -0.85f * 400 });
	spacePress->mesh->SetMeshType(rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	myMap.MapAlignment();

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level5keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level5cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level5mouseButtonCallback);
}

void MovingCheck::Update()
{
	if (CheckTest < 1)
	{
		CheckTest++;
		std::cout << "HELLO" << std::endl;
	}


	float r = static_cast<float>(sqrt(5) / 10) * 400;

	getOrigin1_1.x = movePuzzle->mesh->GetTransform().x;
	getOrigin1_1.y = movePuzzle->mesh->GetTransform().y;

	getOrigin1_2.x = blackPuzzle1->mesh->GetTransform().x;
	getOrigin1_2.y = blackPuzzle1->mesh->GetTransform().y;

	getOrigin2_1.x = movePuzzle2->mesh->GetTransform().x;
	getOrigin2_1.y = movePuzzle2->mesh->GetTransform().y;

	getOrigin2_2.x = blackPuzzle2->mesh->GetTransform().x;
	getOrigin2_2.y = blackPuzzle2->mesh->GetTransform().y;

	getOrigin3_1.x = movePuzzle3->mesh->GetTransform().x;
	getOrigin3_1.y = movePuzzle3->mesh->GetTransform().y;

	getOrigin3_2.x = blackPuzzle3->mesh->GetTransform().x;
	getOrigin3_2.y = blackPuzzle3->mesh->GetTransform().y;

	buttonClick_1.x = button->mesh->GetTransform().x;
	buttonClick_1.y = button->mesh->GetTransform().y;

	if (cursor5.x <= (getOrigin1_1.x + r / 2) &&
		cursor5.x >= (getOrigin1_1.x - r / 2) &&
		cursor5.y <= (getOrigin1_1.y + r) &&
		cursor5.y >= (getOrigin1_1.y - r))
	{
		if (moveCheckTest % 2 == 1)
		{
			if (movableTest_1 == 0)
			{
				movableTest_1 = 1;
			}
			/*movePuzzle->mesh->setTransform({ cursor5.x, cursor5.y });*/
		}
		if (rightCheckTest != 0)
		{
			movePuzzle->pipe->Update();

			degreeTest += static_cast<float>(DegreeToRadian(60.f));
			movePuzzle->mesh->setRotation(degreeTest);

			rightCheckTest = 0;

		}
	}
	else
	{
		moveCheckTest = 0;
		rightCheckTest = 0;
	}
	if (movableTest_1 == 1)
	{
		movePuzzle->mesh->setTransform({ cursor5.x, cursor5.y });
	}

	if (blCheckTest3)
	{
		if ((movePuzzle->pipe->GetDirValue(NW) == puzzle1->pipe->GetDirValue(SE)) && (movePuzzle->pipe->GetDirValue(SE) == puzzle6->pipe->GetDirValue(NW)))
		{
			//std::cout << "pipe connect\n";
			conecTCheckTest_1 = true;
		}
		else
		{
			conecTCheckTest_1 = false;
			//std::cout << "Not connect\n";
		}
	}

	if (blCheckTest3_2)
	{
		if ((movePuzzle->pipe->GetDirValue(W) == puzzle10->pipe->GetDirValue(E)) && (movePuzzle->pipe->GetDirValue(E) == endPuzzle->pipe->GetDirValue(W)))
		{
			conecTCheckTest_1 = true;
			//std::cout << "pipe connect\n";
		}
		else if ((movePuzzle->pipe->GetDirValue(E) == puzzle10->pipe->GetDirValue(W)) && (movePuzzle->pipe->GetDirValue(W) == endPuzzle->pipe->GetDirValue(E)))
		{
			conecTCheckTest_1 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTCheckTest_1 = false;
			//std::cout << "Not connect\n";
		}
	}

	if (cursor5.x <= (getOrigin2_1.x + r / 2) &&
		cursor5.x >= (getOrigin2_1.x - r / 2) &&
		cursor5.y <= (getOrigin2_1.y + r) &&
		cursor5.y >= (getOrigin2_1.y - r))
	{
		if (moveCheckTest_2 % 2 == 1)
		{
			if (movableTest_2 == 0)
			{
				movableTest_2 = 1;
			}
			/*movePuzzle2->mesh->setTransform({ cursor5.x, cursor5.y });*/
		}
		if (rightCheckTest_2 != 0)
		{
			movePuzzle2->pipe->Update();

			degreeTest_2 += static_cast<float>(DegreeToRadian(60.f));


			movePuzzle2->mesh->setRotation(degreeTest_2);

			rightCheckTest_2 = 0;
		}
	}
	else
	{
		moveCheckTest_2 = 0;
		rightCheckTest_2 = 0;
	}
	if (movableTest_2 == 1)
	{
		movePuzzle2->mesh->setTransform({ cursor5.x, cursor5.y });
	}

	if ((movePuzzle2->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle10->pipe->GetDirValue(NW)))
	{
		conecTCheckTest_2 = true;
		//std::cout << "pipe connect\n";
	}
	else
	{
		conecTCheckTest_2 = false;
		//std::cout << "Not connect\n";
	}

	if (cursor5.x <= (getOrigin3_1.x + r / 2) &&
		cursor5.x >= (getOrigin3_1.x - r / 2) &&
		cursor5.y <= (getOrigin3_1.y + r) &&
		cursor5.y >= (getOrigin3_1.y - r))
	{
		if (moveCheckTest_3 % 2 == 1)
		{
			if (movableTest_3 == 0)
			{
				movableTest_3 = 1;
			}
		}
		if (rightCheckTest_3 != 0)
		{
			movePuzzle3->pipe->Update();
			degreeTest_3 += static_cast<float>(DegreeToRadian(60.f));

			movePuzzle3->mesh->setRotation(degreeTest_3);

			rightCheckTest_3 = 0;

		}
	}
	else
	{
		moveCheckTest_3 = 0;
		rightCheckTest_3 = 0;
	}
	if (movableTest_3 == 1)
	{
		movePuzzle3->mesh->setTransform({ cursor5.x, cursor5.y });
	}


	if (blCheckTest)
	{
		if ((movePuzzle3->pipe->GetDirValue(NW) == puzzle1->pipe->GetDirValue(SE)) && (movePuzzle3->pipe->GetDirValue(SE) == puzzle6->pipe->GetDirValue(NW)))
		{
			std::cout << "pipe connect\n";
			conecTCheckTest_3 = true;
		}
		else
		{
			conecTCheckTest_3 = false;
			//std::cout << "Not connect\n";
		}
	}
	if (blCheckTest_2)
	{
		if ((movePuzzle3->pipe->GetDirValue(W) == puzzle10->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(E) == endPuzzle->pipe->GetDirValue(W)))
		{
			conecTCheckTest_3 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTCheckTest_3 = false;
			//std::cout << "Not connect\n";
		}
	}

	//
	if (movableTest_1 == 0)
	{
		if ((getOrigin1_1.x <= (getOrigin1_2.x + r / 2) &&
			getOrigin1_1.x >= (getOrigin1_2.x - r / 2) &&
			getOrigin1_1.y <= (getOrigin1_2.y + r) &&
			getOrigin1_1.y >= (getOrigin1_2.y - r)) ||
			(getOrigin1_1.x <= (getOrigin2_2.x + r / 2) &&
				getOrigin1_1.x >= (getOrigin2_2.x - r / 2) &&
				getOrigin1_1.y <= (getOrigin2_2.y + r) &&
				getOrigin1_1.y >= (getOrigin2_2.y - r)) ||
				(getOrigin1_1.x <= (getOrigin3_2.x + r / 2) &&
					getOrigin1_1.x >= (getOrigin3_2.x - r / 2) &&
					getOrigin1_1.y <= (getOrigin3_2.y + r) &&
					getOrigin1_1.y >= (getOrigin3_2.y - r)))
		{
			if (moveCheckTest % 2 == 0)
			{
				if ((getOrigin1_1.x <= (getOrigin1_2.x + r / 2) &&
					getOrigin1_1.x >= (getOrigin1_2.x - r / 2) &&
					getOrigin1_1.y <= (getOrigin1_2.y + r) &&
					getOrigin1_1.y >= (getOrigin1_2.y - r)))
				{
					movePuzzle->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
					blCheckTest3 = true;
					blCheckTest3_2 = false;
				}

				if ((getOrigin1_1.x <= (getOrigin2_2.x + r / 2) &&
					getOrigin1_1.x >= (getOrigin2_2.x - r / 2) &&
					getOrigin1_1.y <= (getOrigin2_2.y + r) &&
					getOrigin1_1.y >= (getOrigin2_2.y - r)))
				{
					movePuzzle->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
					blCheckTest3 = false;
					blCheckTest3_2 = false;
				}

				if ((getOrigin1_1.x <= (getOrigin3_2.x + r / 2) &&
					getOrigin1_1.x >= (getOrigin3_2.x - r / 2) &&
					getOrigin1_1.y <= (getOrigin3_2.y + r) &&
					getOrigin1_1.y >= (getOrigin3_2.y - r)))
				{
					movePuzzle->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });
					blCheckTest3 = false;
					blCheckTest3_2 = true;
				}
			}
		}
	}

	if (movableTest_2 == 0)
	{
		if ((getOrigin2_1.x <= (getOrigin1_2.x + r / 2) &&
			getOrigin2_1.x >= (getOrigin1_2.x - r / 2) &&
			getOrigin2_1.y <= (getOrigin1_2.y + r) &&
			getOrigin2_1.y >= (getOrigin1_2.y - r)) ||
			(getOrigin2_1.x <= (getOrigin2_2.x + r / 2) &&
				getOrigin2_1.x >= (getOrigin2_2.x - r / 2) &&
				getOrigin2_1.y <= (getOrigin2_2.y + r) &&
				getOrigin2_1.y >= (getOrigin2_2.y - r)) ||
				(getOrigin2_1.x <= (getOrigin3_2.x + r / 2) &&
					getOrigin2_1.x >= (getOrigin3_2.x - r / 2) &&
					getOrigin2_1.y <= (getOrigin3_2.y + r) &&
					getOrigin2_1.y >= (getOrigin3_2.y - r))
			)
		{
			if (moveCheckTest_2 % 2 == 0)
			{
				if ((getOrigin2_1.x <= (getOrigin1_2.x + r / 2) &&
					getOrigin2_1.x >= (getOrigin1_2.x - r / 2) &&
					getOrigin2_1.y <= (getOrigin1_2.y + r) &&
					getOrigin2_1.y >= (getOrigin1_2.y - r)))
				{
					movePuzzle2->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
				}
				if ((getOrigin2_1.x <= (getOrigin2_2.x + r / 2) &&
					getOrigin2_1.x >= (getOrigin2_2.x - r / 2) &&
					getOrigin2_1.y <= (getOrigin2_2.y + r) &&
					getOrigin2_1.y >= (getOrigin2_2.y - r)))
				{
					movePuzzle2->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
				}
				if ((getOrigin2_1.x <= (getOrigin3_2.x + r / 2) &&
					getOrigin2_1.x >= (getOrigin3_2.x - r / 2) &&
					getOrigin2_1.y <= (getOrigin3_2.y + r) &&
					getOrigin2_1.y >= (getOrigin3_2.y - r)))
				{
					movePuzzle2->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });

				}
			}
		}
	}

	if (movableTest_3 == 0)
	{
		if ((getOrigin3_1.x <= (getOrigin1_2.x + r / 2) &&
			getOrigin3_1.x >= (getOrigin1_2.x - r / 2) &&
			getOrigin3_1.y <= (getOrigin1_2.y + r) &&
			getOrigin3_1.y >= (getOrigin1_2.y - r)) ||
			(getOrigin3_1.x <= (getOrigin2_2.x + r / 2) &&
				getOrigin3_1.x >= (getOrigin2_2.x - r / 2) &&
				getOrigin3_1.y <= (getOrigin2_2.y + r) &&
				getOrigin3_1.y >= (getOrigin2_2.y - r)) ||
				(getOrigin3_1.x <= (getOrigin3_2.x + r / 2) &&
					getOrigin3_1.x >= (getOrigin3_2.x - r / 2) &&
					getOrigin3_1.y <= (getOrigin3_2.y + r) &&
					getOrigin3_1.y >= (getOrigin3_2.y - r))
			)
		{

			if (moveCheckTest_3 % 2 == 0)
			{
				if ((getOrigin3_1.x <= (getOrigin1_2.x + r / 2) &&
					getOrigin3_1.x >= (getOrigin1_2.x - r / 2) &&
					getOrigin3_1.y <= (getOrigin1_2.y + r) &&
					getOrigin3_1.y >= (getOrigin1_2.y - r)))
				{
					movePuzzle3->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
					blCheckTest = true;
					blCheckTest_2 = false;
				}
				if ((getOrigin3_1.x <= (getOrigin2_2.x + r / 2) &&
					getOrigin3_1.x >= (getOrigin2_2.x - r / 2) &&
					getOrigin3_1.y <= (getOrigin2_2.y + r) &&
					getOrigin3_1.y >= (getOrigin2_2.y - r)))
				{
					movePuzzle3->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
					blCheckTest = false;
					blCheckTest_2 = false;
				}
				if ((getOrigin3_1.x <= (getOrigin3_2.x + r / 2) &&
					getOrigin3_1.x >= (getOrigin3_2.x - r / 2) &&
					getOrigin3_1.y <= (getOrigin3_2.y + r) &&
					getOrigin3_1.y >= (getOrigin3_2.y - r)))
				{
					movePuzzle3->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });
					blCheckTest = false;
					blCheckTest_2 = true;
				}
			}
		}
	}

	if (button->collision->Point2BoxCollision(cursor5, button->mesh)==true)
	{
		if (connectMove4Test % 2 == 1)
		{
			if (conecTCheckTest_1 && conecTCheckTest_2 && conecTCheckTest_3)
			{
				clear->mesh->setTransform({ -0.7f * 400, -0.6f * 400 });
				chekNextTest = 1;
				std::cout << "clear" << std::endl;

			}
			connectMove4Test = 0;
		}
	}
	else
	{
		connectMove4Test = 0;
	}

	//background->mesh->Update(mShader2.GetShaderHandler(), textureBackground4);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	if (puzzle9->collision->Point2HexagonCollision({ cursor5.x, cursor5.y }, puzzle9->mesh) == true)
	{
		puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	}
	else
	{
		puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack4);
	}
	
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

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void MovingCheck::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
