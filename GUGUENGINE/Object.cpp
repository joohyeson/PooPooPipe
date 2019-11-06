#include"Object.h"
#include "ObjectFactory.h"

Object::Object()
{
	objectID = 0;
	transform = nullptr;
	mesh = nullptr;
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
	OBJECT_FACTORY->Destroy(obj);
}

bool Object::AddComponent(Component* component)
{
	component->SetOwner(this);
	switch (component->GetType())
	{
	case COMPONENTTYPE_MESH:
		mesh = dynamic_cast<Mesh*>(component);
		return true;
		
	case COMPONENTTYPE_TRANSFORM:
		transform = dynamic_cast<Transform*>(component);
		return true;
		
	default:
		assert(!"error");
		break;
	}
	return false;
}



