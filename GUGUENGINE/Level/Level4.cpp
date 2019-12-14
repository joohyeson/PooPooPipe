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

int check4 = 0;
Vector2<float> cursor4;

int moveCheck4 = 0;
int moveCheck4_2 = 0;
int moveCheck4_3 = 0;
int connectMove4 = 0;

float degree4 = 0;
float degree4_2 = 0;
float degree4_3 = 0;


int rightCheck4 = 0;
int rightCheck4_2 = 0;
int rightCheck4_3 = 0;

int chekNext4 = 0;

GLuint textureBackground4;

GLuint texureIdLine4;
GLuint texureIdCurve4;
GLuint texureIdBlack4;

GLuint texureIdStart4;
GLuint texureIdEnd4;

GLuint texureIdLine4_1;
GLuint texureIdCurve4_2;

GLuint texureIdbutton4;
GLuint texureIdclear4;
GLuint texureSpace4;
Sound se4;

bool conecTcheck4_1 = false;
bool conecTcheck4_2 = false;
bool conecTcheck4_3 = false;

bool blCheck3 = false;
bool blCheck3_2 = false;

bool blCheck4 = false;
bool blCheck4_2 = false;

void level4keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNext4 == 1)
	{
		STATE_MANAGER->ChangeLevel(MAINMENU);
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
}

void level4cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor4 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) - APPLICATION->height / 2) / (APPLICATION->height / 2) };
}

