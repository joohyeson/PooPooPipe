/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *MainMenu.cpp
 *this is mainmenu
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
int moveCheck0_3 = 0;

float volume = 0.5f;

GLuint textureId00;	//game title
GLuint textureId01; //game start
GLuint textureId02; //title
GLuint textureId03; //tutorial
GLuint textureId05;//test
GLuint textureId04;	//option button
GLuint textureId06;//man

Sound bgm;

void menuKeyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
		bgm.Stop();
		std::cout << "Stop music" << std::endl;
	}
	
	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}

	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		std::cout << "Up Key" << std::endl;

		if (volume < 1.0f)
		{
			volume += 0.1f;
			bgm.SetVolume(volume);

			std::cout << volume << std::endl;
		}
	}

	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
	{
		std::cout << "Down Key" << std::endl;

		if (volume > 0.0f)
		{
			volume -= 0.1f;
			bgm.SetVolume(volume);

			std::cout << volume << std::endl;
		}
	}
}
void menuCursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor0 = { static_cast<float>(xpos) -APPLICATION->height/2 ,  -(static_cast<float>(ypos)-APPLICATION->width/2)};
}
void  menuMouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck0 += 1;
		moveCheck0_2 += 1;
		moveCheck0_3 += 1;
		std::cout << "LEFT mouse button pressed" << std::endl;

	}
}

void MainMenu::Init()
{
	bgm.Stop();
	bgm.Init();
	bgm.LoadMusic("assets\\airplane.mp3");
	if (!bgm.IsPlaying())
	{
		bgm.Play(0);
	}

	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();
	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(800.f,800.f);

	textureId02 = TEXTURE->CreateTexture("assets\\title.png", 0);
	
	startButton = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton = OBJECT_FACTORY->CreateEmptyObject();
	optionButton = OBJECT_FACTORY->CreateEmptyObject();
	test = OBJECT_FACTORY->CreateEmptyObject();
	test2 = OBJECT_FACTORY->CreateEmptyObject();

	textureId00 = TEXTURE->CreateTexture("assets\\game_title.png", 0);
	textureId01 = TEXTURE->CreateTexture("assets\\start.png", 0);
	textureId03 = TEXTURE->CreateTexture("assets\\tutorial.png", 0);
	textureId04 = TEXTURE->CreateTexture("assets\\option.png", 0);
	textureId05 = TEXTURE->CreateTexture("assets\\testpoopoo.png", 0);
	textureId06= TEXTURE->CreateTexture("assets\\man.png", 0);

	mShader.BuildTextureShader();
	//testNDCShader.BuildTextureShaderNDC();
	startButton->AddComponent(new Mesh());
	startButton->Init();

	startButton->mesh->setTransform({ 0.f,-20.f });
	startButton->mesh->SetMeshType(rectangle);
	startButton->mesh->InitializeTextureMesh(280.f, 70.f);

	tutorialButton->AddComponent(new Mesh());
	tutorialButton->Init();

	tutorialButton->mesh->setTransform({ 0.0f,-80.f });
	tutorialButton->mesh->SetMeshType(rectangle);
	tutorialButton->mesh->InitializeTextureMesh(280.f, 70.f);

	optionButton->AddComponent(new Mesh());
	optionButton->Init();
	
	optionButton->mesh->setTransform({ 0.0f,-140.f });
	optionButton->mesh->SetMeshType(rectangle);
	optionButton->mesh->InitializeTextureMesh(280.f, 70.f);

	/*test->AddComponent(new Mesh());
	test->Init();

	test->mesh->setTransform({ 0.0f,56.f });
	test->mesh->SetMeshType(rectangle);
	test->mesh->InitializeTextureMesh(160.f, 160.f);
*/
	/*test2->AddComponent(new Mesh());
	test2->Init();
		  
	test2->mesh->setTransform({ -0.7f, -0.7f });
	test2->mesh->SetMeshType(rectangle);
	test2->mesh->InitializeTextureMesh(2.f, 2.f);*/
	
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

	getOrigin3.x = optionButton->mesh->GetTransform().x;
	getOrigin3.y = optionButton->mesh->GetTransform().y;

	if (moveCheck0 %2== 1)
	{
		std::cout << cursor0.x<<", "<<cursor0.y << std::endl;
		getDirectionPooPoo.SetIsSuccess(true);
	}

	if ((cursor0.x <= (getOrigin.x + 140.0f) &&
		(cursor0.x >= (getOrigin.x - 140.0f)) &&
		(cursor0.y <= (getOrigin.y + 35.f)) &&
		(cursor0.y >= (getOrigin.y - 35.6f))))
	{
		if (moveCheck0 % 2 == 1)
		{
			std::cout << "to test" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST3);
			moveCheck0 = 0;
		}
	}
	else
	{
		moveCheck0 = 0;
	}

	if ((cursor0.x <= (getOrigin2.x + 140) &&
		(cursor0.x >= (getOrigin2.x - 140)) &&
		(cursor0.y <= (getOrigin2.y + 35)) &&
		(cursor0.y >= (getOrigin2.y - 35))))
	{
		if (moveCheck0_2 % 2 == 1)
		{
			std::cout << "to level1" << std::endl;
			STATE_MANAGER->ChangeLevel(LV_TEST1);
			moveCheck0_2 = 0;
		}
	}
	else
	{
		moveCheck0_2 = 0;
	}

	if ((cursor0.x <= (getOrigin3.x + 140) &&
		(cursor0.x >= (getOrigin3.x - 140)) &&
		(cursor0.y <= (getOrigin3.y + 35)) &&
		(cursor0.y >= (getOrigin3.y - 35))))
	{
		if (moveCheck0_3 % 2 == 1)
		{
			STATE_MANAGER->ChangeLevel(OPTION);
			std::cout << "to option" << std::endl;
			moveCheck0_3 = 0;
		}
	}
	else
	{
		moveCheck0_3 = 0;
	}

	background->mesh->Update(mShader.GetShaderHandler(), textureId02);
	startButton->mesh->Update(mShader.GetShaderHandler(), textureId01);
	tutorialButton->mesh->Update(mShader.GetShaderHandler(), textureId03);
	optionButton->mesh->Update(mShader.GetShaderHandler(), textureId04);

	getDirectionPooPoo.Update(mShader.GetShaderHandler());

	//test->mesh->SplitAnimation();
	//test->mesh->Update(mShader.GetShaderHandler(), textureId05);

	/*test2->mesh->SplitAnimation();
	test2->mesh->Update(mShader.GetShaderHandler(), textureId06);*/

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
