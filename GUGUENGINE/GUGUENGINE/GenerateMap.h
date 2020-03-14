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

	void MapAlignment();
	void SaveObject(Object* objectName);
	int GetObjectSize();

private:
	
	std::vector<Object*> objects;

	std::vector< Vector2<float> > coorSaver;//saver center coordinate
	int mapRow = 6;
	int mapColumn = 5;
};

