#include "LevelSelect.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/glfwInput.h"

Vector2<float> cursorLv;
GLuint textureBackgroundLv;

GLuint texureIdLv1;
GLuint texureIdLv1_pressed;

GLuint texureIdLv2;
GLuint texureIdLv2_pressed;

GLuint texureIdLv3;
GLuint texureIdLv3_pressed;

GLuint texureIdLv4;
GLuint texureIdLv4_pressed;

GLuint texureIdLv5;
GLuint texureIdLv5_pressed;

GLuint texureIdLv6;
GLuint texureIdLv6_pressed;

Sound seLv;

int mouse1 = 0;
int mouse2 = 0;
int mouse3 = 0;
int mouse4 = 0;
int mouse5 = 0;
int mouse6 = 0;

void levelkeyCallback(GLFWwindow* /*window*/, int /*key*/, int /*scancode*/, int /*action*/, int /*mods*/)
{
}

void levelcursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursorLv = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
}

void  levelmouseButtonCallback(GLFWwindow* /*window*/, int /*button*/, int /*action*/, int /*mods*/)
{
	mouse1++;
	mouse2++;
	mouse3++;
	mouse4++;
	mouse5++;
	mouse6++;
}


void LevelSelect::Init()
{
	std::cout << "come in LevelSelect" << std::endl;
	backgroundLv = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	backgroundLv->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackgroundLv = TEXTURE->CreateTexture("assets\\background.png", 0);

	Level1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 200.f, 160.f });
	texureIdLv1 = TEXTURE->CreateTexture("assets\\levelButton1.png", 0);

	Level1_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f });
	texureIdLv1_pressed = TEXTURE->CreateTexture("assets\\levelButton1_2.png", 0);

	Level2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 160.f, 160.f }, 60*3);
	texureIdLv2 = TEXTURE->CreateTexture("assets\\levelButton2.png", 0);

	Level2_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv2_pressed = TEXTURE->CreateTexture("assets\\levelButton2_2.png", 0);

	Level3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 120.f, 160.f }, 60 * 3);
	texureIdLv3 = TEXTURE->CreateTexture("assets\\levelButton3.png", 0);

	Level3_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv3_pressed = TEXTURE->CreateTexture("assets\\levelButton3_2.png", 0);

	Level4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 45.f, 40.f - 30.f }, 60 * 3);
	texureIdLv4 = TEXTURE->CreateTexture("assets\\levelButton4.png", 0);

	Level4_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv4_pressed = TEXTURE->CreateTexture("assets\\levelButton4_2.png", 0);

	Level5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 5.f  , 40.f - 30.f }, 60 * 3);
	texureIdLv5 = TEXTURE->CreateTexture("assets\\levelButton5.png", 0);

	Level5_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv5_pressed = TEXTURE->CreateTexture("assets\\levelButton5_2.png", 0);

	Level6 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f + 30.f, 40.f - 30.f }, 60 * 3);
	texureIdLv6 = TEXTURE->CreateTexture("assets\\levelButton6.png", 0);

	Level6_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv6_pressed = TEXTURE->CreateTexture("assets\\levelButton6_2.png", 0);


	seLv.Init();
	seLv.LoadMusic("assets\\coin.mp3");

	mShader2.BuildTextureShader();

	glfwSetKeyCallback(APPLICATION->getMyWindow(), levelkeyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), levelcursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), levelmouseButtonCallback);
}

void LevelSelect::Update()
{
	if (Level1->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level1->mesh))
	{
		Level1_pressed->mesh->setTransform(Level1->mesh->GetTransform());
		if (mouse1 % 2 == 1)
		{
			std::cout << "get mouse left" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST3);	
			mouse1 = 0;
			mouse2 = 0;
			mouse3 = 0;
			mouse4 = 0;
			mouse5 = 0;
			mouse6 = 0;
		}
	}
	else
	{
		mouse1 = 0;
		Level1_pressed->mesh->setTransform({ 850.0f, 850.0f });
	}
	
	if (Level2->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level2->mesh))
	{
		Level2_pressed->mesh->setTransform(Level2->mesh->GetTransform());
		if (mouse2 % 2 == 1)
		{
			std::cout << "get mouse left" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST4);
			mouse1 = 0;
			mouse2 = 0;
			mouse3 = 0;
			mouse4 = 0;
			mouse5 = 0;
			mouse6 = 0;
		}
	}
	else
	{
		mouse2 = 0;
		Level2_pressed->mesh->setTransform({ 850.0f, 850.0f });
	}

	if (Level3->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level3->mesh))
	{
		Level3_pressed->mesh->setTransform(Level3->mesh->GetTransform());
		if (mouse3 % 2 == 1)
		{
			std::cout << "get mouse left" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST5);
			mouse1 = 0;
			mouse2 = 0;
			mouse3 = 0;
			mouse4 = 0;
			mouse5 = 0;
			mouse6 = 0;
		}
	}
	else
	{
		mouse3 = 0;
		Level3_pressed->mesh->setTransform({ 850.0f, 850.0f });
	}

	if (Level4->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level4->mesh))
	{
		Level4_pressed->mesh->setTransform(Level4->mesh->GetTransform());
		if (mouse4 % 2 == 1)
		{
			std::cout << "get mouse left" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST6);
			mouse1 = 0;
			mouse2 = 0;
			mouse3 = 0;
			mouse4 = 0;
			mouse5 = 0;
			mouse6 = 0;
		}
	}
	else
	{
		mouse4 = 0;
		Level4_pressed->mesh->setTransform({ 850.0f, 850.0f });
	}

	if (Level5->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level5->mesh))
	{
		Level5_pressed->mesh->setTransform(Level5->mesh->GetTransform());
		if (mouse5 % 2 == 1)
		{
			std::cout << "get mouse left" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST7);
			mouse1 = 0;
			mouse2 = 0;
			mouse3 = 0;
			mouse4 = 0;
			mouse5 = 0;
			mouse6 = 0;
		}
	}
	else
	{
		mouse5 = 0;
		Level5_pressed->mesh->setTransform({ 850.0f, 850.0f });
	}

	if (Level6->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level6->mesh))
	{
		Level6_pressed->mesh->setTransform(Level6->mesh->GetTransform());
		if (mouse6 % 2 == 1)
		{
			std::cout << "get mouse left" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST8);
			mouse1 = 0;
			mouse2 = 0;
			mouse3 = 0;
			mouse4 = 0;
			mouse5 = 0;
			mouse6 = 0;
		}
	}
	else
	{
		mouse6 = 0;
		Level6_pressed->mesh->setTransform({ 850.0f, 850.0f });
	}
	backgroundLv->mesh->Update(mShader2.GetShaderHandler(), textureBackgroundLv);

	Level1->mesh->Update(mShader2.GetShaderHandler(), texureIdLv1);
	Level1_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv1_pressed);

	Level2->mesh->Update(mShader2.GetShaderHandler(), texureIdLv2);
	Level2_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv2_pressed);

	Level3->mesh->Update(mShader2.GetShaderHandler(), texureIdLv3);
	Level3_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv3_pressed);

	Level4->mesh->Update(mShader2.GetShaderHandler(), texureIdLv4);
	Level4_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv4_pressed);

	Level5->mesh->Update(mShader2.GetShaderHandler(), texureIdLv5);
	Level5_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv5_pressed);

	Level6->mesh->Update(mShader2.GetShaderHandler(), texureIdLv6);
	Level6_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv6_pressed);

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void LevelSelect::Close()
{
	mShader.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
