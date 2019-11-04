#pragma once
#include "ComponentType.h"


class Object;

class Component
{
public:
	Component(ComponentType type);
	virtual ~Component();
	virtual void Initialize() = 0;
	virtual void Update(float dt) = 0;

	void SetOwner(Object* owner);

	Object* GetOwner();
	ComponentType GetType() const;
	
	/*void SetState(bool active);
	bool GetState() const;*/
	
private:
	Component(const Component& rhs) = delete;
	Component& operator=(const Component& rhs) = delete;
protected:
	Object* mOwner;
private:
	ComponentType	mType;
	bool mbActive;
};

