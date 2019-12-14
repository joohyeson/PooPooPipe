/*
 *hakyung.kim
 *uijin.lee
 *10.1.2019
 *digipen.hagyeong@gmail.com
 *Object.cpp
 *to make object
 */
#include"Object.h"
#include <iostream>
#include "ObjectManager.h"
#include <cassert>

Object::Object()
{
	objectID = 0;
	transform = nullptr;
	mesh = nullptr;
	pipe = nullptr;
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
	
	if (pipe != nullptr)
		pipe->Init();
}

void Object::Destroy(Object* obj)
{
	OBJECT_FACTORY->Destroy(obj);
}

bool Object::AddComponent(Component* component)
{
	component->SetOwner(this);
	switch (component->GetComponentType())
	{
	case COMPONENTTYPE_MESH:
		mesh = dynamic_cast<Mesh*>(component);
		return true;
	case COMPONENTTYPE_TRANSFORM:
		transform = dynamic_cast<Transform*>(component);
		return true;
	case COMPONENTTYPE_PIPE:
		pipe = dynamic_cast<PuzzleComponent*>(component);
		return true;
	default:
		assert(!"Can't add an unknown component");
		break;
	}
	return false;
}



