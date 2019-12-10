#include "Level3.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/MathFunctions.hpp"
#include "../GUGUENGINE/external/glfw/include/GLFW/glfw3.h"

int check3 = 0;
Vector2<float> cursor3;

int moveCheck3 = 0;


GLuint texureId31;
GLuint texureId32;
GLuint texureId33;
GLuint texureId34;
GLuint texureId35;

int rightCheck2 = 0;

float degree2 = 0;


void level3keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		std::cout << "Change level to Level1" << std::endl;
		STATE_MANAGER->ChangeLevel(LV_TEST1);
	}
}

void level3cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	cursor3 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos)-APPLICATION->height / 2) / (APPLICATION->height / 2) };
}

void  level3mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck3 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck2 += 1;
		std::cout << "rightCheck2: " << rightCheck2 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;

	}
	
}

void Level3::Init()
{
	puzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle3 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle4 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle5 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle6 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle7 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle8 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle9 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle10 = OBJECT_FACTORY->CreateEmptyObject();

	texureId31 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId32 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureId33 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureId34 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);
	texureId35 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	mShader.BuildTextureShader();
	mShader2.BuildTextureShader();
	mShader3.BuildTextureShader();
	mShader4.BuildTextureShader();
	mShader5.BuildTextureShader();
	mShader6.BuildTextureShader();
	mShader7.BuildTextureShader();
	mShader8.BuildTextureShader();
	mShader9.BuildTextureShader();
	mShader10.BuildTextureShader();

	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransform({ 0.7f, 0.7f });
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

	puzzle5->AddComponent(new Mesh());
	puzzle5->Init();
	puzzle5->mesh->setTransform({ 0.3f, 0.5f });
	puzzle5->mesh->InitializeTextureMesh();

	puzzle6->AddComponent(new Mesh());
	puzzle6->Init();
	puzzle6->mesh->setTransform({ -0.3f, 0.5f });
	puzzle6->mesh->InitializeTextureMesh();

	puzzle7->AddComponent(new Mesh());
	puzzle7->Init();
	puzzle7->mesh->setTransform({ 0.0f, 0.7f }); 
	puzzle7->mesh->InitializeTextureMesh();

	puzzle8->AddComponent(new Mesh());
	puzzle8->Init();
	puzzle8->mesh->setTransform({ 0.0f, -0.1f }); 
	puzzle8->mesh->InitializeTextureMesh();

	puzzle9->AddComponent(new Mesh());
	puzzle9->Init();
	puzzle9->mesh->setTransform({ -0.3f, -0.3f });
	puzzle9->mesh->InitializeTextureMesh();

	puzzle10->AddComponent(new Mesh());
	puzzle10->Init();
	puzzle10->mesh->setTransform({ 0.3f, -0.3f });
	puzzle10->mesh->InitializeTextureMesh();

	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), level3keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level3cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level3mouseButtonCallback);

}

void Level3::Update()
{
	if (check3 < 1)
	{
		check3++;
		std::cout << "HELLO" << std::endl;
	}

	getOrigin.x = puzzle1->mesh->GetTransform().x;
	getOrigin.y = puzzle1->mesh->GetTransform().y;

	getOrigin2.x = puzzle2->mesh->GetTransform().x;
	getOrigin2.y = puzzle2->mesh->GetTransform().y;
	
	float r = sqrt(5) / 10;

	if (cursor3.x <= (getOrigin.x + r / 2) &&
		cursor3.x >= (getOrigin.x - r / 2) &&
		cursor3.y <= (getOrigin.y + r) &&
		cursor3.y >= (getOrigin.y - r))
	{
		if (moveCheck3 % 2 == 1)
		{
			puzzle1->mesh->setTransform({ cursor3.x, cursor3.y });
			rightCheck2 = 0;
			//moveCheck = 0;
		}
	}
	else
	{
		moveCheck3 = 0;
	}

	if (getOrigin.x <= (getOrigin2.x + r / 2) &&
		getOrigin.x >= (getOrigin2.x - r / 2) &&
		getOrigin.y <= (getOrigin2.y + r) &&
		getOrigin.y >= (getOrigin2.y - r))
	{
		if (moveCheck3 % 2 == 0)
		{
			puzzle1->mesh->setTransform({ puzzle2->mesh->GetTransform().x ,puzzle2->mesh->GetTransform().y });
			
			/*if (rotationCheck == 1)
			{
				mMesh = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
				std::cout << time;
				mMesh2 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
				rotationCheck = 0;
			}*/
		}
	}

	if (rightCheck2 != 0)
	{
		degree2 += static_cast<float>(DegreeToRadian(60.f));
		puzzle1->mesh->setRotation(degree2);
		rightCheck2 = 0;
		//moveCheck = 0;

	}
	
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureId35);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureId32);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureId32);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureId33);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureId31);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureId32);
	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureId32);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureId34);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureId31);
	
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureId31);
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.6f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level3::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
