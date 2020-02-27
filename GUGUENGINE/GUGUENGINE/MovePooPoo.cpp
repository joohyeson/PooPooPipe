#include "ObjectManager.h"
#include "MovePooPoo.h"
#include "Texture.h"

MovePooPoo::MovePooPoo() :
	startD({ 0.f, 0.f }), endD({ 0.5f, 0.5f }) {
};

MovePooPoo::MovePooPoo(Vector2<float> startDirection, Vector2<float> endDirection) :
	startD(startDirection), endD(endDirection) {
};
void MovePooPoo::Init()
{
	objectPP = OBJECT_FACTORY->CreateEmptyObject();
	objectPP->AddComponent(new Mesh());
	objectPP->Init();
	objectPP->mesh->setTransform({ 0,0 });
	objectPP->mesh->SetMeshType(rectangle);
	objectPP->mesh->InitializeTextureMesh(1.f, 1.f);

	texturePP = TEXTURE->CreateTexture("assets\\testpoopoo.png", 0);

}
void MovePooPoo::Update(int shaderHandler)
{
	objectPP->mesh->SplitAnimation();
	objectPP->mesh->Update(shaderHandler, texturePP);
	if (isSuccess == true)
	{
		if ((startD.x != endD.x) ||
			(startD.y != endD.y))
		{
			startD.x += 0.001f;
			startD.y += 0.001f;
			objectPP->mesh->setTransform({ startD });
		}
		else
		{
			objectPP->mesh->setTransform({ startD });
		}
	}

}
void MovePooPoo::SetIsSuccess(bool success)
{
	isSuccess = success;
}