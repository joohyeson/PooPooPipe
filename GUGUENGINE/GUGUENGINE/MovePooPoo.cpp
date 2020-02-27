#include "ObjectManager.h"
#include "MovePooPoo.h"
#include "Texture.h"

MovePooPoo::MovePooPoo() :
	startD({ 50.f, 50.f }), endD({-50.f, 50.f }) {
	betweenDelta = { endD.x - startD.x, endD.y - startD.x };
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
	if (isSuccess == true)
	{
	
		if ((startD.x != endD.x) ||
			(startD.y != endD.y))
		{
			if (startD.x > endD.x)
			{
				startD.x -= 0.1f;
			}
			else if(startD.x < endD.x)
			{
				startD.x += 0.1f;
			}

			if (startD.y > endD.y)
			{
				startD.y -= 0.1f;
			}
			else if (startD.y < endD.y)
			{
				startD.y += 0.1f;
			}

			if ((startD.x == endD.x) &&
				(startD.y == endD.y))
			{
				std::cout << startD.x << " " << startD.y << std::endl;
				std::cout << endD.x << " " << endD.y << std::endl;
				std::cout << "correct" << std::endl;

				isSuccess = false;
			}
			objectPP->mesh->setTransform({ startD });
		}
	}
	objectPP->mesh->UpdateNDC(shaderHandler, texturePP);
	

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