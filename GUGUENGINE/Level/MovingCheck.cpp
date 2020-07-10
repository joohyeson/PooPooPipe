/*
 *hakyung.kim
 *uijin.lee
 *12.13.2019
 *digipen.hagyeong@gmail.com
 *if you want to check pipe connect, you can remove "//"pipe connect
 *this is level 4
 *Level4.cpp
 */

#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "MovingCheck.h"
#include "../GUGUENGINE/Sound.h"
#include "../GUGUENGINE/GenerateMap.h"
#include "../GUGUENGINE/MovePooPoo.h"

int chekNextTest = 0;

bool conecTCheckTest_1 = false;
bool conecTCheckTest_2 = false;
bool conecTCheckTest_3 = false;

bool blCheckTest3 = false;
bool blCheckTest3_2 = false;

bool blCheckTest = false;
bool blCheckTest_2 = false;

float degreeTest = 0;
float degreeTest_2 = 0;
float degreeTest_3 = 0;

int CheckTest = 0;
Vector2<float> cursorTest;

int movableTest_1 = 0;
int movableTest_2 = 0;
int movableTest_3 = 0;

int moveCheckTest = 0;
int moveCheckTest_2 = 0;
int moveCheckTest_3 = 0;
int connectMove4Test = 0;

int rightCheckTest = 0;
int rightCheckTest_2 = 0;
int rightCheckTest_3 = 0;

int puzzleIDCount = 0;

void Test5keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNextTest == 1)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
		chekNextTest = 0;

		conecTCheckTest_1 = false;
		conecTCheckTest_2 = false;
		conecTCheckTest_3 = false;

		degreeTest = 0;
		degreeTest_2 = 0;
		degreeTest_3 = 0;

		blCheckTest3 = false;
		blCheckTest3_2 = false;

		blCheckTest = false;
		blCheckTest_2 = false;
	}


	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		chekNextTest = 0;

		conecTCheckTest_1 = false;
		conecTCheckTest_2 = false;
		conecTCheckTest_3 = false;

		degreeTest = 0;
		degreeTest_2 = 0;
		degreeTest_3 = 0;

		blCheckTest3 = false;
		blCheckTest3_2 = false;

		blCheckTest = false;
		blCheckTest_2 = false;
		STATE_MANAGER->ChangeLevel(GameLevels::MAINMENU);
	}

	//if (key == GLFW_KEY_ESCAPE)
	//{

	//	STATE_MANAGER->ChangeLevel(GameLevels::OPTION);
	//}
}

void TestcursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursorTest = { static_cast<float>(xpos) - APPLICATION->height / 2 ,  -(static_cast<float>(ypos) - APPLICATION->width / 2) };
}

