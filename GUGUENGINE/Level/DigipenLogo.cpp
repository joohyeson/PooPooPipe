/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *DigipenLogo.h
 *this is digipen logo
 */
#include "DigipenLogo.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

void DigipenLogo::Init()
{
	check = false;
	firstTime = glfwGetTime();

	digipenLogo = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f, 0.f });
	digipenLogo->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width/2), static_cast<float>(APPLICATION->height/3));
	
	mShader.BuildTextureShader();

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void DigipenLogo::Update()
{

	cursor0 = mInput.Cursor;
	if(check == false)
	{
		this->sound->Play("assets\\logo.wav", 1);
	}
	
	if (mInput.IsPressed(KEY::F))
	{
		INPUT->setInput(KEY::F);
		APPLICATION->SetFullScreen();
	}

	lastTime = glfwGetTime();
	digipenLogo->mesh->Update(mShader.GetShaderHandler(),TEXTURE->GetTexture(Textures::DIGIPENLOGO));
	if(lastTime - firstTime > 2.f)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::FMODLOGO);
	}

	if (mInput.IsPressed(KEY::ESCAPE))
	{
		glfwTerminate();
		ENGINE->Quit();
	}

    glfwSwapBuffers(APPLICATION->getMyWindow());
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
}

void DigipenLogo::Close()
{
	mShader.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
	
}