void  level4mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck4 += 1;
		moveCheck4_2 += 1;
		moveCheck4_3 += 1;
		connectMove4 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck4 = 1;
		rightCheck4_2 = 1;
		rightCheck4_3 = 1;

		std::cout << "rightCheck2: " << rightCheck4 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level4::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(10.f, 10.f);
	textureBackground4 = TEXTURE->CreateTexture("assets\\background.png", 0);

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
	se4.Init();
	se4.LoadMusic("assets\\coin.mp3");

	mShader.BuildColorShader();
	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->AddComponent(new PuzzleComponent());
	movePuzzle->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 0.8f, 0.7f });
	movePuzzle->mesh->InitializeColorMesh();

	movePuzzle2->AddComponent(new Mesh());
	movePuzzle2->AddComponent(new PuzzleComponent());
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle2->mesh->SetMeshType(hexagon);
	movePuzzle2->Init();
	movePuzzle2->mesh->setTransform({ 0.9f, 0.3f });
	movePuzzle2->mesh->InitializeColorMesh();

	movePuzzle3->AddComponent(new Mesh());
	movePuzzle3->AddComponent(new PuzzleComponent());
	movePuzzle3->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle3->mesh->SetMeshType(hexagon);
	movePuzzle3->Init();
	movePuzzle3->mesh->setTransform({ 1.0f, 0.0f });
	movePuzzle3->mesh->InitializeColorMesh();

	startPuzzle->AddComponent(new Mesh());
	startPuzzle->Init();
	startPuzzle->mesh->setTransform({ -0.8f, 0.7f });
	startPuzzle->mesh->setRotation(DegreeToRadian(-240.f));
	startPuzzle->mesh->InitializeTextureMesh();

	endPuzzle->AddComponent(new Mesh());
	endPuzzle->AddComponent(new PuzzleComponent());
	endPuzzle->mesh->setRotation(DegreeToRadian(60.f));
	endPuzzle->pipe->SetDirection(false, false, false, false, false, true);
	endPuzzle->Init();
	endPuzzle->mesh->setTransform({ 0.58f, -0.5f });
	endPuzzle->mesh->InitializeTextureMesh();

	puzzle1->AddComponent(new Mesh());
	puzzle1->AddComponent(new PuzzleComponent());
	puzzle1->pipe->SetDirection(false, false, false, true, false, true);
	puzzle1->Init();
	puzzle1->mesh->setTransform({ -0.46f, 0.7f });
	puzzle1->mesh->InitializeTextureMesh();

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	puzzle2->mesh->setTransform({ -0.12f, 0.7f });
	puzzle2->mesh->InitializeTextureMesh();

	puzzle3->AddComponent(new Mesh());
	puzzle3->Init();
	puzzle3->mesh->setTransform({ -0.63f, 0.4f });
	puzzle3->mesh->setRotation(DegreeToRadian(180.f));
	puzzle3->mesh->InitializeTextureMesh();

	puzzle4->AddComponent(new Mesh());
	puzzle4->Init();
	puzzle4->mesh->setTransform({ 0.057f, 0.4f });
	puzzle4->mesh->InitializeTextureMesh();

	puzzle5->AddComponent(new Mesh());
	puzzle5->Init();
	puzzle5->mesh->setTransform({ -0.46f, 0.1f });
	puzzle5->mesh->setRotation(DegreeToRadian(60.f));
	puzzle5->mesh->InitializeTextureMesh();

	puzzle6->AddComponent(new Mesh());
	puzzle6->AddComponent(new PuzzleComponent());
	puzzle6->Init();
	puzzle6->mesh->setTransform({ -0.115f, 0.1f });
	puzzle6->mesh->setRotation(DegreeToRadian(300.f));
	puzzle6->pipe->SetDirection(true, false, false, false, true, false);
	puzzle6->mesh->InitializeTextureMesh();

	puzzle7->AddComponent(new Mesh());
	puzzle7->Init();
	puzzle7->mesh->setTransform({ 0.23f, 0.1f });
	puzzle7->mesh->setRotation(DegreeToRadian(240.f));
	puzzle7->mesh->InitializeTextureMesh();

	puzzle8->AddComponent(new Mesh());
	puzzle8->Init();
	puzzle8->mesh->setTransform({ 0.057f, -0.2f });
	puzzle8->mesh->setRotation(DegreeToRadian(60.f));
	puzzle8->mesh->InitializeTextureMesh();

	puzzle9->AddComponent(new Mesh());
	puzzle9->Init();
	puzzle9->mesh->setTransform({ 0.4f, -0.2f });
	puzzle9->mesh->setRotation(DegreeToRadian(60.f));
	puzzle9->mesh->InitializeTextureMesh();

	puzzle10->AddComponent(new Mesh());
	puzzle10->AddComponent(new PuzzleComponent());
	puzzle10->Init();
	puzzle10->mesh->setTransform({ -0.115f, -0.5f });
	puzzle10->mesh->setRotation(DegreeToRadian(180.f));
	puzzle10->pipe->SetDirection(true, false, true, false, false, false);
	puzzle10->mesh->InitializeTextureMesh();

	blackPuzzle1->AddComponent(new Mesh());
	blackPuzzle1->Init();
	blackPuzzle1->mesh->setTransform({ -0.29f, 0.4f });
	blackPuzzle1->mesh->InitializeTextureMesh();

	blackPuzzle2->AddComponent(new Mesh());
	blackPuzzle2->Init();
	blackPuzzle2->mesh->setTransform({ -0.29f, -0.2f });
	blackPuzzle2->mesh->InitializeTextureMesh();

	blackPuzzle3->AddComponent(new Mesh());
	blackPuzzle3->Init();
	blackPuzzle3->mesh->setTransform({ 0.23f, -0.5f });
	blackPuzzle3->mesh->InitializeTextureMesh();

	button->AddComponent(new Mesh());
	button->mesh->setTransform({ -0.7f, -0.6f });
	button->mesh->SetMeshType(rectangle);
	button->Init();
	button->mesh->InitializeTextureMesh(1.f, 1.f);

	clear->AddComponent(new Mesh());
	clear->mesh->setTransform({ -10.0f, 10.0f });
	clear->mesh->SetMeshType(rectangle);
	clear->Init();
	clear->mesh->InitializeTextureMesh(1.f, 1.f);

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -0.85f });
	spacePress->mesh->SetMeshType(rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(5.f, 1.f);
	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), level4keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level4cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level4mouseButtonCallback);
}

