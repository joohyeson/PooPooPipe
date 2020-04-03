
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level9.h"
#include "../GUGUENGINE/Sound.h"

int check9 = 0;
Vector2<float> cursor9;

int coorcheck9 = 0;

int connectMove9 = 0;

bool autoRot = true;

float degree9 = 0;
float degree9_2 = DegreeToRadian(60.f);
float degree9_3 = DegreeToRadian(-60.f);
float degree9_4 = DegreeToRadian(60.f);
float degree9_5 = 0;
float degree9_6 = DegreeToRadian(-180.f);
float degree9_7 = DegreeToRadian(120.f);
float degree9_rot = DegreeToRadian(-120.f);

int rightCheck9 = 0;
int rightCheck9_2 = 0;
int rightCheck9_3 = 0;
int rightCheck9_4 = 0;
int rightCheck9_5 = 0;
int rightCheck9_6 = 0;
int rightCheck9_7 = 0;

int chekNext9 = 0;

int move9_1 = 0;
int move9_2 = 0;
int move9_3 = 0;

GLuint textureBackground9;

GLuint texureIdLine9;
GLuint texureIdCurve9;
GLuint texureIdThree9;
GLuint texureIdV9;
GLuint texureIdBlack9;

GLuint texureIdStart9;
GLuint texureIdEnd9;

GLuint texureIdLine9_2;
GLuint texureIdCurve9_2;
GLuint texureIdV9_2;

GLuint texureIdCurve9_3;


GLuint texureIdbutton9;
GLuint texureIdclear9;
GLuint texureSpace9;

Sound se9;

GLint texturePlayUI9;
GLint textureQuitUI9;
GLint textureOptionUI9;
GLint textureRestartUI9;
;
bool conecTcheck9_1 = false;
bool conecTcheck9_2 = false;
bool conecTcheck9_3 = false;



void level9keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNext9 == 1)
	{
		STATE_MANAGER->ChangeLevel(MAINMENU);
		chekNext9 = 0;

		conecTcheck9_1 = false;
		conecTcheck9_2 = false;
		conecTcheck9_3 = false;

		degree9 = 0;
		degree9_2 = DegreeToRadian(60.f);
		degree9_3 = DegreeToRadian(-60.f);
		degree9_4 = DegreeToRadian(60.f);
		degree9_5 = 0;
		degree9_6 = DegreeToRadian(-180.f);
		degree9_7 = DegreeToRadian(120.f);
		degree9_rot = DegreeToRadian(-120.f);
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		degree9 = 0;
		degree9_2 = DegreeToRadian(60.f);
		degree9_3 = DegreeToRadian(-60.f);
		degree9_4 = DegreeToRadian(60.f);
		degree9_5 = 0;
		degree9_6 = DegreeToRadian(-180.f);
		degree9_7 = DegreeToRadian(120.f);
		degree9_rot = DegreeToRadian(-120.f);

		STATE_MANAGER->ChangeLevel(MAINMENU);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}

	if (key == GLFW_KEY_TAB)
	{
		if (coorcheck9 == 1)
		{
			coorcheck9 = 0;
		}

		coorcheck9 += 1;
	}
}

void level9cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor9 = { static_cast<float>(xpos) - APPLICATION->width / 2 ,  -(static_cast<float>(ypos) - APPLICATION->height / 2) };
}

