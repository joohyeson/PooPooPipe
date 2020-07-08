#include "99.h"
#include "DigipenLogo.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

GLuint textureGuguLogo;
void GUGULOGO::Init()
{
	check = false;
	firstTime = glfwGetTime();

	gugulogo = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f, 0.f });
	textureGuguLogo = TEXTURE->CreateTexture("assets\\team99.png", 0);
	gugulogo->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width/3), static_cast<float>(APPLICATION->height/1.5f));

	mShader.BuildTextureShader();
}

void GUGULOGO::Update()
{
	if(check == false)
	{
		check = true;
		this->sound->Play("assets\\fart.mp3", 1);
	}
	lastTime = glfwGetTime();
	gugulogo->mesh->Update(mShader.GetShaderHandler(), textureGuguLogo);
	if (lastTime - firstTime > 2.f)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::CUTSCENE);
	}
	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}

void GUGULOGO::Close()
{
	mShader.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
