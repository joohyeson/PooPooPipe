#include "Component.h"

Component::Component(ComponentType type):
	mOwner(nullptr),
	mType(type),
	mbActive(true)
{

}

Component::~Component()
{
}

void Component::SetOwner(Object* owner)
{
	mOwner = owner;
}

Object* Component::GetOwner()
{
	return mOwner;
}

ComponentType Component::GetType() const
{
	return mType;
}

void Component::SetState(bool active)
{
	mbActive = active;
}

bool Component::GetState() const
{
	return mbActive;
}