void  level9mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	move9_1 += 1;
	move9_2 += 1;
	move9_3 += 1;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		connectMove9 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck9 = 1;
		rightCheck9_2 = 1;
		rightCheck9_3 = 1;
		rightCheck9_4 = 1;
		rightCheck9_5 = 1;
		rightCheck9_6 = 1;
		rightCheck9_7 = 1;

		std::cout << "rightCheck2: " << rightCheck9 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level9::Init()
{
	background = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0,0 });
	background->mesh->InitializeTextureMesh(1920, 1920.f);
	textureBackground9 = TEXTURE->CreateTexture("assets\\background.png", 0);	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine9 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack9 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve9 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree9 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV9 = TEXTURE->CreateTexture("assets\\image4.png", 0);

	texureIdStart9 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd9 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine9_2 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve9_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);
	texureIdV9_2 = TEXTURE->CreateTexture("assets\\image4_11.png", 0);
	texureIdCurve9_3 = TEXTURE->CreateTexture("assets\\55.png", 0);

	texureIdbutton9 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear9 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace9 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);

	se9.Init();
	se9.LoadSE("assets\\coin.mp3");

	mShader2.BuildTextureShader();


	playUI = OBJECT_FACTORY->CreateEmptyObject();
	playUI->AddComponent(new Mesh());
	playUI->Init();

	playUI->mesh->setTransform({ 800.f, 300.f });
	playUI->mesh->SetMeshType(rectangle);
	playUI->mesh->InitializeTextureMesh(150.f, 150.f);
	texturePlayUI9 = TEXTURE->CreateTexture("assets\\playUI.png", 0);


	quitUI = OBJECT_FACTORY->CreateEmptyObject();
	quitUI->AddComponent(new Mesh());
	quitUI->Init();

	quitUI->mesh->setTransform({ 800.f, 150.f });
	quitUI->mesh->SetMeshType(rectangle);
	quitUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureQuitUI9 = TEXTURE->CreateTexture("assets\\quitUI.png", 0);


	optionUI = OBJECT_FACTORY->CreateEmptyObject();
	optionUI->AddComponent(new Mesh());
	optionUI->Init();
	optionUI->mesh->setTransform({ 800.f, 0.f });
	optionUI->mesh->SetMeshType(rectangle);
	optionUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureOptionUI9 = TEXTURE->CreateTexture("assets\\optionUI.png", 0);


	restartUI = OBJECT_FACTORY->CreateEmptyObject();
	restartUI->AddComponent(new Mesh());
	restartUI->Init();
	restartUI->mesh->setTransform({ 800.f, -150.f });
	restartUI->mesh->SetMeshType(rectangle);
	restartUI->mesh->InitializeTextureMesh(150.f, 150.f);
	textureRestartUI9 = TEXTURE->CreateTexture("assets\\restartUI.png", 0);

	startPuzzle = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 280.f + 50.f }, 120.f);

	endPuzzle = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, -200.f - 62.f }, -180.f);
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);

	puzzle1 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 280.f + 50.f });
	puzzle1->pipe->SetDirection(false, false, false, false, true, true);

	puzzle2 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -64.f - 465.f, 280.f + 50.f });
	puzzle2->pipe->SetDirection(false, false, false, true, false, true);

	puzzle3 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, 160.f + 22.f }, 120.f);
	//puzzle3->pipe->SetDirection(false, true, false, true, false, false);

	puzzle4 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, 160.f + 22.f }, -120.f);
	puzzle4->pipe->SetDirection(false, true, false, true, false, true);

	puzzle5 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, 40.f - 5.f }, -60.f);

	puzzle6 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -200.f - 500.f, 40.f - 5.f }, 60.f);
	puzzle6->pipe->SetDirection(true, false, false, true, false, false);

	puzzle7 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 72.f - 430.f, 40.f - 5.f }, 60.f);
	//puzzle7->pipe->SetDirection(false, false, true, true, false, false);

	puzzle8 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -268.f - 519.f, -80.f - 32.f }, 180.f);

	puzzle9 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, -80.f - 32.f });
	puzzle9->pipe->SetDirection(false, false, false, true, false, true);

	puzzle10 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 140.f - 415.f, -80.f - 32.f }, -240.f);
	puzzle10->pipe->SetDirection(true, false, true, true, false, false);

	puzzle11 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { -64.f - 465.f, -200.f - 62.f }, 60.f);

	puzzle12 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 72.f - 430.f, -200.f - 62.f }, 120.f);
	puzzle12->pipe->SetDirection(false, true, false, true, false, false);

	puzzle13 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 280.f + 50.f });
	puzzle13->pipe->SetDirection(false, true, true, false, false, false);

	puzzle14 = OBJECT_FACTORY->CreateObject(Type::Puzzle, { 276.f - 376.f, 160.f + 22.f }, -60);
	//puzzle14->pipe->SetDirection(false, false, false, true, true, false);

	puzzle15 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, 40.f - 5.f });
	puzzle15->pipe->SetDirection(true, false, false, true, false, false);

	puzzle16 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 276.f - 376.f, -80.f - 32.f }, -180.f);
	puzzle16->pipe->SetDirection(false, true, true, false, false, false);

	puzzle17 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 208.f - 393.f, -200.f - 62.f }, -60.f);
	puzzle17->pipe->SetDirection(true, false, false, false, false, true);

	puzzle18 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, 160.f + 22.f }, -60.f);
	puzzle18->pipe->SetDirection(true, false, false, true, false, true);

	puzzle19 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { 4.0f - 448.f, 160.f + 22.f }, 60.f);
	puzzle19->pipe->SetDirection(true, false, true, false, false, false);

	puzzle20 = OBJECT_FACTORY->CreateObject(Type::DirPuzzle, { -132.f - 482.f, -80.0f - 32.f });
	puzzle20->pipe->SetDirection(false, false, false, true, false, true);

	button = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 280.f, -240.f });
	clear = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 850.0f, 850.0f });
	spacePress = OBJECT_FACTORY->CreateObject(Type::shape_rec, { 0.0f, -340.f });

	button->mesh->InitializeTextureMesh(80.f, 80.f);
	clear->mesh->InitializeTextureMesh(80.f, 80.f);
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	mPooPoo.Init();

	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::NE_, startPuzzle->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SW_, DirAngle::S_, puzzle13->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, puzzle4->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SE_, puzzle15->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle16->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::SE_, puzzle10->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NW_, DirAngle::SW_, puzzle17->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::NW_, puzzle12->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::SE_, DirAngle::SW_, puzzle9->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::NE_, DirAngle::S_, puzzle20->mesh->GetTransform());
	mPooPoo.AddAngle(DirAngle::N_, DirAngle::SE_, endPuzzle->mesh->GetTransform());

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level9keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level9cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level9mouseButtonCallback);
}

