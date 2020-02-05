/*
 *eunjin.hong
 *01.28.2020
 *eunjin.hong@gmail.com
 *Option.cpp
 *This is Option
 */
#include "Option.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"


Vector2<float> cursor00;

int moveCheck00 = 0;

GLuint textureBackgroundOption;
GLuint textureOption;
GLuint textureMusic;

GLuint textureArrowLeft;
GLuint textureArrowRight;

void optionCursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor00 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) - APPLICATION->height / 2) / (APPLICATION->height / 2) };
}
void optionMouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck00 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void LevelOption::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();
	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(10.f, 10.f);
	textureBackgroundOption = TEXTURE->CreateTexture("assets\\background.png", 0);



	option = OBJECT_FACTORY->CreateEmptyObject();
	option->AddComponent(new Mesh());
	option->Init();

	option->mesh->setTransform({ 0.0f,0.8f });
	option->mesh->SetMeshType(rectangle);
	option->mesh->InitializeTextureMesh(6.f, 1.5f);
	textureOption = TEXTURE->CreateTexture("assets\\option.png", 0);

	
	music = OBJECT_FACTORY->CreateEmptyObject();
	music->AddComponent(new Mesh());
	music->Init();

	music->mesh->setTransform({ -0.7f,0.5f });
	music->mesh->SetMeshType(rectangle);
	music->mesh->InitializeTextureMesh(3.f, 1.f);
	textureMusic = TEXTURE->CreateTexture("assets\\music.png", 0);


	arrowRight = OBJECT_FACTORY->CreateEmptyObject();
	arrowRight->AddComponent(new Mesh());
	arrowRight->Init();
	arrowRight->mesh->setTransform({ 0.8f,0.5f });
	arrowRight->mesh->SetMeshType(rectangle);
	arrowRight->mesh->InitializeTextureMesh(1.f, 1.f);
	textureArrowRight = TEXTURE->CreateTexture("assets\\arrow_right.png", 0);

	arrowLeft= OBJECT_FACTORY->CreateEmptyObject();
	arrowLeft->AddComponent(new Mesh());
	arrowLeft->Init();
	arrowLeft->mesh->setTransform({ -0.3f,0.5f });
	arrowLeft->mesh->SetMeshType(rectangle);
	arrowLeft->mesh->InitializeTextureMesh(1.f, 1.f);
	textureArrowLeft = TEXTURE->CreateTexture("assets\\arrow_left.png", 0);
	
	mShader.BuildColorShader();
	mShader.BuildTextureShader();


	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), optionCursorPositionCallback);
}

void LevelOption::Update()
{
	background->mesh->Update(mShader.GetShaderHandler(), textureBackgroundOption);
	option->mesh->Update(mShader.GetShaderHandler(), textureOption);
	music->mesh->Update(mShader.GetShaderHandler(), textureMusic);
	
	arrowRight->mesh->Update(mShader.GetShaderHandler(), textureArrowRight);
	arrowLeft->mesh->Update(mShader.GetShaderHandler(), textureArrowLeft);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwPollEvents();
}

void LevelOption::Close()
{
	mShader.Delete();
	mMesh.Delete();
	
	ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}