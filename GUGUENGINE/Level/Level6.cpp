
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level6.h"
#include "../GUGUENGINE/Sound.h"

int check6 = 0;
Vector2<float> cursor6;

int coorcheck6 = 0;

int connectMove6 = 0;

float degree6 = DegreeToRadian(60.f);
float degree6_2 = DegreeToRadian(-60.f);
float degree6_3 = DegreeToRadian(120.f);
float degree6_4 = DegreeToRadian(180.f);
float degree6_5 = DegreeToRadian(-180.f);
float degree6_6 = DegreeToRadian(-120.f);

int rightCheck6 = 0;
int rightCheck6_2 = 0;
int rightCheck6_3 = 0;
int rightCheck6_4 = 0;
int rightCheck6_5 = 0;
int rightCheck6_6 = 0;

bool rotrot = true;

int chekNext6 = 0;

GLuint textureBackground6;

GLuint texureIdLine6;
GLuint texureIdCurve6;
GLuint texureIdThree6;
GLuint texureIdV6;
GLuint texureIdBlack6;

GLuint texureIdStart6;
GLuint texureIdEnd6;

GLuint texureIdLine6_1;
GLuint texureIdCurve6_2;

GLuint texureIdbutton6;
GLuint texureIdclear6;
GLuint texureSpace6;

Sound se6;

bool conecTcheck6_1 = false;
bool conecTcheck6_2 = false;
bool conecTcheck6_3 = false;
bool conecTcheck6_4 = false;
bool conecTcheck6_5 = false;


void level6keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNext6 == 1)
	{
		STATE_MANAGER->ChangeLevel(LV_TEST8);
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
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		degree6 = DegreeToRadian(60.f);
		degree6_2 = DegreeToRadian(-60.f);
		degree6_3 = DegreeToRadian(120.f);
		degree6_4 = DegreeToRadian(180.f);
		degree6_5 = DegreeToRadian(-180.f);
		degree6_6 = DegreeToRadian(-120.f);

		STATE_MANAGER->ChangeLevel(LV_TEST8);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}

	if (key == GLFW_KEY_TAB)
	{
		if (coorcheck6 == 1)
		{
			coorcheck6 = 0;
		}

		coorcheck6 += 1;
	}
}

void level6cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor6 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
}
void  level6mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		connectMove6 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck6 = 1;
		rightCheck6_2 = 1;
		rightCheck6_3 = 1;
		rightCheck6_4 = 1;
		rightCheck6_5 = 1;
		rightCheck6_6 = 1;

		std::cout << "rightCheck2: " << rightCheck6 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level6::Init()
{
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground6 = TEXTURE->CreateTexture("assets\\background.png", 0);	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine6 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack6 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve6 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree6 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV6 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart6 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd6 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine6_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve6_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	texureIdbutton6 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear6 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace6 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	
	se6.Init();
	se6.LoadSE("assets\\coin.mp3");

	mShader2.BuildTextureShader();

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f - 465.f, 280.f + 50.f }, -240.f);
	startPuzzle->pipe->SetDirection(true, false, false, true, false, false);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);

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

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -20.0f, -340.f - 20.f });

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level6keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level6cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level6mouseButtonCallback);
}

