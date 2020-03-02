#include "GenerateMap.h"
#include "Mathematics/Vector2.hpp"
#include <vector>

GenerateMap::GenerateMap() :mapColumn(6), mapRow(5) {};
GenerateMap::GenerateMap(int column, int row) :mapColumn(column), mapRow(row) {};

void GenerateMap::GetNextCenterCoor(float radius)
{
	Vector2<float> next;
	Vector2<float> down;
	Vector2<float> down_;
	int maxBlockCount = 0;

	if (mapRow % 2 == 1)
	{
		maxBlockCount = mapColumn * mapRow - (mapRow - 1) / 2;
	}
	else if (mapRow % 2 == 0)
	{
		maxBlockCount = mapColumn * mapRow - (mapRow) / 2;
	}

	next = { static_cast<float>((radius / 2.f) * sqrt(3) * 2), 0 };
	down = { static_cast<float>((radius / 2.f) * sqrt(3)) ,static_cast<float>(-((radius + (radius / 2.f)))) };
	down_ = { static_cast<float>(-(radius / 2.f) * sqrt(3)) ,static_cast<float>(-((radius + (radius / 2.f)))) };

	std::vector<Vector2<float>> blockCoorSaver;

	std::vector< Vector2<float> > tmp;

	bool isFirst = true;
	Vector2<float> beforeSave = { -320, 280 };
	Vector2<float> mileStone = beforeSave;


	for (int k = 0; k < mapRow; k++) {
		for (int i = 0; i < mapColumn; i++) {
			if (k % 2 == 1 &&
				i == mapColumn - 1)
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