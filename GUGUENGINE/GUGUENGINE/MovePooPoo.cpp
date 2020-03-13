#include "ObjectManager.h"
#include "MovePooPoo.h"
#include "Texture.h"
#include "HexagonElements.h"

MovePooPoo::MovePooPoo() :
	startD({ 50.f, 50.f }), endD({ -50.f, 50.f }), speed(30.f) {

	Init();

};

MovePooPoo::MovePooPoo(Vector2<float> startDirection, Vector2<float> endDirection, int Speed) :
	startD(startDirection), endD(endDirection), speed(Speed) {

	Init();

};
void MovePooPoo::Init()
{
	setDelta();
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
	if (startD == endD)
	{
		isSuccess = false;
	}

	if (isSuccess == true)
	{

		if (isHidden == true)
		{
			objectPP->mesh->setTransform(startD);
			isHidden = false;
		}

		objectPP->mesh->AddTransform({ direction.x * speed * elapse, direction.y * speed * elapse });

		if (startD.magnitude({ objectPP->mesh->GetTransform().x - startD.x, objectPP->mesh->GetTransform().y - startD.y }) >= distance)
		{
			objectPP->mesh->setTransform(endD);
			isSuccess = false;
			isFirst = false;
		}
	}

	objectPP->mesh->Update(shaderHandler, texturePP);
}
void MovePooPoo::SetSpeed(int Speed)
{
	speed = Speed;
}
void MovePooPoo::SetStartD(float startX, float startY)
{
	startD = { startX, startY };
	setDelta();
}
void MovePooPoo::SetStartD(Vector2<float> startDirection)
{
	startD = startDirection;
	setDelta();
}
void MovePooPoo::SetEndD(float endX, float endY)
{
	endD = { endX, endY };
	setDelta();
}
void MovePooPoo::SetEndD(Vector2<float> endDirection)
{
	endD = endDirection;
	setDelta();
}
Vector2<float> MovePooPoo::GetEndD()
{
	return endD;
}
Vector2<float> MovePooPoo::GetPooPooTransform()
{
	return objectPP->mesh->GetTransform();
}
Vector2<float> MovePooPoo::GetStartD()
{
	return startD;
}
void MovePooPoo::SetIsSuccess(bool success)
{
	isSuccess = success;
}
void MovePooPoo::setDelta()
{
	distance = startD.magnitude({ endD.x - startD.x, endD.y - startD.y });
	direction = startD.normalize({ endD.x - startD.x, endD.y - startD.y });
	betweenDelta = { endD.x - startD.x, endD.y - startD.y };
}
void MovePooPoo::MoveInPuzzle(DirAngle startDirection, DirAngle endDirection, Vector2<float>ori, int shaderHandler)
{
	origin = ori;
	HexagonCoordinates myCoordinates(origin);
	realEndD= myCoordinates.GetEdgeCenterCoordinates(endDirection);
	if (isFirst == true)
	{
		SetStartD(myCoordinates.GetEdgeCenterCoordinates(startDirection));
		SetEndD(origin);
	}
	else if (isFirst == false)
	{
		isSuccess = true;
		SetEndD(myCoordinates.GetEdgeCenterCoordinates(endDirection));
		SetStartD(origin);
	}

	Update(shaderHandler);

}
