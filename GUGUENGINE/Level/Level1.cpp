#include "Level1.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"

int check = 0;
glm::vec2 cursor;

int moveCheck = 0;

GLuint texureId3;
GLuint texureId2;


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
	cursor = { (xpos - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * ((ypos)-APPLICATION->height / 2) / (APPLICATION->height / 2) };
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

	//texureId = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId2 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId3 = TEXTURE->CreateTexture("assets\\image2.png", 0);


<<<<<<< HEAD
	bgm.Init();
	bgm.LoadMusic("assets\\up.mp3");
	if(!bgm.IsPlaying())
	{
		bgm.Play();
	}

	texureId = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId2 = TEXTURE->CreateTexture("assets\\image2.png", 0);
=======
>>>>>>> 346ed081468116eafdfc1899d48f309d5a45d0c9
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
	
	glfwSetKeyCallback(APPLICATION->getMyWindow(), level1keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level1cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level1mouseButtonCallback);

}

void Level1::Update()
{
	if (check < 1)
	{
		check++;
		std::cout << "HELLO" << std::endl;
	}

<<<<<<< HEAD
	bgm.Update();
=======
	getOrigin.x = puzzle1->mesh->getTransfrom().x;
	getOrigin.y = puzzle1->mesh->getTransfrom().y;

	getOrigin2.x = puzzle2->mesh->getTransfrom().x;
	getOrigin2.y = puzzle2->mesh->getTransfrom().y;
	float r = sqrt(5) / 10;

	if (cursor.x <= (getOrigin.x + r / 2) &&
		cursor.x >= (getOrigin.x - r / 2) &&
		cursor.y <= (getOrigin.y + r) &&
		cursor.y >= (getOrigin.y - r))
	{
		if (moveCheck % 2 == 1)
		{
			puzzle1->mesh->setTransfrom({ cursor });
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
			puzzle1->mesh->setTransfrom({ puzzle2->mesh->getTransfrom().x ,puzzle2->mesh->getTransfrom().y });
			/*if (rotationCheck == 1)
			{
				mMesh = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
				std::cout << time;
				mMesh2 = MESH::create_circle(0.3f, { 255, 255, 255 }, 6, { -0.3, 0.3, 1 }, time);
				rotationCheck = 0;
			}*/
		}
	}
>>>>>>> 346ed081468116eafdfc1899d48f309d5a45d0c9
	

	puzzle1->mesh->Update();
	glUseProgram(mShader.GetShaderID());
	glBindVertexArray(puzzle1->mesh->GetVertexArrayObject());
	GLint texLoc = glGetUniformLocation(mShader.GetShaderID(), "tex");
	glUniform1i(texLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texureId);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);

	puzzle2->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle2->mesh->GetVertexArrayObject());
	GLint texLoc2 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc2, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId2);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);

	puzzle3->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle3->mesh->GetVertexArrayObject());
	GLint texLoc3 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc3, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId3);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);


	puzzle4->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle4->mesh->GetVertexArrayObject());
	GLint texLoc4 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc4, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId3);
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
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
