#include "LevelSelect.h"
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/glfwInput.h"

Vector2<float> cursorLv;

Sound seLv;

void LevelSelect::Init()
{
	currentLevel = STATE_MANAGER->GetCurrentLV();
	std::cout << "come in LevelSelect" << std::endl;
	backgroundLv = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	backgroundLv->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width), static_cast<float>(APPLICATION->height));
	textureBackgroundLv = TEXTURE->CreateTexture("assets\\background.png", 0);

	Level1 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -132.f - 200.f, 160.f });
	texureIdLv1 = TEXTURE->CreateTexture("assets\\levelButton1.png", 0);

	Level1_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f });
	texureIdLv1_pressed = TEXTURE->CreateTexture("assets\\levelButton1_2.png", 0);

	Level2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 4.0f - 160.f, 160.f }, 60 * 3);
	texureIdLv2 = TEXTURE->CreateTexture("assets\\levelButton2.png", 0);

	Level2_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv2_pressed = TEXTURE->CreateTexture("assets\\levelButton2_2.png", 0);

	Level2_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureId_lock = TEXTURE->CreateTexture("assets\\locked.png", 0);

	Level3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 140.f - 120.f, 160.f }, 60 * 3);
	texureIdLv3 = TEXTURE->CreateTexture("assets\\levelButton3.png", 0);

	Level3_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv3_pressed = TEXTURE->CreateTexture("assets\\levelButton3_2.png", 0);
	Level3_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 45.f, 40.f - 30.f }, 60 * 3);
	texureIdLv4 = TEXTURE->CreateTexture("assets\\levelButton4.png", 0);

	Level4_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv4_pressed = TEXTURE->CreateTexture("assets\\levelButton4_2.png", 0);
	Level4_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 5.f  , 40.f - 30.f }, 60 * 3);
	texureIdLv5 = TEXTURE->CreateTexture("assets\\levelButton5.png", 0);

	Level5_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv5_pressed = TEXTURE->CreateTexture("assets\\levelButton5_2.png", 0);
	Level5_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level6 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f + 30.f, 40.f - 30.f }, 60 * 3);
	texureIdLv6 = TEXTURE->CreateTexture("assets\\levelButton6.png", 0);

	Level6_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv6_pressed = TEXTURE->CreateTexture("assets\\levelButton6_2.png", 0);
	Level6_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level7 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 45.f + 87.f, -140.f }, 60 * 3);
	texureIdLv7 = TEXTURE->CreateTexture("assets\\levelButton7.png", 0);

	Level7_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv7_pressed = TEXTURE->CreateTexture("assets\\levelButton7_2.png", 0);
	Level7_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 45.f + 87.f + 176.f, -140.f }, 60 * 3);
	texureIdLv8 = TEXTURE->CreateTexture("assets\\levelButton8.png", 0);

	Level8_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv8_pressed = TEXTURE->CreateTexture("assets\\levelButton8_2.png", 0);
	Level8_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f - 45.f + 87.f + 176.f + 87.f*2, -140.f }, 60 * 3);
	texureIdLv9 = TEXTURE->CreateTexture("assets\\levelButton9.png", 0);

	Level9_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv9_pressed = TEXTURE->CreateTexture("assets\\levelButton9_2.png", 0);
	Level9_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f+87.f +45.f, -140.f-150.f }, 60 * 3);
	texureIdLv10 = TEXTURE->CreateTexture("assets\\levelButton10.png", 0);

	Level10_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv10_pressed = TEXTURE->CreateTexture("assets\\levelButton10_2.png", 0);
	Level10_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);

	Level11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -200.f + 87.f + 45.f + 87.f+87.f, -140.f - 150.f }, 60 * 3);
	texureIdLv11 = TEXTURE->CreateTexture("assets\\levelButton11.png", 0);

	Level11_pressed = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	texureIdLv11_pressed = TEXTURE->CreateTexture("assets\\levelButton11_2.png", 0);
	Level11_lock = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 850.0f, 850.0f }, 60 * 3);
	
	seLv.Init();
	seLv.LoadMusic("assets\\coin.mp3");

	mShader2.BuildTextureShader();
	levelInput.InitCallback(APPLICATION->getMyWindow());
}

