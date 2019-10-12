#pragma once
#include "Transform.h"
#include "ComponentType.h"
#include <vector>


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

	// Components
	//SoundEffect	sound;		
	//Text		text;		
	//Sprite		sprite;		
	Transform	transform;	// Transform component
	//Physics		physics;	
	//Emitter		emitter;	

	void				SetName(const char* name);
	const std::string& GetName() const;
	unsigned			GetId() const;

	template <typename T>
	void GetComponent(ComponentType type, T*& pComp);
	template <typename T>
	void GetAllComponents(ComponentType type, std::vector<T*>& comps);
	virtual void Shutdown();
protected:
	void			AddComponent(Component* component);
	virtual void Initialize();
private:
	virtual void Update(float dt);
	void UpdateComponents(float dt);
	virtual void Close();

	Object(const Object&) = delete;
	Object(Object&&) = delete;
	Object& operator=(const Object&) = delete;
	Object& operator=(Object&&) = delete;

	void			RemoveAllComponents(void);
private:
	ComponentVector		mComponents;

};


template <typename T>
void Object::GetComponent(ComponentType type, T*& pComp)
{
	for (size_t i = 0; i < mComponents.size(); ++i)
	{
		if (mComponents[i]->GetType() == type)
		{
			pComp = dynamic_cast<T*>(mComponents[i]);
			return;
		}
	}
	pComp = nullptr;
}

template <typename T>
void Object::GetAllComponents(ComponentType type, std::vector<T*>& comps)
{
	for (size_t i = 0; i < mComponents.size(); ++i)
	{
		if (mComponents[i]->GetType() == type)
		{
			comps.push_back(dynamic_cast<T*>(mComponents[i]));
		}
	}
}