/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *DigipenLogo.h
 *this is digipen logo
 */
#include "DigipenLogo.h"
#include <windows.h>
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

void DigipenLogo::Init()
{
	firstTime = glfwGetTime();

	digipenLogo = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f, 0.f });
	textureDigipenLogo = TEXTURE->CreateTexture("assets\\DigiPen_WHITE_1024px.png", 0);
	digipenLogo->mesh->InitializeTextureMesh(APPLICATION->width/2, APPLICATION->height/3);
	
	mShader.BuildTextureShader();
}

void DigipenLogo::Update()
{
	lastTime = glfwGetTime();
	digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo);
	if(lastTime - firstTime > 2.f)
	{
		STATE_MANAGER->ChangeLevel(FMODLOGO);
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
