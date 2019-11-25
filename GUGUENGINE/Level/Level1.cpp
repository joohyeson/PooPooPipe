#include "Level1.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"

int check = 0;
GLuint texureId;
GLuint texureId2;
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
	puzzle2 = OBJECT_FACTORY->CreateEmptyObject();

	texureId = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId2 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	mShader.BuildShader();
	//Shader mShader2;
	mShader2.BuildShader();
	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransfrom({ 0.5f, 0.7f });
	puzzle1->mesh->Initialize();

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	puzzle2->mesh->setTransfrom({ 0.0f, 0.3f });
	puzzle2->mesh->Initialize();
	
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
	glUseProgram(mShader.GetShaderID());
	glBindVertexArray(puzzle1->mesh->GetVertexArrayObject());
	GLint texLoc = glGetUniformLocation(mShader.GetShaderID(), "tex");
	glUniform1i(texLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texureId);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);

	puzzle2->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle2->mesh->GetVertexArrayObject());
	GLint texLoc2 = glGetUniformLocation(mShader.GetShaderID(), "tex");
	glUniform1i(texLoc, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId2);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);
	
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level1::Close()
{
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
