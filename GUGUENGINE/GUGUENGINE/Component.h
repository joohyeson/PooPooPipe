#pragma once
/*
 *hakyung.kim
 *uijin.lee
 *11.18.2019
 *digipen.hagyeong@gmail.com
 *Component.h
 *for make component
 */
#include"ComponentType.h"

class Object;
class Component
{
public:
	Component(ComponentType ctype) :ComponentType(ctype) {}
	virtual ~Component() {}
	virtual void Init() {}
	void SetOwner(Object* pobj)
	{
		pObject = pobj;
	}
	Object* GetOwner()
	{
		return pObject;
	}
	ComponentType GetComponentType()
	{
		return ComponentType;
	}

private:
	friend class Object;
	Component() = delete;
	Object* pObject = nullptr;
	ComponentType ComponentType;
};
