#pragma once
#include "ComponentType.h"


class Object;

class Component
{
public:
	Component(ComponentType type);
	virtual ~Component(void);
	// Initialize the component info
	virtual void    Initialize(void) = 0;
	// per frame behavior of component
	virtual void    Update(float dt) = 0;

	// Set pointer to the parent object
	void                SetOwner(Object* owner);
	// Get pointer to the parent object
	Object* GetOwner(void);
	// Get component type
	ComponentType		GetType(void) const;
	// Set component state (either it is active or not)
	void				SetState(bool active);
	// Get component state
	bool			    GetState(void) const;
private:
	Component(const Component& rhs) = delete;
	Component& operator=(const Component& rhs) = delete;
protected:
	Object* mOwner;         // Pointer to the parent object
private:
	ComponentType		mType;          // Component type
	bool				mbActive;       // Component active toggle
};

