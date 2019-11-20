#pragma once

#include "Object.h"
#include"System.h"
#include<map>
#include<vector>
#include <string>


class Object;
using ObjectID = unsigned;

class ObjectManager : public System
{
public:
	ObjectManager();
	~ObjectManager() override;

	void Init() override {}
	void Update() override;
	void Destroy(Object* gameObject);
	void CreateObjectID(Object* gameObject);
	Object* CreateObject();
	void DestroyAllObjects();

	Object* FindObjectwithName(std::string& name) const;
	Object* FindObjectwithID(ObjectID id) const;

private:
	ObjectID last_objectID;

	std::map<ObjectID, Object*> ObjectIDMap;
	std::vector<Object*> ObjectsToBeDeleted;
};

extern ObjectManager* OBJECT_MANAGER;
