/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Level2.cpp
 *this is level2
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level2.h"
#include "../GUGUENGINE/Sound.h"

Sound se2;

void Level2::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();

	background->AddComponent(new Mesh());
	background->Init();

	degree = 0;
	checkToPipe = 0;
	spaceCheck = false;
	click = 0;

	firstTime = glfwGetTime();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(MESHTYPE::rectangle);
	background->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);
	textureBackground2 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	puzzleUp = OBJECT_FACTORY->CreateEmptyObject();
	puzzleDown = OBJECT_FACTORY->CreateEmptyObject();
	spacePress = OBJECT_FACTORY->CreateEmptyObject();
	mouse = OBJECT_FACTORY->CreateEmptyObject();
	playbutton = OBJECT_FACTORY->CreateEmptyObject();
	pressPlay1 = OBJECT_FACTORY->CreateEmptyObject();
	pressPlay2 = OBJECT_FACTORY->CreateEmptyObject();
	playPressButton = OBJECT_FACTORY->CreateEmptyObject();
	win = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine2 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack2 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve2 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	textureSpace2 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	textureMouse = TEXTURE->CreateTexture("assets\\click_right.png", 0); 
	texturePlay = TEXTURE->CreateTexture("assets\\playUI.png", 0);
	textureWin = TEXTURE->CreateTexture("assets\\next.png", 0);
	texturePress1 = TEXTURE->CreateTexture("assets\\finish_solving.png", 0);
	texturePress2 = TEXTURE->CreateTexture("assets\\then_click.png", 0);
	texturePlayUIp = TEXTURE->CreateTexture("assets\\playUI_2.png", 0);

	se2.Init();
	se2.LoadMusic("assets\\coin.mp3");

	//mShader.BuildTextureShaderNDC();
	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->AddComponent(new PuzzleComponent());
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 160.0f, 280.0f });
	movePuzzle->mesh->setRotation(DegreeToRadian(60.f));
	movePuzzle->pipe->SetDirection(false, false, true, false, false, true);
	movePuzzle->mesh->SetMeshType(MESHTYPE::hexagon);
	movePuzzle->mesh->InitializeTextureMesh();

	blackPuzzle->AddComponent(new Mesh());
	blackPuzzle->mesh->SetMeshType(MESHTYPE::hexagon);
	blackPuzzle->Init();
	blackPuzzle->mesh->setTransform({ 0.0f, 120.0f });
	blackPuzzle->mesh->InitializeTextureMesh();

	puzzleUp->AddComponent(new Mesh());
	puzzleUp->AddComponent(new PuzzleComponent());
	puzzleUp->Init();
	puzzleUp->mesh->setTransform({ -85.f, 228.8f + 40.f });
	puzzleUp->mesh->setRotation(DegreeToRadian(180.f));
	puzzleUp->pipe->SetDirection(true, false, false, true, false, false);
	puzzleUp->mesh->SetMeshType(MESHTYPE::hexagon);
	puzzleUp->mesh->InitializeTextureMesh();

	puzzleDown->AddComponent(new Mesh());
	puzzleDown->AddComponent(new PuzzleComponent());
	puzzleDown->Init();
	puzzleDown->mesh->setTransform({ 72.f + 10.f, 10.f - 40.f });
	puzzleDown->mesh->setRotation(DegreeToRadian(180.f));
	puzzleDown->pipe->SetDirection(true, false, true, false, false, false);
	puzzleDown->mesh->SetMeshType(MESHTYPE::hexagon);
	puzzleDown->mesh->InitializeTextureMesh();

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -160.f });
	spacePress->mesh->SetMeshType(MESHTYPE::rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(560.f, 80.f);

	mouse->AddComponent(new Mesh());
	mouse->mesh->setTransform({ 550.f, 200.f });
	mouse->mesh->SetMeshType(MESHTYPE::rectangle);
	mouse->Init();
	mouse->mesh->InitializeTextureMesh(550.f, 300.f);

	playbutton->AddComponent(new Mesh());
	playbutton->AddComponent(new PuzzleComponent());
	playbutton->mesh->setTransform({ -2000, -2000.f });
	playbutton->Init(); 
	playbutton->mesh->SetMeshType(MESHTYPE::hexagon);
	playbutton->mesh->InitializeTextureMesh(400.f,400.f);

	playPressButton->AddComponent(new Mesh());
	playPressButton->AddComponent(new PuzzleComponent());
	playPressButton->mesh->setTransform({ -2000, -2000.f });
	playPressButton->Init();
	playPressButton->mesh->SetMeshType(MESHTYPE::hexagon);
	playPressButton->mesh->InitializeTextureMesh(400.f, 400.f);

	pressPlay1->AddComponent(new Mesh());
	pressPlay1->mesh->setTransform({ -2000.f, -2000.f });
	pressPlay1->mesh->SetMeshType(MESHTYPE::rectangle);
	pressPlay1->Init();
	pressPlay1->mesh->InitializeTextureMesh(500.f, 250.f);

	pressPlay2->AddComponent(new Mesh());
	pressPlay2->mesh->setTransform({ -2000.f, -2000.f });
	pressPlay2->mesh->SetMeshType(MESHTYPE::rectangle);
	pressPlay2->Init();
	pressPlay2->mesh->InitializeTextureMesh(500.f, 250.f);

	win->AddComponent(new Mesh());
	win->mesh->setTransform({ -2000.0f, -2000.0f });
	win->mesh->SetMeshType(MESHTYPE::rectangle);
	win->Init();
	win->mesh->InitializeTextureMesh(APPLICATION->width, APPLICATION->height);

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void Level2::Update()
{
	cursor = mInput.Cursor;
	lastTime = glfwGetTime();

	
	if (mInput.IsPressed(KEY::F) == true)
	{
		APPLICATION->SetFullScreen();
		mInput.setInput(KEY::F);
	}

	se2.Update();


	if (movePuzzle->collision->Point2HexagonCollision({ cursor.x,cursor.y }, movePuzzle->mesh) == true)
	{
		if (mInput.IsPressed(KEY::LEFT) == true )
		{
			movePuzzle->mesh->setTransform({ cursor.x, cursor.y });
		}

		if (mInput.IsPressed(KEY::RIGHT) == true)
		{
			rot = true;
		}
		if (rot == true)
		{
			if (mInput.IsPressed(KEY::RIGHT) == false)
			{
				movePuzzle->pipe->Update();

				degree += static_cast<float>(DegreeToRadian(60.f) );
				movePuzzle->mesh->setRotation(degree + DegreeToRadian(60.f));
				this->sound->Play("assets\\coin.mp3", 1);

				rot = false;
			}
		}
	}

	if (mInput.IsPressed(KEY::LEFT) == false)
	{
		if ((movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh)))
		{
			{
				if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh))
				{
					movePuzzle->mesh->setTransform({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y });
				}
			}
		}
	}

	if (movePuzzle->collision->Point2HexagonCollision({ blackPuzzle->mesh->GetTransform().x,blackPuzzle->mesh->GetTransform().y }, movePuzzle->mesh) == true)
	{
		if (movePuzzle->pipe->GetDirValue(SE) && movePuzzle->pipe->GetDirValue(NW))
		{
			checkToPipe = 1;
		}
		else
		{
			checkToPipe = 0;
		}
	}

	if (checkToPipe)
	{
		pressPlay1->mesh->setTransform({ 550.f,100.f });
		playbutton->mesh->setTransform({ 500.f,300.f });
		mouse->mesh->setTransform({ -2000.f,-2000.f });

		if (lastTime - firstTime > 2)
		{
			pressPlay2->mesh->setTransform({ 550.f,-100.f });

			if (playbutton->collision->Point2HexagonCollision({ cursor.x,cursor.y }, playbutton->mesh) == true)
			{
				playPressButton->mesh->setTransform({ 500.f,300.f });


				if (mInput.IsPressed(KEY::LEFT) == true && !click)
				{
					mInput.setInput(KEY::LEFT);
					spaceCheck = true;
					click = true;
				}
				else
				{
					click = false;
				}
			}
		}
	}

	if (spaceCheck)
	{
		win->mesh->setTransform({ 0,0 });

		if (lastTime - firstTime > 2)
		{
			STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
		}
	}

	se2.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground2);
	blackPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack2);
	puzzleUp->mesh->Update(mShader2.GetShaderHandler(), texureIdLine2);
	puzzleDown->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve2);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), textureSpace2);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdLine2);
	mouse->mesh->Update(mShader2.GetShaderHandler(), textureMouse);
	playbutton->mesh->Update(mShader2.GetShaderHandler(), texturePlay);
	playbutton->mesh->Update(mShader2.GetShaderHandler(), texturePlay);
	pressPlay1->mesh->Update(mShader2.GetShaderHandler(), texturePress1);
	pressPlay2->mesh->Update(mShader2.GetShaderHandler(), texturePress2);
	playPressButton->mesh->Update(mShader2.GetShaderHandler(), texturePlayUIp);

	win->mesh->Update(mShader2.GetShaderHandler(), textureWin);


	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level2::Close()
{
	mShader.Delete();
	mMesh.Delete();
	//ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
