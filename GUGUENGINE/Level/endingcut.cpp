#include "endingcut.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"
#include "../GUGUENGINE/Sound.h"
void endingCut::Init()
{
	mShader.BuildTextureShader();
	for (int i = 0; i < 3; i++)
	{
		sound_[i] = false;
	}

	endCut1 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.f,  0.f });
	textureendCut1 = TEXTURE->CreateTexture("assets\\ending1.png", 0);
	endCut1->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height) - 250.f);

	endCut2 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });
	textureendCut2 = TEXTURE->CreateTexture("assets\\ending2.png", 0);
	endCut2->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height) - 250.f);

	/*endCut3 = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -2000.f,  -2000.f });
	texturestartCut3 = TEXTURE->CreateTexture("assets\\imagest3.png", 0);
	startCut3->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height) - 250.f);*/

	skip = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.f,  450.f });
	texturestartSkip = TEXTURE->CreateTexture("assets\\skip.png", 0);
	skip->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	skip->mesh->InitializeTextureMesh(173.f, 200.f);

	next = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.f,  -500.f });
	texturestartNext = TEXTURE->CreateTexture("assets\\nextd.png", 0);
	next->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	next->mesh->InitializeTextureMesh(173.f, 200.f);

	mInput.InitCallback(APPLICATION->getMyWindow());

	SOUND->StopSound("BGM");
}

void endingCut::Update()
{
	cursor__ = mInput.Cursor;
	if (mInput.IsPressed(KEY::A) == true)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
	}

	if (mInput.IsPressed(KEY::LEFT) == true)
	{
		std::cout << "CURSOR:" << cursor__.x << "," << cursor__.y << std::endl;
	}

	if (mInput.IsPressed(KEY::F))
	{
		APPLICATION->SetFullScreen();
	}

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

	if (sound_[0] == false)
	{
		sound_[0] = true;
		this->sound->Play("assets\\rain.wav", 1);
	}


	if (next->collision->Point2BoxCollision({ cursor__.x,cursor__.y }, next->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true)
		{
			INPUT->setInput(KEY::LEFT);
			if (input[1] == false)
			{
				input[1] = true;
				if (cut[0] == false && cut[1] == false)
				{
					cut[0] = true;
					if (sound_[1] == false)
					{
						sound_[1] = true;
						//this->sound->Play("assets\\flushing.wav", 1);
					}
					endCut2->mesh->setTransform({ 0.f, 0.f });
				}
				/*else if (cut[0] == true && cut[1] == false)
				{
					cut[1] = true;
					if (sound_[2] == false)
					{
						sound_[2] = true;
						this->sound->Play("assets\\heaven.wav", 1);

					}
					startCut3->mesh->setTransform({ 0.f, 0.f });
				}*/
				else if (cut[0] == true /*&& cut[1] == true*/)
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
	endCut1->mesh->Update(mShader.GetShaderHandler(), textureendCut1);
	endCut2->mesh->Update(mShader.GetShaderHandler(), textureendCut2);
	//endCut3->mesh->Update(mShader.GetShaderHandler(), texturestartCut3);

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}

void endingCut::Close()
{
	mShader.Delete();
	SOUND->StopEffectSound();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();

}
