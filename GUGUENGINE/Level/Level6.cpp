
#include "StateManager.h"
#include "../GUGUENGINE/ObjectManager.h"
#include <iostream>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Texture.h"
#include "../GUGUENGINE/Engine.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"
#include "Level6.h"
#include "../GUGUENGINE/Sound.h"

int check6 = 0;
Vector2<float> cursor6;

int coorcheck6 = 0;

int connectMove6 = 0;

float degree6 = 0;
float degree6_2 = 0;
float degree6_3 = 0;
float degree6_4 = 0;
float degree6_5 = 0;
float degree6_6 = 0;

int rightCheck6 = 0;
int rightCheck6_2 = 0;
int rightCheck6_3 = 0;
int rightCheck6_4 = 0;
int rightCheck6_5 = 0;
int rightCheck6_6 = 0;



int chekNext6 = 0;

GLuint textureBackground6;

GLuint texureIdLine6;
GLuint texureIdCurve6;
GLuint texureIdThree6;
GLuint texureIdV6;
GLuint texureIdBlack6;

GLuint texureIdStart6;
GLuint texureIdEnd6;

GLuint texureIdLine6_1;
GLuint texureIdCurve6_2;

GLuint texureIdbutton6;
GLuint texureIdclear6;
GLuint texureSpace6;

Sound se6;

bool conecTcheck6_1 = false;
bool conecTcheck6_2 = false;
bool conecTcheck6_3 = false;
bool conecTcheck6_4 = false;
bool conecTcheck6_5 = false;


void level6keyCallback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && chekNext6 == 1)
	{
		STATE_MANAGER->ChangeLevel(MAINMENU);
		chekNext6 = 0;

		conecTcheck6_1 = false;
		conecTcheck6_2 = false;
		conecTcheck6_3 = false;
		conecTcheck6_4 = false;
		conecTcheck6_5 = false;

		degree6 = 0;
		degree6_2 = 0;
		degree6_3 = 0;
		degree6_4 = 0;
		degree6_5 = 0;
		degree6_6 = 0;
	}

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		degree6 = 0;
		degree6_2 = 0;
		degree6_3 = 0;
		degree6_4 = 0;
		degree6_5 = 0;
		degree6_6 = 0;

		STATE_MANAGER->ChangeLevel(MAINMENU);
	}

	if (key == GLFW_KEY_ESCAPE)
	{
		glfwTerminate();
	}

	if (key == GLFW_KEY_TAB)
	{
		if (coorcheck6 == 1)
		{
			coorcheck6 = 0;
		}

		coorcheck6 += 1;
	}
}

void level6cursorPositionCallback(GLFWwindow* /*window*/, double xpos, double ypos)
{
	cursor6 = { static_cast<float>(xpos) - APPLICATION->height / 2 ,  -(static_cast<float>(ypos) - APPLICATION->width / 2) };
}

void  level6mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
{
	static float time = 0;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		connectMove6 += 1;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightCheck6 = 1;
		rightCheck6_2 = 1;
		rightCheck6_3 = 1;
		rightCheck6_4 = 1;
		rightCheck6_5 = 1;
		rightCheck6_6 = 1;

		std::cout << "rightCheck2: " << rightCheck6 << std::endl;
		std::cout << "RIGHT mouse button pressed" << std::endl;
	}
}

