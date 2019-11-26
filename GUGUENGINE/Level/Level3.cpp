#include "Level3.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"

int check3 = 0;
glm::vec2 cursor3;

int moveCheck3 = 0;

GLuint texureId33;
GLuint texureId23;


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
	cursor3 = { (xpos - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * ((ypos)-APPLICATION->height / 2) / (APPLICATION->height / 2) };
}
void  level3mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck3 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level3::Init()
{
	puzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle3 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle4 = OBJECT_FACTORY->CreateEmptyObject();

	//texureId = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId23 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureId33 = TEXTURE->CreateTexture("assets\\image2.png", 0);


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

	getOrigin.x = puzzle1->mesh->getTransfrom().x;
	getOrigin.y = puzzle1->mesh->getTransfrom().y;

	getOrigin2.x = puzzle2->mesh->getTransfrom().x;
	getOrigin2.y = puzzle2->mesh->getTransfrom().y;
	float r = sqrt(5) / 10;

	if (cursor3.x <= (getOrigin.x + r / 2) &&
		cursor3.x >= (getOrigin.x - r / 2) &&
		cursor3.y <= (getOrigin.y + r) &&
		cursor3.y >= (getOrigin.y - r))
	{
		if (moveCheck3 % 2 == 1)
		{
			puzzle1->mesh->setTransfrom({ cursor3 });
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
	glBindTexture(GL_TEXTURE_2D, texureId23);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);

	puzzle3->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle3->mesh->GetVertexArrayObject());
	GLint texLoc3 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc3, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId33);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);


	puzzle4->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle4->mesh->GetVertexArrayObject());
	GLint texLoc4 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc4, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId33);
	glDrawArrays(GL_TRIANGLE_FAN/*mMesh.GetPointListPattern()*/, 0, /*mMesh.GetPointCount()*/8);


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
