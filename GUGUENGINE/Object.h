#pragma once
#include "Transform.h"
#include "ComponentType.h"
#include <vector>


class Component;
class Object
{

public:
	
	Object();
	virtual ~Object();
	
	void SetName(const char* name);
	const std::string& GetName() const;
	unsigned int GetId() const;

	//void GetComponent(ComponentType type, /**/);
	
	//void GetAllComponents(ComponentType type, /**/);
	
	virtual void Shutdown();
	
protected:
	void AddComponent(Component* component);
	virtual void Initialize();
	
private:
	virtual void Update(float dt);
	void UpdateComponents(float dt);
	
	virtual void Close();

	Object(const Object&) = delete;
	Object(Object&&) = delete;
	Object& operator=(const Object&) = delete;
	Object& operator=(Object&&) = delete;

	void Remove();

};