void  Test5mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheckTest += 1;
		moveCheckTest_2 += 1;
		moveCheckTest_3 += 1;
		connectMove4Test += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;

		if (movableTest_1 == 1)
		{
			movableTest_1 = 0;
		}
		if (movableTest_2 == 1)
		{
			movableTest_2 = 0;
		}
		if (movableTest_3 == 1)
		{
			movableTest_3 = 0;
		}

	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheckTest = 1;
		rightCheckTest_2 = 1;
		rightCheckTest_3 = 1;

		std::cout << "rightCheck2: " << rightCheckTest << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void MovingCheck::Init()
{
	myMap.SetColumn(4);
	myMap.SetRow(4);
	myMap.GetNextCenterCoor(100);
	
	//background = OBJECT_FACTORY->CreateEmptyObject();

	//background->AddComponent(new Mesh());
	//background->Init();

	//background->mesh->setTransform({ 0,0 });
	//background->mesh->SetMeshType(rectangle);
	//background->mesh->InitializeTextureMesh(800.f, 800.f);
	//textureBackground4 = TEXTURE->CreateTexture("assets\\background.png", 0);

	movePuzzle = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 320.f, 280.f }, 60.f);
	movePuzzle2 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 360.f, 120.f }, 60.f);
	movePuzzle3 = OBJECT_FACTORY->CreateObject(Type::MovePuzzle, { 400.0f, 0.0f }, 60.f);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, 0.f, false, false, true, false, true, false);//24
	puzzle2 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.f, 0.f }, 60.f,false, true, false, false, true, false);//14
	puzzle3 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, 0.f, false, false, true, false, true, false);//24
	puzzle4 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.f, 0.f }, 60.f, false, true, false, false, true, false);//14
	puzzle5 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, -60.f, false, false, false, true, false, true);//35
	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, 0.f, false, false, true, false, true, false);//24
	puzzle7 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, 0.f, false, false, true, false, true, false);//24

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.f, 0.f },60.f, false, true, false, false, true, false);//14
	puzzle9 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.f, 0.f }, 60.f, false, true, false, true, false, false);//13
	puzzle10 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 0.f, 0.f }, 60.f, false, true, false, true, false, false);//13

	blackPuzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, 120.f, true, false, true, false, false, false);//02
	blackPuzzle2 = OBJECT_FACTORY->CreateObject(Type::BlackPuzzle, { 0.f, 0.f }, 0.f);

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, 0.f, false, true, false, true, false, false);//13
	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 0.f, 0.f }, 0.f, false, false, false, true, false, true);//35
	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -0.7f * 400, -0.6f * 400 });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { -10.0f * 400, 10.0f * 400 });
	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.0f * 400, -0.85f * 400 });


	texureIdLine4 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack4 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve4 = TEXTURE->CreateTexture("assets\\image2.png", 0);

	texureIdStart4 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd4 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine4_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve4_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	texureIdbutton4 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear4 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace4 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);

	mShader2.BuildTextureShader();

	movePuzzle->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle2->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle3->pipe->SetDirection(true, false, false, true, false, false);
	//puzzle1->pipe->SetDirection(false, false, false, true, false, true);
	//puzzle6->pipe->SetDirection(true, false, false, false, true, false);
	//endPuzzle->pipe->SetDirection(false, false, false, false, false, true);

	myMap.SaveObject(startPuzzle);
	myMap.SaveObject(puzzle1);
	myMap.SaveObject(puzzle2);
	myMap.SaveObject(puzzle3);

	myMap.SaveObject(puzzle4);
	myMap.SaveObject(puzzle5);
	myMap.SaveObject(puzzle6);

	myMap.SaveObject(puzzle7);
	myMap.SaveObject(blackPuzzle1);
	myMap.SaveObject(blackPuzzle2);
	myMap.SaveObject(puzzle8);

	myMap.SaveObject(puzzle10);
	myMap.SaveObject(endPuzzle);
	myMap.SaveObject(puzzle9);

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	myMap.MapAlignment();
	myMap.SetReadyToStart(true);
	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::S_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::SE_, puzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::S_, puzzle5->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, blackPuzzle1->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::S_, endPuzzle->mesh->GetTransform());

	glfwSetKeyCallback(APPLICATION->getMyWindow(), Test5keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), TestcursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), Test5mouseButtonCallback);
}

void MovingCheck::Update()
{
	if (CheckTest < 1)
	{
		CheckTest++;
		std::cout << "HELLO" << std::endl;
		
		//myPooPoo.SetIsSuccess(true);
	}
	myMap.Update();

	if (myMap.GetHasWay() == true)
	{
		mPooPoo.SetIsSuccess(true);
	}

	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4);

	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack4);
	//blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack4);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart4);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd4);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4_1);
	movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve4_2);
	movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdLine4_1);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton4);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear4);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace4);
	//if (mPooPoo.IsFinish() == false)
	//{
	//	mPooPoo.MoveInPuzzle(mShader2.GetShaderHandler());
	//}
	//mPooPoo.Update(mShader2.GetShaderHandler());
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.f, 0.f, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void MovingCheck::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
