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

int movable4_1 = 0;
int movable4_2 = 0;
int movable4_3 = 0;

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


	if (key == GLFW_KEY_A && action == GLFW_PRESS)
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
		STATE_MANAGER->ChangeLevel(LV_TEST6);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}
}

void level4cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor4 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
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

		if (movable4_1 == 1)
		{
			movable4_1 = 0;
		}
		if (movable4_2 == 1)
		{
			movable4_2 = 0;
		}
		if (movable4_3 == 1)
		{
			movable4_3 = 0;
		}

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
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground4 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f }, 60.f);
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -184.f, 280.f });
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -48.f, 280.f });
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -252.f, 160.f }, 180.f);
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 22.8f, 160.f });
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -0.46f * 400, 0.1f * 400 }, 60.f);
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -0.115f * 400, 0.1f * 400 }, 300.f);
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.23f * 400, 0.1f * 400 }, 240.f);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.057f * 400, -0.2f * 400 }, 60.f);
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.4f * 400, -0.2f * 400 }, 60.f);
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -0.115f * 400, -0.5f * 400 }, 180.f);

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -0.29f * 400, 0.4f * 400 });
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -0.29f * 400, -0.2f * 400 });
	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 0.23f * 400, -0.5f * 400 });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -320.f, 280.f }, 120.f);
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 232.f, -200.f }, 60.f);
	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -0.7f * 400, -0.6f * 400 });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -10.0f * 400, 10.0f * 400 });
	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.0f * 400, -0.85f * 400 });

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

	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle3->pipe->SetDirection(true, false, false, true, false, false);
	endPuzzle->pipe->SetDirection(false, false, false, false, false, true);
	puzzle1->pipe->SetDirection(false, false, false, true, false, true);
	puzzle6->pipe->SetDirection(true, false, false, false, true, false);
	puzzle10->pipe->SetDirection(true, false, true, false, false, false);

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level4keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level4cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level4mouseButtonCallback);
}

void Level4::Update()
{
	if (check4 < 1)
	{
		check4++;
	}

	se4.Update();

	if (movePuzzle->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle->mesh))
	{
		if (moveCheck4 % 2 == 1)
		{
			if (movable4_1 == 0)
			{
				movable4_1 = 1;
			}
			/*movePuzzle->mesh->setTransform({ cursor4.x, cursor4.y });*/
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
	if (movable4_1 == 1)
	{
		movePuzzle->mesh->setTransform({ cursor4.x, cursor4.y });
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

	if (movePuzzle2->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle2->mesh))
	{
		if (moveCheck4_2 % 2 == 1)
		{
			if (movable4_2 == 0)
			{
				movable4_2 = 1;
			}
			/*movePuzzle2->mesh->setTransform({ cursor4.x, cursor4.y });*/
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
	if (movable4_2 == 1)
	{
		movePuzzle2->mesh->setTransform({ cursor4.x, cursor4.y });
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

	if (movePuzzle3->collision->Point2HexagonCollision({ cursor4.x,cursor4.y }, movePuzzle3->mesh))
	{
		if (moveCheck4_3 % 2 == 1)
		{
			if (movable4_3 == 0)
			{
				movable4_3 = 1;
			}
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
	if (movable4_3 == 1)
	{
		movePuzzle3->mesh->setTransform({ cursor4.x, cursor4.y });
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
	if (movable4_1 == 0)
	{
		if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh)))

		{
			if (moveCheck4 % 2 == 0)
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
			conecTcheck4_1 = false;
	}

	if (movable4_2 == 0)
	{
		if ((movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh)))
		{
			if (moveCheck4_2 % 2 == 0)
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
			conecTcheck4_2 = false;
	}

	if (movable4_3 == 0)
	{
		if ((movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh)))
		{
			if (moveCheck4_3 % 2 == 0)
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
			conecTcheck4_3 = false;
	}

	if (button->collision->Point2BoxCollision({ cursor4.x,cursor4.y }, button->mesh))
	{
		if (connectMove4 % 2 == 1)
		{
			if (conecTcheck4_1 && conecTcheck4_2 && conecTcheck4_3)
			{
				clear->mesh->setTransform({ -0.7f * 400, -0.6f * 400 });
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
