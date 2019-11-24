#include "Level1.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/external/SDL2/include/SDL_scancode.h"
#include "../GUGUENGINE/Application.h"
int check = 0;


void level1keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	if (key==GLFW_KEY_SPACE)
	{
		std::cout << "Change level to Level2" << std::endl;
		STATE_MANAGER->ChangeLevel(LV_TEST2);
	}
}

void  level1cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	
}

void  level1mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_RIGHT&& action == GLFW_PRESS)
	{
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level1::Init()
{

	puzzle1 = OBJECT_FACTORY->CreateEmptyObject();

	mShader.BuildShader();
	
	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->Initialize();
	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), level1keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level1cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level1mouseButtonCallback);
	//puzzle1->Init()
	//puzzle1->AddComponent(new Transform());
}

void Level1::Update()
{
	if(check < 1 )
	{
		check++;
		std::cout << "HELLO" << std::endl;
	}

	puzzle1->mesh->Update();
	



	glfwSwapInterval(1);

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
	glUseProgram(mShader.GetShaderID());

	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);
}

void Level1::Close()
{
	mShader.Delete();
	//mMesh.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
