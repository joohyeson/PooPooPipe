#include "glfwInput.h"

Input* INPUT = nullptr;

	void key_callback(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/)
	{
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			INPUT->Key[KEY::SPACE] = true;
		}
		else if (action != GLFW_PRESS)
		{
			INPUT->Key[KEY::SPACE] = false;
		}

		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			INPUT->Key[KEY::A] = true;
		}
		else
		{
			INPUT->Key[KEY::A] = false;
		}

		if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
		{
			INPUT->Key[KEY::ESCAPE] = true;
		}
		else
		{
			INPUT->Key[KEY::ESCAPE] = false;
		}

		if (key == GLFW_KEY_TAB && action == GLFW_RELEASE)
		{
			INPUT->Key[KEY::TAB] = true;
		}
		else
		{
			INPUT->Key[KEY::TAB] = false;
		}

		if (key == GLFW_KEY_F && action == GLFW_RELEASE)
		{
			INPUT->Key[KEY::F] = true;
		}
		else
		{
			INPUT->Key[KEY::F] = false;
		}

		if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
		{
			INPUT->Key[KEY::ENTER] = true;
		}
		else if (action != GLFW_PRESS)
		{
			INPUT->Key[KEY::ENTER] = false;
		}

		if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		{
			INPUT->Key[KEY::UP] = true;
		}
		else if (action != GLFW_PRESS)
		{
			INPUT->Key[KEY::UP] = false;
		}

		if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
		{
			INPUT->Key[KEY::DOWN] = true;
		}
		else if (action != GLFW_PRESS)
		{
			INPUT->Key[KEY::DOWN] = false;
		}

	}

	void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		INPUT->Cursor = { (static_cast<float>(xpos))/APPLICATION->framebufferWidth,  (static_cast<float>(-ypos)) / APPLICATION->framebufferHeight };
		INPUT->Cursor.x *= 1920;
		INPUT->Cursor.y *= 1080;

		if (INPUT->Cursor.y < 540)
		{
	
			INPUT->Cursor.y += 540;
		}
		else
		{
			INPUT->Cursor.y -= 540;
		}

		INPUT->Cursor.x -= 960;
	}

	void  mouseButtonCallback(GLFWwindow* window, int button, int action, int /*mods*/)
	{
		//Input* input = (Input*)glfwGetWindowUserPointer(window);
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			INPUT->Key[KEY::LEFT] = true;
		}
		else
		{
			INPUT->Key[KEY::LEFT] = false;
		}

		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		{		
			INPUT->Key[KEY::RIGHT] = true;
		}
		else
		{
			INPUT->Key[KEY::RIGHT] = false;
		}
	}

Input::Input()
{
		for(int i = 0; i  < KEY::SIZE; i++)
		{
			Key[i] = false;
			WasKey[i] = false;
		}
}

void	Input::InitCallback(GLFWwindow* window)
{
	INPUT = this;
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
}

bool Input::IsPressed(KEY k)
{
	if(WasKey[k] == false && Key[k] == true)
	{
		return true;
	}
	return false;
}

void Input::Update()
{
	for(int i = 0; i < KEY::SIZE; i++)
	{
		WasKey[i] = Key[i];
	}
}

bool Input::IsKeyDown(KEY k)
{
	return Key[k];
}

void Input::setInput(KEY k)
{
	Key[k] = false;
}






