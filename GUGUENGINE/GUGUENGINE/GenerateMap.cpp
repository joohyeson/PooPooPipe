#include "GenerateMap.h"
#include "HexagonElements.h"
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

	DoesEdgeHasNeighbor();
	for (int i = 0; i <= 13; i++)
	{
		std::cout << "Puzzle"<<i<<": ";
		for (int k = 0; k < 6; k++)
		{
			std::cout << neighborSaver[i].myEdge[k].GetHasNeighbor() << ", ";
		}
		std::cout<<std::endl;
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

void GenerateMap::SetFirstLine(int k)
{
	HexagonEdges currentHexa;
	if (k >= 1&&k<mapColumn-1)//not startpuzzle, and not last puzzle
	{
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else if (k == mapColumn-1)
	{
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}
void GenerateMap::SetLastLine(int k)
{
	HexagonEdges currentHexa;
	if (k == 0)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}
void GenerateMap::SetOddLine(int i)
{
	HexagonEdges currentHexa;

	if (i == 0)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else if (i == mapColumn-2)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}
void GenerateMap::SetEvenLine(int i)
{
	HexagonEdges currentHexa;

	if (i == 0)
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else if (i == mapColumn-1)
	{
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
	else
	{
		currentHexa.myEdge[0].SetHasNeigbor(true);
		currentHexa.myEdge[1].SetHasNeigbor(true);
		currentHexa.myEdge[2].SetHasNeigbor(true);
		currentHexa.myEdge[3].SetHasNeigbor(true);
		currentHexa.myEdge[4].SetHasNeigbor(true);
		currentHexa.myEdge[5].SetHasNeigbor(true);
		neighborSaver.push_back(currentHexa);
	}
}

void GenerateMap::DoesEdgeHasNeighbor() {
	neighborSaver.clear();

	HexagonEdges currentHexa;//neighborSaver에 pushback 할거임
	HexagonEdges startHexagon;
	HexagonEdges endHexagon;

	bool isFirst = true;
	
	startHexagon.myEdge[1].SetHasNeigbor(true);
	startHexagon.myEdge[2].SetHasNeigbor(true);

	endHexagon.myEdge[0].SetHasNeigbor(true);
	endHexagon.myEdge[4].SetHasNeigbor(true);
	endHexagon.myEdge[5].SetHasNeigbor(true);

	int count = 0;
	for (int k = 0; k < mapRow; k++) {
		for (int i = 0; i < mapColumn; i++) {
			currentHexa.clear();

			if (k == 0 && i == 0)
			{
				neighborSaver.push_back(startHexagon);
			}//set start Puzzle
			else if (k == mapRow-1 && i == mapColumn-2)
			{
				neighborSaver.push_back(endHexagon);
				break;
			}//set end puzzle

			if (k == 0)
			{
				SetFirstLine(i);
			}

			if (k % 2 == 1 &&
				i == mapColumn - 1)
			{
				break;
			}//if puzzle is "the smaller" line's last puzzle, not use push back

			if (k == mapRow-1)
			{
				SetLastLine(i);
			}

			if (k != mapRow-1 && k != 0)//other lines
			{
				if (isFirst == true)
				{
					SetEvenLine(i);
				}
				else
				{
					SetOddLine(i);
				}
			}

		}

		if (isFirst == true)
		{
			isFirst = false;
		}
		else
		{
			isFirst = true;
		}
	}

}
