#include "ObjectManager.h"
#include "MovePooPoo.h"
#include "Texture.h"
#include "HexagonElements.h"

static int PuzzleID = 0;
static int OriginID = 0;

MovePooPoo::MovePooPoo() :
	startD({ 0.f, 0.f }), endD({ 50.f, 0.f }), speed(30.f) {

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
			//isSuccess = false;
			isFirst = PuzzleID%2;
			PuzzleID += 1;

			if (isFirst == true)
			{
				OriginID++;
			}
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
void MovePooPoo::Clear()
{
	OriginID = 0;
	PuzzleID = 0;
}
void MovePooPoo::setDelta()
{
	distance = startD.magnitude({ endD.x - startD.x, endD.y - startD.y });
	direction = startD.normalize({ endD.x - startD.x, endD.y - startD.y });
	betweenDelta = { endD.x - startD.x, endD.y - startD.y };
}
void MovePooPoo::MoveInPuzzle(std::vector < Vector2<float>> exact)
{
	int count = 0;

	while (count <= exact.size())
	{

	}
}
void MovePooPoo::MoveInPuzzle(int shaderHandler)
{
	
	if (myAngles.size() ==PuzzleID)
	{
		isFinish = true;
		OriginID = 0;
		PuzzleID = 0;
		return;
	}

	origin = coor[OriginID];
	HexagonCoordinates myCoordinates(origin);
	if (isFirst == true)
	{
		SetStartD(myCoordinates.GetEdgeCenterCoordinates(myAngles[PuzzleID]));
		SetEndD(origin);
	}
	else if (isFirst == false)
	{
		//isSuccess = true;
		SetEndD(myCoordinates.GetEdgeCenterCoordinates(myAngles[PuzzleID]));
		SetStartD(origin);
	}

	Update(shaderHandler);

	
}
