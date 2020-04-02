
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level7.h"
#include "../GUGUENGINE/Sound.h"

int check7 = 0;
Vector2<float> cursor7;

int coorcheck7 = 0;

int connectMove7 = 0;

float degree7 = 0;
float degree7_2 = 0;
float degree7_3 = 0;
float degree7_4 = 0;
float degree7_5 = 0;
float degree7_6 = 0;
float degree7_7 = 0;

int rightCheck7 = 0;
int rightCheck7_2 = 0;
int rightCheck7_3 = 0;
int rightCheck7_4 = 0;
int rightCheck7_5 = 0;
int rightCheck7_6 = 0;
int rightCheck7_7 = 0;

int chekNext7 = 0;

GLuint textureBackground7;

GLuint texureIdLine7;
GLuint texureIdCurve7;
GLuint texureIdThree7;
GLuint texureIdV7;
GLuint texureIdBlack7;

GLuint texureIdStart7;
GLuint texureIdEnd7;

GLuint texureIdLine7_2;
GLuint texureIdCurve7_2;
GLuint texureIdV7_2;

GLint texturePlayUI7;
GLint textureQuitUI7;
GLint textureOptionUI7;
GLint textureRestartUI7;

GLuint texureIdbutton7;
GLuint texureIdclear7;
GLuint texureSpace7;

Sound se7;

bool conecTcheck7_1 = false;
bool conecTcheck7_2 = false;
bool conecTcheck7_3 = false;
bool conecTcheck7_4 = false;
bool conecTcheck7_5 = false;
bool conecTcheck7_6 = false;
bool conecTcheck7_7 = false;
bool conecTcheck7_8 = false;
bool conecTcheck7_9 = false;



void level7keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNext7 == 1)
	{
		STATE_MANAGER->ChangeLevel(LV_TEST8);
		chekNext7 = 0;

		conecTcheck7_1 = false;
		conecTcheck7_2 = false;
		conecTcheck7_3 = false;
		conecTcheck7_4 = false;
		conecTcheck7_5 = false;
		conecTcheck7_6 = false;
		conecTcheck7_7 = false;
		conecTcheck7_8 = false;
		conecTcheck7_9 = false;


		degree7 = 0;
		degree7_2 = 0;
		degree7_3 = 0;
		degree7_4 = 0;
		degree7_5 = 0;
		degree7_6 = 0;
		degree7_7 = 0;
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		degree7 = 0;
		degree7_2 = 0;
		degree7_3 = 0;
		degree7_4 = 0;
		degree7_5 = 0;
		degree7_6 = 0;
		degree7_7 = 0;

		STATE_MANAGER->ChangeLevel(LV_TEST8);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}

	if (key == GLFW_KEY_TAB)
	{
		if (coorcheck7 == 1)
		{
			coorcheck7 = 0;
		}

		coorcheck7 += 1;
	}
}

void level7cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor7 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
}

void  level7mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		connectMove7 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck7 = 1;
		rightCheck7_2 = 1;
		rightCheck7_3 = 1;
		rightCheck7_4 = 1;
		rightCheck7_5 = 1;
		rightCheck7_6 = 1;
		rightCheck7_7 = 1;

		std::cout << "rightCheck2: " << rightCheck7 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level7::Init()
{
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground7 = TEXTURE->CreateTexture("assets\\background.png", 0);	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 800.f, 300.f });
	playUI->mesh->SetMeshType(rectangle);
	playUI->mesh->InitializeTextureMesh(150.f, 150.f);
	texturePlayUI7 = TEXTURE->CreateTexture("assets\\playUI.png", 0);


	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->SetMeshType(rectangle);
	quitUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureQuitUI7 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 800.f, 0.f });
	optionUI->mesh->SetMeshType(rectangle);
	optionUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureOptionUI7 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->SetMeshType(rectangle);
	restartUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureRestartUI7 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);


	texureIdLine7 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack7 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve7 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree7 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV7 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart7 = TEXTURE->CreateTexture("assets\\imageStart2.png", 0);
	texureIdEnd7 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine7_2 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve7_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV7_2 = TEXTURE->CreateTexture("assets\\pipe2.png", 0);


	texureIdbutton7 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear7 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace7 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);

	se7.Init();
	se7.LoadSE("assets\\coin.mp3");

	mShader2.BuildTextureShader();

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f, 280.f }, 0.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f, -200.f }, -0.f);
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

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level7keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level7cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level7mouseButtonCallback);
}

