#include "ObjectManager.h"
#include "Object.h"

extern ObjectManager* OBJECT_MANAGER = nullptr;

ObjectManager::ObjectManager()
{
	OBJECT_MANAGER = this;
	last_objectID = 0;
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Update()
{
	for (auto obj : ObjectsToBeDeleted)
	{
		if (obj == nullptr)
			continue;

		auto delete_objID = ObjectIDMap.find(obj->m_id);

		if (delete_objID != ObjectIDMap.end())
		{
			delete obj;
			ObjectIDMap.erase(delete_objID);
		}
	}
	ObjectsToBeDeleted.clear();
}

void ObjectManager::Destroy(Object* gameObject)
{
	ObjectsToBeDeleted.push_back(gameObject);
}

void ObjectManager::CreateObjectID(Object* gameObject)
{
	++last_objectID;
	gameObject->m_id = last_objectID;

	ObjectIDMap[last_objectID] = gameObject;
}

Object* ObjectManager::CreateObject()
{
	Object* obj = new Object();

	CreateObjectID(obj);

	return obj;
}

void ObjectManager::DestroyAllObjects()
{
	Update();
	for (auto GUGU : ObjectIDMap)
		delete GUGU.second;

	ObjectIDMap.clear();
}

Object* ObjectManager::FindObjectwithName(std::string& name) const
{
	for (const auto obj : ObjectIDMap)
	{
		if (obj.second->m_name == name)
			return obj.second;
	}
	return nullptr;
}

Object* ObjectManager::FindObjectwithID(ObjectID id) const
{
	for (const auto obj : ObjectIDMap)
	{
		if (obj.second->GetId() == id)
			return obj.second;
	}
	return nullptr;
}
