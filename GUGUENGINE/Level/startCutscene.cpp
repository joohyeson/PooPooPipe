#include "startCutscene.h"
#include <windows.h>
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

void startCut::Init()
{
	mShader.BuildTextureShader();

	startCut1 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f,  0.f });
	texturestartCut1 = TEXTURE->CreateTexture("assets\\imagest1.png", 0);
	startCut1->mesh->InitializeTextureMesh(APPLICATION->width , APPLICATION->height );

	startCut2 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });
	texturestartCut2 = TEXTURE->CreateTexture("assets\\imagest2.png", 0);
	startCut2->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	
	startCut3 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });
	texturestartCut3 = TEXTURE->CreateTexture("assets\\imagest3.png", 0);
	startCut3->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	
}

void startCut::Update()
{
	dt++;

	if (dt < 500.f)
	{
		startCut1->mesh->setTransform({ 0.f, 0.f });
	}
	else
	{
		startCut1->mesh->setTransform({ -2000.f, -2000.f });
	}
	
	if(dt>= 500.f && dt < 1000.f)
	{
		startCut2->mesh->setTransform({ 0.f, 0.f });
	}
	else
	{
		startCut2->mesh->setTransform({ -2000.f, -2000.f });
	}

	if(dt >= 1000.f && dt < 1500.f)
	{
		startCut3->mesh->setTransform({ 0.f, 0.f });
	}
	else
	{
		startCut3->mesh->setTransform({ -2000.f, -2000.f });
	}

	

	if (dt >= 1500.f)
	{
		STATE_MANAGER->ChangeLevel(MAINMENU);
	}

	startCut1->mesh->Update(mShader.GetShaderHandler(), texturestartCut1);
	startCut2->mesh->Update(mShader.GetShaderHandler(), texturestartCut2);
	startCut3->mesh->Update(mShader.GetShaderHandler(), texturestartCut3);

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}

void startCut::Close()
{

	mShader.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();

}
