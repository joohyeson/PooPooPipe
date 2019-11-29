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

int check1 = 0;
Mathematics::Vector2<float> cursor1({ 0.f, 0.f });

int moveCheck1 = 0;
float degree = 0;
int rightCheck1 = 0;
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

	mShader.BuildShader();
	mShader2.BuildShader();

	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransfrom({ 0.5f, 0.7f });
	puzzle1->mesh->Initialize();

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	puzzle2->mesh->setTransfrom({ 0.0f, 0.3f });
	puzzle2->mesh->Initialize();

	puzzle3->AddComponent(new Mesh());
	puzzle3->Init();
	puzzle3->mesh->setTransfrom({ -0.3f, 0.1f });
	puzzle3->mesh->Initialize();

	puzzle4->AddComponent(new Mesh());
	puzzle4->Init();
	puzzle4->mesh->setTransfrom({ 0.3f, 0.1f });
	puzzle4->mesh->Initialize();

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

	getOrigin.x = puzzle1->mesh->getTransfrom().x;
	getOrigin.y = puzzle1->mesh->getTransfrom().y;

	getOrigin2.x = puzzle2->mesh->getTransfrom().x;
	getOrigin2.y = puzzle2->mesh->getTransfrom().y;
	float r = sqrt(5) / 10;

	if (cursor1.x <= (getOrigin.x + r / 2) &&
		cursor1.x >= (getOrigin.x - r / 2) &&
		cursor1.y <= (getOrigin.y + r) &&
		cursor1.y >= (getOrigin.y - r))
	{
		if (moveCheck1 % 2 == 1)
		{
			puzzle1->mesh->setTransfrom({ cursor1.x, cursor1.y });
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
			puzzle1->mesh->setTransfrom({ puzzle2->mesh->getTransfrom().x ,puzzle2->mesh->getTransfrom().y });

		}
	}

	if (rightCheck1 !=0)
	{
		degree += static_cast<float>(Mathematics::DegreeToRadian(60.f));
		puzzle1->mesh->setRotation(degree);
		rightCheck1 = 0;
		//moveCheck = 0;

		std::cout << puzzle1->mesh->getVertex(0).x << ", " << puzzle1->mesh->getVertex(0).y << std::endl;
		std::cout << puzzle1->mesh->getVertex(1).x << ", " << puzzle1->mesh->getVertex(1).y << std::endl;
		std::cout << puzzle1->mesh->getVertex(2).x << ", " << puzzle1->mesh->getVertex(2).y << std::endl;
		std::cout << puzzle1->mesh->getVertex(3).x << ", " << puzzle1->mesh->getVertex(3).y << std::endl;
		std::cout << puzzle1->mesh->getVertex(4).x << ", " << puzzle1->mesh->getVertex(4).y << std::endl;
		std::cout << puzzle1->mesh->getVertex(5).x << ", " << puzzle1->mesh->getVertex(5).y << std::endl;
		std::cout << puzzle1->mesh->getVertex(6).x << ", " << puzzle1->mesh->getVertex(6).y << std::endl;
		std::cout << puzzle1->mesh->getVertex(7).x << ", " << puzzle1->mesh->getVertex(7).y << std::endl;
	}

	puzzle1->mesh->Update();

	
	glUseProgram(mShader.GetShaderID());
	glBindVertexArray(puzzle1->mesh->GetVertexArrayObject());
	GLint texLoc = glGetUniformLocation(mShader.GetShaderID(), "tex");
	glUniform1i(texLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texureId21);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);

	puzzle2->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle2->mesh->GetVertexArrayObject());
	GLint texLoc2 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc2, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId21);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);

	puzzle3->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle3->mesh->GetVertexArrayObject());
	GLint texLoc3 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc3, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId22);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);

	puzzle4->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle4->mesh->GetVertexArrayObject());
	GLint texLoc4 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc4, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId22);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);


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