void Level9::Update()
{
	if (check9 < 1)
	{
		check9++;
	}
	se9.Update();

	if (puzzle1->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle1->mesh))
	{
		if (rightCheck9 != 0)
		{
			puzzle1->pipe->Update();

			degree9 += static_cast<float>(DegreeToRadian(60.f));
			puzzle1->mesh->setRotation(degree9);

			rightCheck9 = 0;

			se9.Play(1);
			se9.SetVolume(0.5f);
			se9.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck9 = 0;
	}

	if (puzzle19->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle19->mesh))
	{
		if (rightCheck9_2 != 0)
		{
			puzzle19->pipe->Update();

			degree9_2 += static_cast<float>(DegreeToRadian(60.f));
			puzzle19->mesh->setRotation(degree9_2);

			rightCheck9_2 = 0;

			se9.Play(1);
			se9.SetVolume(0.5f);
			se9.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck9_2 = 0;
	}

	if (puzzle14->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle14->mesh))
	{
		if (rightCheck9_3 != 0)
		{
			puzzle14->pipe->Update();

			degree9_3 += static_cast<float>(DegreeToRadian(60.f));
			puzzle14->mesh->setRotation(degree9_3);

			rightCheck9_3 = 0;

			se9.Play(1);
			se9.SetVolume(0.5f);
			se9.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck9_3 = 0;
	}

	if (puzzle6->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle6->mesh))
	{
		if (rightCheck9_4 != 0)
		{
			puzzle6->pipe->Update();

			degree9_4 += static_cast<float>(DegreeToRadian(60.f));
			puzzle6->mesh->setRotation(degree9_4);

			rightCheck9_4 = 0;

			se9.Play(1);
			se9.SetVolume(0.5f);
			se9.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck9_4 = 0;
	}

	if (puzzle20->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle20->mesh))
	{
		if (rightCheck9_5 != 0)
		{
			puzzle20->pipe->Update();

			degree9_5 += static_cast<float>(DegreeToRadian(60.f));
			puzzle20->mesh->setRotation(degree9_5);

			rightCheck9_5 = 0;

			se9.Play(1);
			se9.SetVolume(0.5f);
			se9.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck9_5 = 0;
	}

	if (puzzle16->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle16->mesh))
	{
		if (rightCheck9_6 != 0)
		{
			puzzle16->pipe->Update();

			degree9_6 += static_cast<float>(DegreeToRadian(60.f));
			puzzle16->mesh->setRotation(degree9_6);

			rightCheck9_6 = 0;

			se9.Play(1);
			se9.SetVolume(0.5f);
			se9.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck9_6 = 0;
	}

	if (puzzle12->collision->Point2HexagonCollision({ cursor9.x,cursor9.y }, puzzle12->mesh))
	{
		if (rightCheck9_7 != 0)
		{
			puzzle12->pipe->Update();

			degree9_7 += static_cast<float>(DegreeToRadian(60.f));
			puzzle12->mesh->setRotation(degree9_7);

			rightCheck9_7 = 0;

			se9.Play(1);
			se9.SetVolume(0.5f);
			se9.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck9_7 = 0;
	}

	if ((puzzle15->pipe->GetDirValue(SE) == puzzle16->pipe->GetDirValue(NW)))
	{
		conecTcheck9_1 = true;
	}
	else
	{
		conecTcheck9_1 = false;
	}

	if ((puzzle12->pipe->GetDirValue(E) == puzzle17->pipe->GetDirValue(W)) && (puzzle12->pipe->GetDirValue(NW) == puzzle9->pipe->GetDirValue(SE)))
	{

		conecTcheck9_2 = true;
	}
	else
	{
		conecTcheck9_2 = false;
	}

	if ((puzzle20->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(W)) && (puzzle20->pipe->GetDirValue(SW) == endPuzzle->pipe->GetDirValue(NE)))
	{

		conecTcheck9_3 = true;
	}
	else
	{
		conecTcheck9_3 = false;
	}

	if (playUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, playUI->mesh))
	{
		if (connectMove9 % 2 == 1)
		{
			if (autoRot)
			{
				puzzle4->pipe->Update();

				degree9_rot += static_cast<float>(DegreeToRadian(-120.f));
				puzzle4->mesh->setRotation(degree9_rot);

				se9.Play(1);
				se9.SetVolume(0.5f);
				se9.SetLoopCount(1);

				autoRot = false;
			}

			if (conecTcheck9_1 && conecTcheck9_2 && conecTcheck9_3)
			{
				std::cout << "if 3" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext9 = 1;
				std::cout << "clear" << std::endl;
				mPooPoo.SetIsSuccess(true);
				connectMove9 = 0;
			}
		}
	}
	else
	{
		connectMove9 = 0;
	}

	if (restartUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, restartUI->mesh))
	{
		if (move9_1 % 2 == 1)
		{
			STATE_MANAGER->ChangeLevel(LV_TEST9);

		}
	}
	else
	{
		move9_1 = 0;
	}


	if (optionUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, optionUI->mesh))
	{
		if (move9_2 % 2 == 1)
		{
			STATE_MANAGER->ChangeLevel(OPTION);
		}
	}
	else
	{
		move9_2 = 0;
	}

	if (quitUI->collision->Point2BoxCollision({ cursor9.x,cursor9.y }, quitUI->mesh))
	{
		if (move9_2 % 2 == 1)
		{
			glfwTerminate();
		}
	}
	else
	{
		move9_2 = 0;
	}

	se9.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground9);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdV9_2);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_3);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9_2);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdLine9);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdV9_2);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);

	puzzle18->mesh->Update(mShader2.GetShaderHandler(), texureIdV9);
	puzzle19->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);
	puzzle20->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve9_2);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart9);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd9);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton9);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear9);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace9);

	playUI->mesh->Update(mShader2.GetShaderHandler(), texturePlayUI9);
	quitUI->mesh->Update(mShader2.GetShaderHandler(), textureQuitUI9);
	optionUI->mesh->Update(mShader2.GetShaderHandler(), textureOptionUI9);
	restartUI->mesh->Update(mShader2.GetShaderHandler(), textureRestartUI9);
	if (mPooPoo.IsFinish() == false)
	{
		mPooPoo.MoveInPuzzle(mShader2.GetShaderHandler());
	}
	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level9::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
