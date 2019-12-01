/*
*  Choi Jinwoo
*  2018/09/25
*  BLUE ENGINE
*/
#include"Object.h"
#include <iostream>
#include "Graphics.h"
#include "ObjectManager.h"
#include <cassert>

Object::Object()
{
	objectID = 0;
	transform = nullptr;
	mesh = nullptr;
}

Object::~Object()
{
}

void Object::Init()
{
	if (transform != nullptr)
		transform->Init();

	if (mesh != nullptr)
		mesh->Init();
}

void Object::Destroy(Object* obj)
{
	std::cout << "Destroy called" << std::endl;
	OBJECT_FACTORY->Destroy(obj);
}

bool Object::AddComponent(Component* component)
{
	component->SetOwner(this);
	switch (component->GetComponentType())
	{
	case COMPONENTTYPE_MESH:
		mesh = dynamic_cast<Mesh*>(component);
		//GRAPHICS->AddMesh(mesh);
		return true;
	case COMPONENTTYPE_TRANSFORM:
		transform = dynamic_cast<Transform*>(component);
		return true;
	default:
		assert(!"Can't add an unknown component");
		break;
	}
	return false;
}



