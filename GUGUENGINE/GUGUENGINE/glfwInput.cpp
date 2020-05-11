#include "glfwInput.h"

namespace
{
	void key_callback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/);
	void cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos);
	void  mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/);

	Vector2<float> Cursor_;
	int keySpace_;
	int keyA_;
	int keyEscape_;
	int keyTap_;
	int mouseLeft_;
	int mouseRight_;
	/*int MouseRightTriggered_;*/
}

namespace
{
	void key_callback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
	{
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			keySpace_ = 2;
		}
		else
		{
			keySpace_ = 0;
		}

		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			keyA_ = 3;
		}
		else
		{
			keyA_ = 0;
		}

		if (key == GLFW_KEY_ESCAPE)
		{
			keyEscape_ = 4;
		}
		else
		{
			keyEscape_ = 0;
		}

		if (key == GLFW_KEY_TAB)
		{
			keyTap_ = 5;
		}
		else
		{
			keyTap_ = 0;
		}

	}

	void cursorPositionCallback(GLFWwindow*, double xpos, double ypos)
	{
		Cursor_ = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
	}

	void  mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			mouseLeft_ = 6;
		}
		else
		{
			mouseLeft_ = 0;
		}

		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		{
			
			mouseRight_ = 7;
		/*	MouseRightTriggered_ += 1;*/
			
		/*	if (MouseRightTriggered_ == 1)
			{
				MouseRightTriggered_ = 0;
			}*/
		}
		else
		{
			mouseRight_ = 0;
			/*MouseRightTriggered_ = 0;*/
		}
	}
}


void	Input::InitCallback(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
}

void Input::SetInput()
{
	Cursor = Cursor_;
	keySpace = keySpace_;
	keyA = keyA_;
	keyEscape = keyEscape_;
	keyTap = keyTap_;
	mouseLeft = mouseLeft_;
	mouseRight = mouseRight_;
	//MouseRightTriggered = MouseRightTriggered_;
}

bool Input::IsPressed(int key)
{
	if(key > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool Input::IsTrigerred(int key) // Mouseright triggered only now
{
	if(MouseRightTriggered == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}



