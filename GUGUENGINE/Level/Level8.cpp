
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level8.h"
#include "../GUGUENGINE/Sound.h"

int check8 = 0;
Vector2<float> cursor8;

int coorcheck8 = 0;

int connectMove8 = 0;

float degree8 = 0;
float degree8_2 = 0;
float degree8_3 = 0;
float degree8_4 = 0;
float degree8_5 = 0;
float degree8_6 = 0;
float degree8_7 = 0;

int rightCheck8 = 0;
int rightCheck8_2 = 0;
int rightCheck8_3 = 0;
int rightCheck8_4 = 0;
int rightCheck8_5 = 0;
int rightCheck8_6 = 0;
int rightCheck8_7 = 0;

int chekNext8 = 0;

GLuint textureBackground8;

GLuint texureIdLine8;
GLuint texureIdCurve8;
GLuint texureIdThree8;
GLuint texureIdV8;
GLuint texureIdBlack8;

GLuint texureIdStart8;
GLuint texureIdEnd8;

GLuint texureIdLine8_2;
GLuint texureIdCurve8_2;
GLuint texureIdV8_2;


GLuint texureIdbutton8;
GLuint texureIdclear8;
GLuint texureSpace8;

Sound se8;

bool conecTcheck8_1 = false;
bool conecTcheck8_2 = false;
bool conecTcheck8_3 = false;
bool conecTcheck8_4 = false;
bool conecTcheck8_5 = false;
bool conecTcheck8_6 = false;
bool conecTcheck8_7 = false;
bool conecTcheck8_8 = false;
bool conecTcheck8_9 = false;



void level8keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNext8 == 1)
	{
		STATE_MANAGER->ChangeLevel(LV_TEST5);
		chekNext8 = 0;

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
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		degree8 = 0;
		degree8_2 = 0;
		degree8_3 = 0;
		degree8_4 = 0;
		degree8_5 = 0;
		degree8_6 = 0;
		degree8_7 = 0;

		STATE_MANAGER->ChangeLevel(LV_TEST5);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}

	if (key == GLFW_KEY_TAB)
	{
		if (coorcheck8 == 1)
		{
			coorcheck8 = 0;
		}

		coorcheck8 += 1;
	}
}

void level8cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor8 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
}
void  level8mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		connectMove8 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck8 = 1;
		rightCheck8_2 = 1;
		rightCheck8_3 = 1;
		rightCheck8_4 = 1;
		rightCheck8_5 = 1;
		rightCheck8_6 = 1;
		rightCheck8_7 = 1;

		std::cout << "rightCheck2: " << rightCheck8 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level8::Init()
{
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground8 = TEXTURE->CreateTexture("assets\\background.png", 0);	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine8 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack8 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve8 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree8 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV8 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart8 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd8 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine8_2 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve8_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV8_2 = TEXTURE->CreateTexture("assets\\pipe2.png", 0);


	texureIdbutton8 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear8 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace8 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);

	se8.Init();
	se8.LoadSE("assets\\coin.mp3");

	mShader2.BuildTextureShader();

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f, 280.f }, 120.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, -200.f }, -180.f);
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, 280.f });
	puzzle1->pipe->SetDirection(false, false, false, true, false, true);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f, 280.f });
	puzzle2->pipe->SetDirection(false, false, false, false, true, true);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -268.f, 160.f }, 120.f);
	puzzle3->pipe->SetDirection(false, true, false, true, false, false);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f, 160.f });
	puzzle4->pipe->SetDirection(false, false, false, true, false, true);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f, 40.f });

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, 40.f });
	puzzle6->pipe->SetDirection(true, false, false, true, false, false);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f, 40.f });
	puzzle7->pipe->SetDirection(false, false, true, true, false, false);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f, -80.f }, 120.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f, -80.f });
	puzzle9->pipe->SetDirection(false, false, false, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f, -80.f }, -60.f);
	puzzle10->pipe->SetDirection(true, false, false, false, true, false);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f, -200.f }, 180.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f, -200.f }, 180.f);
	puzzle12->pipe->SetDirection(false, true, true, false, false, false);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f, 280.f });
	puzzle13->pipe->SetDirection(false, false, false, false, true, true);

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f, 160.f }, -60);
	puzzle14->pipe->SetDirection(false, false, false, true, true, false);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f, 40.f });
	puzzle15->pipe->SetDirection(true, false, false, true, false, false);

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f, -80.f }, -60.f);
	puzzle16->pipe->SetDirection(true, false, false, false, true, false);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f, -200.f });
	puzzle17->pipe->SetDirection(false, false, false, true, false, true);

	puzzle18 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f, 160.f });
	puzzle18->pipe->SetDirection(false, false, true, true, false, false);

	puzzle19 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f, 160.f }, 60.f);
	puzzle19->pipe->SetDirection(false, false, true, false, false, true);

	puzzle20 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f, -80.0f });
	puzzle20->pipe->SetDirection(false, false, false, true, false, true);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.0f, -340.f });

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level8keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level8cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level8mouseButtonCallback);
}

