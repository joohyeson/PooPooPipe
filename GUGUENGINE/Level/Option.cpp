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
int bar0 = 0;

GLuint textureBackgroundOption;
GLuint textureOption;
GLuint textureMusic;

GLuint textureArrowLeft;
GLuint textureArrowRight;

GLuint textureBar0;

void optionCursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor00 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) - APPLICATION->height / 2) / (APPLICATION->height / 2) };
}
void optionMouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		bar0 += 1;

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
	background->mesh->InitializeTextureMesh(800.f, 800.f);
	textureBackgroundOption = TEXTURE->CreateTexture("assets\\background.png", 0);



	option = OBJECT_FACTORY->CreateEmptyObject();
	option->AddComponent(new Mesh());
	option->Init();
	
	option->mesh->setTransform({ 0.0f,350.f });
	option->mesh->SetMeshType(rectangle);
	option->mesh->InitializeTextureMesh(400.f, 100.f);
	textureOption = TEXTURE->CreateTexture("assets\\option.png", 0);

	
	music = OBJECT_FACTORY->CreateEmptyObject();
	music->AddComponent(new Mesh());
	music->Init();

	music->mesh->setTransform({ -300.f,240.f });
	music->mesh->SetMeshType(rectangle);
	music->mesh->InitializeTextureMesh(240.f, 80.f);
	textureMusic = TEXTURE->CreateTexture("assets\\music.png", 0);


	arrowRight = OBJECT_FACTORY->CreateEmptyObject();
	arrowRight->AddComponent(new Mesh());
	arrowRight->Init();
	arrowRight->mesh->setTransform({ 350.f,240.f });
	arrowRight->mesh->SetMeshType(rectangle);
	arrowRight->mesh->InitializeTextureMesh(80.f, 80.f);
	textureArrowRight = TEXTURE->CreateTexture("assets\\arrow_right.png", 0);

	arrowLeft= OBJECT_FACTORY->CreateEmptyObject();
	arrowLeft->AddComponent(new Mesh());
	arrowLeft->Init();
	arrowLeft->mesh->setTransform({ -160.f,240.f });
	arrowLeft->mesh->SetMeshType(rectangle);
	arrowLeft->mesh->InitializeTextureMesh(80.f, 80.f);
	textureArrowLeft = TEXTURE->CreateTexture("assets\\arrow_left.png", 0);

	bar0 = OBJECT_FACTORY->CreateEmptyObject();
	bar0->AddComponent(new Mesh());
	bar0->Init();
	bar0->mesh->setTransform({ 95.f, 240.f });
	bar0->mesh->SetMeshType(rectangle);
	bar0->mesh->InitializeTextureMesh(400.f, 80.f);
	textureBar0 = TEXTURE->CreateTexture("assets\\bar0.png", 0);
	
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

	bar0->mesh->Update(mShader.GetShaderHandler(), textureBar0);

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