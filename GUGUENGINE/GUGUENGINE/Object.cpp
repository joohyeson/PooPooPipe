#include "Object.h"
//#include "Graphics.h"
#include "ObjectManager.h"
#include "Graphics.h"

Object::Object()
{
	m_id = 0;
	transform = nullptr;
	mesh = nullptr;
}

void Object::Destroy(Object* obj)
{
	OBJECT_MANAGER->Destroy(obj);
}

void Object::AddComponent(Component* component)
{
	VecItor found = std::find(mComponents.begin(), mComponents.end(), component);

	if(found != mComponents.end())
	{
		return;
	}

	component->SetOwner(this);
	mComponents.push_back(component);

}


void Object::UpdateComponents(float dt)
{
	int endIndex = static_cast<int>(mComponents.size()) - 1;
	for(; endIndex >= 0; --endIndex)
	{
		if(mComponents[endIndex]->mbActive)
		{
			mComponents[endIndex]->Update();
			
		}
		else
		{
			delete mComponents[endIndex];
			mComponents[endIndex] = mComponents[mComponents.size() - 1];
			mComponents.pop_back();
		}
	}
}


/*void Object::RemoveComponent(Component* component)
{
	VecItor end = mComponents.end();
	VecItor itor = std::find(mComponents.begin(), end, p)
}*/

void Object::RemoveComponent(Component* component)
{
	VecItor end = mComponents.end();
	VecItor itor = std::find(mComponents.begin(), end, component);
	std::iter_swap(itor, --end);
	mComponents.pop_back();

	component->SetOwner(0);
	delete component;
}

void Object::RemoveAllComponents()
{
	VecItor itor = mComponents.begin();
	VecItor end = mComponents.end();
	while(itor != end)
	{
		delete (*itor);
		++itor;
	}
	mComponents.clear();
}

void Object::RemoveAllComponents(ComponentType type)
{
	for(size_t i = 0; i < mComponents.size(); ++i)
	{
		if (mComponents[i]->GetType() == type)
			mComponents[i]->mbActive = false;
	}
}

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