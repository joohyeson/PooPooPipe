
#pragma once

#include "System.h"
#include <vector>
#include <map>
#include "Object.h"
#include "Shader.h"
#include "ObjectManager.h"
//#include "Camera.h"

class Mesh;

class Graphics : public System
{
public:
	Graphics();
	~Graphics();
	void Init() override;
	void Update() override;
	void ChangeBackgroundColor(float r, float g, float b, float a);
	void AddMesh(Mesh* mesh);
	void DeleteMesh(Mesh* mesh);
	void DeleteAllMeshes();
private:
	std::map<ObjectID, Mesh*> MeshMap;
	std::vector<Mesh*> MeshsToBeDeleted;
	Shader shader;
};

extern Graphics* GRAPHICS;

