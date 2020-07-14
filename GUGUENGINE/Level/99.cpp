/*
 *uijin.lee
 *4.13.2020
 *digipen.uijin.lee@gmail.com
 *this is team logo transition
 */
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
	check[0] = false;
	check[1] = false;
	
	firstTime = glfwGetTime();

	gugulogo = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f, 0.f });
	textureGuguLogo = TEXTURE->CreateTexture("assets\\team99.png", 0);
	gugulogo->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width/3), static_cast<float>(APPLICATION->height/1.5f));

	mShader.BuildTextureShader();

	mInput.InitCallback(APPLICATION->getMyWindow());

}

void GUGULOGO::Update()
{
	if(check[0] == false)
	{
		check[0] = true;
		this->sound->Play("assets\\fart.mp3", 1);
	}
	if(check[1] == false)
	{
		check[1] = true;
		//this->sound->Play("assets\\footprint.wav", 1);
	}
	lastTime = glfwGetTime();
	gugulogo->mesh->Update(mShader.GetShaderHandler(), textureGuguLogo);
	if (lastTime - firstTime > 2.f)
	{
		this->sound->Pause();
		STATE_MANAGER->ChangeLevel(GameLevels::LOAD1);
		
	}

	if (mInput.IsPressed(KEY::F))
	{
		INPUT->setInput(KEY::F);
		APPLICATION->SetFullScreen();
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
