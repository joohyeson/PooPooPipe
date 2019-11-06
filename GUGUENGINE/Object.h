#pragma once
#include "Transform.h"
#include "ComponentType.h"
#include "Mesh.h"

using ObjectID = unsigned;

class ObjectFactory;
class Component;

class Object 
{
public:
	friend class ObjectFactory;

	Object();
	~Object(){}

	void Init();
	void Destroy(Object* obj);

	bool AddComponent(Component* component);

	ObjectID GetObjectID()
	{
		return objectID;
	}
	void SetObjectID(ObjectID objID)
	{
		objectID = objID;
	}
	void SetName(const std::string& name)
	{
		objName = name;
	}
	std::string GetName() const
	{
		return objName;
	}
	std::string objName = "";

	ObjectID objectID;
	Transform* transform;
	Mesh* mesh;
};

