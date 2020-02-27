#include "ObjectManager.h"
#include "MovePooPoo.h"
#include "Texture.h"

MovePooPoo::MovePooPoo() :
	startD({ 0.f, 0.f }), endD({10.f, 10.f }) {
	Init();
};

MovePooPoo::MovePooPoo(Vector2<float> startDirection, Vector2<float> endDirection) :
	startD(startDirection), endD(endDirection) {
	Init();
};
void MovePooPoo::Init()
{
	objectPP = OBJECT_FACTORY->CreateEmptyObject();
	objectPP->AddComponent(new Mesh());
	objectPP->Init();
	objectPP->mesh->setTransform({ -500, -500 });
	objectPP->mesh->SetMeshType(rectangle);
	objectPP->mesh->InitializeTextureMesh(80.f, 80.f);

	texturePP = TEXTURE->CreateTexture("assets\\testpoopoo.png", 0);

}
void MovePooPoo::Update(int shaderHandler)
{
	objectPP->mesh->SplitAnimation();
	objectPP->mesh->UpdateNDC(shaderHandler, texturePP);
	if (isSuccess == true)
	{
		if ((startD.x == endD.x) &&
			(startD.y == endD.y))
		{
			startD = endD;
			isSuccess = false;
		}
		else if ((startD.x != endD.x) ||
			(startD.y != endD.y))
		{
			startD.x += 0.1f;
			startD.y += 0.1f;
			objectPP->mesh->setTransform({ startD });
		}
		else
		{
			objectPP->mesh->setTransform({ endD });
			isSuccess = false;
		}
	}

}

void MovePooPoo::SetStartD(Vector2<float> start)
{
	startD = start;
}
void MovePooPoo::SetEndD(Vector2<float> end)
{
	endD = end;
}
void MovePooPoo::SetIsSuccess(bool success)
{
	isSuccess = success;
}