#include "DigipenLogo.h"
#include <windows.h>
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"


GLuint textureDigipenLogo;

void DigipenLogo::Init()
{
	textureDigipenLogo = TEXTURE->CreateTexture("assets\\DigiPenLogo.png", 0);

	digipenLogo = OBJECT_FACTORY->CreateEmptyObject();

	mShader.BuildTextureShader();
	digipenLogo->AddComponent(new Mesh);
	digipenLogo->Init();

	digipenLogo->mesh->setTransform({0,0});
	digipenLogo->mesh->SetMeshType(rectangle);
	digipenLogo->mesh->InitializeTextureMesh(9.65f, 5.0f);


}

void DigipenLogo::Update()
{
	digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo);


	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClearColor(1.f, 1.f, 1.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();

	Sleep(3000);
	STATE_MANAGER->ChangeLevel(MAINMENU);
	
}

void DigipenLogo::Close()
{
	mShader.Delete();
	ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
