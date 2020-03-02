#pragma once
#include <string>
#include <vector>
#include "Object.h"
class GenerateMap {
public:
	GenerateMap();
	GenerateMap(int column, int row);

	void GetNextCenterCoor(float radius);
	void SaveObject(Object* objectName);
	void MapAlignment();

	int GetObjectSize();
	
private:
	int mapColumn;
	int mapRow;
	std::vector<Object*> objects;
	std::vector< Vector2<float> > coorSaver;
};