#pragma once
#include "Transform.h"
#include "ComponentType.h"
#include <vector>
#include "Mesh.h"
#include "Component.h"
#include "System.h"


class ObjectManager;
class Component;
class Object : public System
{
	using ComponentVector = std::vector<Component*>;

public:

	unsigned    m_id/* = 0*/;	        // Object unique id - By 

	std::string m_name = "Unnamed";	// Object name - By User
	
	Object();
	virtual ~Object(){}

	bool active = true;		// Object active toggle
	bool isDead = false;    // Object dead toggle
	
	Transform*	transform;	// Transform component
	Mesh*		mesh;

	void				SetName(const char* name)
	{
		m_name = name;
	}
	const std::string& GetName() const
	{
		return m_name;
	}
	unsigned			GetId() const
	{
		return m_id;
	}
	void Destroy(Object* obj);
	template <typename T>
	void GetComponent(ComponentType type, T*& pComp);
	template <typename T>
	void GetAllComponents(ComponentType type, std::vector<T*>& comps);
	//virtual void Shutdown();
	
//protected:
	void		AddComponent(Component* component);
	//virtual void Initialize();
	
public:
	void UpdateComponents(float dt);
	//virtual void Close();
	void Init() override {}
	void Update() override {}
	
	Object(const Object&) = delete;
	Object(Object&&) = delete;
	
	Object& operator=(const Object&) = delete;
	Object& operator=(Object&&) = delete;
	
	void	RemoveComponent(Component* component);
	void	RemoveAllComponents(void);
	void	RemoveAllComponents(ComponentType type);

private:
	ComponentVector		mComponents;
	typedef ComponentVector::iterator VecItor;
};


