/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *MainMenu.cpp
 */
#include "MainMenu.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"

int check0 = 0;
Vector2<float> cursor0;
int moveCheck0 = 0;
int moveCheck0_2 = 0;


GLuint textureId00;
GLuint textureId01;
GLuint textureId02;

Sound bgm;

void menuKeyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
		bgm.Stop();
		std::cout << "Stop music" << std::endl;
	}

}
void menuCursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor0 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) - APPLICATION->height / 2) / (APPLICATION->height / 2) };
}
void  menuMouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck0 += 1;
		moveCheck0_2 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void MainMenu::Init()
{
	bgm.Init();
	bgm.LoadMusic("assets\\airplane.mp3");
	if (!bgm.IsPlaying())
	{
		bgm.Play(0);
		bgm.SetVolume(0.3f);
	}

	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();
	
	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(10.f,10.f);
	textureId02 = TEXTURE->CreateTexture("assets\\title.png", 0);
	
	
	startButton = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton = OBJECT_FACTORY->CreateEmptyObject();


	textureId00 = TEXTURE->CreateTexture("assets\\game_title.png", 0);
	textureId01 = TEXTURE->CreateTexture("assets\\start.png", 0);

	mShader.BuildTextureShader();

	startButton->AddComponent(new Mesh());
	startButton->Init();

	startButton->mesh->setTransform({ 0.0f,-0.2f });
	startButton->mesh->SetMeshType(rectangle);
	startButton->mesh->InitializeTextureMesh(4.f, 1.f);

	tutorialButton->AddComponent(new Mesh());
	tutorialButton->Init();

	tutorialButton->mesh->setTransform({ 0.0f,-0.5f });
	tutorialButton->mesh->SetMeshType(rectangle);
	tutorialButton->mesh->InitializeTextureMesh(4.f, 1.f);
	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), menuKeyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), menuCursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), menuMouseButtonCallback);
}

void MainMenu::Update()
{

	bgm.Update();
	
	getOrigin.x = startButton->mesh->GetTransform().x;
	getOrigin.y = startButton->mesh->GetTransform().y;

	getOrigin2.x = tutorialButton->mesh->GetTransform().x;
	getOrigin2.y = tutorialButton->mesh->GetTransform().y;
	
	if ((cursor0.x <= (getOrigin.x + 0.43f) &&
		(cursor0.x >= (getOrigin.x - 0.43f)) &&
		(cursor0.y <= (getOrigin.y + 0.095f)) &&
		(cursor0.y >= (getOrigin.y - 0.095f))))
	{
		if (moveCheck0 % 2 == 1)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST3);
			std::cout << "DEmo is " << std::endl;
			moveCheck0 = 0;
		}
	}
	else
	{
		moveCheck0 = 0;
	}

	if ((cursor0.x <= (getOrigin2.x + 0.43f) &&
		(cursor0.x >= (getOrigin2.x - 0.43f)) &&
		(cursor0.y <= (getOrigin2.y + 0.095f)) &&
		(cursor0.y >= (getOrigin2.y - 0.095f))))
	{
		if (moveCheck0_2 % 2 == 1)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST1);
			std::cout << "TUTO is " << std::endl;
			moveCheck0_2 = 0;
		}
	}
	else
	{
		moveCheck0_2 = 0;
	}
	
	background->mesh->Update(mShader.GetShaderHandler(), textureId02);
	startButton->mesh->Update(mShader.GetShaderHandler(), textureId01);
	tutorialButton->mesh->Update(mShader.GetShaderHandler(), textureId01);


	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void MainMenu::Close()
{
	bgm.Free();
	mShader.Delete();
	ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
