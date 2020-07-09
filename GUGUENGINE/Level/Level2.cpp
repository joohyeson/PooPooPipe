/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Level2.cpp
 *this is level2
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level2.h"
#include "../GUGUENGINE/Sound.h"

int check2 = 0;
Vector2<float> cursor2;

int moveCheck2 = 0;
int connectCheck2 = 0;
float degree = 0;
int rightCheck2 = 0;
int checkToPipe = 0;

GLuint texureIdLine2;
GLuint texureIdCurve2;
GLuint texureIdBlack2;
GLuint textureBackground2;
GLuint textureSpace2;

Sound se2;


void level2keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && checkToPipe == 1)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
		checkToPipe = 0;
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
		ENGINE->Quit();
	}
}

void level2cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor2 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
}

void  level2mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck2 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck2 = 1;
		std::cout << "rightCheck2: " << rightCheck2 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level2::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground2 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	puzzleUp = OBJECT_FACTORY->CreateEmptyObject();
	puzzleDown = OBJECT_FACTORY->CreateEmptyObject();
	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine2 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack2 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve2 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	textureSpace2 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);

	se2.Init();
	se2.LoadMusic("assets\\coin.mp3");

	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->AddComponent(new PuzzleComponent());
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle->mesh->SetMeshType(MESHTYPE::hexagon);
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 160.0f, 280.0f });
	movePuzzle->mesh->InitializeTextureMesh();

	blackPuzzle->AddComponent(new Mesh());
	blackPuzzle->mesh->SetMeshType(MESHTYPE::hexagon);
	blackPuzzle->Init();
	blackPuzzle->mesh->setTransform({ 0.0f, 120.0f });
	blackPuzzle->mesh->InitializeTextureMesh();

	puzzleUp->AddComponent(new Mesh());
	puzzleUp->AddComponent(new PuzzleComponent());
	puzzleUp->Init();
	puzzleUp->mesh->setTransform({ -72.f - 10.f, 238.8f + 40.f });
	puzzleUp->mesh->setRotation(DegreeToRadian(180.f));
	puzzleUp->pipe->SetDirection(true, false, false, true, false, false);
	puzzleUp->mesh->SetMeshType(MESHTYPE::hexagon);
	puzzleUp->mesh->InitializeTextureMesh();

	puzzleDown->AddComponent(new Mesh());
	puzzleDown->AddComponent(new PuzzleComponent());
	puzzleDown->Init();
	puzzleDown->mesh->setTransform({ 72.f + 10.f, 4.f - 40.f });
	puzzleDown->mesh->setRotation(DegreeToRadian(180.f));
	puzzleDown->pipe->SetDirection(true, false, true, false, false, false);
	puzzleDown->mesh->SetMeshType(MESHTYPE::hexagon);
	puzzleDown->mesh->InitializeTextureMesh();

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -160.f });
	spacePress->mesh->SetMeshType(MESHTYPE::rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(560.f, 80.f);

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level2keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level2cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level2mouseButtonCallback);
}

void Level2::Update()
{
	if (check2 < 1)
	{
		check2++;
		std::cout << "HELLO" << std::endl;
	}

	se2.Update();

	getOrigin.x = movePuzzle->mesh->GetTransform().x;
	getOrigin.y = movePuzzle->mesh->GetTransform().y;

	getOrigin2.x = blackPuzzle->mesh->GetTransform().x;
	getOrigin2.y = blackPuzzle->mesh->GetTransform().y;
	float r = static_cast<float>(sqrt(5) / 10);

	if (cursor2.x <= (getOrigin.x + (r / 2) * 400) &&
		cursor2.x >= (getOrigin.x - (r / 2) * 400) &&
		cursor2.y <= (getOrigin.y + r * 400) &&
		cursor2.y >= (getOrigin.y - r * 400))
	{
		if (moveCheck2 % 2 == 1)
		{
			movePuzzle->mesh->setTransform({ cursor2.x, cursor2.y });
		}
		if (rightCheck2 != 0)
		{
			movePuzzle->pipe->Update();

			degree += static_cast<float>(DegreeToRadian(60.f));
			movePuzzle->mesh->setRotation(degree);
			rightCheck2 = 0;

			if ((movePuzzle->pipe->GetDirValue(SE) == puzzleDown->pipe->GetDirValue(NW)) && (movePuzzle->pipe->GetDirValue(NW) == puzzleUp->pipe->GetDirValue(SE)))
			{
				std::cout << "pipe connect\n";
				checkToPipe = 1;
			}
			else
			{
				std::cout << "Not connect\n";
				checkToPipe = 0;
			}

			//se2.Play(1);
			//se2.SetVolume(0.5f);
			//se2.SetLoopCount(1);

		}
	}
	else
	{
		moveCheck2 = 0;
	}

	if (getOrigin.x <= (getOrigin2.x + (r / 2) * 400) &&
		getOrigin.x >= (getOrigin2.x - (r / 2) * 400) &&
		getOrigin.y <= (getOrigin2.y + r * 400) &&
		getOrigin.y >= (getOrigin2.y - r * 400))
	{
		if (moveCheck2 % 2 == 0)
		{
			movePuzzle->mesh->setTransform({ getOrigin2.x,getOrigin2.y });
			connectCheck2 = 1;
		}
		else
		{
			connectCheck2 = 0;
		}
	}

	se2.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground2);
	blackPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack2);
	puzzleUp->mesh->Update(mShader2.GetShaderHandler(), texureIdLine2);
	puzzleDown->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve2);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), textureSpace2);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdLine2);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level2::Close()
{
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
