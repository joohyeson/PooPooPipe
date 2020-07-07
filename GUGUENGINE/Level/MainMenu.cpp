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

float volume = 0.3f;

GLuint textureId00;	//game title
GLuint textureId01; //game start
GLuint textureId02; //title
GLuint textureId03; //tutorial
GLuint textureId05;//test
GLuint textureId04;	//option button
GLuint textureId06;//man
GLuint startPress;
GLuint tutorialPress;
GLuint optionPress;

bool isPlaying = false;
//Sound bgm;

void menuKeyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
		//bgm.Stop();
		std::cout << "Stop music" << std::endl;
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
		//bgm.Free();
	}

	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		std::cout << "Up Key" << std::endl;

		if (volume < 1.0f)
		{
			volume += 0.1f;
			//bgm.SetVolume(volume);

			std::cout << volume << std::endl;
		}
	}

	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
	{
		std::cout << "Down Key" << std::endl;

		if (volume > 0.0f)
		{
			volume -= 0.1f;
			//bgm.SetVolume(volume);

			std::cout << volume << std::endl;
		}
	}

	if (key == GLFW_KEY_F&& action == GLFW_RELEASE)
	{
		std::cout << "F Key" << std::endl;

		APPLICATION->SetFullScreen();

	}


}
void menuCursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor0 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
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



	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();
	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(1920, 1080.f);

	textureId02 = TEXTURE->CreateTexture("assets\\title.png", 0);

	startButton = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton = OBJECT_FACTORY->CreateEmptyObject();
	optionButton = OBJECT_FACTORY->CreateEmptyObject();

	startButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	tutorialButton_pressed = OBJECT_FACTORY->CreateEmptyObject();
	optionButton_pressed = OBJECT_FACTORY->CreateEmptyObject();

	test = OBJECT_FACTORY->CreateEmptyObject();
	test2 = OBJECT_FACTORY->CreateEmptyObject();

	textureId00 = TEXTURE->CreateTexture("assets\\game_title.png", 0);
	textureId01 = TEXTURE->CreateTexture("assets\\start.png", 0);
	textureId03 = TEXTURE->CreateTexture("assets\\tutorial.png", 0);
	textureId04 = TEXTURE->CreateTexture("assets\\option.png", 0);
	textureId05 = TEXTURE->CreateTexture("assets\\testpoopoo.png", 0);
	textureId06 = TEXTURE->CreateTexture("assets\\man.png", 0);
	startPress = TEXTURE->CreateTexture("assets\\start2.png", 0);
	tutorialPress = TEXTURE->CreateTexture("assets\\tutorial2.png", 0);
	optionPress = TEXTURE->CreateTexture("assets\\option2.png", 0);

	mShader.BuildTextureShader();
	//testNDCShader.BuildTextureShaderNDC();
	startButton->AddComponent(new Mesh());
	startButton->AddComponent(new CollisionCheck());
	startButton->Init();
	startButton_pressed->AddComponent(new Mesh());
	startButton_pressed->AddComponent(new CollisionCheck());
	startButton_pressed->Init();

	startButton->mesh->setTransform({ 0.f,-20.f });
	startButton->mesh->SetMeshType(rectangle);
	startButton->mesh->InitializeTextureMesh(280.f, 70.f);
	startButton_pressed->mesh->setTransform({ 1000.f,-20.f });
	startButton_pressed->mesh->SetMeshType(rectangle);
	startButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	tutorialButton->AddComponent(new Mesh());
	tutorialButton->Init();
	tutorialButton_pressed->AddComponent(new Mesh());
	tutorialButton_pressed->Init();

	tutorialButton->mesh->setTransform({ 0.0f,-100.f });
	tutorialButton->mesh->SetMeshType(rectangle);
	tutorialButton->mesh->InitializeTextureMesh(280.f, 70.f);
	tutorialButton_pressed->mesh->setTransform({ 1000.0f,-100.f });
	tutorialButton_pressed->mesh->SetMeshType(rectangle);
	tutorialButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

	optionButton->AddComponent(new Mesh());
	optionButton->Init();
	optionButton_pressed->AddComponent(new Mesh());
	optionButton_pressed->Init();
	optionButton->mesh->setTransform({ 0.0f,-180.f });
	optionButton->mesh->SetMeshType(rectangle);
	optionButton->mesh->InitializeTextureMesh(280.f, 70.f);
	optionButton_pressed->mesh->setTransform({ 0.0f,-180.f });
	optionButton_pressed->mesh->SetMeshType(rectangle);
	optionButton_pressed->mesh->InitializeTextureMesh(280.f, 70.f);

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
	//bgm.Update();

	if (isPlaying == false)
	{
		this->sound->Play("assets\\BGM_airplane.mp3", -1);
		isPlaying = true;
	}


	if (moveCheck0 % 2 == 1)
	{
		std::cout << cursor0.x << ", " << cursor0.y << std::endl;
		//getDirectionPooPoo.SetIsSuccess(true);
	}
	
	std::cout << "mouse: " << cursor0.x << ", " << cursor0.y << std::endl;
	std::cout << "buttom: " << startButton->mesh->GetTransform().x << ", " << startButton->mesh->GetTransform().y << std::endl;
	
	if (startButton->collision->Point2BoxCollision(cursor0, startButton->mesh))
	{


		startButton_pressed->mesh->setTransform(startButton->mesh->GetTransform());
		if (moveCheck0 % 2 == 1)
		{
			std::cout << "to test" << std::endl;
			moveCheck0 = 0;
			STATE_MANAGER->ChangeLevel(LV_TEST3);
		}
	}
	else
	{
		startButton_pressed->mesh->setTransform({1000.f, 1000.f});
		moveCheck0 = 0;
	}


	if (tutorialButton->collision->Point2BoxCollision(cursor0, tutorialButton->mesh))
	{
		tutorialButton_pressed->mesh->setTransform(tutorialButton->mesh->GetTransform());
		if (moveCheck0_2 % 2 == 1)
		{
			std::cout << "to level1" << std::endl;
			moveCheck0_2 = 0;
			STATE_MANAGER->ChangeLevel(LV_TEST1);
		}
	}
	else
	{
		tutorialButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
		moveCheck0_2 = 0;
	}

	if (optionButton->collision->Point2BoxCollision(cursor0, optionButton->mesh))
	{
		optionButton_pressed->mesh->setTransform(optionButton->mesh->GetTransform());

		if (moveCheck0_3 % 2 == 1)
		{
			STATE_MANAGER->ChangeLevel(OPTION);
			std::cout << "to option" << std::endl;
			moveCheck0_3 = 0;
		}
	}
	else
	{
		optionButton_pressed->mesh->setTransform({ 1000.f, 1000.f });
		moveCheck0_3 = 0;
	}

	background->mesh->Update(mShader.GetShaderHandler(), textureId02);
	startButton->mesh->Update(mShader.GetShaderHandler(), textureId01);
	tutorialButton->mesh->Update(mShader.GetShaderHandler(), textureId03);
	optionButton->mesh->Update(mShader.GetShaderHandler(), textureId04);
	startButton_pressed->mesh->Update(mShader.GetShaderHandler(), startPress);
	tutorialButton_pressed->mesh->Update(mShader.GetShaderHandler(), tutorialPress);
	optionButton_pressed->mesh->Update(mShader.GetShaderHandler(), optionPress);

	//getDirectionPooPoo.Update(mShader.GetShaderHandler());

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
	//bgm.Free();
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
