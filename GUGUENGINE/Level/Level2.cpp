#include "Level2.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "../GUGUENGINE/Mathematics/MathFunctions.hpp"
#include "../GUGUENGINE/external/glfw/include/GLFW/glfw3.h"

int check1 = 0;
Vector2<float> cursor1({ 0.f, 0.f });

int moveCheck1 = 0;
float degree = 0;
int rightCheck1 = 0;
GLuint texureId23;
GLuint texureId22;
GLuint texureId21;

void level2keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		std::cout << "Change level to Level3" << std::endl;
		STATE_MANAGER->ChangeLevel(LV_TEST3);
	}
} 

void level2cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	cursor1 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>((ypos))-APPLICATION->height / 2) / (APPLICATION->height / 2) };
}
void  level2mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck1 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck1 += 1;
		std::cout << "rightCheck1: " << rightCheck1 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
		
	}
}

void Level2::Init()
{
	puzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle3 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle4 = OBJECT_FACTORY->CreateEmptyObject();

	//texureId = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId21 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId22 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureId23 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	mShader.BuildTextureShader();
	mShader2.BuildTextureShader();

	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransform({ 0.5f, 0.7f });
	puzzle1->mesh->InitializeTextureMesh();

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	puzzle2->mesh->setTransform({ 0.0f, 0.3f });
	puzzle2->mesh->InitializeTextureMesh();

	puzzle3->AddComponent(new Mesh());
	puzzle3->Init();
	puzzle3->mesh->setTransform({ -0.3f, 0.1f });
	puzzle3->mesh->InitializeTextureMesh();

	puzzle4->AddComponent(new Mesh());
	puzzle4->Init();
	puzzle4->mesh->setTransform({ 0.3f, 0.1f });
	puzzle4->mesh->InitializeTextureMesh();

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level2keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level2cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level2mouseButtonCallback);

}

void Level2::Update()
{
	if (check1 < 1)
	{
		check1++;
		std::cout << "HELLO" << std::endl;
	}

	getOrigin.x = puzzle1->mesh->GetTransform().x;
	getOrigin.y = puzzle1->mesh->GetTransform().y;

	getOrigin2.x = puzzle2->mesh->GetTransform().x;
	getOrigin2.y = puzzle2->mesh->GetTransform().y;
	float r = sqrt(5) / 10;

	if (cursor1.x <= (getOrigin.x + r / 2) &&
		cursor1.x >= (getOrigin.x - r / 2) &&
		cursor1.y <= (getOrigin.y + r) &&
		cursor1.y >= (getOrigin.y - r))
	{
		if (moveCheck1 % 2 == 1)
		{
			puzzle1->mesh->setTransform({ cursor1.x, cursor1.y });
			//moveCheck = 0;
			rightCheck1 = 0;
		}
	}
	else
	{
		moveCheck1 = 0;
	}

	if (getOrigin.x <= (getOrigin2.x + r / 2) &&
		getOrigin.x >= (getOrigin2.x - r / 2) &&
		getOrigin.y <= (getOrigin2.y + r) &&
		getOrigin.y >= (getOrigin2.y - r))
	{
		if (moveCheck1 % 2 == 0)
		{
			puzzle1->mesh->setTransform({ puzzle2->mesh->GetTransform().x ,puzzle2->mesh->GetTransform().y });

		}
	}

	if (rightCheck1 !=0)
	{
		degree += static_cast<float>(DegreeToRadian(60.f));
		puzzle1->mesh->setRotation(degree);
		rightCheck1 = 0;
		//moveCheck = 0;

	
	}
	
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureId23);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureId22);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureId22);

	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureId21);
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.5f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level2::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
