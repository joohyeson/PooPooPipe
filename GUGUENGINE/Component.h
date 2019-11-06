#pragma once
#include "ComponentType.h"


class Object;

class Component
{
public:
	Component();
	Component(ComponentType type): mType(type){}
	virtual ~Component();
	
	virtual void Init();
	virtual void Update(float dt);

	void SetOwner(Object* owner)
	{
		pObject = owner;
	}

	Object* GetOwner()
	{
		return pObject;
	}
	
	ComponentType GetType()
	{
		return mType;
	}
	
	/*void SetState(bool active);
	bool GetState() const;*/
	
private:
	Component(const Component& rhs) = delete;
	Component& operator=(const Component& rhs) = delete;
	
private:
	ComponentType	mType;
	Object* mOwner;
	Object* pObject = nullptr;
//	bool mbActive;
	

};

