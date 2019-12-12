#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Input.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level3.h"
#include "../GUGUENGINE/Sound.h"

int check3 = 0;
Vector2<float> cursor3;

int moveCheck3 = 0;
int connectCheck3 = 0;
float degree2 = 0;
int rightCheck3 = 0;

GLuint texureIdLine3;
GLuint texureIdCurve3;
GLuint texureIdBlack3;

Sound se3;

void level3keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		STATE_MANAGER->ChangeLevel(LV_TEST1);
	}
}

void level3cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	cursor3 = { (static_cast<float>(xpos) - APPLICATION->width / 2) / (APPLICATION->width / 2), -1 * (static_cast<float>(ypos) - APPLICATION->height / 2) / (APPLICATION->height / 2) };
}

void  level3mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		moveCheck3 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck3 = 1;
		std::cout << "rightCheck2: " << rightCheck3 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level3::Init()
{
	movePuzzle = OBJECT_FACTORY->CreateEmptyObject();
	movePuzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	movePuzzle3 = OBJECT_FACTORY->CreateEmptyObject();

	puzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle3 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle4 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle5 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle6 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle7 = OBJECT_FACTORY->CreateEmptyObject();

	puzzle8 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle9 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle10 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle11 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle12 = OBJECT_FACTORY->CreateEmptyObject();

	blackPuzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle3 = OBJECT_FACTORY->CreateEmptyObject();

	startPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	endPuzzle = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine3 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack3 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve3 = TEXTURE->CreateTexture("assets\\image2.png", 0);

	se3.Init();
	se3.LoadMusic("assets\\coin.mp3");

	mShader.BuildColorShader();
	mShader2.BuildTextureShader();

	movePuzzle->AddComponent(new Mesh());
	movePuzzle->AddComponent(new PuzzleComponent());
	movePuzzle->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle->mesh->SetMeshType(hexagon);
	movePuzzle->Init();
	movePuzzle->mesh->setTransform({ 0.8f, 0.7f });
	movePuzzle->mesh->InitializeColorMesh();

	movePuzzle2->AddComponent(new Mesh());
	movePuzzle2->AddComponent(new PuzzleComponent());
	movePuzzle2->pipe->SetDirection(true, false, false, true, false, false);
	movePuzzle2->mesh->SetMeshType(hexagon);
	movePuzzle2->Init();
	movePuzzle2->mesh->setTransform({ 0.9f, 0.7f });
	movePuzzle2->mesh->InitializeColorMesh();

	movePuzzle3->AddComponent(new Mesh());
	movePuzzle3->AddComponent(new PuzzleComponent());
	movePuzzle3->pipe->SetDirection(false, false, false, true, false, true);
	movePuzzle3->mesh->SetMeshType(hexagon);
	movePuzzle3->Init();
	movePuzzle3->mesh->setTransform({ 1.0f, 0.7f });
	movePuzzle3->mesh->InitializeColorMesh();

	startPuzzle->AddComponent(new Mesh());
	startPuzzle->Init();
	startPuzzle->mesh->setTransform({ -0.5f, 0.7f });
	startPuzzle->mesh->InitializeTextureMesh();

	endPuzzle->AddComponent(new Mesh());
	endPuzzle->Init();
	endPuzzle->mesh->setTransform({ -0.5f, -0.5f });
	endPuzzle->mesh->InitializeTextureMesh();

	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransform({ -0.16f, 0.7f });
	puzzle1->mesh->setRotation(DegreeToRadian(60.f));
	puzzle1->mesh->InitializeTextureMesh();

	puzzle2->AddComponent(new Mesh());
	puzzle2->AddComponent(new PuzzleComponent());
	puzzle2->Init();
	puzzle2->mesh->setTransform({ 0.18f, 0.7f });
	puzzle2->pipe->SetDirection(false, false, false, true, false, true);
	puzzle2->mesh->InitializeTextureMesh();

	puzzle3->AddComponent(new Mesh());
	puzzle3->Init();
	puzzle3->mesh->setTransform({ -0.67f, 0.4f });
	puzzle3->mesh->setRotation(DegreeToRadian(180.f));
	puzzle3->mesh->InitializeTextureMesh();

	puzzle4->AddComponent(new Mesh());
	puzzle4->Init();
	puzzle4->mesh->setTransform({ -0.33f, 0.4f });
	puzzle4->mesh->InitializeTextureMesh();

	puzzle5->AddComponent(new Mesh());
	puzzle5->Init();
	puzzle5->mesh->setTransform({ 0.01f, 0.4f });
	puzzle5->mesh->setRotation(DegreeToRadian(120.f));
	puzzle5->mesh->InitializeTextureMesh();

	puzzle6->AddComponent(new Mesh());
	puzzle6->AddComponent(new PuzzleComponent());
	puzzle6->Init();
	puzzle6->mesh->setTransform({ -0.5f, 0.1f });
	puzzle6->mesh->setRotation(DegreeToRadian(60.f));
	puzzle6->pipe->SetDirection(false, false, true, false, true, false);
	puzzle6->mesh->InitializeTextureMesh();

	puzzle7->AddComponent(new Mesh());
	puzzle7->AddComponent(new PuzzleComponent());
	puzzle7->Init();
	puzzle7->mesh->setTransform({ 0.18f, 0.1f });
	puzzle7->mesh->setRotation(DegreeToRadian(240.f));
	puzzle7->pipe->SetDirection(false, true, false, false, false, true);
	puzzle7->mesh->InitializeTextureMesh();

	puzzle8->AddComponent(new Mesh());
	puzzle8->Init();
	puzzle8->mesh->setTransform({ -0.33f, -0.2f });
	puzzle8->mesh->InitializeTextureMesh();

	puzzle9->AddComponent(new Mesh());
	puzzle9->Init();
	puzzle9->mesh->setTransform({ 0.01f, -0.2f });
	puzzle9->mesh->setRotation(DegreeToRadian(60.f));
	puzzle9->mesh->InitializeTextureMesh();

	puzzle10->AddComponent(new Mesh());
	puzzle10->Init();
	puzzle10->mesh->setTransform({ 0.35f, -0.2f });
	puzzle10->mesh->setRotation(DegreeToRadian(60.f));
	puzzle10->mesh->InitializeTextureMesh();

	puzzle11->AddComponent(new Mesh());
	puzzle11->Init();
	puzzle11->mesh->setTransform({ -0.16f, -0.5f });
	puzzle11->mesh->setRotation(DegreeToRadian(60.f));
	puzzle11->mesh->InitializeTextureMesh();

	puzzle12->AddComponent(new Mesh());
	puzzle12->Init();
	puzzle12->mesh->setTransform({ 0.18f, -0.5f });
	puzzle12->mesh->InitializeTextureMesh();

	blackPuzzle1->AddComponent(new Mesh());
	blackPuzzle1->Init();
	blackPuzzle1->mesh->setTransform({ 0.35f, 0.4f });
	blackPuzzle1->mesh->InitializeTextureMesh();

	blackPuzzle2->AddComponent(new Mesh());
	blackPuzzle2->Init();
	blackPuzzle2->mesh->setTransform({ -0.16f, 0.1f });
	blackPuzzle2->mesh->InitializeTextureMesh();

	blackPuzzle3->AddComponent(new Mesh());
	blackPuzzle3->Init();
	blackPuzzle3->mesh->setTransform({ -0.67f, -0.2f });
	blackPuzzle3->mesh->InitializeTextureMesh();

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level3keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level3cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level3mouseButtonCallback);
}

