#include "Level2.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"

void level2keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	if (key == GLFW_KEY_F)
	{
		std::cout << "Change level to Level1 in LEVEL2" << std::endl;
		STATE_MANAGER->ChangeLevel(LV_TEST1);
	}
}

void  level2cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{

}

void  level2mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level2::Init()
{

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level2keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level2cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level2mouseButtonCallback);
}

void Level2::Update()
{
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.8f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void Level2::Close()
{
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
