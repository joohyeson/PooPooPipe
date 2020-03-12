#pragma once
#include <string>
#include <vector>
#include "Object.h"
#include "HexagonElements.h"

class GenerateMap {
public:
	GenerateMap();
	GenerateMap(int column, int row);

	void GetNextCenterCoor(float radius);
	void SaveObject(Object* objectName);
	void MapAlignment();
	void DoesEdgeHasNeighbor();
	int GetObjectSize();
	void SetFirstLine(int k);
	void SetLastLine(int k, bool isOdd);
	void SetOddLine(int k, int i);
	void SetEvenLine(int k, int i);

private:
	int mapRow;
	int mapColumn;
	std::vector<Object*> objects;
	
	std::vector< Vector2<float> > coorSaver;
	std::vector<HexagonEdges> neighborSaver;
};