void Level3::Update()
{
	if (check3 < 1)
	{
		check3++;
		std::cout << "HELLO" << std::endl;
	}

	se3.Update();

	float r = sqrt(5) / 10;

	getOrigin1_1.x = movePuzzle->mesh->GetTransform().x;
	getOrigin1_1.y = movePuzzle->mesh->GetTransform().y;

	getOrigin1_2.x = blackPuzzle1->mesh->GetTransform().x;
	getOrigin1_2.y = blackPuzzle1->mesh->GetTransform().y;

	if (cursor3.x <= (getOrigin1_1.x + r / 2) &&
		cursor3.x >= (getOrigin1_1.x - r / 2) &&
		cursor3.y <= (getOrigin1_1.y + r) &&
		cursor3.y >= (getOrigin1_1.y - r))
	{
		if (moveCheck3 % 2 == 1)
		{
			movePuzzle->mesh->setTransform({ cursor3.x, cursor3.y });
		}
		if (rightCheck3 != 0)
		{
			movePuzzle->pipe->Update();

			degree2 += static_cast<float>(DegreeToRadian(60.f));
			movePuzzle->mesh->setRotation(degree2);
			rightCheck3 = 0;

			if ((movePuzzle->pipe->GetDirValue(NW) == puzzle2->pipe->GetDirValue(SE)) && (movePuzzle->pipe->GetDirValue(SW) == puzzle7->pipe->GetDirValue(NE)))
			{
				std::cout << "pipe connect\n";
			}
			else
			{
				std::cout << "Not connect\n";
			}

			se3.Play(1);
			se3.SetVolume(0.5f);
			se3.SetLoopCount(1);
		}
	}
	else
	{
		moveCheck3 = 0;
	}

	if (getOrigin1_1.x <= (getOrigin1_2.x + r / 2) &&
		getOrigin1_1.x >= (getOrigin1_2.x - r / 2) &&
		getOrigin1_1.y <= (getOrigin1_2.y + r) &&
		getOrigin1_1.y >= (getOrigin1_2.y - r))
	{
		if (moveCheck3 % 2 == 0)
		{
			movePuzzle->mesh->setTransform({ getOrigin1_2.x,getOrigin1_2.y });
			connectCheck3 = 1;
		}
		else
		{
			connectCheck3 = 0;
		}
	}

	se3.Update();

	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdBlack3);

	movePuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);
	movePuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine3);
	movePuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve3);

	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level3::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
