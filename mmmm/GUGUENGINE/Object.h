#pragma once
#include "Transform.h"
#include "ComponentType.h"
#include <vector>
#include "Mesh.h"
#include "Component.h"

class Component;
class Object {

	friend class State;
	using ComponentVector = std::vector<Component*>;

	unsigned    m_id = 0;	        // Object unique id - By Engine
	std::string m_name = "Unnamed";	// Object name - By User

public:
	Object();
	virtual ~Object();

	bool active = true;		// Object active toggle
	bool isDead = false;    // Object dead toggle
	
	Transform*	transform;	// Transform component
	Mesh*		mesh;

	void				SetName(const char* name);
	const std::string& GetName() const;
	unsigned			GetId() const;

	template <typename T>
	void GetComponent(ComponentType type, T*& pComp);
	template <typename T>
	void GetAllComponents(ComponentType type, std::vector<T*>& comps);
	virtual void Shutdown();
	
protected:
	void		AddComponent(Component* component);
	virtual void Initialize();
	
public:
	virtual void Update(float dt);
	void UpdateComponents(float dt);
	virtual void Close();

	Object(const Object&) = delete;
	Object(Object&&) = delete;
	Object& operator=(const Object&) = delete;
	Object& operator=(Object&&) = delete;
	void RemoveComponent(Component* component);
	void			RemoveAllComponents(void);
private:
	ComponentVector		mComponents;
	typedef ComponentVector::iterator VecItor;
};