void Level4::Update()
{
	if (check4 < 1)
	{
		check4++;
		std::cout << "HELLO" << std::endl;
	}

	se4.Update();

	float r = static_cast<float>(sqrt(5) / 10);

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

	if (cursor4.x <= (getOrigin1_1.x + r / 2) &&
		cursor4.x >= (getOrigin1_1.x - r / 2) &&
		cursor4.y <= (getOrigin1_1.y + r) &&
		cursor4.y >= (getOrigin1_1.y - r))
	{
		if (moveCheck4 % 2 == 1)
		{
			movePuzzle->mesh->setTransform({ cursor4.x, cursor4.y });
		}
		if (rightCheck4 != 0)
		{
			movePuzzle->pipe->Update();

			degree4 += static_cast<float>(DegreeToRadian(60.f));
			movePuzzle->mesh->setRotation(degree4);

			rightCheck4 = 0;

			se4.Play(1);
			se4.SetVolume(0.5f);
			se4.SetLoopCount(1);
		}		
	}
	else
	{
		moveCheck4 = 0;
		rightCheck4 = 0;
	}

	
	if (blCheck3)
	{
		if ((movePuzzle->pipe->GetDirValue(NW) == puzzle1->pipe->GetDirValue(SE)) && (movePuzzle->pipe->GetDirValue(SE) == puzzle6->pipe->GetDirValue(NW)))
		{
			//std::cout << "pipe connect\n";
			conecTcheck4_1 = true;
		}
		else
		{
			conecTcheck4_1 = false;
			//std::cout << "Not connect\n";
		}
	}
	
	if (blCheck3_2)
	{
		if ((movePuzzle->pipe->GetDirValue(W) == puzzle10->pipe->GetDirValue(E)) && (movePuzzle->pipe->GetDirValue(E) == endPuzzle->pipe->GetDirValue(W)))
		{
			conecTcheck4_1 = true;
			//std::cout << "pipe connect\n";
		}
		else if ((movePuzzle->pipe->GetDirValue(E) == puzzle10->pipe->GetDirValue(W)) && (movePuzzle->pipe->GetDirValue(W) == endPuzzle->pipe->GetDirValue(E)))
		{
			conecTcheck4_1 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck4_1 = false;
			//std::cout << "Not connect\n";
		}
	}
	
	if (cursor4.x <= (getOrigin2_1.x + r / 2) &&
		cursor4.x >= (getOrigin2_1.x - r / 2) &&
		cursor4.y <= (getOrigin2_1.y + r) &&
		cursor4.y >= (getOrigin2_1.y - r))
	{
		if (moveCheck4_2 % 2 == 1)
		{
			movePuzzle2->mesh->setTransform({ cursor4.x, cursor4.y });
		}
		if (rightCheck4_2 != 0)
		{
			movePuzzle2->pipe->Update();

			degree4_2 += static_cast<float>(DegreeToRadian(60.f));


			movePuzzle2->mesh->setRotation(degree4_2);

			rightCheck4_2 = 0;

			se4.Play(1);
			se4.SetVolume(0.5f);
			se4.SetLoopCount(1);
		}
	}
	else
	{
		moveCheck4_2 = 0;
		rightCheck4_2 = 0;
	}

	if ((movePuzzle2->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle2->pipe->GetDirValue(SE) == puzzle10->pipe->GetDirValue(NW)))
	{
		conecTcheck4_2 = true;
		//std::cout << "pipe connect\n";
	}
	else
	{
		conecTcheck4_2 = false;
		//std::cout << "Not connect\n";
	}
	
	if (cursor4.x <= (getOrigin3_1.x + r / 2) &&
		cursor4.x >= (getOrigin3_1.x - r / 2) &&
		cursor4.y <= (getOrigin3_1.y + r) &&
		cursor4.y >= (getOrigin3_1.y - r))
	{
		if (moveCheck4_3 % 2 == 1)
		{
			movePuzzle3->mesh->setTransform({ cursor4.x, cursor4.y });
		}
		if (rightCheck4_3 != 0)
		{
			movePuzzle3->pipe->Update();
			degree4_3 += static_cast<float>(DegreeToRadian(60.f));

			movePuzzle3->mesh->setRotation(degree4_3);

			rightCheck4_3 = 0;

			se4.Play(1);
			se4.SetVolume(0.5f);
			se4.SetLoopCount(1);
		}
	}
	else
	{
		moveCheck4_3 = 0;
		rightCheck4_3 = 0;
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
			//std::cout << "Not connect\n";
		}
	}
	if (blCheck4_2)
	{
		if ((movePuzzle3->pipe->GetDirValue(W) == puzzle10->pipe->GetDirValue(E)) && (movePuzzle3->pipe->GetDirValue(E) == endPuzzle->pipe->GetDirValue(W)))
		{
			conecTcheck4_3 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck4_3 = false;
			//std::cout << "Not connect\n";
		}
	}
	
	//
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
		if (moveCheck4 % 2 == 0)
		{
			if ((getOrigin1_1.x <= (getOrigin1_2.x + r / 2) &&
				getOrigin1_1.x >= (getOrigin1_2.x - r / 2) &&
				getOrigin1_1.y <= (getOrigin1_2.y + r) &&
				getOrigin1_1.y >= (getOrigin1_2.y - r)))
			{
				movePuzzle->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
				blCheck3 = true;
				blCheck3_2 = false;
			}

			if ((getOrigin1_1.x <= (getOrigin2_2.x + r / 2) &&
				getOrigin1_1.x >= (getOrigin2_2.x - r / 2) &&
				getOrigin1_1.y <= (getOrigin2_2.y + r) &&
				getOrigin1_1.y >= (getOrigin2_2.y - r)))
			{
				movePuzzle->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
				blCheck3 = false;
				blCheck3_2 = false;
			}

			if ((getOrigin1_1.x <= (getOrigin3_2.x + r / 2) &&
				getOrigin1_1.x >= (getOrigin3_2.x - r / 2) &&
				getOrigin1_1.y <= (getOrigin3_2.y + r) &&
				getOrigin1_1.y >= (getOrigin3_2.y - r)))
			{
				movePuzzle->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });
				blCheck3 = false;
				blCheck3_2 = true;
			}
		}
	}

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
		if (moveCheck4_2 % 2 == 0)
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

		if (moveCheck4_3 % 2 == 0)
		{
			if ((getOrigin3_1.x <= (getOrigin1_2.x + r / 2) &&
				getOrigin3_1.x >= (getOrigin1_2.x - r / 2) &&
				getOrigin3_1.y <= (getOrigin1_2.y + r) &&
				getOrigin3_1.y >= (getOrigin1_2.y - r)))
			{
				movePuzzle3->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
				blCheck4 = true;
				blCheck4_2 = false;
			}
			if ((getOrigin3_1.x <= (getOrigin2_2.x + r / 2) &&
				getOrigin3_1.x >= (getOrigin2_2.x - r / 2) &&
				getOrigin3_1.y <= (getOrigin2_2.y + r) &&
				getOrigin3_1.y >= (getOrigin2_2.y - r)))
			{
				movePuzzle3->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
				blCheck4 = false;
				blCheck4_2 = false;
			}
			if ((getOrigin3_1.x <= (getOrigin3_2.x + r / 2) &&
				getOrigin3_1.x >= (getOrigin3_2.x - r / 2) &&
				getOrigin3_1.y <= (getOrigin3_2.y + r) &&
				getOrigin3_1.y >= (getOrigin3_2.y - r)))
			{
				movePuzzle3->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });
				blCheck4 = false;
				blCheck4_2 = true;
			}
		}
	}

	if (cursor4.x <= (buttonClick_1.x + 0.5f) &&
		cursor4.x >= (buttonClick_1.x - 0.5f) &&
		cursor4.y <= (buttonClick_1.y + 0.5f) &&
		cursor4.y >= (buttonClick_1.y - 0.5f))
	{
		if (connectMove4 % 2 == 1)
		{
			if (conecTcheck4_1 && conecTcheck4_2 && conecTcheck4_3)
			{
				clear->mesh->setTransform({ -0.7f, -0.6f });
				chekNext4 = 1;
				std::cout << "clear" << std::endl;

			}
			connectMove4 = 0;
		}
	}
	else
	{
		connectMove4 = 0;
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
	
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level4::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
