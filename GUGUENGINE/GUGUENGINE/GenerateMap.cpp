#include "GenerateMap.h"
#include "HexagonElements.h"
#include "Mathematics/Vector2.hpp"
#include <vector>
#include "ZigZagMap.h"
#include "GetDirection.h"

GenerateMap::GenerateMap() :mapRow(6), mapColumn(5) {};
GenerateMap::GenerateMap(int column, int row) :mapRow(column), mapColumn(row) {};

void GenerateMap::GetNextCenterCoor(float radius)
{
	Vector2<float> next;
	Vector2<float> down;
	Vector2<float> down_;
	int maxBlockCount = 0;

	ZigZagMap myMapType(mapRow, mapColumn);//maptype여러개 만든 후 스위치 문 안에서 map type고르게 바꿀거임
	GetDirection GetD(mapRow, mapColumn);

	if (mapColumn % 2 == 1)
	{
		maxBlockCount = mapRow * mapColumn - (mapColumn - 1) / 2;
	}
	else if (mapColumn % 2 == 0)
	{
		maxBlockCount = mapRow * mapColumn - (mapColumn) / 2;
	}

	next = { static_cast<float>((radius / 2.f) * sqrt(3) * 2), 0 };
	down = { static_cast<float>((radius / 2.f) * sqrt(3)) ,static_cast<float>(-((radius + (radius / 2.f)))) };
	down_ = { static_cast<float>(-(radius / 2.f) * sqrt(3)) ,static_cast<float>(-((radius + (radius / 2.f)))) };

	std::vector<Vector2<float>> blockCoorSaver;

	std::vector< Vector2<float> > tmp;

	bool isFirst = true;
	Vector2<float> beforeSave = { -320, 280 };
	Vector2<float> mileStone = beforeSave;


	for (int k = 0; k < mapColumn; k++) {
		for (int i = 0; i < mapRow; i++) {
			if (k % 2 == 1 &&
				i == mapRow - 1)
			{
				break;
			}

			std::cout << beforeSave.x << ", " << beforeSave.y;
			std::cout << "	";
			tmp.push_back(beforeSave);

			beforeSave.x += next.x;
			beforeSave.y += next.y;
		}
		std::cout << std::endl;

		if (isFirst == true)
		{
			beforeSave = { mileStone.x + down.x, mileStone.y + down.y };
			mileStone = beforeSave;
			isFirst = false;
		}
		else
		{
			beforeSave = { mileStone.x + down_.x, mileStone.y + down_.y };
			mileStone = beforeSave;
			isFirst = true;
		}

	}
	coorSaver = tmp;

	myMapType.DoesEdgeHasNeighbor();
	myMapType.SetAllNeighbor();

	GetD.StartGetDirection(0, 1, 12, 3, &myMapType);

	for (int i = 0; i <= 13; i++)
	{
		std::cout << "Puzzle" << i << ": ";
		for (int k = 0; k < 6; k++)
		{
			//std::cout << neighborSaver[i].myEdge[k].GetHasNeighbor() << ", ";
			std::cout <<"("<< myMapType.neighborSaver[i].myEdge[k].GetWhoIsNeighbor().x << ", "<< myMapType.neighborSaver[i].myEdge[k].GetWhoIsNeighbor().y<<")";
		}
		std::cout << std::endl;
	}

}

void GenerateMap::SaveObject(Object* objectName)
{
	objects.push_back(objectName);
}

int GenerateMap::GetObjectSize()
{
	return objects.size();
}

void GenerateMap::MapAlignment()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->mesh->setTransform(coorSaver[i]);
	}
}


