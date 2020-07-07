#include "startCutscene.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

void startCut::Init()
{
	mShader.BuildTextureShader();

	startCut1 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f,  0.f });
	texturestartCut1 = TEXTURE->CreateTexture("assets\\imagest1.png", 0);
	startCut1->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height) - 250.f);

	startCut2 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });
	texturestartCut2 = TEXTURE->CreateTexture("assets\\imagest2.png", 0);
	startCut2->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height) - 250.f);
	
	startCut3 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });
	texturestartCut3 = TEXTURE->CreateTexture("assets\\imagest3.png", 0);
	startCut3->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height) - 250.f);

	skip = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.f,  450.f });
	texturestartSkip = TEXTURE->CreateTexture("assets\\skip.png", 0);
	skip->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	skip->mesh->InitializeTextureMesh(173.f, 200.f);

	next = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.f,  -400.f });
	texturestartNext = TEXTURE->CreateTexture("assets\\nextd.png", 0);
	next->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	next->mesh->InitializeTextureMesh(173.f, 200.f);


	mInput.InitCallback(APPLICATION->getMyWindow());
}

void startCut::Update()
{
	cursor__ = mInput.Cursor;

	if (skip->collision->Point2BoxCollision({ cursor__.x,cursor__.y }, skip->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			if (input[0] == false)
			{
				input[0] = true;
				STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
			}
		}
		else
		{
			input[0] = false;
		}
	}


	if (next->collision->Point2BoxCollision({ cursor__.x,cursor__.y }, next->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			if (input[1] == false)
			{
				input[1] = true;
				if(cut[0] == false && cut[1] == false)
				{
					cut[0] = true;
					startCut2->mesh->setTransform({ 0.f, 0.f });
				}
				else if(cut[0] == true && cut[1] == false)
				{
					cut[1] = true;
					startCut3->mesh->setTransform({ 0.f, 0.f });
				}
				else if(cut[0] == true && cut[1] == true)
				{
					STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
				}
			}
		}
		else
		{
			input[1] = false;
		}
	}
	else
	{
		input[1] = false;
	}
	skip->mesh->Update(mShader.GetShaderHandler(), texturestartSkip);
	next->mesh->Update(mShader.GetShaderHandler(), texturestartNext);
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
