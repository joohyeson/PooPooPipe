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
	cursor3 = { static_cast<float>(xpos) - APPLICATION->height / 2 ,  -(static_cast<float>(ypos) - APPLICATION->width / 2) };
}

void  level3mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck3 += 1;
		moveCheck3_2 += 1;
		moveCheck3_3 += 1;
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
	background->mesh->InitializeTextureMesh(800.f, 800.f);
	textureBackground3 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f });
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f });
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f });

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f, 280.f });
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f, 280.f });
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f, 160.f });
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f, 160.f });
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f, 160.f });
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, 40.f });
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f, 40.f });
	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f, -80.0f });
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f, -80.f });
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f, -80.f });
	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f, -200.f });
	puzzle12 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f, -200.f });

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 140.f, 160.f });
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -64.f, 40.f });
	blackPuzzle3 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { -268.f, -80.f });

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f, 280.f });
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, -200.f });
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

	texureIdbutton3 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear3 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace3 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	se3.Init();
	se3.LoadMusic("assets\\coin.mp3");

	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle2->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle3->pipe->SetDirection(false, false, false, true, false, true);

	startPuzzle->mesh->setRotation(DegreeToRadian(-240.f));
	endPuzzle->pipe->SetDirection(true, false, false, false, false, false);

	puzzle1->mesh->setRotation(DegreeToRadian(60.f));
	puzzle1->coor->SetAngle();

	puzzle2->pipe->SetDirection(false, false, false, true, false, true);

	puzzle3->mesh->setRotation(DegreeToRadian(180.f));

	puzzle5->mesh->setRotation(DegreeToRadian(120.f));

	puzzle6->mesh->setRotation(DegreeToRadian(60.f));
	puzzle6->pipe->SetDirection(false, false, true, false, true, false);

	puzzle7->mesh->setRotation(DegreeToRadian(240.f));
	puzzle7->pipe->SetDirection(false, true, false, false, false, true);

	puzzle9->mesh->setRotation(DegreeToRadian(60.f));

	puzzle10->mesh->setRotation(DegreeToRadian(60.f));

	puzzle11->mesh->setRotation(DegreeToRadian(60.f));

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level3keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level3cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level3mouseButtonCallback);
}