void LevelSelect::Update()
{
	cursorLv = levelInput.Cursor;

	if (levelInput.IsPressed(KEY::F) == true)
	{
		APPLICATION->SetFullScreen();
		levelInput.setInput(KEY::F);
	}

	if (levelInput.IsPressed(KEY::ESCAPE) == true)
	{
		INPUT->setInput(KEY::ESCAPE);
		STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
	}

	if (Level1->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level1->mesh))
	{
		Level1_pressed->mesh->setTransform(Level1->mesh->GetTransform());
		if (levelInput.IsPressed(KEY::LEFT) == true)
		{
			
			std::cout << "get mouse left" << std::endl;
			getLevNum = 1;
		}
	}
	else
	{
		Level1_pressed->mesh->setTransform({ 850.0f, 850.0f });
	}

	if (currentLevel >= 2)
	{
		if (Level2->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level2->mesh))
		{
			Level2_pressed->mesh->setTransform(Level2->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 2;
			}
		}
		else
		{
			Level2_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level2_lock->mesh->setTransform(Level2->mesh->GetTransform());
	}

	if (currentLevel >= 3)
	{
		if (Level3->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level3->mesh))
		{
			Level3_pressed->mesh->setTransform(Level3->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 3;
			}
		}
		else
		{
			Level3_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level3_lock->mesh->setTransform(Level3->mesh->GetTransform());
	}

	if (currentLevel >= 4)
	{
		if (Level4->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level4->mesh))
		{
			Level4_pressed->mesh->setTransform(Level4->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 4;
			}
		}
		else
		{
			Level4_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level4_lock->mesh->setTransform(Level4->mesh->GetTransform());
	}

	if (currentLevel >= 5)
	{
		if (Level5->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level5->mesh))
		{
			Level5_pressed->mesh->setTransform(Level5->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 5;
			}
		}
		else
		{
			Level5_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level5_lock->mesh->setTransform(Level5->mesh->GetTransform());
	}

	if (currentLevel >= 6)
	{
		if (Level6->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level6->mesh))
		{
			Level6_pressed->mesh->setTransform(Level6->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 6;
			}
		}
		else
		{
			Level6_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level6_lock->mesh->setTransform(Level6->mesh->GetTransform());
	}

	if (currentLevel >= 7)
	{
		if (Level7->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level7->mesh))
		{
			Level7_pressed->mesh->setTransform(Level7->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 7;
			}
		}
		else
		{
			Level7_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level7_lock->mesh->setTransform(Level7->mesh->GetTransform());
	}

	if (currentLevel >= 8)
	{
		if (Level8->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level8->mesh))
		{
			Level8_pressed->mesh->setTransform(Level8->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 8;
			}
		}
		else
		{
			Level8_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level8_lock->mesh->setTransform(Level8->mesh->GetTransform());
	}
	
	if (currentLevel >= 9)
	{
		if (Level9->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level9->mesh))
		{
			Level9_pressed->mesh->setTransform(Level9->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 9;
			}
		}
		else
		{
			Level9_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level9_lock->mesh->setTransform(Level9->mesh->GetTransform());
	}

	if (currentLevel >= 10)
	{
		if (Level10->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level10->mesh))
		{
			Level10_pressed->mesh->setTransform(Level10->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 10;
			}
		}
		else
		{
			Level10_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level10_lock->mesh->setTransform(Level10->mesh->GetTransform());
	}
	
	if (currentLevel >= 11)
	{
		if (Level11->collision->Point2HexagonCollision({ cursorLv.x, cursorLv.y }, Level11->mesh))
		{
			Level11_pressed->mesh->setTransform(Level11->mesh->GetTransform());
			if (levelInput.IsPressed(KEY::LEFT) == true)
			{
				std::cout << "get mouse left" << std::endl;
				getLevNum = 10;
			}
		}
		else
		{
			Level11_pressed->mesh->setTransform({ 850.0f, 850.0f });
		}
	}
	else
	{
		Level11_lock->mesh->setTransform(Level11->mesh->GetTransform());
	}
	
	if(getLevNum > 0)
	{
		INPUT->setInput(KEY::LEFT);
		switch (getLevNum)
		{		
		case 1:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST3);
			break;
		case 2:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST4);
			break;
		case 3:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST6);
			break;
		case 4:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST8);
			break;
		case 5:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST5);
			break;
		case 6:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST9);
			break;
		case 7:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST10);
			break;
		case 8:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST11);
			break;
		case 9:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST12);
			break;
		case 10:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST13);
			break;
		case 11:
			STATE_MANAGER->ChangeLevel(GameLevels::LV_TEST14);
			break;
			default:
				break;
		}
	}
	
	
	backgroundLv->mesh->Update(mShader2.GetShaderHandler(), textureBackgroundLv);

	Level1->mesh->Update(mShader2.GetShaderHandler(), texureIdLv1);
	Level1_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv1_pressed);

	Level2->mesh->Update(mShader2.GetShaderHandler(), texureIdLv2);
	Level2_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv2_pressed);
	Level2_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level3->mesh->Update(mShader2.GetShaderHandler(), texureIdLv3);
	Level3_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv3_pressed);
	Level3_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level4->mesh->Update(mShader2.GetShaderHandler(), texureIdLv4);
	Level4_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv4_pressed);
	Level4_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level5->mesh->Update(mShader2.GetShaderHandler(), texureIdLv5);
	Level5_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv5_pressed);
	Level5_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level6->mesh->Update(mShader2.GetShaderHandler(), texureIdLv6);
	Level6_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv6_pressed);
	Level6_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level7->mesh->Update(mShader2.GetShaderHandler(), texureIdLv7);
	Level7_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv7_pressed);
	Level7_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level8->mesh->Update(mShader2.GetShaderHandler(), texureIdLv8);
	Level8_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv8_pressed);
	Level8_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level9->mesh->Update(mShader2.GetShaderHandler(), texureIdLv9);
	Level9_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv9_pressed);
	Level9_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level10->mesh->Update(mShader2.GetShaderHandler(), texureIdLv10);
	Level10_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv10_pressed);
	Level10_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);

	Level11->mesh->Update(mShader2.GetShaderHandler(), texureIdLv11);
	Level11_pressed->mesh->Update(mShader2.GetShaderHandler(), texureIdLv11_pressed);
	Level11_lock->mesh->Update(mShader2.GetShaderHandler(), texureId_lock);
	
	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClearColor(0.f, 0.f, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
}

void LevelSelect::Close()
{
	getLevNum = 0;
	STATE_MANAGER->setCurrentLV(0);
	mShader.Delete();

	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