void Level6::Init()
{
	background = OBJECT_FACTORY->CreateEmptyObject();
	background->AddComponent(new Mesh());
	background->Init();

	background->mesh->setTransform({ 0,0 });
	background->mesh->SetMeshType(rectangle);
	background->mesh->InitializeTextureMesh(800.f, 800.f);
	textureBackground6 = TEXTURE->CreateTexture("assets\\background.png", 0);

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

	puzzle13 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle14 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle15 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle16 = OBJECT_FACTORY->CreateEmptyObject();
	puzzle17 = OBJECT_FACTORY->CreateEmptyObject();

	blackPuzzle1 = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle2 = OBJECT_FACTORY->CreateEmptyObject();
	blackPuzzle3 = OBJECT_FACTORY->CreateEmptyObject();

	startPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	endPuzzle = OBJECT_FACTORY->CreateEmptyObject();
	button = OBJECT_FACTORY->CreateEmptyObject();
	clear = OBJECT_FACTORY->CreateEmptyObject();

	spacePress = OBJECT_FACTORY->CreateEmptyObject();

	texureIdLine6 = TEXTURE->CreateTexture("assets\\image0.png", 0);
	texureIdBlack6 = TEXTURE->CreateTexture("assets\\image1.png", 0);
	texureIdCurve6 = TEXTURE->CreateTexture("assets\\image2.png", 0);
	texureIdThree6 = TEXTURE->CreateTexture("assets\\image3.png", 0);
	texureIdV6 = TEXTURE->CreateTexture("assets\\image4.png", 0);


	texureIdStart6 = TEXTURE->CreateTexture("assets\\imageStart.png", 0);
	texureIdEnd6 = TEXTURE->CreateTexture("assets\\imageEnd.png", 0);

	texureIdLine6_1 = TEXTURE->CreateTexture("assets\\image0-1.png", 0);
	texureIdCurve6_2 = TEXTURE->CreateTexture("assets\\image2-1.png", 0);

	texureIdbutton6 = TEXTURE->CreateTexture("assets\\character.png", 0);
	texureIdclear6 = TEXTURE->CreateTexture("assets\\clear.png", 0);
	texureSpace6 = TEXTURE->CreateTexture("assets\\pressSpace.png", 0);
	se6.Init();
	se6.LoadMusic("assets\\coin.mp3");

	mShader2.BuildTextureShader();

	startPuzzle->AddComponent(new Mesh());
	startPuzzle->AddComponent(new PuzzleComponent());
	startPuzzle->pipe->SetDirection(true, false, false, true, false, false);
	startPuzzle->Init();
	startPuzzle->mesh->setTransform({ -64.f, 280.f });
	startPuzzle->mesh->setRotation(DegreeToRadian(-240.f));
	startPuzzle->mesh->SetMeshType(hexagon);
	startPuzzle->mesh->InitializeTextureMesh();

	endPuzzle->AddComponent(new Mesh());
	endPuzzle->AddComponent(new PuzzleComponent());
	endPuzzle->pipe->SetDirection(false, true, false, false, true, false);
	endPuzzle->Init();
	endPuzzle->mesh->setRotation(DegreeToRadian(-180.f));
	endPuzzle->mesh->setTransform({ -200.f, -200.f });
	endPuzzle->mesh->SetMeshType(hexagon);
	endPuzzle->mesh->InitializeTextureMesh();

	puzzle1->AddComponent(new Mesh());
	puzzle1->Init();
	puzzle1->mesh->setTransform({ -200.f, 280.f });
	puzzle1->mesh->setRotation(DegreeToRadian(-60.f));
	puzzle1->mesh->SetMeshType(hexagon);
	puzzle1->mesh->InitializeTextureMesh();
	puzzle1->coor->SetAngle();

	puzzle2->AddComponent(new Mesh());
	puzzle2->Init();
	puzzle2->mesh->setTransform({ 72.f, 280.f });
	puzzle2->mesh->setRotation(DegreeToRadian(60.f));
	puzzle2->mesh->SetMeshType(hexagon);
	puzzle2->mesh->InitializeTextureMesh();

	puzzle3->AddComponent(new Mesh());
	puzzle3->AddComponent(new PuzzleComponent());
	puzzle3->Init();
	puzzle3->mesh->setTransform({ -268.f, 160.f });
	puzzle3->mesh->setRotation(DegreeToRadian(180.f));
	puzzle3->pipe->SetDirection(false, false, false, true, false, true);
	puzzle3->mesh->InitializeTextureMesh();

	puzzle4->AddComponent(new Mesh());
	puzzle4->AddComponent(new PuzzleComponent());
	puzzle4->Init();
	puzzle4->mesh->setTransform({ 140.f, 160.f });
	puzzle4->mesh->setRotation(DegreeToRadian(60.f));
	puzzle4->pipe->SetDirection(false, false, true, false, true, false);
	puzzle4->mesh->InitializeTextureMesh();

	puzzle5->AddComponent(new Mesh());
	puzzle5->Init();
	puzzle5->mesh->setTransform({ -64.f, 40.f });
	puzzle5->mesh->setRotation(DegreeToRadian(-60.f));
	puzzle5->mesh->InitializeTextureMesh();

	puzzle6->AddComponent(new Mesh());
	puzzle6->Init();
	puzzle6->mesh->setTransform({ -200.f, 40.f });
	puzzle6->mesh->setRotation(DegreeToRadian(-120.f));
	puzzle6->mesh->InitializeTextureMesh();

	puzzle7->AddComponent(new Mesh());
	puzzle7->AddComponent(new PuzzleComponent());
	puzzle7->Init();
	puzzle7->mesh->setTransform({ 72.f, 40.f });
	puzzle7->mesh->setRotation(DegreeToRadian(120.f)); //60
	puzzle7->pipe->SetDirection(false, false, true, true, false, false);
	puzzle7->mesh->InitializeTextureMesh();

	puzzle8->AddComponent(new Mesh());
	puzzle8->Init();
	puzzle8->mesh->setTransform({ -268.f, -80.f });
	puzzle8->mesh->setRotation(DegreeToRadian(120.f));
	puzzle8->mesh->InitializeTextureMesh();

	puzzle9->AddComponent(new Mesh());
	puzzle9->AddComponent(new PuzzleComponent());
	puzzle9->Init();
	puzzle9->pipe->SetDirection(false, false, false, true, false, true);
	puzzle9->mesh->setTransform({ 4.0f, -80.f });
	puzzle9->mesh->InitializeTextureMesh();

	puzzle10->AddComponent(new Mesh());
	puzzle10->Init();
	puzzle10->mesh->setTransform({ 140.f, -80.f });
	puzzle10->mesh->setRotation(DegreeToRadian(60.f));
	puzzle10->mesh->InitializeTextureMesh();

	puzzle11->AddComponent(new Mesh());
	puzzle11->Init();
	puzzle11->mesh->setTransform({ -64.f, -200.f });
	puzzle11->mesh->setRotation(DegreeToRadian(180.f));
	puzzle11->mesh->InitializeTextureMesh();

	puzzle12->AddComponent(new Mesh());
	puzzle12->AddComponent(new PuzzleComponent());
	puzzle12->Init();
	puzzle12->pipe->SetDirection(false, true, false, false, false, true);
	puzzle12->mesh->setRotation(DegreeToRadian(-120.f)); //-180
	puzzle12->mesh->setTransform({ 72.f, -200.f });
	puzzle12->mesh->InitializeTextureMesh();

	puzzle13->AddComponent(new Mesh());
	puzzle13->AddComponent(new PuzzleComponent());
	puzzle13->Init();
	puzzle13->mesh->setTransform({ 208.f, 280.f });
	puzzle13->pipe->SetDirection(false, false, false, true, false, true);
	//puzzle13->mesh->setRotation(DegreeToRadian(-60.f));
	puzzle13->mesh->InitializeTextureMesh();

	puzzle14->AddComponent(new Mesh());
	puzzle14->AddComponent(new PuzzleComponent());
	puzzle14->Init();
	puzzle14->mesh->setTransform({ 276.f, 160.f });
	puzzle14->mesh->setRotation(DegreeToRadian(60.f)); //-60
	puzzle14->pipe->SetDirection(false, false, false, true, true, false);
	puzzle14->mesh->InitializeTextureMesh();

	puzzle15->AddComponent(new Mesh());
	puzzle15->AddComponent(new PuzzleComponent());
	puzzle15->Init();
	puzzle15->mesh->setTransform({ 208.f, 40.f });
	//puzzle15->mesh->setRotation(DegreeToRadian(-60.f));
	puzzle15->pipe->SetDirection(false, false, false, true, false, true);
	puzzle15->mesh->InitializeTextureMesh();

	puzzle16->AddComponent(new Mesh());
	puzzle16->AddComponent(new PuzzleComponent());
	puzzle16->Init();
	puzzle16->mesh->setTransform({ 276.f, -80.f });
	puzzle16->mesh->setRotation(DegreeToRadian(-180.f)); //-60
	puzzle16->pipe->SetDirection(true, false, true, false, false, false);
	puzzle16->mesh->InitializeTextureMesh();

	puzzle17->AddComponent(new Mesh());
	puzzle17->AddComponent(new PuzzleComponent());
	puzzle17->Init();
	puzzle17->mesh->setTransform({ 208.f, -200.f });
	puzzle17->mesh->setRotation(DegreeToRadian(-120.f));
	puzzle17->pipe->SetDirection(false, true, false, false, false, true);
	puzzle17->mesh->InitializeTextureMesh();


	blackPuzzle1->AddComponent(new Mesh());
	blackPuzzle1->AddComponent(new PuzzleComponent());
	blackPuzzle1->Init();
	blackPuzzle1->mesh->setTransform({ -132.f, 160.f });
	blackPuzzle1->mesh->setRotation(DegreeToRadian(-60.f)); //120
	blackPuzzle1->pipe->SetDirection(true, false, false, false, false, true);
	blackPuzzle1->mesh->InitializeTextureMesh();

	blackPuzzle2->AddComponent(new Mesh());
	blackPuzzle2->Init();
	blackPuzzle2->mesh->setTransform({ 4.0f, 160.f });
	//blackPuzzle2->mesh->setRotation(DegreeToRadian(180.f));
	blackPuzzle2->mesh->InitializeTextureMesh();

	blackPuzzle3->AddComponent(new Mesh());
	blackPuzzle3->AddComponent(new PuzzleComponent());
	blackPuzzle3->Init();
	blackPuzzle3->mesh->setTransform({ -132.f, -80.0f });
	blackPuzzle3->mesh->setRotation(DegreeToRadian(180.f));
	blackPuzzle3->pipe->SetDirection(true, false, true, false, false, false);
	blackPuzzle3->mesh->InitializeTextureMesh();


	button->AddComponent(new Mesh());
	button->mesh->setTransform({ 280.f, -240.f });
	button->mesh->SetMeshType(rectangle);
	button->Init();
	button->mesh->InitializeTextureMesh(80.f, 80.f);

	clear->AddComponent(new Mesh());
	clear->mesh->setTransform({ 850.0f, 850.0f });
	clear->mesh->SetMeshType(rectangle);
	clear->Init();
	clear->mesh->InitializeTextureMesh(80.f, 80.f);

	spacePress->AddComponent(new Mesh());
	spacePress->mesh->setTransform({ 0.0f, -340.f });
	spacePress->mesh->SetMeshType(rectangle);
	spacePress->Init();
	spacePress->mesh->InitializeTextureMesh(400.f, 80.f);

	glfwSetKeyCallback(APPLICATION->getMyWindow(), level6keyCallback);
	glfwSetCursorPosCallback(APPLICATION->getMyWindow(), level6cursorPositionCallback);
	glfwSetMouseButtonCallback(APPLICATION->getMyWindow(), level6mouseButtonCallback);
}

