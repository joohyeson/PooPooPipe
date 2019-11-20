
#include"Graphics.h"
#include <iostream>
#include <SDL.h>

Graphics* GRAPHICS = nullptr;

Graphics::Graphics()
{
	std::cout << "Graphics constructor called" << std::endl;
	GRAPHICS = this;
}

Graphics::~Graphics()
{
	delete GRAPHICS;
}

void Graphics::Init()
{
	glewInit();
	glClearColor(0.5f, 0.5f, 0.9f, 1.0f);

	int screenWidth = 0, screenHeight = 0;
	SDL_GetWindowSize(SDL_GL_GetCurrentWindow(), &screenWidth, &screenHeight);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	shader.BuildShader();
	
}

void Graphics::Update()
{
	for (auto obj : MeshsToBeDeleted)
	{
		if (obj == nullptr)
			continue;

		auto delete_objID = MeshMap.find(obj->GetOwner()->GetId());

		if (delete_objID != MeshMap.end())
		{
			delete obj;
			obj = nullptr;
			MeshMap.erase(delete_objID);
		}
	}
	MeshsToBeDeleted.clear();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
//	cam.update();
	//shader.SendUniformVariable("camera", cam.getCameraMatrix());

	for (auto mesh : MeshMap)
	{
		if (mesh.second != nullptr)
		{
			mesh.second->Initialize();
			mesh.second->Update();
		}
	}

	SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}

void Graphics::ChangeBackgroundColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Graphics::AddMesh(Mesh* mesh)
{
	std::cout << mesh->GetOwner()->GetId() << std::endl;
	MeshMap[mesh->GetOwner()->GetId()] = mesh;
}

void Graphics::DeleteMesh(Mesh* mesh)
{
	MeshsToBeDeleted.push_back(mesh);
}

void Graphics::DeleteAllMeshes()
{
	Update();
	for (auto GUGU : MeshMap)
	{
		delete GUGU.second;
		GUGU.second = nullptr;
	}
	MeshMap.clear();
}
