/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *FmodLogo.h
 *this is FmodLogo
 */
#include "FmodLogo.h"
#include <windows.h>
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"

GLuint textureFmodLogo;

void FmodLogo::Init()
{
	textureFmodLogo = TEXTURE->CreateTexture("assets\\images2.png", 0);

	fmodLogo = OBJECT_FACTORY->CreateEmptyObject();

	mShader.BuildTextureShader();
	fmodLogo->AddComponent(new Mesh);
    fmodLogo->Init();

	fmodLogo->mesh->setTransform({ 0,0 });
	fmodLogo->mesh->SetMeshType(rectangle);

	fmodLogo->mesh->InitializeTextureMesh(560.0f, 240.f);


}

void FmodLogo::Update()
{
	fmodLogo->mesh->Update(mShader.GetShaderHandler(), textureFmodLogo);

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();

	Sleep(3000);
	STATE_MANAGER->ChangeLevel(MAINMENU);

}

void FmodLogo::Close()
{
	mShader.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
