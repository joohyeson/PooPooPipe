/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Level1.cpp
 *this is level1
 */
#include "Level1.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

int check = 0;
Vector2<float> cursor;

int moveCheck = 0;
int connectCheck1 = 0;

GLuint texureIdLine1;
GLuint texureIdCurve1;
GLuint texureIdBlack1;
GLuint textureBackground1;
GLuint textureSpace1;

Sound se;

void level1keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (connectCheck1 == 1)
	{
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST2);
			connectCheck1 = 0;
		}
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}
}

void level1cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) - APPLICATION->height / 2) / (APPLICATION->height / 2) };
}

void  level1mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level1::Init()
{

	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(10.f, 10.f);
	textureBackground1 = TEXTURE->CreateTexture("assets\\background.png", 0);

	
	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	puzzleLeft = OBJECT_FACTORY->CreateEmptyObject();
	puzzleRight = OBJECT_FACTORY->CreateEmptyObject();
	spacePress = OBJECT_FACTORY->CreateEmptyObject();


	texureIdLine1 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack1 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve1 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	textureSpace1 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	
	se.Init();
	se.LoadMusic("assets\\coin.mp3");


	mShader.BuildColorShader();
	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 0.5f, 0.7f });
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->mesh->InitializeColorMesh();

	blackPuzzle->AddComponent(new Mesh());
	blackPuzzle->Init();
	blackPuzzle->mesh->setTransform({ 0.0f, 0.3f });
	blackPuzzle->mesh->InitializeTextureMesh();

	puzzleLeft->AddComponent(new Mesh());
	puzzleLeft->Init();
	puzzleLeft->mesh->setTransform({ -0.34f, 0.3f });
	puzzleLeft->mesh->setRotation(DegreeToRadian(60.f));
	puzzleLeft->mesh->InitializeTextureMesh();

	puzzleRight->AddComponent(new Mesh());
	puzzleRight->Init();
	puzzleRight->mesh->setTransform({ 0.34f, 0.3f });
	puzzleRight->mesh->InitializeTextureMesh();

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -0.5f });
	spacePress->mesh->SetMeshType(rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(7.f, 1.f);
	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), level1keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level1cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level1mouseButtonCallback);
}

void Level1::Update()
{
	if (check < 1)
	{
		check++;
	}
	
	se.Update();

	getOrigin.x = movePuzzle->mesh->GetTransform().x;
	getOrigin.y = movePuzzle->mesh->GetTransform().y;

	getOrigin2.x = blackPuzzle->mesh->GetTransform().x;
	getOrigin2.y = blackPuzzle->mesh->GetTransform().y;
	
	float r = static_cast<float>(sqrt(5) / 10);

	if (cursor.x <= (getOrigin.x + r / 2) &&
		cursor.x >= (getOrigin.x - r / 2) &&
		cursor.y <= (getOrigin.y + r) &&
		cursor.y >= (getOrigin.y - r))
	{
		if (moveCheck % 2 == 1)
		{
			movePuzzle->mesh->setTransform({ cursor.x, cursor.y });
		}
	}
	else
	{
		moveCheck = 0;
	}

	if (getOrigin.x <= (getOrigin2.x + r / 2) &&
		getOrigin.x >= (getOrigin2.x - r / 2) &&
		getOrigin.y <= (getOrigin2.y + r) &&
		getOrigin.y >= (getOrigin2.y - r))
	{
		if (moveCheck % 2 == 0)
		{
			movePuzzle->mesh->setTransform({ getOrigin2.x,getOrigin2.y });
			connectCheck1 = 1;
		}
		else
		{
			connectCheck1 = 0;
		}
	}

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground1);
	blackPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack1);
	puzzleLeft->mesh->Update(mShader2.GetShaderHandler(), texureIdLine1);
	puzzleRight->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve1);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), textureSpace1);


	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdLine1);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level1::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