void Level8::Update()
{
	if (check8 < 1)
	{
		check8++;
	}
	se8.Update();

	if (puzzle1->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle1->mesh))
	{
		if (rightCheck8 != 0)
		{
			puzzle1->pipe->Update();

			degree8 += static_cast<float>(DegreeToRadian(60.f));
			puzzle1->mesh->setRotation(degree8);

			rightCheck8 = 0;

			se8.Play(1);
			se8.SetVolume(0.5f);
			se8.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck8 = 0;
	}

	if (puzzle18->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle18->mesh))
	{
		if (rightCheck8_2 != 0)
		{
			puzzle18->pipe->Update();

			degree8_2 += static_cast<float>(DegreeToRadian(60.f));
			puzzle18->mesh->setRotation(degree8_2);

			rightCheck8_2 = 0;

			se8.Play(1);
			se8.SetVolume(0.5f);
			se8.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck8_2 = 0;
	}

	if (puzzle4->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle4->mesh))
	{
		if (rightCheck8_3 != 0)
		{
			puzzle4->pipe->Update();

			degree8_3 += static_cast<float>(DegreeToRadian(60.f));
			puzzle4->mesh->setRotation(degree8_3);

			rightCheck8_3 = 0;

			se8.Play(1);
			se8.SetVolume(0.5f);
			se8.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck8_3 = 0;
	}

	if (puzzle7->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle7->mesh))
	{
		if (rightCheck8_4 != 0)
		{
			puzzle7->pipe->Update();

			degree8_4 += static_cast<float>(DegreeToRadian(60.f));
			puzzle7->mesh->setRotation(degree8_4);

			rightCheck8_4 = 0;

			se8.Play(1);
			se8.SetVolume(0.5f);
			se8.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck8_4 = 0;
	}

	if (puzzle20->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle20->mesh))
	{
		if (rightCheck8_5 != 0)
		{
			puzzle20->pipe->Update();

			degree8_5 += static_cast<float>(DegreeToRadian(60.f));
			puzzle20->mesh->setRotation(degree8_5);

			rightCheck8_5 = 0;

			se8.Play(1);
			se8.SetVolume(0.5f);
			se8.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck8_5 = 0;
	}

	if (puzzle9->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle9->mesh))
	{
		if (rightCheck8_6 != 0)
		{
			puzzle9->pipe->Update();

			degree8_6 += static_cast<float>(DegreeToRadian(60.f));
			puzzle9->mesh->setRotation(degree8_6);

			rightCheck8_6 = 0;

			se8.Play(1);
			se8.SetVolume(0.5f);
			se8.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck8_6 = 0;
	}

	if (puzzle17->collision->Point2HexagonCollision({ cursor8.x,cursor8.y }, puzzle17->mesh))
	{
		if (rightCheck8_7 != 0)
		{
			puzzle17->pipe->Update();

			degree8_7 += static_cast<float>(DegreeToRadian(60.f));
			puzzle17->mesh->setRotation(degree8_7);

			rightCheck8_7 = 0;

			se8.Play(1);
			se8.SetVolume(0.5f);
			se8.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck8_7 = 0;
	}

	if ((puzzle1->pipe->GetDirValue(E) == puzzle2->pipe->GetDirValue(W)) && (puzzle1->pipe->GetDirValue(SW) == puzzle3->pipe->GetDirValue(NE)))
	{
		conecTcheck8_1 = true;
	}
	else
	{
		conecTcheck8_1 = false;
	}

	if ((puzzle18->pipe->GetDirValue(NE) == puzzle2->pipe->GetDirValue(SW)) && (puzzle18->pipe->GetDirValue(E) == puzzle19->pipe->GetDirValue(W)))
	{

		conecTcheck8_2 = true;
	}
	else
	{
		conecTcheck8_2 = false;
	}

	if ((puzzle7->pipe->GetDirValue(SW) == puzzle9->pipe->GetDirValue(NE)) && (puzzle7->pipe->GetDirValue(SE) == puzzle10->pipe->GetDirValue(NW)))
	{

		conecTcheck8_3 = true;
	}
	else
	{
		conecTcheck8_3 = false;
	}

	if ((puzzle9->pipe->GetDirValue(NE) == puzzle7->pipe->GetDirValue(SW)) && (puzzle9->pipe->GetDirValue(W) == puzzle20->pipe->GetDirValue(E)))
	{
		conecTcheck8_4 = true;

	}
	else
	{
		conecTcheck8_4 = false;
	}

	if ((puzzle17->pipe->GetDirValue(NE) == puzzle16->pipe->GetDirValue(SW)) && (puzzle17->pipe->GetDirValue(W) == puzzle12->pipe->GetDirValue(E)))
	{
		conecTcheck8_9 = true;

	}
	else
	{
		conecTcheck8_9 = false;
	}


	if ((puzzle4->pipe->GetDirValue(NE) == puzzle13->pipe->GetDirValue(SW)) && (puzzle4->pipe->GetDirValue(SE) == puzzle15->pipe->GetDirValue(NW)))
	{
		conecTcheck8_5 = true;
	}
	else
	{
		conecTcheck8_5 = false;
	}

	if ((puzzle4->pipe->GetDirValue(NE) == puzzle13->pipe->GetDirValue(SW)) && (puzzle4->pipe->GetDirValue(W) == puzzle19->pipe->GetDirValue(E)))
	{
		conecTcheck8_6 = true;

	}
	else
	{
		conecTcheck8_6 = false;
	}

	if ((puzzle20->pipe->GetDirValue(NW) == puzzle6->pipe->GetDirValue(SE)) && (puzzle20->pipe->GetDirValue(SW) == endPuzzle->pipe->GetDirValue(NE)))
	{
		conecTcheck8_7 = true;

	}
	else
	{
		conecTcheck8_7 = false;
	}

	if ((puzzle20->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (puzzle20->pipe->GetDirValue(SW) == endPuzzle->pipe->GetDirValue(NE)))
	{
		conecTcheck8_8 = true;

	}
	else
	{
		conecTcheck8_8 = false;
	}

	if (button->collision->Point2BoxCollision({ cursor8.x,cursor8.y }, button->mesh))
	{
		if (connectMove8 % 2 == 1)
		{
			if (conecTcheck8_1 && conecTcheck8_2 && conecTcheck8_6 && conecTcheck8_7)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext8 = 1;
				std::cout << "clear" << std::endl;
				connectMove8 = 0;
			}
			else if (conecTcheck8_3 && conecTcheck8_4 && conecTcheck8_5 && conecTcheck8_8 && conecTcheck8_9)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext8 = 1;
				std::cout << "clear" << std::endl;
				connectMove8 = 0;
			}
		}
	}
	else
	{
		connectMove8 = 0;
	}
	se8.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground8);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV8);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);

	puzzle18->mesh->Update(mShader2.GetShaderHandler(), texureIdV8_2);
	puzzle19->mesh->Update(mShader2.GetShaderHandler(), texureIdLine8);
	puzzle20->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve8_2);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart8);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd8);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton8);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear8);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace8);


	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level8::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
