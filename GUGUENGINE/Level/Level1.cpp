#include "Level1.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
int check = 0;

void Level1::Init()
{
	puzzle1 = OBJECT_MANAGER->CreateObject();
	mShader.BuildShader();
	
	//puzzle1->AddComponent(new Mesh());
	//puzzle1->AddComponent(new Transform());
}

void Level1::Update()
{
	if(check < 1 )
	{
		check++;
		std::cout << "HELLO" << std::endl;
	}
	
	mMesh.Initialize();
	mMesh.Update();
	
	if (key == GLFW_KEY_D)
	{
		std::cout << "key is pressed" << std::endl;
	}

	glfwSwapInterval(1);

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glUseProgram(mShader.GetShaderID());

	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/24 * sizeof(float));
}

void Level1::Close()
{
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();
	OBJECT_MANAGER->DestroyAllObjects();
}
