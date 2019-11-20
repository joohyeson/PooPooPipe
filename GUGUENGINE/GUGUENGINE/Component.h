#pragma once
#include "ComponentType.h"

class Object;

class Component
{
public:
	Component(ComponentType type);
	virtual ~Component(void)=0;
	// Initialize the component info
	virtual void    Initialize(void) = 0;
	// per frame behavior of component

	
	virtual void    Update() = 0;
	//Component& operator =(const Component&);
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

	//Component(const Component& rhs);

	//Component& operator=(const Component& rhs);
protected:
	Object* mOwner;         // Pointer to the parent object
public:
	ComponentType		mType;          // Component type
	bool				mbActive;       // Component active toggle

};