void Level6::Update()
{
	if (check6 < 1)
	{
		check6++;
	}

	if (rotTime.getLimitTime() == 0)
	{
		rotrot = false;
	}

	se6.Update();

	if (rotrot)
	{
		if (puzzle14->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle14->mesh))
		{
			if (rightCheck6 != 0)
			{
				puzzle14->pipe->Update();

				degree6 += static_cast<float>(DegreeToRadian(60.f));
				std::cout << "1" << std::endl;
				puzzle14->mesh->setRotation(degree6);
				rotTime.Update();
				rightCheck6 = 0;
				se6.Play(1);
				se6.SetVolume(0.5f);
				se6.SetLoopCount(1);
			}
		}
		else
		{
			rightCheck6 = 0;
		}

		if (blackPuzzle1->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, blackPuzzle1->mesh))
		{
			if (rightCheck6_2 != 0)
			{
				blackPuzzle1->pipe->Update();
				degree6_2 += static_cast<float>(DegreeToRadian(60.f));
				std::cout << "2" << std::endl;
				blackPuzzle1->mesh->setRotation(degree6_2);
				rightCheck6_2 = 0;
				rotTime.Update();
				se6.Play(1);
				se6.SetVolume(0.5f);
				se6.SetLoopCount(1);
			}
		}
		else
		{
			rightCheck6_2 = 0;
		}


		if (puzzle7->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle7->mesh))
		{
			if (rightCheck6_3 != 0)
			{
				puzzle7->pipe->Update();
				degree6_3 += static_cast<float>(DegreeToRadian(60.f));
				puzzle7->mesh->setRotation(degree6_3);
				rightCheck6_3 = 0;
				rotTime.Update();
				se6.Play(1);
				se6.SetVolume(0.5f);
				se6.SetLoopCount(1);
			}
		}
		else
		{
			rightCheck6_3 = 0;
		}

		if (blackPuzzle3->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, blackPuzzle3->mesh))
		{
			if (rightCheck6_4 != 0)
			{
				blackPuzzle3->pipe->Update();
				degree6_4 += (60.f);
				blackPuzzle3->mesh->setRotation(static_cast<float>((DegreeToRadian(degree6_4))));
				std::cout << "4" << std::endl;
				rightCheck6_4 = 0;
				rotTime.Update();
				se6.Play(1);
				se6.SetVolume(0.5f);
				se6.SetLoopCount(1);
			}
		}
		else
		{
			rightCheck6_4 = 0;
		}

		if (puzzle16->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle16->mesh))
		{
			if (rightCheck6_5 != 0)
			{
				puzzle16->pipe->Update();
				degree6_5 += static_cast<float>(DegreeToRadian(60.f));
				puzzle16->mesh->setRotation(degree6_5);
				rotTime.Update();
				rightCheck6_5 = 0;
				std::cout << "5" << std::endl;
				se6.Play(1);
				se6.SetVolume(0.5f);
				se6.SetLoopCount(1);
			}
		}
		else
		{
			rightCheck6_5 = 0;
		}

		if (puzzle12->collision->Point2HexagonCollision({ cursor6.x,cursor6.y }, puzzle12->mesh))
		{
			if (rightCheck6_6 != 0)
			{
				puzzle12->pipe->Update();
				degree6_6 += static_cast<float>(DegreeToRadian(60.f));
				puzzle12->mesh->setRotation(degree6_6);
				rightCheck6_6 = 0;
				rotTime.Update();
				std::cout << "6" << std::endl;
				se6.Play(1);
				se6.SetVolume(0.5f);
				se6.SetLoopCount(1);
			}
		}
		else
		{
			rightCheck6_6 = 0;
		}

		if (button->collision->Point2BoxCollision({ cursor6.x,cursor6.y }, button->mesh))
		{
			if (connectMove6 % 2 == 1)
			{
				if (conecTcheck6_1 && conecTcheck6_2 && conecTcheck6_3)
				{
					std::cout << "if 5" << std::endl;
					clear->mesh->setTransform({ 280.f, -240.f });
					chekNext6 = 1;
					std::cout << "clear" << std::endl;
					connectMove6 = 0;
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

	if (button->collision->Point2BoxCollision({ cursor6.x,cursor6.y }, button->mesh))
	{
		if (connectMove6 % 2 == 1)
		{
			if (conecTcheck6_1 && conecTcheck6_2 && conecTcheck6_3 && conecTcheck6_4 && conecTcheck6_5)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext6 = 1;
				std::cout << "clear" << std::endl;
				connectMove6 = 0;
			}

		}
	}

	else
	{
		connectMove6 = 0;
	}
	se6.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground6);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart6);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd6);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton6);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear6);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace6);


	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level6::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
