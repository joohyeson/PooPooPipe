#include "Object.h"

void Object::AddComponent(Component* component)
{
	VecItor found = std::find(mComponents.begin(), mComponents.end(), component);

	if(found != mComponents.end())
	{
		return;
	}
	
	component->SetOwner(this);
	mComponents.push_back(component);
	//switch (component->GetType())
	//{
	//case COMPONENTTYPE_MESH:
	//	mesh = dynamic_cast<Mesh*>(component);
	//	//GRAPHICS->AddMesh(mesh);
	//	break;
	//case COMPONENTTYPE_TRANSFORM:
	//	transform = dynamic_cast<Transform*>(component);
	//	break;
	//default:
	//	assert(!"Can't add an unknown component");
	//	break;
	//}
}

void Object::UpdateComponents(float dt)
{
	int endIndex = mComponents.size() - 1;
	for(; endIndex >= 0; --endIndex)
	{
		if(mComponents[endIndex]->mbActive)
		{
			mComponents[endIndex]->Update(dt);
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