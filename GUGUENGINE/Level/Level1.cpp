#include "Level1.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

int check = 0;
Vector2<float> cursor;

int moveCheck = 0;
GLuint texureId4;
GLuint texureId3;
GLuint texureId2;

Sound se;

void level1keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		std::cout << "Change level to Level2" << std::endl;
		STATE_MANAGER->ChangeLevel(LV_TEST2);
	}
}

void level1cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	cursor = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) -APPLICATION->height / 2) / (APPLICATION->height / 2) };
}
void  level1mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level1::Init()
{
	puzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle3 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle4 = OBJECT_FACTORY->CreateEmptyObject();

	texureId2 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId3 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureId4 = TEXTURE->CreateTexture("assets\\image1.png", 0);

	se.Init();
	se.LoadMusic("assets\\coin.mp3");
	
	bgm.Init();
	bgm.LoadMusic("assets\\up.mp3");
	if(!bgm.IsPlaying())
	{
		bgm.Play();
		bgm.SetVolume(0.05f);
	}

	//texureId3 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	//texureId2 = TEXTURE->CreateTexture("assets\\image2.png", 0);

	mShader.BuildColorShader();
	mShader2.BuildTextureShader();

	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransform({ 0.5f, 0.7f });
	puzzle1->mesh->InitializeColorMesh();

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	
	puzzle2->mesh->setTransform({ 0.3f, 0.5f });
	puzzle2->mesh->InitializeTextureMesh();

	puzzle3->AddComponent(new Mesh());
	puzzle3->Init();
	puzzle3->mesh->SetMeshType(box);
	puzzle3->mesh->setTransform({ -0.3f, 0.1f });
	puzzle3->mesh->InitializeTextureMesh();

	puzzle4->AddComponent(new Mesh());
	puzzle4->Init();
	puzzle4->mesh->setTransform({ 0.3f, 0.1f });
	puzzle4->mesh->InitializeTextureMesh();
	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), level1keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level1cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level1mouseButtonCallback);

	//std::cout<<puzzle3->pipe->giveDir(1);

}

void Level1::Update()
{
	if (check < 1)
	{
		check++;
		std::cout << "HELLO" << std::endl;
	}

	bgm.Update();
	se.Update();
	
	getOrigin.x = puzzle1->mesh->GetTransform().x;
	getOrigin.y = puzzle1->mesh->GetTransform().y;

	getOrigin2.x = puzzle2->mesh->GetTransform().x;
	getOrigin2.y = puzzle2->mesh->GetTransform().y;
	float r = sqrt(5) / 10;

	if (cursor.x <= (getOrigin.x + r / 2) &&
		cursor.x >= (getOrigin.x - r / 2) &&
		cursor.y <= (getOrigin.y + r) &&
		cursor.y >= (getOrigin.y - r))
	{
		if (moveCheck % 2 == 1)
		{
			puzzle1->mesh->setTransform({ cursor.x, cursor.y });
			//moveCheck = 0;
		}
	}
	else
	{
		moveCheck = 0;
	}

	if (getOrigin.x <= (getOrigin2.x + r / 2) &&
		getOrigin.x >= (getOrigin2.x - r / 2) &&
		getOrigin.y <= (getOrigin2.y + r) &&
		getOrigin.y >= (getOrigin2.y - r))
	{
		
		if (moveCheck % 2 == 0)
		{
			puzzle1->mesh->setTransform({ getOrigin2.x,getOrigin2.y });
			/*if (rotationCheck == 1)
			{
				mMesh = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
				std::cout << time;
				mMesh2 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
				rotationCheck = 0;
			}*/
		}
	}
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureId4);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureId3);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureId2);

	puzzle1->mesh->ColorMeshUpdate(mShader.GetShaderHandler());
	
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level1::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
