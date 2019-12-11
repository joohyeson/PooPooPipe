#include "MainMenu.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"

int check0 = 0;
Vector2<float> cursor0;
int moveCheck0 = 0;

GLuint textureId00;
Sound bgm;

void menuKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		bgm.Stop();
		std::cout << "Change level to Level1" << std::endl;
		STATE_MANAGER->ChangeLevel(LV_TEST1);
	}
	else if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
		bgm.Stop();
		std::cout << "Stop music" << std::endl;
	}

}
void menuCursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	cursor0 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) - APPLICATION->height / 2) / (APPLICATION->height / 2) };
}
void  menuMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck0 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void MainMenu::Init()
{
	bgm.Init();
	bgm.LoadMusic("assets\\airplane.mp3");

	if(!bgm.IsPlaying())
	{
		bgm.Play(2);
		bgm.SetVolume(0.1f);
	}
	
	gameLogo = OBJECT_FACTORY->CreateEmptyObject();

	textureId00 = TEXTURE->CreateTexture("assets\\game_title.png", 0);

	mShader.BuildTextureShader();

	gameLogo->AddComponent(new Mesh());
	gameLogo->Init();
	
	gameLogo->mesh->setTransform({ 0,0 });
	gameLogo->mesh->SetMeshType(rectangle);
	gameLogo->mesh->InitializeTextureMesh(6.f, 2.f);
	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), menuKeyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), menuCursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), menuMouseButtonCallback);
}

void MainMenu::Update()
{
	bgm.Update();
	
	getOrigin.x = gameLogo->mesh->GetTransform().x;
	getOrigin.y = gameLogo->mesh->GetTransform().y;

	float r = sqrt(5) / 10;

	if (cursor0.x <= (getOrigin.x + r / 2) &&
		cursor0.x >= (getOrigin.x - r / 2) &&
		cursor0.y <= (getOrigin.y + r) &&
		cursor0.y >= (getOrigin.y - r))
	{
		if (moveCheck0 % 2 == 1)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST1);
		}
	}
	else
	{
		moveCheck0 = 0;
	}

	gameLogo->mesh->Update(mShader.GetShaderHandler(),textureId00);

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