void Level7::Update()
{
	if (check7 < 1)
	{
		check7++;
	}
	se7.Update();

	if (puzzle1->collision->Point2HexagonCollision({ cursor7.x,cursor7.y }, puzzle1->mesh))
	{
		if (rightCheck7 != 0)
		{
			puzzle1->pipe->Update();

			degree7 += static_cast<float>(DegreeToRadian(60.f));
			puzzle1->mesh->setRotation(degree7);

			rightCheck7 = 0;

			se7.Play(1);
			se7.SetVolume(0.5f);
			se7.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck7 = 0;
	}

	if (puzzle17->collision->Point2HexagonCollision({ cursor7.x,cursor7.y }, puzzle17->mesh))
	{
		if (rightCheck7_2 != 0)
		{
			puzzle17->pipe->Update();

			degree7_2 += static_cast<float>(DegreeToRadian(60.f));
			puzzle17->mesh->setRotation(degree7_2);

			rightCheck7_2 = 0;

			se7.Play(1);
			se7.SetVolume(0.5f);
			se7.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck7_2 = 0;
	}

	if (puzzle4->collision->Point2HexagonCollision({ cursor7.x,cursor7.y }, puzzle4->mesh))
	{
		if (rightCheck7_3 != 0)
		{
			puzzle4->pipe->Update();

			degree7_3 += static_cast<float>(DegreeToRadian(60.f));
			puzzle4->mesh->setRotation(degree7_3);

			rightCheck7_3 = 0;

			se7.Play(1);
			se7.SetVolume(0.5f);
			se7.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck7_3 = 0;
	}

	if (puzzle7->collision->Point2HexagonCollision({ cursor7.x,cursor7.y }, puzzle7->mesh))
	{
		if (rightCheck7_4 != 0)
		{
			puzzle7->pipe->Update();

			degree7_4 += static_cast<float>(DegreeToRadian(60.f));
			puzzle7->mesh->setRotation(degree7_4);

			rightCheck7_4 = 0;

			se7.Play(1);
			se7.SetVolume(0.5f);
			se7.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck7_4 = 0;
	}

	if (puzzle20->collision->Point2HexagonCollision({ cursor7.x,cursor7.y }, puzzle20->mesh))
	{
		if (rightCheck7_5 != 0)
		{
			puzzle20->pipe->Update();

			degree7_5 += static_cast<float>(DegreeToRadian(60.f));
			puzzle20->mesh->setRotation(degree7_5);

			rightCheck7_5 = 0;

			se7.Play(1);
			se7.SetVolume(0.5f);
			se7.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck7_5 = 0;
	}

	if (puzzle9->collision->Point2HexagonCollision({ cursor7.x,cursor7.y }, puzzle9->mesh))
	{
		if (rightCheck7_6 != 0)
		{
			puzzle9->pipe->Update();

			degree7_6 += static_cast<float>(DegreeToRadian(60.f));
			puzzle9->mesh->setRotation(degree7_6);

			rightCheck7_6 = 0;

			se7.Play(1);
			se7.SetVolume(0.5f);
			se7.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck7_6 = 0;
	}

	if (puzzle17->collision->Point2HexagonCollision({ cursor7.x,cursor7.y }, puzzle17->mesh))
	{
		if (rightCheck7_7 != 0)
		{
			puzzle17->pipe->Update();

			degree7_7 += static_cast<float>(DegreeToRadian(60.f));
			puzzle17->mesh->setRotation(degree7_7);

			rightCheck7_7 = 0;

			se7.Play(1);
			se7.SetVolume(0.5f);
			se7.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck7_7 = 0;
	}

	if ((puzzle1->pipe->GetDirValue(E) == puzzle2->pipe->GetDirValue(W)) && (puzzle1->pipe->GetDirValue(SW) == puzzle3->pipe->GetDirValue(NE)))
	{
		conecTcheck7_1 = true;
	}
	else
	{
		conecTcheck7_1 = false;
	}

	if ((puzzle17->pipe->GetDirValue(NE) == puzzle2->pipe->GetDirValue(SW)) && (puzzle17->pipe->GetDirValue(E) == puzzle19->pipe->GetDirValue(W)))
	{

		conecTcheck7_2 = true;
	}
	else
	{
		conecTcheck7_2 = false;
	}

	if ((puzzle7->pipe->GetDirValue(SW) == puzzle9->pipe->GetDirValue(NE)) && (puzzle7->pipe->GetDirValue(SE) == puzzle10->pipe->GetDirValue(NW)))
	{

		conecTcheck7_3 = true;
	}
	else
	{
		conecTcheck7_3 = false;
	}

	if ((puzzle9->pipe->GetDirValue(NE) == puzzle7->pipe->GetDirValue(SW)) && (puzzle9->pipe->GetDirValue(W) == puzzle20->pipe->GetDirValue(E)))
	{
		conecTcheck7_4 = true;

	}
	else
	{
		conecTcheck7_4 = false;
	}

	if ((puzzle17->pipe->GetDirValue(NE) == puzzle16->pipe->GetDirValue(SW)) && (puzzle17->pipe->GetDirValue(W) == puzzle12->pipe->GetDirValue(E)))
	{
		conecTcheck7_9 = true;

	}
	else
	{
		conecTcheck7_9 = false;
	}


	if ((puzzle4->pipe->GetDirValue(NE) == puzzle13->pipe->GetDirValue(SW)) && (puzzle4->pipe->GetDirValue(SE) == puzzle15->pipe->GetDirValue(NW)))
	{
		conecTcheck7_5 = true;
	}
	else
	{
		conecTcheck7_5 = false;
	}

	if ((puzzle4->pipe->GetDirValue(NE) == puzzle13->pipe->GetDirValue(SW)) && (puzzle4->pipe->GetDirValue(W) == puzzle19->pipe->GetDirValue(E)))
	{
		conecTcheck7_6 = true;

	}
	else
	{
		conecTcheck7_6 = false;
	}

	if ((puzzle20->pipe->GetDirValue(NW) == puzzle6->pipe->GetDirValue(SE)) && (puzzle20->pipe->GetDirValue(SW) == endPuzzle->pipe->GetDirValue(NE)))
	{
		conecTcheck7_7 = true;

	}
	else
	{
		conecTcheck7_7 = false;
	}

	if ((puzzle20->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (puzzle20->pipe->GetDirValue(SW) == endPuzzle->pipe->GetDirValue(NE)))
	{
		conecTcheck7_8 = true;

	}
	else
	{
		conecTcheck7_8 = false;
	}

	if (button->collision->Point2BoxCollision({ cursor7.x,cursor7.y }, button->mesh))
	{
		if (connectMove7 % 2 == 1)
		{
			if (conecTcheck7_1 && conecTcheck7_2 && conecTcheck7_6 && conecTcheck7_7)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext7 = 1;
				std::cout << "clear" << std::endl;
				connectMove7 = 0;
			}
			else if (conecTcheck7_3 && conecTcheck7_4 && conecTcheck7_5 && conecTcheck7_8 && conecTcheck7_9)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext7 = 1;
				std::cout << "clear" << std::endl;
				connectMove7 = 0;
			}
		}
	}
	else
	{
		connectMove7 = 0;
	}
	se7.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground7);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7_2);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdV7);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7_2);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdLine7);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdV7_2);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdV7);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7_2);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdV7);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdV7);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV7);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdLine7);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7_2);

	puzzle18->mesh->Update(mShader2.GetShaderHandler(), texureIdV7_2);
	puzzle19->mesh->Update(mShader2.GetShaderHandler(), texureIdLine7);
	puzzle20->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve7_2);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart7);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd7);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton7);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear7);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace7);

	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI7);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI7);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI7);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI7);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level7::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