void Level6::Update()
{
	if (check6 < 1)
	{
		check6++;
	}

	se6.Update();

	float r = static_cast<float>(sqrt(5) / 10);

	getOrigin1.x = puzzle14->mesh->GetTransform().x;
	getOrigin1.y = puzzle14->mesh->GetTransform().y;

	getOrigin2.x = blackPuzzle1->mesh->GetTransform().x;
	getOrigin2.y = blackPuzzle1->mesh->GetTransform().y;

	getOrigin3.x = puzzle7->mesh->GetTransform().x;
	getOrigin3.y = puzzle7->mesh->GetTransform().y;

	getOrigin4.x = blackPuzzle3->mesh->GetTransform().x;
	getOrigin4.y = blackPuzzle3->mesh->GetTransform().y;

	getOrigin5.x = puzzle16->mesh->GetTransform().x;
	getOrigin5.y = puzzle16->mesh->GetTransform().y;

	getOrigin6.x = puzzle12->mesh->GetTransform().x;
	getOrigin6.y = puzzle12->mesh->GetTransform().y;

	buttonClick_1.x = button->mesh->GetTransform().x;
	buttonClick_1.y = button->mesh->GetTransform().y;

	if (cursor6.x <= (getOrigin1.x + (r / 2) * 400) &&
		cursor6.x >= (getOrigin1.x - (r / 2) * 400) &&
		cursor6.y <= (getOrigin1.y + r * 400) &&
		cursor6.y >= (getOrigin1.y - r * 400))
	{
		if (rightCheck6 != 0)
		{
			puzzle14->pipe->Update();

			degree6 += static_cast<float>(DegreeToRadian(60.f));
			puzzle14->mesh->setRotation(degree6);

			rightCheck6 = 0;
			se6.Play(1);
			se6.SetVolume(0.5f);
			se6.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck6 = 0;
	}

	if (cursor6.x <= (getOrigin2.x + (r / 2) * 400) &&
		cursor6.x >= (getOrigin2.x - (r / 2) * 400) &&
		cursor6.y <= (getOrigin2.y + r * 400) &&
		cursor6.y >= (getOrigin2.y - r * 400))
	{
		if (rightCheck6_2 != 0)
		{
			blackPuzzle1->pipe->Update();

			degree6_2 += static_cast<float>(DegreeToRadian(60.f));
			blackPuzzle1->mesh->setRotation(degree6_2);
			rightCheck6_2 = 0;


			se6.Play(1);
			se6.SetVolume(0.5f);
			se6.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck6_2 = 0;
	}


	if (cursor6.x <= (getOrigin3.x + (r / 2) * 400) &&
		cursor6.x >= (getOrigin3.x - (r / 2) * 400) &&
		cursor6.y <= (getOrigin3.y + r * 400) &&
		cursor6.y >= (getOrigin3.y - r * 400))
	{
		if (rightCheck6_3 != 0)
		{
			puzzle7->pipe->Update();
			degree6_3 += static_cast<float>(DegreeToRadian(60.f));
			puzzle7->mesh->setRotation(degree6_3);
			rightCheck6_3 = 0;

			se6.Play(1);
			se6.SetVolume(0.5f);
			se6.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck6_3 = 0;
	}

	if (cursor6.x <= (getOrigin4.x + (r / 2) * 400) &&
		cursor6.x >= (getOrigin4.x - (r / 2) * 400) &&
		cursor6.y <= (getOrigin4.y + r * 400) &&
		cursor6.y >= (getOrigin4.y - r * 400))
	{
		if (rightCheck6_4 != 0)
		{
			blackPuzzle3->pipe->Update();
			degree6_4 += static_cast<float>(DegreeToRadian(60.f));
			blackPuzzle3->mesh->setRotation(degree6_4);
			rightCheck6_4 = 0;

			se6.Play(1);
			se6.SetVolume(0.5f);
			se6.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck6_4 = 0;
	}

	if (cursor6.x <= (getOrigin5.x + (r / 2) * 400) &&
		cursor6.x >= (getOrigin5.x - (r / 2) * 400) &&
		cursor6.y <= (getOrigin5.y + r * 400) &&
		cursor6.y >= (getOrigin5.y - r * 400))
	{
		if (rightCheck6_5 != 0)
		{
			puzzle16->pipe->Update();
			degree6_5 += static_cast<float>(DegreeToRadian(60.f));
			puzzle16->mesh->setRotation(degree6_5);
			rightCheck6_5 = 0;

			se6.Play(1);
			se6.SetVolume(0.5f);
			se6.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck6_5 = 0;
	}

	if (cursor6.x <= (getOrigin6.x + (r / 2) * 400) &&
		cursor6.x >= (getOrigin6.x - (r / 2) * 400) &&
		cursor6.y <= (getOrigin6.y + r * 400) &&
		cursor6.y >= (getOrigin6.y - r * 400))
	{
		if (rightCheck6_6 != 0)
		{
			puzzle12->pipe->Update();
			degree6_6 += static_cast<float>(DegreeToRadian(60.f));
			puzzle12->mesh->setRotation(degree6_6);
			rightCheck6_6 = 0;

			se6.Play(1);
			se6.SetVolume(0.5f);
			se6.SetLoopCount(1);
		}
	}
	else
	{
		rightCheck6_6 = 0;
	}

	if (cursor6.x <= (buttonClick_1.x + 200.f) &&
		cursor6.x >= (buttonClick_1.x - 200.f) &&
		cursor6.y <= (buttonClick_1.y + 200.f) &&
		cursor6.y >= (buttonClick_1.y - 200.f))
	{
		if (connectMove6 % 2 == 1)
		{
			if (conecTcheck6_1 && conecTcheck6_2 && conecTcheck6_3)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext6 = 1;
				std::cout << "clear" << std::endl;
				connectMove6 = 0;
			}

		}
	}
	else
	{
		connectMove6 = 0;
	}

	if ((puzzle14->pipe->GetDirValue(W) == puzzle13->pipe->GetDirValue(SE)) && (puzzle14->pipe->GetDirValue(SW) == puzzle4->pipe->GetDirValue(E)))
	{
		conecTcheck6_1 = true;
	}
	else
	{
		conecTcheck6_1 = false;
	}

	if ((puzzle7->pipe->GetDirValue(W) == puzzle4->pipe->GetDirValue(SW)) && (puzzle7->pipe->GetDirValue(NW) == puzzle15->pipe->GetDirValue(W)))
	{
		conecTcheck6_2 = true;
	}
	else
	{
		conecTcheck6_2 = false;
	}

	if ((puzzle16->pipe->GetDirValue(SE) == puzzle15->pipe->GetDirValue(SE)) && (puzzle16->pipe->GetDirValue(NE) == puzzle17->pipe->GetDirValue(NE)))
	{
		conecTcheck6_3 = true;
	}
	else
	{
		conecTcheck6_3 = false;
	}

	if ((puzzle12->pipe->GetDirValue(SW) == puzzle17->pipe->GetDirValue(W)) && (puzzle12->pipe->GetDirValue(E) == puzzle9->pipe->GetDirValue(SE)))
	{
		conecTcheck6_4 = true;

	}
	else
	{
		conecTcheck6_4 = false;
	}

	if ((blackPuzzle3->pipe->GetDirValue(W) == puzzle9->pipe->GetDirValue(W)) && (blackPuzzle3->pipe->GetDirValue(NE) == endPuzzle->pipe->GetDirValue(NE)))
	{
		conecTcheck6_5 = true;

	}
	else
	{
		conecTcheck6_5 = false;
	}


	if (cursor6.x <= (buttonClick_1.x + 200.f) &&
		cursor6.x >= (buttonClick_1.x - 200.f) &&
		cursor6.y <= (buttonClick_1.y + 200.f) &&
		cursor6.y >= (buttonClick_1.y - 200.f))
	{
		if (connectMove6 % 2 == 1)
		{
			if (conecTcheck6_1 && conecTcheck6_2 && conecTcheck6_3 && conecTcheck6_4 && conecTcheck6_5)
			{
				std::cout << "if 5" << std::endl;
				clear->mesh->setTransform({ 280.f, -240.f });
				chekNext6 = 1;
				std::cout << "clear" << std::endl;
				connectMove6 = 0;
			}

		}
	}
	else
	{
		connectMove6 = 0;
	}
	se6.Update();

	background->mesh->Update(mShader2.GetShaderHandler(), textureBackground6);
	puzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	puzzle4->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle5->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle6->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle7->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);

	puzzle8->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	puzzle9->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle10->mesh->Update(mShader2.GetShaderHandler(), texureIdLine6);
	puzzle11->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle12->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);

	puzzle13->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle14->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	puzzle15->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle16->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	puzzle17->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);

	blackPuzzle1->mesh->Update(mShader2.GetShaderHandler(), texureIdV6);
	blackPuzzle2->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);
	blackPuzzle3->mesh->Update(mShader2.GetShaderHandler(), texureIdCurve6);

	startPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdStart6);
	endPuzzle->mesh->Update(mShader2.GetShaderHandler(), texureIdEnd6);

	button->mesh->Update(mShader2.GetShaderHandler(), texureIdbutton6);
	clear->mesh->Update(mShader2.GetShaderHandler(), texureIdclear6);
	spacePress->mesh->Update(mShader2.GetShaderHandler(), texureSpace6);


	glfwSwapBuffers(APPLICATION->getMyWindow());

	glClearColor(0.4f, 0.3f, 0.3f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();

}

void Level6::Close()
{
	mShader.Delete();
	mMesh.Delete();
	ENGINE->Quit();

	OBJECT_FACTORY->DestroyAllObjects();
}
