/*
 *hakyung.kim
 *12.13.2019
 *digipen.hagyeong@gmail.com
 *Level3.cpp
 *if you want to check pipe connect, you can remove "//"pipe connect
 *this is level3
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level3.h"
#include "../GUGUENGINE/Sound.h"

int check3 = 0;
Vector2<float> cursor3;

int coorcheck = 0;

int movable1 = 0;
int movable2 = 0;
int movable3 = 0;

int moveCheck3 = 0;
int moveCheck3_2 = 0;
int moveCheck3_3 = 0;
int connectMove = 0;
int LevelCheck = 0;

float degree2 = 0;
float degree2_2 = 0;
float degree2_3 = 0;

int rightCheck3 = 0;
int rightCheck3_2 = 0;
int rightCheck3_3 = 0;

int chekNext = 0;

GLuint textureBackground3;

GLuint texureIdLine3;
GLuint texureIdCurve3;
GLuint texureIdBlack3;

GLuint texureIdStart3;
GLuint texureIdEnd3;

GLuint texureIdLine3_1;
GLuint texureIdCurve3_2;

GLuint texureIdbutton3;
GLuint texureIdclear3;
GLuint texureSpace3;
GLint LevelPage;
Sound se3;

bool blCheck1 = false;
bool blCheck1_2 = false;

bool blCheck2 = false;
bool blCheck2_2 = false;

bool conecTcheck1 = false;
bool conecTcheck2 = false;
bool conecTcheck3 = false;

void level3keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNext == 1)
	{
		STATE_MANAGER->ChangeLevel(LV_TEST4);
		chekNext = 0;

		conecTcheck1 = false;
		conecTcheck2 = false;
		conecTcheck3 = false;

		degree2 = 0;
		degree2_2 = 0;
		degree2_3 = 0;

		blCheck1 = false;
		blCheck1_2 = false;

		blCheck2 = false;
		blCheck2_2 = false;

	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		degree2 = 0;
		degree2_2 = 0;
		degree2_3 = 0;

		blCheck1 = false;
		blCheck1_2 = false;

		blCheck2 = false;
		blCheck2_2 = false;


		STATE_MANAGER->ChangeLevel(LV_TEST4);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}

	if (key == GLFW_KEY_TAB)
	{
		if (coorcheck == 1)
		{
			coorcheck = 0;
		}

		coorcheck += 1;
	}
}

void level3cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor3 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
}

void  level3mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck3 += 1;
		moveCheck3_2 += 1;
		moveCheck3_3 += 1;
		LevelCheck += 1;
		connectMove += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;

		if (movable1 == 1)
		{
			movable1 = 0;
		}
		if (movable2 == 1)
		{
			movable2 = 0;
		}
		if (movable3 == 1)
		{
			movable3 = 0;
		}

	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck3 = 1;
		rightCheck3_2 = 1;
		rightCheck3_3 = 1;

		std::cout << "rightCheck2: " << rightCheck3 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level3::Init()
{
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground3 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f }, 0,
		false, false, false, true, false, true);
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f, 280.f }, 60.f);
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f, 280.f });
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f, 160.f }, 180.f);
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f, 160.f });
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f, 160.f }, 120.f);
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, 40.f }, 60.f);
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f, 40.f }, 240.f);
	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f, -80.0f });
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f, -80.f }, 60.f);
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f, -80.f }, 60.f);
	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f, -200.f }, 60.f);
	puzzle12 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f, -200.f });

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 140.f, 160.f });
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -64.f, 40.f });
	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -268.f, -80.f });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f, 280.f }, -240.f);
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, -200.f });

	Levelsel = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -100.f });

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });

	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.0f, -340.f });

	texureIdLine3 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack3 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve3 = TEXTURE->CreateTexture("assets\\image2.png", 0);

	texureIdStart3 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd3 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine3_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve3_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	LevelPage = TEXTURE->CreateTexture("assets\\LevelUI.png", 0);

	texureIdbutton3 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear3 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace3 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	se3.Init();
	se3.LoadMusic("assets\\coin.mp3");

	mShader2.BuildTextureShader();

	//movePuzzle->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle2->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle3->pipe->SetDirection(false, false, false, true, false, true);
	endPuzzle->pipe->SetDirection(true, false, false, false, false, false);
	puzzle2->pipe->SetDirection(false, false, false, true, false, true);
	puzzle6->pipe->SetDirection(false, false, true, false, true, false);
	puzzle7->pipe->SetDirection(false, true, false, false, false, true);

	Levelsel->mesh->InitializeTextureMesh(80.f, 80.f);
	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level3keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level3cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level3mouseButtonCallback);
}

void Level3::Update()
{
	if (Levelsel->collision->Point2BoxCollision({ cursor3.x,cursor3.y }, Levelsel->mesh) == true)
	{
		if (LevelCheck % 2 == 1)
		{
			std::cout << "check" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_SELECT);
		}
	}
	else
	{
		if (LevelCheck % 2 == 1)
		{
			LevelCheck = 0;
		}
	}

	//if(rotTime.getLimitTime() == 0)
	//{
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//	std::cout << "STOP" << std::endl;
	//}

	if (check3 < 1)
	{
		check3++;
	}

	se3.Update();

	if (movePuzzle->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle->mesh) == true)
	{
		if (moveCheck3 % 2 == 1)
		{
			if (movable1 == 0)
			{
				movable1 = 1;
			}
			//movePuzzle->mesh->setTransform({ cursor3.x, cursor3.y });
		}
		if (rightCheck3 != 0)
		{
			movePuzzle->pipe->Update();

			degree2 += static_cast<float>(DegreeToRadian(60.f));
			movePuzzle->mesh->setRotation(degree2);
			//rotTime.Update();
			//std::cout << "left rotTIme" << rotTime.getLimitTime() << " " << std::endl;
			rightCheck3 = 0;

			se3.Play(1);
			se3.SetVolume(0.5f);
			se3.SetLoopCount(1);
		}
	}
	else
	{
		//movable1 = 0;
		moveCheck3 = 0;
		rightCheck3 = 0;
	}
	if (movable1 == 1)
	{
		movePuzzle->mesh->setTransform({ cursor3.x, cursor3.y });
	}

	if (blCheck1)
	{
		if ((movePuzzle->pipe->GetDirValue(NW) == puzzle2->pipe->GetDirValue(SE)) && (movePuzzle->pipe->GetDirValue(SW) == puzzle7->pipe->GetDirValue(NE)))
		{
			//std::cout << "pipe connect\n";
			conecTcheck1 = true;
		}
		else
		{
			conecTcheck1 = false;
			//std::cout << "Not connect\n";
		}
	}
	if (blCheck1_2)
	{
		if ((movePuzzle->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle->pipe->GetDirValue(SE) == endPuzzle->pipe->GetDirValue(NW)))
		{
			conecTcheck1 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck1 = false;
			//std::cout << "Not connect\n";
		}
	}

	if (movePuzzle2->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle2->mesh) == true)
	{
		if (moveCheck3_2 % 2 == 1)
		{
			if (movable2 == 0)
			{
				movable2 = 1;
			}
			//movePuzzle2->mesh->setTransform({ cursor3.x, cursor3.y });
		}
		if (rightCheck3_2 != 0)
		{
			movePuzzle2->pipe->Update();

			degree2_2 += static_cast<float>(DegreeToRadian(60.f));
			movePuzzle2->mesh->setRotation(degree2_2);
			//rotTime.Update();
			//std::cout << "left rotTIme" << rotTime.getLimitTime() << " " << std::endl;

			rightCheck3_2 = 0;

			se3.Play(1);
			se3.SetVolume(0.5f);
			se3.SetLoopCount(1);
		}
	}
	else
	{
		moveCheck3_2 = 0;
		rightCheck3_2 = 0;
		//movable2 = 0;
	}
	if (movable2 == 1)
	{
		movePuzzle2->mesh->setTransform({ cursor3.x, cursor3.y });
	}

	if ((movePuzzle2->pipe->GetDirValue(E) == puzzle7->pipe->GetDirValue(W)) && (movePuzzle2->pipe->GetDirValue(W) == puzzle6->pipe->GetDirValue(E)))
	{
		conecTcheck2 = true;
		//std::cout << "pipe connect\n";
	}
	else
	{
		conecTcheck2 = false;
		//std::cout << "Not connect\n";
	}

	if (movePuzzle3->collision->Point2HexagonCollision({ cursor3.x,cursor3.y }, movePuzzle3->mesh) == true)

	{
		if (moveCheck3_3 % 2 == 1)
		{
			if (movable3 == 0)
			{
				movable3 = 1;
			}
			//movePuzzle3->mesh->setTransform({ cursor3.x, cursor3.y });
		}
		if (rightCheck3_3 != 0)
		{
			movePuzzle3->pipe->Update();
			degree2_3 += static_cast<float>(DegreeToRadian(60.f));
			movePuzzle3->mesh->setRotation(degree2_3);
			//rotTime.Update();
			//std::cout << "left rotTIme" << rotTime.getLimitTime() << " " << std::endl;
			rightCheck3_3 = 0;

			se3.Play(1);
			se3.SetVolume(0.5f);
			se3.SetLoopCount(1);
		}
	}
	else
	{
		moveCheck3_3 = 0;
		rightCheck3_3 = 0;
		//movable3 = 0;
	}
	if (movable3 == 1)
	{
		movePuzzle3->mesh->setTransform({ cursor3.x, cursor3.y });
	}

	if (blCheck2)
	{
		if ((movePuzzle3->pipe->GetDirValue(NW) == puzzle2->pipe->GetDirValue(SE)) && (movePuzzle3->pipe->GetDirValue(SW) == puzzle7->pipe->GetDirValue(NE)))
		{
			//std::cout << "pipe connect\n";
			conecTcheck3 = true;
		}
		else
		{
			conecTcheck3 = false;
			//std::cout << "Not connect\n";
		}
	}
	if (blCheck2_2)
	{
		if ((movePuzzle3->pipe->GetDirValue(NE) == puzzle6->pipe->GetDirValue(SW)) && (movePuzzle3->pipe->GetDirValue(SE) == endPuzzle->pipe->GetDirValue(NW)))
		{
			conecTcheck3 = true;
			//std::cout << "pipe connect\n";
		}
		else
		{
			conecTcheck3 = false;
			//std::cout << "Not connect\n";
		}
	}

	//

	if (movable1 == 0)
	{
		if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh)) || (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh)))
		{
			if (moveCheck3 % 2 == 0)
			{
				if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
					blCheck1 = true;
					blCheck1_2 = false;

				}
				else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					blCheck1_2 = false;
					blCheck1 = false;
				}
				else if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					blCheck1_2 = true;
					blCheck1 = false;

				}
			}
		}
		else
		{
			conecTcheck1 = false;
		}
	}

	if (movable2 == 0)
	{
		if ((movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle2->mesh)) || (movePuzzle2->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle2->mesh)))

		{
			if (moveCheck3_2 % 2 == 0)
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
			conecTcheck2 = false;
		}
	}

	if (movable3 == 0)
	{
		if ((movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh)) || (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh)))
		{
			if (moveCheck3_3 % 2 == 0)
			{
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle1->mesh->GetTransform().x,blackPuzzle1->mesh->GetTransform().y });
					blCheck2 = true;
					blCheck2_2 = false;
				}
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle2->mesh->GetTransform().x,blackPuzzle2->mesh->GetTransform().y });
					blCheck2 = false;
					blCheck2_2 = false;
				}
				if (movePuzzle3->collision->Point2HexagonCollision({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y }, movePuzzle3->mesh))
				{
					movePuzzle3->mesh->setTransform({ blackPuzzle3->mesh->GetTransform().x,blackPuzzle3->mesh->GetTransform().y });
					blCheck2 = false;
					blCheck2_2 = true;
				}
			}
		}
		else
		{
			conecTcheck3 = false;
		}
	}


	if (button->collision->Point2BoxCollision({ cursor3.x,cursor3.y }, button->mesh))
	{
		if (connectMove % 2 == 1)
		{
			if (conecTcheck1 && conecTcheck2 && conecTcheck3)
			{
				std::cout << "if 3" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext = 1;
				std::cout << "clear" << std::endl;
				connectMove = 0;
			}

		}
	}
	else
	{
		connectMove = 0;
	}
	se3.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground3);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart3);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd3);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3_2);
	movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3_1);
	movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3_2);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton3);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear3);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace3);
	Levelsel->mesh->Update(mShader2.GetShaderHandler(), LevelPage);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level3::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
