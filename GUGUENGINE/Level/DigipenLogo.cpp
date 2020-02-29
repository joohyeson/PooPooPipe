/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *DigipenLogo.h
 *this is digipen logo
 */
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
	textureDigipenLogo = TEXTURE->CreateTexture("assets\\DigiPen_WHITE_1024px.png", 0);

	digipenLogo = OBJECT_FACTORY->CreateEmptyObject();

	mShader.BuildTextureShader();
	digipenLogo->AddComponent(new Mesh);
    digipenLogo->Init();

	digipenLogo->mesh->setTransform({0,0});
	digipenLogo->mesh->SetMeshType(rectangle);

	digipenLogo->mesh->InitializeTextureMesh(100.f, 100.f);

}

void DigipenLogo::Update()
{
	digipenLogo->mesh->Update(mShader.GetShaderHandler(), textureDigipenLogo);

    glfwSwapBuffers(APPLICATION->getMyWindow());
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();

	Sleep(3000);


	STATE_MANAGER->ChangeLevel(FMODLOGO);
	
}

void DigipenLogo::Close()
{
	mShader.Delete();
	ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
