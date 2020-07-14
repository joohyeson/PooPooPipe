/*
 *eunjin.hong
 *12.10.2019
 *chocob0217@gmail.com
 *FmodLogo.h
 *this is FmodLogo
 */

#include "FmodLogo.h"
#include "../GUGUENGINE/ObjectManager.h"
#include "../GUGUENGINE/Texture.h"
#include <glfw3.h>
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Engine.h"
#include "StateManager.h"
#include "../GUGUENGINE/glfwInput.h"


GLuint textureFmodLogo;

void FmodLogo::Init()
{
	firstTime = glfwGetTime();

	fmodLogo = OBJECT_FACTORY->CreateEmptyObject();

	mShader.BuildTextureShader();
	fmodLogo->AddComponent(new Mesh);
    fmodLogo->Init();

	fmodLogo->mesh->setTransform({ 0,0 });
	fmodLogo->mesh->SetMeshType(MESHTYPE::rectangle);

	fmodLogo->mesh->InitializeTextureMesh(static_cast<float>(APPLICATION->width / 3), static_cast<float>(APPLICATION->height / 3));

	mInput.InitCallback(APPLICATION->getMyWindow());
}

void FmodLogo::Update()
{
	lastTime = glfwGetTime();

	if (mInput.IsPressed(KEY::F))
	{
		INPUT->setInput(KEY::F);
		APPLICATION->SetFullScreen();
	}

	fmodLogo->mesh->Update(mShader.GetShaderHandler(), TEXTURE->GetTexture(Textures::FMODLOGO));

	glfwSwapBuffers(APPLICATION->getMyWindow());
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();



	if(lastTime - firstTime > 2.f)
	{
		STATE_MANAGER->ChangeLevel(GameLevels::GUGULOGO);
	}
}

void FmodLogo::Close()
{
	mShader.Delete();
	//ENGINE->Quit();
	OBJECT_FACTORY->DestroyAllObjects();
}
