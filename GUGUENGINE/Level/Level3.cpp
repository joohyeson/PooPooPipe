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

	mShader.BuildShader();
	mShader2.BuildShader();
	mShader3.BuildShader();
	mShader4.BuildShader();
	mShader5.BuildShader();
	mShader6.BuildShader();
	mShader7.BuildShader();
	mShader8.BuildShader();
	mShader9.BuildShader();
	mShader10.BuildShader();

	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransform({ 0.7f, 0.7f });
	puzzle1->mesh->Initialize();

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	puzzle2->mesh->setTransform({ 0.0f, 0.3f }); 
	puzzle2->mesh->Initialize();

	puzzle3->AddComponent(new Mesh());
	puzzle3->Init();
	puzzle3->mesh->setTransform({ -0.3f, 0.1f });
	puzzle3->mesh->Initialize();

	puzzle4->AddComponent(new Mesh());
	puzzle4->Init();
	puzzle4->mesh->setTransform({ 0.3f, 0.1f });
	puzzle4->mesh->Initialize();

	puzzle5->AddComponent(new Mesh());
	puzzle5->Init();
	puzzle5->mesh->setTransform({ 0.3f, 0.5f });
	puzzle5->mesh->Initialize();

	puzzle6->AddComponent(new Mesh());
	puzzle6->Init();
	puzzle6->mesh->setTransform({ -0.3f, 0.5f });
	puzzle6->mesh->Initialize();

	puzzle7->AddComponent(new Mesh());
	puzzle7->Init();
	puzzle7->mesh->setTransform({ 0.0f, 0.7f }); 
	puzzle7->mesh->Initialize();

	puzzle8->AddComponent(new Mesh());
	puzzle8->Init();
	puzzle8->mesh->setTransform({ 0.0f, -0.1f }); 
	puzzle8->mesh->Initialize();

	puzzle9->AddComponent(new Mesh());
	puzzle9->Init();
	puzzle9->mesh->setTransform({ -0.3f, -0.3f });
	puzzle9->mesh->Initialize();

	puzzle10->AddComponent(new Mesh());
	puzzle10->Init();
	puzzle10->mesh->setTransform({ 0.3f, -0.3f });
	puzzle10->mesh->Initialize();

	
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

		std::cout << puzzle1->mesh->GetVertex(0).x << ", " << puzzle1->mesh->GetVertex(0).y << std::endl;
		std::cout << puzzle1->mesh->GetVertex(1).x << ", " << puzzle1->mesh->GetVertex(1).y << std::endl;
		std::cout << puzzle1->mesh->GetVertex(2).x << ", " << puzzle1->mesh->GetVertex(2).y << std::endl;
		std::cout << puzzle1->mesh->GetVertex(3).x << ", " << puzzle1->mesh->GetVertex(3).y << std::endl;
		std::cout << puzzle1->mesh->GetVertex(4).x << ", " << puzzle1->mesh->GetVertex(4).y << std::endl;
		std::cout << puzzle1->mesh->GetVertex(5).x << ", " << puzzle1->mesh->GetVertex(5).y << std::endl;
		std::cout << puzzle1->mesh->GetVertex(6).x << ", " << puzzle1->mesh->GetVertex(6).y << std::endl;
		std::cout << puzzle1->mesh->GetVertex(7).x << ", " << puzzle1->mesh->GetVertex(7).y << std::endl;
	}
	
	puzzle1->mesh->Update();
	glUseProgram(mShader.GetShaderID());
	glBindVertexArray(puzzle1->mesh->GetVertexArrayObject());
	GLint texLoc = glGetUniformLocation(mShader.GetShaderID(), "tex");
	glUniform1i(texLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texureId31);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

	puzzle2->mesh->Update();
	glUseProgram(mShader2.GetShaderID());
	glBindVertexArray(puzzle2->mesh->GetVertexArrayObject());
	GLint texLoc2 = glGetUniformLocation(mShader2.GetShaderID(), "tex");
	glUniform1i(texLoc2, 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texureId31);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

	puzzle3->mesh->Update();
	glUseProgram(mShader3.GetShaderID());
	glBindVertexArray(puzzle3->mesh->GetVertexArrayObject());
	GLint texLoc3 = glGetUniformLocation(mShader3.GetShaderID(), "tex");
	glUniform1i(texLoc3, 2);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, texureId32);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

	puzzle4->mesh->Update();
	glUseProgram(mShader4.GetShaderID());
	glBindVertexArray(puzzle4->mesh->GetVertexArrayObject());
	GLint texLoc4 = glGetUniformLocation(mShader4.GetShaderID(), "tex");
	glUniform1i(texLoc4, 3);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, texureId32);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

	puzzle5->mesh->Update();
	glUseProgram(mShader5.GetShaderID());
	glBindVertexArray(puzzle5->mesh->GetVertexArrayObject());
	GLint texLoc5 = glGetUniformLocation(mShader5.GetShaderID(), "tex");
	glUniform1i(texLoc5, 4);
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, texureId33);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);  //strat

	puzzle6->mesh->Update();
	glUseProgram(mShader6.GetShaderID());
	glBindVertexArray(puzzle6->mesh->GetVertexArrayObject());
	GLint texLoc6 = glGetUniformLocation(mShader6.GetShaderID(), "tex");
	glUniform1i(texLoc6, 5);
	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, texureId31);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

	puzzle7->mesh->Update();
	glUseProgram(mShader7.GetShaderID());
	glBindVertexArray(puzzle7->mesh->GetVertexArrayObject());
	GLint texLoc7 = glGetUniformLocation(mShader7.GetShaderID(), "tex");
	glUniform1i(texLoc7, 6);
	glActiveTexture(GL_TEXTURE6);
	glBindTexture(GL_TEXTURE_2D, texureId32);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);


	puzzle8->mesh->Update();
	glUseProgram(mShader8.GetShaderID());
	glBindVertexArray(puzzle8->mesh->GetVertexArrayObject());
	GLint texLoc8 = glGetUniformLocation(mShader8.GetShaderID(), "tex");
	glUniform1i(texLoc8, 7);
	glActiveTexture(GL_TEXTURE7);
	glBindTexture(GL_TEXTURE_2D, texureId32);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

	puzzle9->mesh->Update();
	glUseProgram(mShader9.GetShaderID());
	glBindVertexArray(puzzle9->mesh->GetVertexArrayObject());
	GLint texLoc9 = glGetUniformLocation(mShader9.GetShaderID(), "tex");
	glUniform1i(texLoc9, 8);
	glActiveTexture(GL_TEXTURE8);
	glBindTexture(GL_TEXTURE_2D, texureId34);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8); //last

	puzzle10->mesh->Update();
	glUseProgram(mShader10.GetShaderID());
	glBindVertexArray(puzzle10->mesh->GetVertexArrayObject());
	GLint texLoc10 = glGetUniformLocation(mShader10.GetShaderID(), "tex");
	glUniform1i(texLoc10, 9);
	glActiveTexture(GL_TEXTURE9);
	glBindTexture(GL_TEXTURE_2D, texureId31);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8); //move
	
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