void Level3::Update()
{
	if (coorcheck == 1)
	{
		Vector2<float> origin = puzzle1->mesh->GetTransform();
		Vector2<float> coordi = { 0, 0 };
		std::cout << "puzzle1 center : " << origin.x << " , " << origin.y << std::endl;

		coordi = puzzle1->coor->ReturnPuzzleCoor(origin,
			DirAngle::NE_, 80.f);
		std::cout << "puzzle1 NE_ : " <<
			coordi.x << " , " << coordi.y << std::endl;

		coordi = puzzle1->coor->ReturnPuzzleCoor(origin,
			DirAngle::N_, 80.f);
		std::cout << "puzzle1 N_ : " <<
			coordi.x << " , " << coordi.y << std::endl;

		coordi = puzzle1->coor->ReturnPuzzleCoor(origin,
			DirAngle::NW_, 80.f);
		std::cout << "puzzle1 NW_ : " <<
			coordi.x << " , " << coordi.y << std::endl;
		//
		button->mesh->setTransform({ coordi.x, coordi.y });
		//
		coordi = puzzle1->coor->ReturnPuzzleCoor(origin,
			DirAngle::SW_, 80.f);
		std::cout << "puzzle1 SW_ : " <<
			coordi.x << " , " << coordi.y << std::endl;

		coordi = puzzle1->coor->ReturnPuzzleCoor(origin,
			DirAngle::S_, 80.f);
		std::cout << "puzzle1 S_, : " <<
			coordi.x << " , " << coordi.y << std::endl;

		coordi = puzzle1->coor->ReturnPuzzleCoor(origin,
			DirAngle::SE_, 80.f);
		std::cout << "puzzle1 SE_, : " <<
			coordi.x << " , " << coordi.y << std::endl;

		coorcheck = 0;
	}



	if (check3 < 1)
	{
		check3++;
	}

	se3.Update();

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

	if (cursor3.x <= (getOrigin1_1.x + (r / 2) * 400) &&
		cursor3.x >= (getOrigin1_1.x - (r / 2) * 400) &&
		cursor3.y <= (getOrigin1_1.y + r * 400) &&
		cursor3.y >= (getOrigin1_1.y - r * 400))
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

			rightCheck3 = 0;

			std::cout << "this is 2" << std::endl;
			std::cout << puzzle2->pipe->GetDirValue(NW) << std::endl;
			std::cout << puzzle2->pipe->GetDirValue(NE) << std::endl;
			std::cout << puzzle2->pipe->GetDirValue(E) << std::endl;
			std::cout << puzzle2->pipe->GetDirValue(SE) << std::endl;
			std::cout << puzzle2->pipe->GetDirValue(SW) << std::endl;
			std::cout << puzzle2->pipe->GetDirValue(W) << std::endl;

			std::cout << "movepuzzle" << std::endl;
			std::cout << movePuzzle->pipe->GetDirValue(NW) << std::endl;
			std::cout << movePuzzle->pipe->GetDirValue(NE) << std::endl;
			std::cout << movePuzzle->pipe->GetDirValue(E) << std::endl;
			std::cout << movePuzzle->pipe->GetDirValue(SE) << std::endl;
			std::cout << movePuzzle->pipe->GetDirValue(SW) << std::endl;
			std::cout << movePuzzle->pipe->GetDirValue(W) << std::endl;

			std::cout << "this is 7" << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(NW) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(NE) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(E) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(SE) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(SW) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(W) << std::endl;
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

	if (cursor3.x <= (getOrigin2_1.x + (r / 2) * 400) &&
		cursor3.x >= (getOrigin2_1.x - (r / 2) * 400) &&
		cursor3.y <= (getOrigin2_1.y + r * 400) &&
		cursor3.y >= (getOrigin2_1.y - r * 400))
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

			rightCheck3_2 = 0;

			std::cout << "this is 6" << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(NW) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(NE) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(E) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(SE) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(SW) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(W) << std::endl;

			std::cout << "movepuzzle2" << std::endl;
			std::cout << movePuzzle2->pipe->GetDirValue(NW) << std::endl;
			std::cout << movePuzzle2->pipe->GetDirValue(NE) << std::endl;
			std::cout << movePuzzle2->pipe->GetDirValue(E) << std::endl;
			std::cout << movePuzzle2->pipe->GetDirValue(SE) << std::endl;
			std::cout << movePuzzle2->pipe->GetDirValue(SW) << std::endl;
			std::cout << movePuzzle2->pipe->GetDirValue(W) << std::endl;

			std::cout << "this is 7" << std::endl;

			std::cout << puzzle7->pipe->GetDirValue(NW) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(NE) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(E) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(SE) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(SW) << std::endl;
			std::cout << puzzle7->pipe->GetDirValue(W) << std::endl;

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

	if (cursor3.x <= (getOrigin3_1.x + (r / 2) * 400) &&
		cursor3.x >= (getOrigin3_1.x - (r / 2) * 400) &&
		cursor3.y <= (getOrigin3_1.y + r * 400) &&
		cursor3.y >= (getOrigin3_1.y - r * 400))
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

			rightCheck3_3 = 0;

			std::cout << "this is 6" << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(NW) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(NE) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(E) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(SE) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(SW) << std::endl;
			std::cout << puzzle6->pipe->GetDirValue(W) << std::endl;

			std::cout << "this is movepuzzle3" << std::endl;
			std::cout << movePuzzle3->pipe->GetDirValue(NW) << std::endl;
			std::cout << movePuzzle3->pipe->GetDirValue(NE) << std::endl;
			std::cout << movePuzzle3->pipe->GetDirValue(E) << std::endl;
			std::cout << movePuzzle3->pipe->GetDirValue(SE) << std::endl;
			std::cout << movePuzzle3->pipe->GetDirValue(SW) << std::endl;
			std::cout << movePuzzle3->pipe->GetDirValue(W) << std::endl;

			std::cout << "this is endpuzzle" << std::endl;
			std::cout << endPuzzle->pipe->GetDirValue(NW) << std::endl;
			std::cout << endPuzzle->pipe->GetDirValue(NE) << std::endl;
			std::cout << endPuzzle->pipe->GetDirValue(E) << std::endl;
			std::cout << endPuzzle->pipe->GetDirValue(SE) << std::endl;
			std::cout << endPuzzle->pipe->GetDirValue(SW) << std::endl;
			std::cout << endPuzzle->pipe->GetDirValue(W) << std::endl;

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
		if ((getOrigin1_1.x <= (getOrigin1_2.x + (r / 2) * 400) &&
			getOrigin1_1.x >= (getOrigin1_2.x - (r / 2) * 400) &&
			getOrigin1_1.y <= (getOrigin1_2.y + r * 400) &&
			getOrigin1_1.y >= (getOrigin1_2.y - r * 400)) ||
			(getOrigin1_1.x <= (getOrigin2_2.x + (r / 2) * 400) &&
				getOrigin1_1.x >= (getOrigin2_2.x - (r / 2) * 400) &&
				getOrigin1_1.y <= (getOrigin2_2.y + r * 400) &&
				getOrigin1_1.y >= (getOrigin2_2.y - r * 400)) ||
				(getOrigin1_1.x <= (getOrigin3_2.x + (r / 2) * 400) &&
					getOrigin1_1.x >= (getOrigin3_2.x - (r / 2) * 400) &&
					getOrigin1_1.y <= (getOrigin3_2.y + r * 400) &&
					getOrigin1_1.y >= (getOrigin3_2.y - r * 400)))
		{
			if (moveCheck3 % 2 == 0)
			{
				if ((getOrigin1_1.x <= (getOrigin1_2.x + (r / 2) * 400) &&
					getOrigin1_1.x >= (getOrigin1_2.x - (r / 2) * 400) &&
					getOrigin1_1.y <= (getOrigin1_2.y + r * 400) &&
					getOrigin1_1.y >= (getOrigin1_2.y - r * 400)))
				{
					movePuzzle->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
					blCheck1 = true;
					blCheck1_2 = false;

				}
				else if ((getOrigin1_1.x <= (getOrigin2_2.x + (r / 2) * 400) &&
					getOrigin1_1.x >= (getOrigin2_2.x - (r / 2) * 400) &&
					getOrigin1_1.y <= (getOrigin2_2.y + r * 400) &&
					getOrigin1_1.y >= (getOrigin2_2.y - r * 400)))
				{
					movePuzzle->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
					blCheck1_2 = false;
					blCheck1 = false;
				}
				else if ((getOrigin1_1.x <= (getOrigin3_2.x + (r / 2) * 400) &&
					getOrigin1_1.x >= (getOrigin3_2.x - (r / 2) * 400) &&
					getOrigin1_1.y <= (getOrigin3_2.y + r * 400) &&
					getOrigin1_1.y >= (getOrigin3_2.y - r * 400)))
				{
					movePuzzle->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });
					blCheck1_2 = true;
					blCheck1 = false;

				}
			}
		}
	}

	if (movable2 == 0)
	{
		if ((getOrigin2_1.x <= (getOrigin1_2.x + (r / 2) * 400) &&
			getOrigin2_1.x >= (getOrigin1_2.x - (r / 2) * 400) &&
			getOrigin2_1.y <= (getOrigin1_2.y + r * 400) &&
			getOrigin2_1.y >= (getOrigin1_2.y - r * 400)) ||
			(getOrigin2_1.x <= (getOrigin2_2.x + (r / 2) * 400) &&
				getOrigin2_1.x >= (getOrigin2_2.x - (r / 2) * 400) &&
				getOrigin2_1.y <= (getOrigin2_2.y + r * 400) &&
				getOrigin2_1.y >= (getOrigin2_2.y - r * 400)) ||
				(getOrigin2_1.x <= (getOrigin3_2.x + (r / 2) * 400) &&
					getOrigin2_1.x >= (getOrigin3_2.x - (r / 2) * 400) &&
					getOrigin2_1.y <= (getOrigin3_2.y + r * 400) &&
					getOrigin2_1.y >= (getOrigin3_2.y - r * 400))
			)
		{
			if (moveCheck3_2 % 2 == 0)
			{
				if ((getOrigin2_1.x <= (getOrigin1_2.x + (r / 2) * 400) &&
					getOrigin2_1.x >= (getOrigin1_2.x - (r / 2) * 400) &&
					getOrigin2_1.y <= (getOrigin1_2.y + r * 400) &&
					getOrigin2_1.y >= (getOrigin1_2.y - r * 400)))
				{
					movePuzzle2->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
				}
				if ((getOrigin2_1.x <= (getOrigin2_2.x + (r / 2) * 400) &&
					getOrigin2_1.x >= (getOrigin2_2.x - (r / 2) * 400) &&
					getOrigin2_1.y <= (getOrigin2_2.y + r * 400) &&
					getOrigin2_1.y >= (getOrigin2_2.y - r * 400)))
				{
					movePuzzle2->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
				}
				if ((getOrigin2_1.x <= (getOrigin3_2.x + (r / 2) * 400) &&
					getOrigin2_1.x >= (getOrigin3_2.x - (r / 2) * 400) &&
					getOrigin2_1.y <= (getOrigin3_2.y + r * 400) &&
					getOrigin2_1.y >= (getOrigin3_2.y - r * 400)))
				{
					movePuzzle2->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });
				}
			}
		}
	}

	if (movable3 == 0)
	{
		if ((getOrigin3_1.x <= (getOrigin1_2.x + (r / 2) * 400) &&
			getOrigin3_1.x >= (getOrigin1_2.x - (r / 2) * 400) &&
			getOrigin3_1.y <= (getOrigin1_2.y + r * 400) &&
			getOrigin3_1.y >= (getOrigin1_2.y - r * 400)) ||
			(getOrigin3_1.x <= (getOrigin2_2.x + (r / 2) * 400) &&
				getOrigin3_1.x >= (getOrigin2_2.x - (r / 2) * 400) &&
				getOrigin3_1.y <= (getOrigin2_2.y + r * 400) &&
				getOrigin3_1.y >= (getOrigin2_2.y - r * 400)) ||
				(getOrigin3_1.x <= (getOrigin3_2.x + (r / 2) * 400) &&
					getOrigin3_1.x >= (getOrigin3_2.x - (r / 2) * 400) &&
					getOrigin3_1.y <= (getOrigin3_2.y + r * 400) &&
					getOrigin3_1.y >= (getOrigin3_2.y - r * 400))
			)
		{
			if (moveCheck3_3 % 2 == 0)
			{
				if ((getOrigin3_1.x <= (getOrigin1_2.x + (r / 2) * 400) &&
					getOrigin3_1.x >= (getOrigin1_2.x - (r / 2) * 400) &&
					getOrigin3_1.y <= (getOrigin1_2.y + r * 400) &&
					getOrigin3_1.y >= (getOrigin1_2.y - r * 400)))
				{
					movePuzzle3->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
					blCheck2 = true;
					blCheck2_2 = false;
				}
				if ((getOrigin3_1.x <= (getOrigin2_2.x + (r / 2) * 400) &&
					getOrigin3_1.x >= (getOrigin2_2.x - (r / 2) * 400) &&
					getOrigin3_1.y <= (getOrigin2_2.y + r * 400) &&
					getOrigin3_1.y >= (getOrigin2_2.y - r * 400)))
				{
					movePuzzle3->mesh->setTransform({ getOrigin2_2.x,getOrigin2_2.y });
					blCheck2 = false;
					blCheck2_2 = false;
				}
				if ((getOrigin3_1.x <= (getOrigin3_2.x + (r / 2) * 400) &&
					getOrigin3_1.x >= (getOrigin3_2.x - (r / 2) * 4002) &&
					getOrigin3_1.y <= (getOrigin3_2.y + r * 400) &&
					getOrigin3_1.y >= (getOrigin3_2.y - r * 400)))
				{
					movePuzzle3->mesh->setTransform({ getOrigin3_2.x,getOrigin3_2.y });
					blCheck2 = false;
					blCheck2_2 = true;
				}
			}
		}
	}


	if (cursor3.x <= (buttonClick_1.x + 200.f) &&
		cursor3.x >= (buttonClick_1.x - 200.f) &&
		cursor3.y <= (buttonClick_1.y + 200.f) &&
		cursor3.y >= (buttonClick_1.y - 200.f))
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
